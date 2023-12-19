#include "FPGA_simulator.h"


void FPGA_simulator(hls::stream<snr_t> &snr_strm,hls::stream<int> &f_shift_strm,hls::stream<dynamic_information_init> &dynamic_information_init_strm,hls::stream<falsification_information> &falsification_information_strm,hls::stream<static_information> &static_information_strm,hls::stream<bool> &start_e,hls::stream<data_t> &data_obs_strm,hls::stream<sin_cos_t> &I_obs_strm_e,hls::stream<sin_cos_t> &Q_obs_strm_e,hls::stream<sin_cos_t> &I_obs_strm_c,hls::stream<sin_cos_t> &Q_obs_strm_c,hls::stream<longitude_rad_t> &longitude_strm_out,hls::stream<latitude_rad_t> &latitude_strm_out,hls::stream<ap_uint<NB_BITS_DATA>> &data_out_strm)
{

#pragma HLS INTERFACE axis port=dynamic_information_init_strm
#pragma HLS INTERFACE axis port=falsification_information_strm
#pragma HLS INTERFACE axis port=static_information_strm
#pragma HLS INTERFACE axis port=start_e
#pragma HLS INTERFACE axis port=data_obs_strm
#pragma HLS INTERFACE axis port=snr_strm
#pragma HLS INTERFACE axis port=f_shift_strm
#pragma HLS INTERFACE axis port=I_obs_strm_e
#pragma HLS INTERFACE axis port=Q_obs_strm_e
#pragma HLS INTERFACE axis port=I_obs_strm_c
#pragma HLS INTERFACE axis port=Q_obs_strm_c
#pragma HLS INTERFACE axis port=longitude_strm_out
#pragma HLS INTERFACE axis port=latitude_strm_out
#pragma HLS INTERFACE axis port=data_out_strm

#pragma HLS dataflow

	hls::stream<data_t> data_strm_1("data_strm_1");
	hls::stream<bool> start_e_cps("start_e_cps");
	hls::stream<snr_t> snr_strm_1("snr_strm_1");
	hls::stream<int> f_shift_strm_1("f_shift_strm_1");

	piloting(snr_strm,f_shift_strm,dynamic_information_init_strm,falsification_information_strm,static_information_strm,data_strm_1,start_e,start_e_cps,data_obs_strm,snr_strm_1,f_shift_strm_1);
	CPS(start_e_cps,data_strm_1,snr_strm_1,f_shift_strm_1,I_obs_strm_e,Q_obs_strm_e,I_obs_strm_c,Q_obs_strm_c,longitude_strm_out,latitude_strm_out,data_out_strm);

}
