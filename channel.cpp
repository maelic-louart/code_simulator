#include "FPGA_simulator.h"

void Shift_frequency(sin_cos_t I_in[NB_EL_ARRAY],sin_cos_t Q_in[NB_EL_ARRAY],sin_cos_t I_in1[NB_EL_ARRAY],sin_cos_t Q_in1[NB_EL_ARRAY],hls::stream<int> &idx_f_shift)
{
	phase_shift_t angle_shift;
	int idx_f_shift_tmp=idx_f_shift.read();
	phase_shift_t angle_shift_ech=idx_f_shift_tmp*ANGLE_FREQ;
	sin_cos_t tmp_I;
	sin_cos_t tmp_Q;
	int n;
	phase_shift_t const_angle=CONST_ANGLE;

	for (int i=0;i<NB_EL_ARRAY;i++)
	{
	#pragma HLS PIPELINE
		tmp_I=I_in[i];
		tmp_Q=Q_in[i];
		angle_shift=angle_shift_ech*i;
		n=angle_shift*const_angle;
		n%=256;
		if(n<0)
		{
			n+=256;
		}

		sin_cos_t I = cos_lookup(n) * tmp_I - sin_lookup(n) * tmp_Q;
		sin_cos_t Q= cos_lookup(n) * tmp_Q + sin_lookup(n) * tmp_I;

		I_in1[i]=I;
		Q_in1[i]=Q;
	}
}

//void Delay_adding(sin_cos_t I_in[NB_EL_ARRAY],sin_cos_t Q_in[NB_EL_ARRAY],sin_cos_t I_out[NB_EL_ARRAY],sin_cos_t Q_out[NB_EL_ARRAY])
//{
//	for (ap_uint<13>i=0;i<DELAY_NB_EL;i++)
//	{
//		I_out[i]=0;
//		Q_out[i]=0;
//	}
//	for (ap_uint<13> i=DELAY_NB_EL;i<NB_EL_ARRAY;i++)
//	{
//		sin_cos_t I_in_tmp=I_in[i-DELAY_NB_EL];
//		sin_cos_t Q_in_tmp=Q_in[i-DELAY_NB_EL];
//		I_out[i]=I_in_tmp;
//		Q_out[i]=Q_in_tmp;
//	}
//	for (ap_uint<13>i=NB_EL_ARRAY-DELAY_NB_EL;i<NB_EL_ARRAY;i++)
//	{
//		sin_cos_t I_in_tmp=I_in[i];
//		sin_cos_t Q_in_tmp=Q_in[i];
//	}
//}


void Noise_adding(sin_cos_t I_in[NB_EL_ARRAY],sin_cos_t Q_in[NB_EL_ARRAY],sin_cos_t I_out[NB_EL_ARRAY],sin_cos_t Q_out[NB_EL_ARRAY],hls::stream<sin_cos_t> &I_out_obs,hls::stream<sin_cos_t> &Q_out_obs,hls::stream<snr_t> &snr_tmp,sin_cos_t fading_ampl)
{
	sin_cos_t I_in_tmp;
	sin_cos_t Q_in_tmp;
	sin_cos_t I_in_tmp_1;
	sin_cos_t Q_in_tmp_1;
	sin_cos_t rand_tmp_I;
	sin_cos_t rand_tmp_Q;
	static ap_uint<10> k_I;
	static ap_uint<10> k_Q;
	//	SNR maximum value is 1000
	snr_t c_SNR_tmp = snr_tmp.read();
	//	The function isqrt takes only int values
	int c_SNR_tmp1=c_SNR_tmp<<14;
	snr_t c_SNR_tmp2=isqrt(c_SNR_tmp1);
	snr_t1 c_SNR_tmp3=c_SNR_tmp2>>7;
	//	We consider the fading amplitude value to change the noise amplitude
	sin_cos_t c_SNR_tmp4=fading_ampl/c_SNR_tmp3;
	for (ap_uint<13> i=0;i<NB_EL_ARRAY;i++)
	{
		I_in_tmp=I_in[i];
		Q_in_tmp=Q_in[i];
		rand_tmp_I=rand_gaussian_12_5[k_I]*c_SNR_tmp4;
		rand_tmp_Q=rand_gaussian_12_5[k_Q]*c_SNR_tmp4;
		I_in_tmp_1=I_in_tmp+rand_tmp_I;
		Q_in_tmp_1=Q_in_tmp+rand_tmp_Q;
		I_out[i]=I_in_tmp_1;
		Q_out[i]=Q_in_tmp_1;
		I_out_obs<<I_in_tmp_1;
		Q_out_obs<<Q_in_tmp_1;
		k_I=k_I+1;
		k_Q=k_Q+1;
	}
}

