#include "FPGA_simulator.h"


sin_cos_t sin_lookup (int n){

	int idx=0;
	bool sign=0;
	if (n == DATA_SIZE){
		idx = 0;
		sign =0;
	}
	else if (n>=0 && n<=DATA_SIZE/4){
		idx = n;
		sign =0;
	}
	else if (n>=DATA_SIZE/4 && n<DATA_SIZE/2)
	{
		idx = DATA_SIZE/4-n%(DATA_SIZE/4);
		sign = 0;
	}
	else if (n>=DATA_SIZE/2 && n<3* DATA_SIZE/4)
	{
		idx = n%(DATA_SIZE/4);
		sign =1;
	}
	else
	{
		idx = DATA_SIZE/4-n%(DATA_SIZE/4);
		sign =1;
	}
	if (sign)
	{
		return(-sin_table[idx]);
	}
	else
	{
		return(sin_table[idx]);
	}
}


sin_cos_t cos_lookup (int n){

	int idx=0;
	bool sign=0;
	if (n == DATA_SIZE){
		idx = 0;
		sign =0;
	}
	else if (n>=0 && n<=DATA_SIZE/4){
		idx = n;
		sign =0;
	}
	else if (n>=DATA_SIZE/4 && n<DATA_SIZE/2) {
		idx = DATA_SIZE/4-n%(DATA_SIZE/4);
		sign = 1;
	}
	else if (n>=DATA_SIZE/2 && n<3* DATA_SIZE/4){
		idx = n%(DATA_SIZE/4);
		sign =1;
	}
	else{
		idx = DATA_SIZE/4-n%(DATA_SIZE/4);
		sign =0;
	}
	if (sign)
	{
		return(-cos_table[idx]);
	}
	else
	{
		return(cos_table[idx]);
	}
}


