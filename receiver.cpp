#include "FPGA_simulator.h"


void change_dynamic(sin_cos_t I_in[NB_EL_ARRAY],sin_cos_t Q_in[NB_EL_ARRAY],sin_cos_t I_out[NB_EL_ARRAY],sin_cos_t Q_out[NB_EL_ARRAY],bool *flag)
{
	sin_cos_t I_1[NB_EL_ARRAY];
	sin_cos_t Q_1[NB_EL_ARRAY];
	sin_cos_t sum_I=0;
	sin_cos_t sum_Q=0;
	sin_cos_t mean=0;

	//	the mean of samples is computed with 256 samples starting at index begin_index. We do not start at index 0 because of delay that can be added
	int begin_index=NB_EL_ARRAY>>1;
	for (ap_uint<12> i = begin_index;i<begin_index+256;i++)
	{
		//	not to overcome the dynamic
		sin_cos_t tmp_I=I_in[i]>>1;
		sin_cos_t tmp_Q=Q_in[i]>>1;

		//	abs function is available only for float
		if (tmp_I>=0)
		{
			sum_I+=tmp_I;
		}
		else
		{
			sum_I-=tmp_I;
		}
		if (tmp_Q>=0)
		{
			sum_Q+=tmp_Q;
		}
		else
		{
			sum_Q-=tmp_Q;
		}
	}

	//mean of sum_I+sum_Q is computed
	mean=(sum_I+sum_Q)>>8;

	//	We devide by four not to overcome the dynamic
	change_dyn_t change_dyn_tmp=(max_energy/mean)>>2;

	for (ap_uint<13> i = 0 ;i<NB_EL_ARRAY;i++)
	{
		sin_cos_t tmp_I=I_in[i];
		sin_cos_t tmp_Q=Q_in[i];
		sin_cos_t new_tmp_I=tmp_I*change_dyn_tmp;
		sin_cos_t new_tmp_Q=tmp_Q*change_dyn_tmp;
		I_out[i]=new_tmp_I;
		Q_out[i]=new_tmp_Q;
	}

//	the flag indicate if the message contains only noise or noise plus AID data
	if (change_dyn_tmp<420)
	{
		*flag=1;
	}
	else
	{
		*flag=0;
	}
}


//	dac application
void DAC(sin_cos_t I_in[NB_EL_ARRAY],sin_cos_t Q_in[NB_EL_ARRAY],sin_cos_t I_out[NB_EL_ARRAY],sin_cos_t Q_out[NB_EL_ARRAY])
{
	//	The data is converted to a variable of 16bits.
	for(int i=0;i<NB_EL_ARRAY;i++)
	{
		dac_t tmp_I1=I_in[i];
		dac_t tmp_Q1=Q_in[i];
		I_out[i]=tmp_I1;
		Q_out[i]=tmp_Q1;
	}
}

void Message_detection(change_dyn_t change_dyn,bool *flag)
{
	if (change_dyn<420)
	{
		*flag=1;
	}
	else
	{
		*flag=0;
	}
}


// Check whether the 16 bits CRC of the given length data is right.
bool IsCrc16Good(ap_uint<8> pData[23])
{
	ap_uint<16> fcs = 0xffff;    // Initialize
	int nLength=23;
	for(int i=0;i<nLength;i++)
	{
		fcs = (fcs >> 8) ^ crctab16[(fcs ^ pData[i]) & 0xff];
	}
	return (fcs == 0xf0b8);  // 0xf0b8 is CRC-ITU"Magic Value"
}


//Gaussian low pass filter with type sin_cos_t
void filtered_list(sin_cos_t list_in[NB_EL_ARRAY],sin_cos_t list_out[NB_EL_ARRAY])
{

	sin_cos_t corr_0=0;
	sin_cos_t hcorr[LEN_GAUSSIAN]={0};

	//	Initialisation
	for (ap_uint<13> k=0;k<LEN_GAUSSIAN;k++)
	{
		hcorr[k]=list_in[k];
		corr_0+=hcorr[k]*gaussian[k];
	}
	list_out[0]=corr_0;

	//Steaty state
	for (ap_uint<13> i=1;i<NB_EL_ARRAY-LEN_GAUSSIAN-1;i++)
	{
		sin_cos_t corr=0;
		for (ap_uint<13> k=0;k<LEN_GAUSSIAN;k++)
		{
			hcorr[k] = k < LEN_GAUSSIAN - 1 ? hcorr[k + 1] : list_in[i+LEN_GAUSSIAN-1];
			corr+=hcorr[k]*gaussian[k];
		}
		list_out[i]=corr;
	}
}

