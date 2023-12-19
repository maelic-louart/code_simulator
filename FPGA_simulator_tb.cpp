#include "FPGA_simulator.h"


int main()
{

	phase_t lat;
	phase_t lon;
	sog_f_t sog;

	bool start("start");
	hls::stream<bool> start_emission("start_emission");
	hls::stream<ap_uint<NB_BITS_DATA>> data_out_strm("data_out_strm");
	hls::stream<data_t> data_obs_strm("data_obs_strm");
	hls::stream<data_t> data_strm1;
	hls::stream<bool> start_e_cps;
	hls::stream<snr_t> snr_strm("snr_strm");
	hls::stream<int> f_shift_strm("f_shift_strm");
	hls::stream<snr_t> snr_strm_1;
	hls::stream<int> f_shift_strm_1;
	ap_uint<27> latitude=0;
	ap_uint<28> longitude=0;
	hls::stream<ap_uint<12>> cog_strm_init("cog_strm_init");
	hls::stream<ap_uint<10>> sog_strm_init("sog_strm_init");
	hls::stream<ap_uint<27>> latitude_strm_init("latitude_strm_init");
	hls::stream<ap_uint<28>> longitude_strm_init("longitude_strm_init");
	hls::stream<ap_uint<12>> TS_interval_strm("TS_interval_strm");

	sin_cos_t I_strm[NB_EL_ARRAY]={0};
	sin_cos_t Q_strm[NB_EL_ARRAY]={0};
	sin_cos_t I_strm_1[NB_EL_ARRAY]={0};
	sin_cos_t Q_strm_1[NB_EL_ARRAY]={0};
	hls::stream<sin_cos_t> I_obs_strm_e("I_obs_strm_e");
	hls::stream<sin_cos_t> Q_obs_strm_e("Q_obs_strm_e");
	hls::stream<sin_cos_t> I_obs_strm_c("I_obs_strm_c");
	hls::stream<sin_cos_t> Q_obs_strm_c("Q_obs_strm_c");

	FILE *message_id_file=fopen("data/message_id.dat","r");
	FILE *repeat_indicator_file=fopen("data/repeat_indicator.dat","r");
	FILE *user_id_file=fopen("data/user_id.dat","r");
	FILE *navigational_status_file=fopen("data/navigational_status.dat","r");
	FILE *rot_file=fopen("data/rot.dat","r");
	FILE *position_accuracy_file=fopen("data/position_accuracy.dat","r");
	FILE *true_heading_file=fopen("data/true_heading.dat","r");
	FILE *time_stamp_file=fopen("data/time_stamp.dat","r");
	FILE *special_manoeuvre_indicator_file=fopen("data/special_manoeuvre_indicator.dat","r");
	FILE *spare_file=fopen("data/spare.dat","r");
	FILE *raim_flag_file=fopen("data/raim_flag.dat","r");
	FILE *communication_state_file=fopen("data/communication_state.dat","r");
	FILE *latitude_file=fopen("data/latitude.dat","r");
	FILE *longitude_file=fopen("data/longitude.dat","r");
	FILE *cog_file=fopen("data/cog.dat","r");
	FILE *sog_file=fopen("data/sog.dat","r");

	hls::stream<dynamic_information_init> dynamic_information_init_strm("dynamic_information_init_strm");

	static_information static_information_tmp;

	if (message_id_file == NULL)
	{
		printf("erreur lecture fichier");
	}
	else
	{
		int tmp;
		fscanf(message_id_file,"%u",& tmp);
		static_information_tmp.message_id=tmp;
	}
	if (repeat_indicator_file == NULL)
	{
		printf("erreur lecture fichier");
	}
	else
	{
		int tmp;
		fscanf(repeat_indicator_file,"%u",& tmp);
		static_information_tmp.repeat_indicator=tmp;
	}
	if (user_id_file == NULL)
	{
		printf("erreur lecture fichier");
	}
	else
	{
		int tmp;
		fscanf(user_id_file,"%u",& tmp);
		static_information_tmp.user_id=tmp;
	}
	if (navigational_status_file == NULL)
	{
		printf("erreur lecture fichier");
	}
	else
	{
		int tmp;
		fscanf(navigational_status_file,"%u",& tmp);
		static_information_tmp.navigational_status=tmp;
	}
	if (rot_file == NULL)
	{
		printf("erreur lecture fichier");
	}
	else
	{
		int tmp;
		fscanf(rot_file,"%u",& tmp);
		static_information_tmp.rot=tmp;
	}
	if (position_accuracy_file == NULL)
	{
		printf("erreur lecture fichier");
	}
	else
	{
		int tmp;
		fscanf(position_accuracy_file,"%u",& tmp);
		static_information_tmp.position_accuracy=tmp;
	}
	if (true_heading_file == NULL)
	{
		printf("erreur lecture fichier");
	}
	else
	{
		int tmp;
		fscanf(true_heading_file,"%u",& tmp);
		static_information_tmp.true_heading=tmp;
	}
	if (time_stamp_file == NULL)
	{
		printf("erreur lecture fichier");
	}
	else
	{
		int tmp;
		fscanf(time_stamp_file,"%u",& tmp);
		static_information_tmp.time_stamp=tmp;
	}
	if (special_manoeuvre_indicator_file == NULL)
	{
		printf("erreur lecture fichier");
	}
	else
	{
		int tmp;
		fscanf(special_manoeuvre_indicator_file,"%u",& tmp);
		static_information_tmp.special_manoeuvre_indicator=tmp;
	}
	if (spare_file == NULL)
	{
		printf("erreur lecture fichier");
	}
	else
	{
		int tmp;
		fscanf(spare_file,"%u",& tmp);
		static_information_tmp.spare=tmp;
	}
	if (raim_flag_file == NULL)
	{
		printf("erreur lecture fichier");
	}
	else
	{
		int tmp;
		fscanf(raim_flag_file,"%u",& tmp);
		static_information_tmp.raim_flag=tmp;
	}
	if (communication_state_file == NULL)
	{
		printf("erreur lecture fichier");
	}
	else
	{
		int tmp;
		fscanf(communication_state_file,"%u",& tmp);
		static_information_tmp.communication_state=tmp;
	}

	if (latitude_file == NULL)
	{
		printf("erreur lecture fichier");
	}
	else
	{
		int tmp;
		fscanf(latitude_file,"%u",& tmp);
		latitude_strm_init<<tmp*600000;
	}

	if (longitude_file == NULL)
	{
		printf("erreur lecture fichier");
	}
	else
	{
		int tmp;
		fscanf(longitude_file,"%u",& tmp);
		longitude_strm_init<<tmp*600000;
	}

	if (cog_file == NULL)
	{
		printf("erreur lecture fichier");
	}
	else
	{
		int tmp;
		fscanf(cog_file,"%u",& tmp);
		cog_strm_init<<tmp*10;
	}

	if (sog_file == NULL)
	{
		printf("erreur lecture fichier");
	}
	else
	{
		int tmp;
		fscanf(sog_file,"%u",& tmp);
		sog_strm_init<<tmp*10;
	}


	//	//	il faut initialiser le tableau in_phase.
	phase_t in_phase[NB_EL_ARRAY];
	sin_cos_t I[NB_EL_ARRAY];
	sin_cos_t Q[NB_EL_ARRAY];
	phase_t phase_demod[NB_EL_ARRAY];
	data_separated data_separated;
	int err=0;

	for(int k=0;k<NB_EL_ARRAY;k++)
	{
		in_phase[k]=0;
		I[k]=0;
		Q[k]=0;
		phase_demod[k]=0;
	}

	int nb_simu=5;
	int nb_snr=1;
	int nb_shift=1;

	int nb_simu_sum=nb_snr*nb_simu*nb_shift;

	start=1;

	int add_lat=0;
	int add_lon=0;
	int add_cog=0;
	int add_sog=0;

	hls::stream<falsification_information> falsification_information_strm;
	falsification_information falsification_information_tmp;
	hls::stream<static_information> static_information_strm;
	static_information_strm<<static_information_tmp;

	dynamic_information_init dynamic_information_init_tmp;
	dynamic_information_init_tmp.cog_init=cog_value_e;
	dynamic_information_init_tmp.sog_init=sog_value_e;
	dynamic_information_init_tmp.latitude_init=latitude_value_e_int;
	dynamic_information_init_tmp.longitude_init=longitude_value_e_int;

	dynamic_information_init_strm<<dynamic_information_init_tmp;

	hls::stream<longitude_rad_t> longitude_strm_1;
	hls::stream<latitude_rad_t> latitude_strm_1;

	float ber_tmp=0;

	int nb_bits_data_tmp=NB_BITS_DATA;

	char buf1[30];

	for (int k=0;k<nb_shift;k++)
	{
		float f_shit_tmp1=k*200;
		int f_shit_tmp=k*200;
		snprintf(buf1, sizeof(buf1), "ber%d.dat", k);
		FILE *ber_file=fopen(buf1,"w");
		fprintf(ber_file, "%lf\n",f_shit_tmp1);
		for(int i=0;i<nb_snr;i++)
		{
			snr_t snr_tmp=list_snr[20];
			float ber_f=0;
			cout << endl << "snr=  "<<snr_tmp << endl;

			for(int j=0;j<nb_simu;j++)
			{

				snr_strm<<snr_tmp;
				f_shift_strm<<f_shit_tmp;
				falsification_information_tmp.add_lat=add_lat;
				falsification_information_tmp.add_lon=add_lon;
				falsification_information_tmp.add_cog=add_cog;
				falsification_information_tmp.add_sog=add_sog;
				falsification_information_strm<<falsification_information_tmp;
				start_emission<<1;

				piloting(snr_strm,f_shift_strm,dynamic_information_init_strm,falsification_information_strm,static_information_strm,data_strm1,start_emission,start_e_cps,data_obs_strm,snr_strm,f_shift_strm);

				emitter(start_e_cps,data_strm1,I_strm,Q_strm,I_obs_strm_e,Q_obs_strm_e,&latitude,&longitude);

				channel(I_strm,Q_strm,I_strm_1,Q_strm_1,I_obs_strm_c,Q_obs_strm_c,latitude,longitude,snr_strm,f_shift_strm);

				receiver(I_strm_1,Q_strm_1,longitude_strm_1,latitude_strm_1,data_out_strm);

				data_t data_out_tmp=data_out_strm.read();
				data_t data_obs_tmp=data_obs_strm.read();
				data_t diff_data=data_out_tmp-data_obs_tmp;

				float nb_error=0;
				for(ap_uint<9> i=0;i<NB_BITS_DATA+5;i++)
				{
					if (data_obs_tmp[i]!=data_out_tmp[i])
					{
						nb_error++;
					}
				}
				ber_tmp=nb_error/nb_bits_data_tmp;
				ber_f+=ber_tmp/nb_simu;
			}
			fprintf(ber_file, "%lf\n",ber_f);
		}
		fclose(ber_file);
	}
	cout << "err =" << err << endl;
	return err;
}
