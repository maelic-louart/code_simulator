#include "FPGA_simulator.h"

void Read_data(hls::stream<data_t> &data_strm,ap_uint<27> *latitude_strm,ap_uint<28> *longitude_strm,message_data *mes_out)
{
	message_data mes_t;
	ap_uint<28> longitude_tmp;
	ap_uint<27> latitude_tmp;
	ap_uint<30> user_id_tmp;
	data_t data;
	data=data_strm.read();

	for(ap_uint<8> i=8;i<38;i++)
	{
		user_id_tmp[38-1-i]=data[NB_BITS_DATA-1-i];
	}

	for(ap_uint<8> i=61;i<89;i++)
	{
		longitude_tmp[89-1-i]=data[NB_BITS_DATA-1-i];
	}

	for(ap_uint<8> i=89;i<116;i++)
	{
		latitude_tmp[116-1-i]=data[NB_BITS_DATA-1-i];
	}

	mes_t.data=data;
	mes_t.longitude=longitude_tmp;
	*longitude_strm=longitude_tmp;
	mes_t.latitude=latitude_tmp;
	*latitude_strm=latitude_tmp;
	mes_t.user_id=user_id_tmp;
	*mes_out=mes_t;
	return ;
}


void Bytes_flipping(message_data trame,ap_uint<NB_BITS_DATA> *data_flipped_out)
{
	data_t data=trame.data;
	ap_uint<NB_BITS_DATA> data_flipped=0;

//	168 bits per AIS messages
	for (int i=0;i<NB_BYTES_DATA;i++)
	{
		data_flipped[8*i+7]=data[8*i];
		data_flipped[8*i+6]=data[8*i+1];
		data_flipped[8*i+5]=data[8*i+2];
		data_flipped[8*i+4]=data[8*i+3];
		data_flipped[8*i+3]=data[8*i+4];
		data_flipped[8*i+2]=data[8*i+5];
		data_flipped[8*i+1]=data[8*i+6];
		data_flipped[8*i]=data[8*i+7];
	}
	*data_flipped_out=data_flipped;
	return ;
}

ap_uint<16> GetCrc16(ap_uint<8> pData[21])
{
	ap_uint<16> fcs = 0xffff; // Initialize
	int nLength=21;
	for(int i=0;i<nLength;i++)
	{
		fcs = (fcs >> 8) ^ crctab16[(fcs ^ pData[i]) & 0xff];
	}
	return ~fcs; // Negate
}

void Compute_CRC(ap_uint<NB_BITS_DATA> data,ap_uint<16> *crc)
{
	ap_uint<8> list_bytes[NB_BYTES_DATA];
	ap_uint<8> byte;
	ap_uint<NB_BITS_DATA> data_reversed;
	//	The data to compute the crc have to be reversed as the crc

	for(ap_uint<9> i=0;i<NB_BITS_DATA;i++)
	{
		data_reversed[i]=data[NB_BITS_DATA-1-i];
	}
	for(ap_uint<8> i =0;i<NB_BYTES_DATA;i++)
	{
		byte=1*data_reversed[0+i*8]+2*data_reversed[1+i*8]+4*data_reversed[2+i*8]+8*data_reversed[3+i*8]+16*data_reversed[4+i*8]+32*data_reversed[5+i*8]+64*data_reversed[6+i*8]+128*data_reversed[7+i*8];
		list_bytes[i]=byte;
	}
	ap_uint<16> crc_tmp=GetCrc16(list_bytes);
	ap_uint<16> crc_tmp_reversed=0;
	for(ap_uint<5> i=0;i<16;i++)
	{
		crc_tmp_reversed[i]=crc_tmp[16-1-i];
	}
	for(ap_uint<5> i=0;i<2;i++)
	{
		byte=1*crc_tmp_reversed[0+i*8]+2*crc_tmp_reversed[1+i*8]+4*crc_tmp_reversed[2+i*8]+8*crc_tmp_reversed[3+i*8]+16*crc_tmp_reversed[4+i*8]+32*crc_tmp_reversed[5+i*8]+64*crc_tmp_reversed[6+i*8]+128*crc_tmp_reversed[7+i*8];
		list_bytes[i]=byte;
	}
	*crc=crc_tmp_reversed;
}