//Gaussian low pass filter with type phase_t
void filtered_list_p(phase_t list_in[NB_EL_ARRAY],phase_t list_out[NB_EL_ARRAY])
{

	phase_t corr_0=0;
	phase_t hcorr[LEN_GAUSSIAN]={0};

	//	Initialisation
	for (ap_uint<13> k=0;k<LEN_GAUSSIAN;k++)
	{
		hcorr[k]=list_in[k];
		corr_0+=hcorr[k]*gaussian[k];
	}
	list_out[0]=corr_0;

	//Steaty state
	for (ap_uint<13> i=1;i<NB_EL_ARRAY-LEN_GAUSSIAN-1;i++)
	{
		phase_t corr=0;
		for (ap_uint<13> k=0;k<LEN_GAUSSIAN;k++)
		{
			hcorr[k] = k < LEN_GAUSSIAN - 1 ? hcorr[k + 1] : list_in[i+LEN_GAUSSIAN-1];
			corr+=hcorr[k]*gaussian[k];
		}
		list_out[i]=corr;
	}
}

//Function to compute atan using lut. The function was found on internet
phase_t atan2_maelic(sin_cos_t sin16s,sin_cos_t cos16s)
{
	bool cos_inf_sin=false;
	bool sin_neg=false;
	bool cos_neg=false;
	if(sin16s < 0)   //..The input is sin16s and cos16s
	{
		sin16s= -sin16s;    //..not quite negation, but close...
		sin_neg=true;

	}
	if(cos16s < 0)
	{
		cos16s = -cos16s;    //..not quite negation, but close...
		cos_neg=true;
	}

	//..cos16s and sin17s are now guaranteed to be non-negative..

	if( cos16s < sin16s )
	{
		sin_cos_t temp16;
		temp16 = sin16s;
		sin16s = cos16s;
		cos16s = temp16;
		cos_inf_sin = true;  //..bit 5 records the swap of cos16s and sin16s
	}

	//........Now cos16s >= sin16s >= 0, guaranteed......
	//..So now the 360 deg. of possibilities has been reduced to just 45 degrees.
	//..Next I did some things that were highly optimized for fixed-point arithmetic, but since
	//..you are using a dsPic, maybe you can use just this:

	if(cos16s == 0)  return 0;   //..can't compute atan2 if both inputs are zero
	int index = (sin16s * 64) / cos16s;  //..ranges from 0 to 32.
	phase_t answer = LookUpTable[index];
	phase_t pi_divided_2 =1.570796326794897;
	phase_t pi =3.141592653589793;
	if(cos_inf_sin==true)    //..cos16s and sin16s were swapped...
	{
		answer = pi_divided_2 - answer;   //1.5708=pi/2
	}
	if(cos_neg==true)    //..cos16s was negative..
	{
		answer = pi - answer;   //..substitute appropriate units
	}
	if(sin_neg==true)    //..sin16s was negative..
	{
		answer = -answer;    //..answer ranges from -180 deg. to +180 degrees.
	}
	return answer;
}


void angle_computation(sin_cos_t I[NB_EL_ARRAY],sin_cos_t Q[NB_EL_ARRAY],phase_t tmp_diff_phase_array_0[NB_EL_ARRAY])
{

	sin_cos_t tmp_I=I[0];
	sin_cos_t tmp_Q=Q[0];
	phase_t new_phase=0;
	phase_t last_phase=0;
	phase_t add_phase=0;
	phase_t two_pi=TWO_PI;
	phase_t tmp_diff_phase_m=0;
	phase_t list_diff_phase[NB_EL_ARRAY];

	list_diff_phase[0]=0;

	for (ap_uint<13> i=1;i<NB_EL_ARRAY;i++)
	{
		sin_cos_t tmp_I=I[i];
		sin_cos_t tmp_Q=Q[i];

		//	Computation of angle
		new_phase=atan2_maelic(tmp_Q,tmp_I);

		//	computation of diff_phase
		tmp_diff_phase_m=new_phase-last_phase;


//		We implement the unwrap function
		if(tmp_diff_phase_m>3.0)
		{
			tmp_diff_phase_m-=two_pi;
		}

		else if(tmp_diff_phase_m<-3.0)
		{
			tmp_diff_phase_m+=two_pi;
		}

		tmp_diff_phase_array_0[i]=tmp_diff_phase_m;
		last_phase=new_phase;
	}
}

