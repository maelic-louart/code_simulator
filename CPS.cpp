#include "FPGA_simulator.h"

void CPS(hls::stream<bool> &start_emission,hls::stream<data_t> &data_strm,hls::stream<snr_t> &snr_strm,hls::stream<int> &f_shift_strm,hls::stream<sin_cos_t> &I_obs_strm_e,hls::stream<sin_cos_t> &Q_obs_strm_e,hls::stream<sin_cos_t> &I_obs_strm_c,hls::stream<sin_cos_t> &Q_obs_strm_c,hls::stream<longitude_rad_t> &longitude_strm_out,hls::stream<latitude_rad_t> &latitude_strm_out,hls::stream<ap_uint<NB_BITS_DATA>> &data_out_strm)
{

#pragma HLS dataflow

	//	variables declarations
	sin_cos_t I_strm[NB_EL_ARRAY];
	sin_cos_t Q_strm[NB_EL_ARRAY];
	sin_cos_t I_strm_1[NB_EL_ARRAY];
	sin_cos_t Q_strm_1[NB_EL_ARRAY];
	ap_uint<27> latitude_strm;
	ap_uint<28> longitude_strm;

	emitter(start_emission,data_strm,I_strm,Q_strm,I_obs_strm_e,Q_obs_strm_e,&latitude_strm,&longitude_strm);

	channel(I_strm,Q_strm,I_strm_1,Q_strm_1,I_obs_strm_c,Q_obs_strm_c,latitude_strm,longitude_strm,snr_strm,f_shift_strm);

	receiver(I_strm_1,Q_strm_1,longitude_strm_out,latitude_strm_out,data_out_strm);

}


