//dynamic data generation from sog, cog, latitude and longitude first values.
void dynamic_data_generation_e_p_c(bool flag_emission,hls::stream<dynamic_information> &dynamic_information_strm,hls::stream<dynamic_information_init> &dynamic_information_init_strm,hls::stream<falsification_information> &falsification_information_strm)
{

	static ap_uint<8> sog_noise_indice=0;
	static ap_uint<8> cog_noise_indice=0;
	static ap_uint<8> TS_noise_indice=0;
	static dynamic_information_init dynamic_information_init_tmp=dynamic_information_init_strm.read();
	ap_uint<27> latitude_init_tmp=dynamic_information_init_tmp.latitude_init;
	ap_uint<28> longitude_init_tmp=dynamic_information_init_tmp.longitude_init;
	ap_uint<10> sog_init_tmp=dynamic_information_init_tmp.sog_init;
	ap_uint<12> cog_init_tmp=dynamic_information_init_tmp.cog_init;
	static longitude_rad_t longitude;
	static latitude_rad_t latitude;
	static sog_t sog_tmp;
	static cog_t cog_tmp;
	static bool init=0;
	falsification_information falsification_informationtmp=falsification_information_strm.read();
	ap_uint<12> add_cog_fal_tmp=falsification_informationtmp.add_cog;
	ap_uint<10> add_sog_fal_tmp=falsification_informationtmp.add_sog;
	int add_lat_fal_int_tmp=falsification_informationtmp.add_lat;
	int add_lon_fal_int_tmp=falsification_informationtmp.add_lon;
	ap_uint<12> TS_interval=0;
	latitude_rad_t add_lat_fal_tmp=add_lat_fal_int_tmp*conv_lat_m_deg;
	longitude_rad_t add_lon_fal_tmp=add_lon_fal_int_tmp*conv_lon_m_deg;
	dynamic_information dynamic_information_tmp;
	phase_t two_pi=TWO_PI;

	//	position variable to treat dynamic
	ap_uint<27> latitude_tmp1;
	ap_uint<28> longitude_tmp1;
	latitude_t latitude_tmp2;
	longitude_t longitude_tmp2;
	latitude_tmp_t latitude_tmp3;
	longitude_tmp_t longitude_tmp3;
	latitude_rad_t latitude_f;
	longitude_rad_t longitude_f;
	phase_t deg_to_rad_tmp=DEG_TO_RAD;
	phase_t rad_to_deg_tmp=RAD_TO_DEG;

	if(flag_emission==1)
	{
		if(init==0)
		{
			if(latitude_init_tmp[26]==1)
			{
				latitude_tmp1=(latitude_init_tmp-1)^(0b111111111111111111111111111);
				//		We divide by 600000=9375*2^6. This division is divided by sequencial division to respect variable dynamic
				latitude_tmp2=latitude_tmp1>>6;
				latitude_tmp3=latitude_tmp2/75;
				latitude_f=latitude_tmp3/125;
				latitude_f=(-1)*latitude_f;
			}
			else
			{
				latitude_tmp1=latitude_init_tmp>>6;
				latitude_tmp2=latitude_tmp1;
				latitude_tmp3=latitude_tmp2/75;
				latitude_f=latitude_tmp3/125;
			}

			if(longitude_init_tmp[27]==1)
			{
				longitude_tmp1=(longitude_init_tmp-1)^(0b1111111111111111111111111111);
				longitude_tmp2=longitude_tmp1>>6;
				longitude_tmp3=longitude_tmp2/75;
				longitude_f=longitude_tmp3/125;
				longitude_f=(-1)*longitude_f;
			}
			else
			{
				longitude_tmp1=longitude_init_tmp>>6;
				longitude_tmp2=longitude_tmp1;
				longitude_tmp3=longitude_tmp2/75;
				longitude_f=longitude_tmp3/125;
			}
			init=1;
			longitude=longitude_f;
			latitude=latitude_f;
			sog_tmp=sog_init_tmp/10;
			cog_tmp=cog_init_tmp/10;

			ap_uint<10> sog_tmp_int=sog_init_tmp;
			ap_uint<28> longitude_tmp_int=longitude*600000;
			ap_uint<27> latitude_tmp_int=latitude*600000;
			ap_uint<12> cog_tmp_int=cog_init_tmp;

			dynamic_information_tmp.sog=sog_tmp_int;
			dynamic_information_tmp.cog=cog_tmp_int;
			dynamic_information_tmp.latitude=latitude_tmp_int;
			dynamic_information_tmp.longitude=longitude_tmp_int;
			dynamic_information_strm<<dynamic_information_tmp;
		}
		else
		{
			sog_t noise_sog_tmp=noise_sog[sog_noise_indice];
			cog_t noise_cog_tmp=noise_cog[cog_noise_indice];
			sog_noise_indice++;
			cog_noise_indice++;
			TS_noise_indice++;

			sog_tmp=sog_tmp+noise_sog_tmp+add_sog_fal_tmp;
			cog_tmp=cog_tmp+noise_cog_tmp+add_cog_fal_tmp;

			if(sog_tmp<=14)
			{
				TS_interval=noise_TS_10s[TS_noise_indice];
			}
			else if((sog_tmp>14) and (sog_tmp<23))
			{
				TS_interval=noise_TS_6s[TS_noise_indice];
			}
			else
			{
				TS_interval=noise_TS_2s[TS_noise_indice];
			}

			time1_t time_TS=TIME_TS;
			time1_t delta_t=TS_interval*time_TS;

			phase_t const_angle=CONST_ANGLE_DEG;
			ap_uint<8> n1=const_angle*cog_tmp;
			latitude_rad_t latitude_n2=latitude;
			if(latitude_n2<0)
			{
				latitude_n2+=360;
			}
			ap_uint<8> n2=const_angle*latitude_n2;
			sin_cos_t sog_const=SOG_CONST;

			//		add latitude and add longitude are expressed in deg
			latitude_rad_t add_latitude=sog_tmp*sog_const*delta_t*cos_lookup(n1)+add_lat_fal_tmp;
			longitude_rad_t add_longitude=sog_tmp*sog_const*delta_t*sin_lookup(n1)/cos_lookup(n2)+add_lon_fal_tmp;
			latitude=latitude+add_latitude;
			longitude=longitude+add_longitude;

			//	AIS standart imposes to multiplies latitude and longitude by 6000000 and cog and sog by 10
			ap_uint<10> sog_tmp_int=sog_tmp*10;
			ap_uint<28> longitude_tmp_int=longitude*600000;
			ap_uint<27> latitude_tmp_int=latitude*600000;
			ap_uint<12> cog_tmp_int=cog_tmp*10;

			dynamic_information_tmp.sog=sog_tmp_int;
			dynamic_information_tmp.cog=cog_tmp_int;
			dynamic_information_tmp.latitude=latitude_tmp_int;
			dynamic_information_tmp.longitude=longitude_tmp_int;
			dynamic_information_strm<<dynamic_information_tmp;
		}
	}
	else
	{
		sog_t noise_sog_tmp=noise_sog[sog_noise_indice];
		cog_t noise_cog_tmp=noise_cog[cog_noise_indice];
		sog_noise_indice++;
		cog_noise_indice++;
		TS_noise_indice++;

		time1_t time_TS=TIME_TS;
		time1_t delta_t=TS_interval*time_TS;

		phase_t const_angle=CONST_ANGLE;
		ap_uint<8> n1=const_angle*noise_cog_tmp;
		ap_uint<8> n2=const_angle*latitude;

		sin_cos_t sog_const=SOG_CONST;

		latitude_rad_t offset_latitude=0.0001;
		longitude_rad_t offset_longitude=0.0001;
		latitude_rad_t add_latitude=noise_sog_tmp*sog_const*delta_t*cos_lookup(n1);
		longitude_rad_t add_longitude=noise_sog_tmp*sog_const*delta_t*sin_lookup(n1)/cos_lookup(n2);

		ap_uint<10> sog_tmp_int=noise_sog_tmp*10;
		add_longitude=add_longitude+offset_longitude;
		add_latitude=add_latitude+offset_latitude;
		ap_uint<28> longitude_tmp_int=(add_longitude)*600000;
		ap_uint<27> latitude_tmp_int=(add_latitude)*600000;
		ap_uint<12> cog_tmp_int=noise_cog_tmp*10;

		dynamic_information_tmp.sog=sog_tmp_int;
		dynamic_information_tmp.cog=cog_tmp_int;
		dynamic_information_tmp.latitude=latitude_tmp_int;
		dynamic_information_tmp.longitude=longitude_tmp_int;
		dynamic_information_strm<<dynamic_information_tmp;
	}
	return;
}