void correlation_computation(phase_t tmp_diff_phase_array_0[NB_EL_ARRAY],ap_uint<13> *idx_max)
{

	phase_t hcorr[LEN_DIFF_PHASE_COND2]={0};
	phase_t corr_0=0;
	ap_uint<13> idx_max_tmp=0;

	//	Initialisation of correlation
	for (ap_uint<13> k=0;k<LEN_DIFF_PHASE_COND2;k++)
	{
		hcorr[k]=tmp_diff_phase_array_0[k];
		corr_0+=hcorr[k]*DIFF_PHASE_COND2[k];
	}
	phase_t corr_max=corr_0;

	//	The correlation is computed on the 50 first bits '(25 diffphase_cond1 +25 loop) with a step equal to 2.
	for (ap_uint<13> i=1;i<25*NB_SAMPLES_ECH-1;i++)
	{
		phase_t corr=0;
		//		A method to reduce the array access of correlation computation is implemented (taken from vivado hls tutorial)
		for (ap_uint<13> k=0;k<LEN_DIFF_PHASE_COND2;k++)
		{
			hcorr[k] = k < LEN_DIFF_PHASE_COND2 - 1 ? hcorr[k + 1] : tmp_diff_phase_array_0[i+LEN_DIFF_PHASE_COND2-1];
			corr+=hcorr[k]*DIFF_PHASE_COND2[k];
		}
		//		The maximum value is extracted
		if(corr>corr_max)
		{
			corr_max=corr;
			idx_max_tmp=i;
		}
	}
	//	A delay was introduced by the gaussian filter that is taken into consideration here
	int delay_filter=LEN_GAUSSIAN;
	delay_filter=0;
	int nb_sample_d_2=NB_SAMPLES_ECH>>1;
	*idx_max=idx_max_tmp+delay_filter+nb_sample_d_2;
	return ;
}


void bits_decoding(ap_uint<13> idx_max,phase_t tmp_diff_phase_array[NB_EL_ARRAY],ap_uint<NB_BITS_TRAME_MAX> *bits_decoded)
{
	ap_uint<8> quotient= idx_max / NB_SAMPLES_ECH;
	phase_t tmp_last=tmp_diff_phase_array[idx_max];
	ap_uint<13> idx_phase=0;
	phase_t tmp_new=0;
	idx_phase=idx_max;
	tmp_new=tmp_diff_phase_array[idx_phase];
	phase_t min_phase=tmp_new;
	phase_t max_phase=tmp_new;
	phase_t tmp_diff_phase=0;
	ap_uint<NB_BITS_TRAME_MAX> bits_decoded_tmp=0;


	//	The threshold is computed just during the first 200 bits. The length of AIS frame is 184 bits
	for (ap_uint<13> i=0;i<200;i++)
	{
		if(i>=quotient)
		{
			idx_phase=idx_max+(i-quotient)*NB_SAMPLES_ECH;
			tmp_new=tmp_diff_phase_array[idx_phase];
			if(tmp_new>max_phase)
			{
				max_phase=tmp_new;
			}
			if(tmp_new<min_phase)
			{
				min_phase=tmp_new;
			}
		}

	}
	phase_t threshold=(max_phase+min_phase)>>1;

	//	Decode message, loop start from 0 indice to fix the number of loop iterations
	for (ap_uint<13> i=0;i<NB_BITS_TRAME_MAX;i++)
	{
		if(i>=quotient)
		{
			idx_phase=idx_max+(i-quotient)*NB_SAMPLES_ECH;
			tmp_new=tmp_diff_phase_array[idx_phase];
			if((tmp_new)>threshold)
			{
				bits_decoded_tmp[i-quotient]=1;
			}
			else
			{
				bits_decoded_tmp[i-quotient]=0;
			}
		}
	}

	*bits_decoded=bits_decoded_tmp;
	return ;
}