void Bits_stuffing(ap_uint<NB_BITS_DATA> data,ap_uint<16> crc,message_data_crc *trame_out)
{
	message_data_crc trame;
	int compter=0;
	//	Considering the standard, at the higher value of the bit stuffing is equal to 5 for data or 3 for crc.
	ap_uint<NB_BITS_DATA+10> new_data=0;
	ap_uint<NB_BITS_CRC+3> new_crc=0;
	ap_uint<NB_BITS_CRC+3> new_crc_reversed=0;
	int j=NB_BITS_DATA+10-1;
	ap_uint<8> bits_stuffed_data=0;
	ap_uint<8> bits_stuffed_crc=0;


	for (int i=NB_BITS_DATA-1;i>-1;i--)
	{
		if (data[i]==1)
		{
			compter=compter+1;
		}
		else
		{
			compter=0;
		}
		new_data[j]=data[i];
		j--;
		if (compter==5)
		{
			new_data[j]=0;
			bits_stuffed_data++;
			j--;
			compter=0;
		}
	}

	ap_uint<8> div_data=10-bits_stuffed_data;
	new_data=new_data>>div_data;
	trame.data.data=new_data;
	trame.data.nb_bits=NB_BITS_DATA+bits_stuffed_data;
	int k=NB_BITS_CRC+3-1;

	for (int i=NB_BITS_CRC-1;i>-1;i--)
	{
		if (crc[i]==1)
		{
			compter=compter+1;
		}
		else
		{
			compter=0;
		}
		new_crc[k]=crc[i];
		k--;
		if (compter==5)
		{
			new_crc[k]=0;
			bits_stuffed_crc++;
			k--;
			compter=0;
		}
	}

	ap_uint<8> div_crc=(3-bits_stuffed_crc);
	new_crc=new_crc>>div_crc;
	for (ap_uint<8> i=0;i<NB_BITS_CRC+3;i++)
	{
		new_crc_reversed[i]=new_crc[NB_BITS_CRC+2-i];
	}

	trame.crc.data=new_crc;
	trame.crc.nb_bits=NB_BITS_CRC+bits_stuffed_crc;

	*trame_out=trame;

	return;
}

void HDLC_trame_construction(message_data_crc mes,message_hdlc *mes_hdlc_out)
{
	message_hdlc mes_hdlc;
	mes_hdlc.crc=mes.crc;
	mes_hdlc.data=mes.data;
	*mes_hdlc_out=mes_hdlc;
	return ;
}

void Trainning_sequence_adding(message_hdlc mes,message_trame *mes_trame_out)
{
	message_trame mes_trame;
	mes_trame.hdlc=mes;
	*mes_trame_out=mes_trame;
	return;
}