void read_data_e_p_c(hls::stream<static_information> &static_information_strm,hls::stream<dynamic_information> &dynamic_information_strm,int mes_l[NB_INFORMATION])
{
	//	The values are just read during the first time
	dynamic_information dynamic_information_tmp=dynamic_information_strm.read();
	static static_information static_information_tmp=static_information_strm.read();
	int message_id_tmp=static_information_tmp.message_id;
	mes_l[0]=message_id_tmp;

	int repeat_indicator_tmp=static_information_tmp.repeat_indicator;
	mes_l[1]=repeat_indicator_tmp;

	int user_id_tmp=static_information_tmp.user_id;
	mes_l[2]=user_id_tmp;

	int navigational_status_tmp=static_information_tmp.navigational_status;
	mes_l[3]=navigational_status_tmp;

	int rot_tmp=static_information_tmp.rot;
	mes_l[4]=rot_tmp;

	ap_uint<10> sog_tmp=dynamic_information_tmp.sog;
	mes_l[5]=sog_tmp;

	int position_accuracy_tmp=static_information_tmp.position_accuracy;
	mes_l[6]=position_accuracy_tmp;

	ap_uint<28> longitude_tmp=dynamic_information_tmp.longitude;
	mes_l[7]=longitude_tmp;

	ap_uint<27> latitude_tmp=dynamic_information_tmp.latitude;
	mes_l[8]=latitude_tmp;

	ap_uint<12> cog_tmp=dynamic_information_tmp.cog;
	mes_l[9]=cog_tmp;

	int true_heading_tmp=static_information_tmp.true_heading;
	mes_l[10]=true_heading_tmp;

	int time_stamp_tmp=static_information_tmp.time_stamp;
	mes_l[11]=time_stamp_tmp;

	int special_manoeuvre_indicator_tmp=static_information_tmp.special_manoeuvre_indicator;
	mes_l[12]=special_manoeuvre_indicator_tmp;

	int spare_tmp=static_information_tmp.spare;
	mes_l[13]=spare_tmp;

	int raim_flag_tmp=static_information_tmp.raim_flag;
	mes_l[14]=raim_flag_tmp;

	int communication_state_tmp=static_information_tmp.communication_state;
	mes_l[15]=communication_state_tmp;
}


void NMEA_frame_building(int mes_l[NB_INFORMATION],hls::stream<data_t> &data_strm,hls::stream<data_t> &data_obs_strm)
{
	data_t data_tmp=0;
	data_tmp=mes_l[0];
	for (int j=1;j<NB_INFORMATION;j++)
	{
		int tmp=mes_l[j];
		int tmp_list_nb_bits=list_nb_bits[j];
		if (tmp<0)
		{
			tmp=tmp*(-1);
			int cons=pow_c[tmp_list_nb_bits];
			tmp=(tmp^cons)+1;
		}
		data_tmp = data_tmp << tmp_list_nb_bits;
		data_tmp=data_tmp+tmp;
	}
	data_strm<<data_tmp;
	data_obs_strm<<data_tmp;
}

void frame_building_e_p_c(hls::stream<static_information> &static_information_strm,hls::stream<dynamic_information> &dynamic_information_strm,hls::stream<data_t> &data,hls::stream<data_t> &data_obs)
{
	int mes_l[NB_INFORMATION];
	data_t data_tmp;
	read_data_e_p_c(static_information_strm,dynamic_information_strm,mes_l);
	NMEA_frame_building(mes_l,data,data_obs);
}


void piloting(hls::stream<snr_t> &snr_strm,hls::stream<int> &f_shift_strm,hls::stream<dynamic_information_init> &dynamic_information_init_strm,hls::stream<falsification_information> &falsification_information_strm,hls::stream<static_information> &static_information_strm,hls::stream<data_t> &data_strm,hls::stream<bool> &start_e_in,hls::stream<bool> &start_e,hls::stream<data_t> &data_obs_strm,hls::stream<snr_t> &snr_out,hls::stream<int> &f_shift_out)
{
#pragma HLS DATAFLOW
	hls::stream<dynamic_information> dynamic_information_strm;
	bool start_e_tmp=start_e_in.read();
	snr_t snr_tmp=snr_strm.read();
	int f_shift_tmp=f_shift_strm.read();
	start_e<<start_e_tmp;
	snr_out<<snr_tmp;
	f_shift_out<<f_shift_tmp;
	dynamic_data_generation_e_p_c(start_e_tmp,dynamic_information_strm,dynamic_information_init_strm,falsification_information_strm);
	frame_building_e_p_c(static_information_strm,dynamic_information_strm,data_strm,data_obs_strm);
}