void GMSK_demodulation(sin_cos_t I_in[NB_EL_ARRAY],sin_cos_t Q_in[NB_EL_ARRAY],ap_uint<NB_BITS_TRAME_MAX> *bits_decoded)
{
	//	to prevent unrolling loop made by dataflow directive written in receiver function
#pragma HLS pipeline off

	phase_t tmp_diff_phase_array_0[NB_EL_ARRAY]={0};
	phase_t tmp_diff_phase_array_1[NB_EL_ARRAY]={0};
	sin_cos_t I[NB_EL_ARRAY]={0};
	sin_cos_t Q[NB_EL_ARRAY]={0};
	sin_cos_t I_filtered[NB_EL_ARRAY]={0};
	sin_cos_t Q_filtered[NB_EL_ARRAY]={0};
	ap_uint<13> idx_max=0;
	phase_t diff_tmp=0;
	phase_t tmp_diff_phase=0;

	ap_uint<NB_BITS_TRAME_MAX> bits_decode;

	//	phase are filtered
	filtered_list(I_in,I_filtered);
	filtered_list(Q_in,Q_filtered);

	//	difference of the Angle is computed
	angle_computation(I_filtered,Q_filtered,tmp_diff_phase_array_0);

//	//	phase are filtered
	filtered_list_p(tmp_diff_phase_array_0,tmp_diff_phase_array_1);

	// Correlation is computed to determine the beginning of the training sequence
	correlation_computation(tmp_diff_phase_array_1,&idx_max);

	//	bits are decoding thanks to idx_max and the diffrence of phase
	bits_decoding(idx_max,tmp_diff_phase_array_1,bits_decoded);

	return ;
}


void NRZI_decoding(ap_uint<NB_BITS_TRAME_MAX> bits,ap_uint<NB_BITS_TRAME_MAX> *bits_decoded)
{
	bool last_bit=0;
	bool tmp_bit=0;
	ap_uint<NB_BITS_TRAME_MAX> bits_decoded_tmp=0;
	for (ap_uint<13> i=0;i<NB_BITS_TRAME_MAX;i++)
	{
		tmp_bit=bits[i];
		if (tmp_bit==last_bit)
		{
			bits_decoded_tmp[i]=1;

			last_bit=tmp_bit;
		}
		else
		{
			bits_decoded_tmp[i]=0;
			last_bit=tmp_bit;
		}
	}
	*bits_decoded=bits_decoded_tmp;
}


void find_start(ap_uint<NB_BITS_TRAME_MAX> bit_decode,ap_uint<9> *idx)
{
	ap_uint<3> nb_bits_1=0;
	ap_uint<9> idx_tmp=0;

	//	We consider the 56 first bits to detect the start flag
	for (ap_uint<9> i=0;i<56;i++)
	{
		if (bit_decode[i]==1)
		{
			nb_bits_1++;
		}
		else
		{
			nb_bits_1=0;
		}
		if(nb_bits_1==6)
		{
			idx_tmp=i+2;
		}
	}
	*idx=idx_tmp;
	return ;
}

void Bits_unstuffing(ap_uint<NB_BITS_TRAME_MAX> bit_decode,ap_uint<NB_BITS_DATA_CRC> *bit_decoded_unstuffed)
{
	ap_uint<NB_BITS_TRAME_MAX> bit_decoded_unstuffed_tmp=0;
	ap_uint<NB_BITS_DATA_CRC> bit_decoded_unstuffed_tmp_1=0;
	ap_uint<3> ones_consecutive=0;
	ap_uint<9> idx_bit_decoded_unstuffed=0;
	ap_uint<9> idx;

	find_start(bit_decode,&idx);

	for (ap_uint<9> i=idx;i<NB_BITS_TRAME_MAX;i++)
	{
#pragma HLS LOOP_TRIPCOUNT max=256 min=0
		if(bit_decode[i]==1)
		{
			ones_consecutive++;
			bit_decoded_unstuffed_tmp[idx_bit_decoded_unstuffed]=1;
			if(ones_consecutive==5)
			{
				ones_consecutive=0;
				i++;
			}
		}
		else
		{
			ones_consecutive=0;
			bit_decoded_unstuffed_tmp[idx_bit_decoded_unstuffed]=0;
		}
		idx_bit_decoded_unstuffed++;
	}

	for (ap_uint<9> i=0;i<NB_BITS_DATA_CRC;i++)
	{
#pragma HLS LOOP_TRIPCOUNT max=184 min=0
		bit_decoded_unstuffed_tmp_1[i]=bit_decoded_unstuffed_tmp[i];
	}

	*bit_decoded_unstuffed=bit_decoded_unstuffed_tmp_1;

	return ;
}