//computation of the sqrt of integer. The function was taken on the internet
int32_t isqrt(int32_t num) {
	int32_t res = 0;
	int32_t bit = 1 << 30; // The second-to-top bit is set.

	// "bit" starts at the highest power of four <= the argument.
	for (ap_uint<5> i=31;i>=1;i--)
	{
		if (bit > num)
			bit >>= 2;
	}
	for (ap_uint<5> i=31;i>=1;i--)
	{
		if (bit != 0)
		{
			if (num >= res + bit) {
				num -= res + bit;
				res = (res >> 1) + bit;
			} else
				res >>= 1;
			bit >>= 2;
		}
	}
	return res;
}


int compute_distance(ap_uint<27> latitude_tmp,ap_uint<28> longitude_tmp)
{

	ap_uint<27> latitude_tmp1;
	ap_uint<28> longitude_tmp1;
	latitude_t latitude_tmp2;
	longitude_t longitude_tmp2;
	latitude_tmp_t latitude_tmp3;
	longitude_tmp_t longitude_tmp3;
	latitude_rad_t latitude_f;
	longitude_rad_t longitude_f;
	phase_t latitude_recepteur_f = LATITUDE_RE_RAD;
	phase_t longitude_recepteur_f = LONGITUDE_RE_RAD;
	phase_t diff_lon;
	phase_t diff_lat;

	phase_t two_pi=TWO_PI;
	phase_t deg_to_rad_tmp=DEG_TO_RAD;

	if(latitude_tmp[26]==1)
	{
		latitude_tmp1=(latitude_tmp-1)^(0b111111111111111111111111111);
		//We divide by 600000=9375*2^6. This division is divided by sequencial division the respect variable dynamic
		latitude_tmp2=latitude_tmp1>>6;
		latitude_tmp3=latitude_tmp2/75;
		latitude_f=latitude_tmp3/125;
		latitude_f=(-1)*latitude_f;
		latitude_f=latitude_f*deg_to_rad_tmp;
		//We add 360 to the latitude to have a value comprised between 0 and 360 used by cos_lookup table
		latitude_f=latitude_f+two_pi;
	}
	else
	{
		latitude_tmp1=latitude_tmp>>6;
		latitude_tmp2=latitude_tmp1;
		latitude_tmp3=latitude_tmp2/75;
		latitude_f=latitude_tmp3/125;
		latitude_f=latitude_f*deg_to_rad_tmp;
	}

	if(longitude_tmp[27]==1)
	{
		longitude_tmp1=(longitude_tmp-1)^(0b1111111111111111111111111111);
		longitude_tmp2=longitude_tmp1>>6;
		longitude_tmp3=longitude_tmp2/75;
		longitude_f=longitude_tmp3/125;
		longitude_f=(-1)*longitude_f;
		longitude_f=longitude_f*deg_to_rad_tmp;
	}
	else
	{
		longitude_tmp1=longitude_tmp>>6;
		longitude_tmp2=longitude_tmp1;
		longitude_tmp3=longitude_tmp2/75;
		longitude_f=longitude_tmp3/125;
		longitude_f=longitude_f*deg_to_rad_tmp;
	}

	diff_lat=latitude_f-latitude_recepteur_f;
	if (diff_lat<0)
		diff_lat = -diff_lat;
	diff_lon=longitude_f-longitude_recepteur_f;
	if (diff_lon<0)
		diff_lon = -diff_lon;

	phase_t const_angle=CONST_ANGLE;
	int n=latitude_f*const_angle;
	sin_cos_t cos_lat=cos_lookup(n);

	distance_t distance_lat=RADIUS_PO*diff_lat;
	distance_lat=10000;
	// if distance is higher than 60000 so signal could not be received by the receiver, the distance is fixed to 100000 to attenuate the signal sufficiently and make it considered as noise
	if(distance_lat>60000)
	{
		int distance=100000;
		return distance;
	}
	distance_lat=distance_lat>>5;

	distance_t distance_lon=RADIUS_EQ*diff_lon*cos_lat;
	distance_lon=10000;
	// if distance is higher than 60000 so signal could not be received by the receiver, the distance is fixed to 100000 to attenuate the signal sufficiently and make it considered as noise
	if(distance_lon>60000)
	{
		int distance=100000;
		return distance;
	}
	distance_lon=distance_lon>>5;

	int distance_square=distance_lat*distance_lat+distance_lon*distance_lon;
	distance_t distance=isqrt(distance_square);
	distance=distance<<5;

	//	We prevent to have a value comprised between 0 and 1
	if((0<=distance) and (distance<1))
	{
		distance=1;
	}

	return distance;
}