void NRZI_coding(message_trame trame,message_nrzi *trame_hdlc_nrzi_out)
{
	ap_uint<8> nb_bits_data=trame.hdlc.data.nb_bits;
	ap_uint<8> nb_bits_crc=trame.hdlc.crc.nb_bits;
	ap_uint<NB_BITS_DATA+10> new_data=0;
	ap_uint<1> last_bit=0;

	for (ap_int<9> i=NB_BITS_DATA+10-1;i>NB_BITS_DATA-1;i--)
	{
		if(i<nb_bits_data)
		{
			if(trame.hdlc.data.data[i]==1)
			{
				if(last_bit==1)
				{
					new_data[i]=1;
					last_bit=1;
				}
				else
				{
					new_data[i]=0;
					last_bit=0;
				}
			}
			else
			{
				if (last_bit==1)
				{
					new_data[i]=0;
					last_bit=0;
				}
				else
				{
					new_data[i]=1;
					last_bit=1;
				}
			}
		}
	}
	for (ap_int<9> i=NB_BITS_DATA-1;i>-1;i--)
	{
		if(trame.hdlc.data.data[i]==1)
		{
			if(last_bit==1)
			{
				new_data[i]=1;
				last_bit=1;
			}
			else
			{
				new_data[i]=0;
				last_bit=0;
			}
		}
		else
		{
			if (last_bit==1)
			{
				new_data[i]=0;
				last_bit=0;
			}
			else
			{
				new_data[i]=1;
				last_bit=1;
			}
		}
	}

	ap_uint<NB_BITS_CRC+3> new_crc=0;
	for (ap_int<6> i=NB_BITS_CRC+3-1;i>NB_BITS_CRC-1;i--)
	{
		if (i<nb_bits_crc)
		{
			if(trame.hdlc.crc.data[i]==1)
			{
				if(last_bit==1)
				{
					new_crc[i]=1;
					last_bit=1;
				}
				else
				{
					new_crc[i]=0;
					last_bit=0;
				}
			}
			else
			{
				if (last_bit==1)
				{
					new_crc[i]=0;
					last_bit=0;
				}
				else
				{
					new_crc[i]=1;
					last_bit=1;
				}
			}
		}
	}
	for (ap_int<6> i=NB_BITS_CRC-1;i>-1;i--)
	{

		if(trame.hdlc.crc.data[i]==1)
		{
			if(last_bit==1)
			{
				new_crc[i]=1;
				last_bit=1;
			}
			else
			{
				new_crc[i]=0;
				last_bit=0;
			}
		}
		else
		{
			if (last_bit==1)
			{
				new_crc[i]=0;
				last_bit=0;
			}
			else
			{
				new_crc[i]=1;
				last_bit=1;
			}
		}
	}

	struct message_nrzi trame_hdlc_nrzi;
	trame_hdlc_nrzi.data.data=new_data;
	trame_hdlc_nrzi.data.nb_bits=nb_bits_data;
	trame_hdlc_nrzi.crc.data=new_crc;
	trame_hdlc_nrzi.crc.nb_bits=nb_bits_crc;

	if(last_bit==0)
	{
		trame_hdlc_nrzi.end_flag=0b11111110;
	}
	else
	{
		trame_hdlc_nrzi.end_flag=0b11111110;
	}
	*trame_hdlc_nrzi_out=trame_hdlc_nrzi;
	return ;
}


void modulation_gmsk_body(ap_uint<NB_BITS_TRAME> trame_bits,phase_t in_phase[NB_EL_ARRAY],ap_uint<8> nb_bits)
{
	ap_uint<8> idx_bit=0;
	phase_t tmp_phase[4*NB_SAMPLES_ECH];
	for(int i=0;i<4*NB_SAMPLES_ECH;i++)
	{
		tmp_phase[i]=0;
	}

	//  We take into consideration the bits added, there are 5+3 bits
	//	The bits are inverted to have the lsb at left.
	for (ap_int<9> i=NB_BITS_TRAME-1;i>-1;i--)
	{
		if(i<nb_bits)
		{
			phase_t last_ech=tmp_phase[4*NB_SAMPLES_ECH-1];
			for(int j = 0; j < 4*NB_SAMPLES_ECH; j++)
			{
				if(j<(3*NB_SAMPLES_ECH ) )
				{
					tmp_phase[j]=tmp_phase[j+NB_SAMPLES_ECH];
				}
				else
				{
					tmp_phase[j]=last_ech;
				}
			}
			if (trame_bits[i]==0)
			{
				for(ap_uint<8> j =0;j<4*NB_SAMPLES_ECH;j++)
				{
					tmp_phase[j]-=G[j];
				}
			}
			else
			{
				for(ap_uint<8> j =0;j<4*NB_SAMPLES_ECH;j++)
				{
					tmp_phase[j]+=G[j];
				}
			}
				for(ap_uint<8> j =0;j<NB_SAMPLES_ECH;j++)
				{
					in_phase[idx_bit*NB_SAMPLES_ECH+j]=tmp_phase[j];
				}
			idx_bit++;
		}
	}
}


void GMSK_modulation(message_nrzi trame,phase_t in_phase[NB_EL_ARRAY])
{

	ap_uint<8> nb_bits=trame.data.nb_bits+trame.crc.nb_bits+24+8+8; // conditionning sequence + start flag + end flag
	phase_t tmp_phase[4*NB_SAMPLES_ECH];

	//	training sequence plus start flag
	ap_uint<NB_BITS_TRAME> trame_bits=0b11001100110011001100110011111110;

	trame_bits=trame_bits<<trame.data.nb_bits;
	trame_bits=trame_bits+trame.data.data;
	trame_bits=trame_bits<<trame.crc.nb_bits;
	trame_bits=trame_bits+trame.crc.data;

	//	nous rajoutons la valeur du tableau end_flag
	trame_bits=trame_bits<<8;
	trame_bits=trame_bits+trame.end_flag;

	for (ap_uint<13> i=NB_EL_TRAME;i<NB_EL_ARRAY;i++)
	{
		in_phase[i]=0;
	}

	modulation_gmsk_body(trame_bits,in_phase,nb_bits);

}