void Bytes_flipping_r(ap_uint<NB_BITS_DATA_CRC> bits_decoded_unstuffed,ap_uint<NB_BITS_DATA> *bit_decode_flipped,bool check)
{
	ap_uint<NB_BITS_DATA> bit_decode_flipped_tmp=0;

	if (check==1)
	{

		for (int i=0;i<NB_BYTES_DATA;i++)
		{
			bit_decode_flipped_tmp[8*i]=bits_decoded_unstuffed[NB_BITS_DATA-1-7-i*8];
			bit_decode_flipped_tmp[8*i+1]=bits_decoded_unstuffed[NB_BITS_DATA-1-6-i*8];
			bit_decode_flipped_tmp[8*i+2]=bits_decoded_unstuffed[NB_BITS_DATA-1-5-i*8];
			bit_decode_flipped_tmp[8*i+3]=bits_decoded_unstuffed[NB_BITS_DATA-1-4-i*8];
			bit_decode_flipped_tmp[8*i+4]=bits_decoded_unstuffed[NB_BITS_DATA-1-3-i*8];
			bit_decode_flipped_tmp[8*i+5]=bits_decoded_unstuffed[NB_BITS_DATA-1-2-i*8];
			bit_decode_flipped_tmp[8*i+6]=bits_decoded_unstuffed[NB_BITS_DATA-1-1-i*8];
			bit_decode_flipped_tmp[8*i+7]=bits_decoded_unstuffed[NB_BITS_DATA-1-0-i*8];
		}
		*bit_decode_flipped=bit_decode_flipped_tmp;
	}
	return ;
}



void CRC_check(ap_uint<NB_BITS_DATA_CRC> bit_decoded_unstuffed,bool *check)
{
	//	Initialisation
	ap_uint<NB_BITS_DATA> data_tmp=0;
	ap_uint<16> crc_tmp=0;
	ap_uint<16> crc1_tmp=0;
	ap_uint<8> byte=0;
	ap_uint<8> list_bytes[23];

	for(ap_uint<8> i=0;i<NB_BYTES_DATA_CRC;i++)
	{
		byte=1*bit_decoded_unstuffed[0+i*8]+2*bit_decoded_unstuffed[1+i*8]+4*bit_decoded_unstuffed[2+i*8]+8*bit_decoded_unstuffed[3+i*8]+16*bit_decoded_unstuffed[4+i*8]+32*bit_decoded_unstuffed[5+i*8]+64*bit_decoded_unstuffed[6+i*8]+128*bit_decoded_unstuffed[7+i*8];
		list_bytes[i]=byte;
	}

	*check=IsCrc16Good(list_bytes);

	return ;
}