void sum(sin_cos_t I_in_1[NB_EL_ARRAY],sin_cos_t Q_in_1[NB_EL_ARRAY],sin_cos_t I_in_2[NB_EL_ARRAY],sin_cos_t Q_in_2[NB_EL_ARRAY],sin_cos_t I_out[NB_EL_ARRAY],sin_cos_t Q_out[NB_EL_ARRAY])
{
	sin_cos_t tmp_I_1;
	sin_cos_t tmp_Q_1;
	sin_cos_t tmp_I_2;
	sin_cos_t tmp_Q_2;
	sin_cos_t tmp_sum_I;
	sin_cos_t tmp_sum_Q;
	for(ap_uint<13> i=0;i<NB_EL_ARRAY;i++)
	{
		tmp_I_1=I_in_1[i];
		tmp_Q_1=Q_in_1[i];
		tmp_I_2=I_in_2[i];
		tmp_Q_2=Q_in_2[i];
		tmp_sum_I=tmp_I_1+tmp_I_2;
		tmp_sum_Q=tmp_Q_1+tmp_Q_2;
		I_out[i]=tmp_sum_I;
		Q_out[i]=tmp_sum_Q;
	}
}


void Fading(sin_cos_t I_in[NB_EL_ARRAY],sin_cos_t Q_in[NB_EL_ARRAY],ap_uint<27> latitude_strm,ap_uint<28> longitude_strm,sin_cos_t I_out[NB_EL_ARRAY],sin_cos_t Q_out[NB_EL_ARRAY],sin_cos_t *fading_ampl)
{
	ap_uint<27> latitude_tmp;
	ap_uint<28> longitude_tmp;
	latitude_tmp=latitude_strm;
	longitude_tmp=longitude_strm;

	int distance=compute_distance(latitude_tmp,longitude_tmp);

	//	the friitz formule is applied to determine the const_ampl. The explanation of the constante computation is present is CPS.h
	sin_cos_t const_ampl=CONST_AMPL;
	sin_cos_t fading_ampl_tmp=const_ampl/distance;
	sin_cos_t I_in_tmp;
	sin_cos_t Q_in_tmp;
	for (ap_uint<13> i=0;i<NB_EL_ARRAY;i++)
	{
		I_in_tmp=I_in[i];
		Q_in_tmp=Q_in[i];
		I_out[i]=I_in_tmp*fading_ampl_tmp;
		Q_out[i]=Q_in_tmp*fading_ampl_tmp;
	}
	*fading_ampl=fading_ampl_tmp;
}


void channel(sin_cos_t I_in[NB_EL_ARRAY],sin_cos_t Q_in[NB_EL_ARRAY],sin_cos_t I_out[NB_EL_ARRAY],sin_cos_t Q_out[NB_EL_ARRAY],hls::stream<sin_cos_t> &I_out_obs,hls::stream<sin_cos_t> &Q_out_obs,ap_uint<27> latitude_strm,ap_uint<28> longitude_strm,hls::stream<snr_t> &snr_strm,hls::stream<int> &f_shift_strm)
{

#pragma HLS DATAFLOW

	sin_cos_t I_in1[NB_EL_ARRAY];
	sin_cos_t Q_in1[NB_EL_ARRAY];
	sin_cos_t I_1[NB_EL_ARRAY];
#pragma HLS STREAM variable=I_1 depth=3
	sin_cos_t Q_1[NB_EL_ARRAY];
#pragma HLS STREAM variable=Q_1 depth=3
	sin_cos_t I_21[NB_EL_ARRAY];
	sin_cos_t Q_21[NB_EL_ARRAY];
	sin_cos_t I_22[NB_EL_ARRAY]={0};
	sin_cos_t Q_22[NB_EL_ARRAY]={0};
	sin_cos_t I_3[NB_EL_ARRAY];
	sin_cos_t Q_3[NB_EL_ARRAY];
	sin_cos_t fading_ampl=0;

	Shift_frequency(I_in,Q_in,I_1,Q_1,f_shift_strm);
//	Delay_adding(I_in1,Q_in1,I_1,Q_1);

	Fading(I_1,Q_1,latitude_strm,longitude_strm,I_21,Q_21,&fading_ampl);

	sum(I_21,Q_21,I_22,Q_22,I_3,Q_3);

	Noise_adding(I_3,Q_3,I_out,Q_out,I_out_obs,Q_out_obs,snr_strm,fading_ampl);

}