void I_Q_coding(phase_t in_phase[NB_EL_ARRAY],sin_cos_t I[NB_EL_ARRAY],sin_cos_t Q[NB_EL_ARRAY])
{
	//	table size is (256*NB_SAMPLES_ECH).
	for (ap_uint<13> i=0;i<NB_EL_ARRAY;i++)
	{
		phase_t const_angle=CONST_ANGLE;

		int n=in_phase[i]*const_angle;
		n%=256;
		if(n<0)
		{
			n+=256;
		}
		I[i]=cos_lookup(n);
		Q[i]=sin_lookup(n);
	}
}



void amplifier(sin_cos_t I_in[NB_EL_ARRAY],sin_cos_t Q_in[NB_EL_ARRAY],sin_cos_t I_out[NB_EL_ARRAY],sin_cos_t Q_out[NB_EL_ARRAY],hls::stream<sin_cos_t> &I_out_obs,hls::stream<sin_cos_t> &Q_out_obs,bool flag_emission)
{
	sin_cos_t ampli=A_AMPLI;

	if(flag_emission==1)
	{
		// Our emitter will emit a signal with a power equal to 12.5 W
		for(int i=0;i<NB_EL_ARRAY;i++)
		{
			sin_cos_t tmp_I=I_in[i];
			sin_cos_t tmp_Q=Q_in[i];
			tmp_I=tmp_I*ampli;
			tmp_Q=tmp_Q*ampli;
			I_out[i]=tmp_I;
			Q_out[i]=tmp_Q;
			I_out_obs<<tmp_I;
			Q_out_obs<<tmp_Q;
		}
	}
	else
		for(int i=0;i<NB_EL_ARRAY;i++)
		{
			I_out[i]=0;
			Q_out[i]=0;
			I_out_obs<<0;
			Q_out_obs<<0;
		}
}

void emitter(hls::stream<bool> &start_emission,hls::stream<data_t> &data_strm,sin_cos_t I_strm[NB_EL_ARRAY],sin_cos_t Q_strm[NB_EL_ARRAY],hls::stream<sin_cos_t> &I_obs_strm,hls::stream<sin_cos_t> &Q_obs_strm,ap_uint<27> *latitude_strm,ap_uint<28> *longitude_strm)
{
#pragma HLS DATAFLOW

	message_data mes;
	ap_uint<16> crc;
	ap_uint<NB_BITS_DATA> data;
	data_t data_f;
	message_data_crc mes_data_crc;
	message_hdlc mes_hdlc;
	message_trame mes_trame;
	message_nrzi mes_hdlc_nrzi;
	phase_t in_phase[NB_EL_ARRAY];
	ap_uint<28> longitude_tmp;
	ap_uint<27> latitude_tmp;
	sin_cos_t I_in[NB_EL_ARRAY];
	sin_cos_t Q_in[NB_EL_ARRAY];
	sin_cos_t I_in1[NB_EL_ARRAY];
	sin_cos_t Q_in1[NB_EL_ARRAY];
	hls::stream<sin_cos_t> I_strm_tmp1;
	hls::stream<sin_cos_t> Q_strm_tmp1;
	ap_uint<27> latitude_cyb=0;
	ap_uint<28> longitude_cyb=0;
	ap_uint<12> cog=0;
	ap_uint<10> sog=0;
	bool start=start_emission.read();

	Read_data(data_strm,latitude_strm,longitude_strm,&mes);
	Bytes_flipping(mes,&data);
	Compute_CRC(data,&crc);
	Bits_stuffing(data,crc,&mes_data_crc);
	HDLC_trame_construction(mes_data_crc,&mes_hdlc);
	Trainning_sequence_adding(mes_hdlc,&mes_trame);
	NRZI_coding(mes_trame,&mes_hdlc_nrzi);
	GMSK_modulation(mes_hdlc_nrzi,in_phase);
	I_Q_coding(in_phase,I_in,Q_in);
	amplifier(I_in,Q_in,I_strm,Q_strm,I_obs_strm,Q_obs_strm,start);

}