void Information_extraction(ap_uint<NB_BITS_DATA> bit_decoded_unstuffed,bool check,hls::stream<longitude_rad_t> &longitude_strm,hls::stream<latitude_rad_t> &latitude_strm,hls::stream<ap_uint<NB_BITS_DATA>> &data_out_strm,ap_uint<30> *user_id,bool flag)
{
	data_separated information;

	ap_uint<6> message_id_tmp=0;
	ap_uint<2> repeat_indicator_tmp=0;
	ap_uint<30> user_id_tmp=0;
	ap_uint<4> navigational_status_tmp=0;
	ap_int<8> rot_tmp=0;
	ap_uint<10> sog_tmp=0;
	ap_uint<1> position_accuracy_tmp=0;
	ap_uint<28> longitude_tmp=0;
	ap_uint<27> latitude_tmp=0;
	longitude_tmp_0_t longitude_tmp0=0;
	latitude_tmp_0_t latitude_tmp0=0;
	latitude_t latitude_tmp1;
	longitude_t longitude_tmp1;
	latitude_t latitude_tmp2;
	longitude_t longitude_tmp2;
	latitude_rad_t latitude_f;
	longitude_rad_t longitude_f;
	latitude_tmp_t latitude_tmp3;
	longitude_tmp_t longitude_tmp3;
	ap_uint<12> cog_tmp=0;
	ap_uint<9> true_heading_tmp=0;
	ap_uint<6> time_stamp_tmp=0;
	ap_uint<2> special_manoeuvre_indicator_tmp=0;
	ap_uint<3> spare_tmp=0;
	ap_uint<1> raim_flag_tmp=0;
	ap_uint<19> communication_stater_tmp=0;

	if (flag==0)
	{
		//	ship to far
		latitude_strm<<information.latitude;
		longitude_strm<<information.longitude;
		*user_id=0;
	}
	else if ((check==0) and (flag==1))
	{
		// CRC is not respected
		latitude_strm<<information.latitude;
		longitude_strm<<information.longitude;
		*user_id=0;
	}
	else
	{
		cout << "ELSE" << endl;
		for(ap_uint<8> i=0;i<6;i++)
		{
			message_id_tmp[6-1-i]=bit_decoded_unstuffed[NB_BITS_DATA-1-i];
		}
		information.message_id=message_id_tmp;

		for(ap_uint<8> i=6;i<8;i++)
		{
			repeat_indicator_tmp[8-1-i]=bit_decoded_unstuffed[NB_BITS_DATA-1-i];
		}

		information.repeat_indicator=repeat_indicator_tmp;

		for(ap_uint<8> i=8;i<38;i++)
		{
			user_id_tmp[38-1-i]=bit_decoded_unstuffed[NB_BITS_DATA-1-i];
		}
		information.user_id=user_id_tmp;

		for(ap_uint<8> i=38;i<42;i++)
		{
			navigational_status_tmp[42-1-i]=bit_decoded_unstuffed[NB_BITS_DATA-1-i];
		}
		information.navigational_status=navigational_status_tmp;

		for(ap_uint<8> i=42;i<50;i++)
		{
			rot_tmp[50-1-i]=bit_decoded_unstuffed[NB_BITS_DATA-1-i];
		}
		if(bit_decoded_unstuffed[NB_BITS_DATA-1-42]==1)
		{
			rot_tmp=(rot_tmp-1)^(0b11111111);
			rot_tmp=(-1)*rot_tmp;
		}
		information.rot=rot_tmp;


		for(ap_uint<8> i=60;i<61;i++)
		{
			position_accuracy_tmp[61-1-i]=bit_decoded_unstuffed[NB_BITS_DATA-1-i];

		}
		information.position_accuracy=position_accuracy_tmp;

		for(ap_uint<8> i=61;i<89;i++)
		{
			longitude_tmp[89-1-i]=bit_decoded_unstuffed[NB_BITS_DATA-1-i];
		}

//		il semble que pour le calul de la précision il faut seulement s'assurer que la valeur qui reçoie la valeur issus de la division possède une précision suffisante.
		if(bit_decoded_unstuffed[NB_BITS_DATA-1-61]==1)
		{
			longitude_tmp=(longitude_tmp-1)^(0b1111111111111111111111111111);
			longitude_tmp0=longitude_tmp;
			longitude_tmp1=longitude_tmp0/32;
			longitude_tmp2=longitude_tmp1;
			longitude_tmp3=longitude_tmp2/150;
			longitude_f=longitude_tmp3/125;
			longitude_f=(-1)*longitude_f;
		}
		else
		{
			longitude_tmp0=longitude_tmp;
			longitude_tmp1=longitude_tmp0/32;
			longitude_tmp2=longitude_tmp1;
			longitude_tmp3=longitude_tmp2/150;
			longitude_f=longitude_tmp3/125;
		}

		for(ap_uint<8> i=89;i<116;i++)
		{
			latitude_tmp[116-1-i]=bit_decoded_unstuffed[NB_BITS_DATA-1-i];
		}

		if(bit_decoded_unstuffed[NB_BITS_DATA-1-89]==1)
		{
			latitude_tmp=(latitude_tmp-1)^(0b111111111111111111111111111);
			latitude_tmp0=latitude_tmp;
			latitude_tmp1=latitude_tmp0/16;
			latitude_tmp3=latitude_tmp1/300;
			latitude_f=latitude_tmp3/125;
			latitude_f=(-1)*latitude_f;
		}
		else
		{
			latitude_tmp0=latitude_tmp;
			latitude_tmp1=latitude_tmp0/16;
//			cout.precision(32);
			latitude_tmp3=latitude_tmp1/300;
			latitude_f=latitude_tmp3/125;
		}

		for(ap_uint<8> i=128;i<137;i++)
		{
			true_heading_tmp[137-1-i]=bit_decoded_unstuffed[NB_BITS_DATA-1-i];
		}
		information.true_heading=true_heading_tmp;

		for(ap_uint<8> i=137;i<143;i++)
		{
			time_stamp_tmp[143-1-i]=bit_decoded_unstuffed[NB_BITS_DATA-1-i];
		}
		information.time_stamp=time_stamp_tmp;

		for(ap_uint<8> i=143;i<145;i++)
		{
			special_manoeuvre_indicator_tmp[145-1-i]=bit_decoded_unstuffed[NB_BITS_DATA-1-i];
		}
		information.special_manoeuvre_indicator=special_manoeuvre_indicator_tmp;

		for(ap_uint<8> i=145;i<148;i++)
		{
			spare_tmp[148-1-i]=bit_decoded_unstuffed[NB_BITS_DATA-1-i];
		}
		information.spare=spare_tmp;

		for(ap_uint<8> i=148;i<149;i++)
		{
			raim_flag_tmp[149-1-i]=bit_decoded_unstuffed[NB_BITS_DATA-1-i];
		}
		information.raim_flag=raim_flag_tmp;

		for(ap_uint<8> i=149;i<168;i++)
		{
			communication_stater_tmp[168-1-i]=bit_decoded_unstuffed[NB_BITS_DATA-1-i];
		}
		information.communication_stater=communication_stater_tmp;

		data_out_strm<<bit_decoded_unstuffed;
		latitude_strm<<latitude_f;
		longitude_strm<<longitude_f;
		*user_id=user_id_tmp;
	}
	return ;
}


void receiver(sin_cos_t I_strm[NB_EL_ARRAY],sin_cos_t Q_strm[NB_EL_ARRAY],hls::stream<longitude_rad_t> &longitude_strm,hls::stream<latitude_rad_t> &latitude_strm,hls::stream<ap_uint<NB_BITS_DATA>> &data_out_strm)
{
#pragma HLS DATAFLOW

	//	déclaration and initialisation variable
	ap_uint<NB_BITS_TRAME_MAX> bit_decode=0;
	ap_uint<NB_BITS_TRAME_MAX> bit_decoded=0;
	ap_uint<NB_BITS_TRAME_MAX> bit_decode_nrzi=0;
	ap_uint<9> idx=0;
	ap_uint<NB_BITS_DATA_CRC> bit_decoded_unstuffed=0;
	data_crc data_crc;
	ap_uint<16> crc_1=0;
	ap_uint<16> crc=0;
	ap_uint<NB_BITS_DATA> bit_decode_flipped=0;
	ap_uint<16> remainder=0;
	data_separated data_separated;
	ap_uint<30> user_id;
	ap_uint<8> idx_start_signal=0;
	bool flag;
	bool check;
	change_dyn_t change_dyn_tmp;

	sin_cos_t I_0[NB_EL_ARRAY];
	sin_cos_t Q_0[NB_EL_ARRAY];
	sin_cos_t I_1[NB_EL_ARRAY];
	sin_cos_t Q_1[NB_EL_ARRAY];
	sin_cos_t I_2[NB_EL_ARRAY];
	sin_cos_t Q_2[NB_EL_ARRAY];
	sin_cos_t I_3[NB_EL_ARRAY];
	sin_cos_t Q_3[NB_EL_ARRAY];

	change_dynamic(I_strm,Q_strm,I_0,Q_0,&flag);

	DAC(I_0,Q_0,I_1,Q_1);

	GMSK_demodulation(I_1,Q_1,&bit_decode);

	NRZI_decoding(bit_decode,&bit_decode_nrzi);

	Bits_unstuffing(bit_decode_nrzi,&bit_decoded_unstuffed);

	CRC_check(bit_decoded_unstuffed,&check);

	Bytes_flipping_r(bit_decoded_unstuffed,&bit_decode_flipped,check);

	Information_extraction(bit_decode_flipped,check,longitude_strm,latitude_strm,data_out_strm,&user_id,flag);
}

