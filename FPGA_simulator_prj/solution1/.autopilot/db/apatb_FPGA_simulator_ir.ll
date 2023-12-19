; ModuleID = '/home/louart/Bureau/these/code_pour_jcll/FPGA_simulator_prj/solution1/.autopilot/db/a.g.ld.5.gdce.bc'
source_filename = "llvm-link"
target datalayout = "e-m:e-i64:64-i128:128-i256:256-i512:512-i1024:1024-i2048:2048-i4096:4096-n8:16:32:64-S128-v16:16-v24:32-v32:32-v48:64-v96:128-v192:256-v256:256-v512:512-v1024:1024"
target triple = "fpga64-xilinx-none"

%"struct.ssdm_int<32, false>" = type { i32 }
%"class.hls::stream<dynamic_information_init, 0>" = type { %struct.dynamic_information_init }
%struct.dynamic_information_init = type { %"struct.ap_uint<28>", %"struct.ap_uint<27>", %"struct.ap_uint<12>", %"struct.ap_uint<10>" }
%"struct.ap_uint<28>" = type { %"struct.ap_int_base<28, false>" }
%"struct.ap_int_base<28, false>" = type { %"struct.ssdm_int<28, false>" }
%"struct.ssdm_int<28, false>" = type { i28 }
%"struct.ap_uint<27>" = type { %"struct.ap_int_base<27, false>" }
%"struct.ap_int_base<27, false>" = type { %"struct.ssdm_int<27, false>" }
%"struct.ssdm_int<27, false>" = type { i27 }
%"struct.ap_uint<12>" = type { %"struct.ap_int_base<12, true>" }
%"struct.ap_int_base<12, true>" = type { %"struct.ssdm_int<12, true>" }
%"struct.ssdm_int<12, true>" = type { i12 }
%"struct.ap_uint<10>" = type { %"struct.ap_int_base<10, false>" }
%"struct.ap_int_base<10, false>" = type { %"struct.ssdm_int<10, false>" }
%"struct.ssdm_int<10, false>" = type { i10 }
%"class.hls::stream<falsification_information, 0>" = type { %struct.falsification_information }
%struct.falsification_information = type { i32, i32, %"struct.ap_uint<12>", %"struct.ap_uint<10>" }
%"class.hls::stream<static_information, 0>" = type { %struct.static_information }
%struct.static_information = type { %"struct.ap_uint<6>", %"struct.ap_uint<2>", %"struct.ap_uint<30>", %"struct.ap_uint<4>", %"struct.ap_uint<8>", %"struct.ap_uint<1>", %"struct.ap_uint<9>", %"struct.ap_uint<6>", %"struct.ap_uint<2>", %"struct.ap_uint<3>", %"struct.ap_uint<1>", %"struct.ap_uint<19>" }
%"struct.ap_uint<30>" = type { %"struct.ap_int_base<30, false>" }
%"struct.ap_int_base<30, false>" = type { %"struct.ssdm_int<30, false>" }
%"struct.ssdm_int<30, false>" = type { i30 }
%"struct.ap_uint<4>" = type { %"struct.ap_int_base<4, false>" }
%"struct.ap_int_base<4, false>" = type { %"struct.ssdm_int<4, false>" }
%"struct.ssdm_int<4, false>" = type { i4 }
%"struct.ap_uint<8>" = type { %"struct.ap_int_base<8, false>" }
%"struct.ap_int_base<8, false>" = type { %"class.std::ios_base::Init" }
%"class.std::ios_base::Init" = type { i8 }
%"struct.ap_uint<9>" = type { %"struct.ap_int_base<9, false>" }
%"struct.ap_int_base<9, false>" = type { %"struct.ssdm_int<9, false>" }
%"struct.ssdm_int<9, false>" = type { i9 }
%"struct.ap_uint<6>" = type { %"struct.ap_int_base<6, false>" }
%"struct.ap_int_base<6, false>" = type { %"struct.ssdm_int<6, false>" }
%"struct.ssdm_int<6, false>" = type { i6 }
%"struct.ap_uint<2>" = type { %"struct.ap_int_base<2, false>" }
%"struct.ap_int_base<2, false>" = type { %"struct.ssdm_int<2, false>" }
%"struct.ssdm_int<2, false>" = type { i2 }
%"struct.ap_uint<3>" = type { %"struct.ap_int_base<3, false>" }
%"struct.ap_int_base<3, false>" = type { %"struct.ssdm_int<3, false>" }
%"struct.ssdm_int<3, false>" = type { i3 }
%"struct.ap_uint<1>" = type { %"struct.ap_int_base<1, false>" }
%"struct.ap_int_base<1, false>" = type { %"struct.ssdm_int<1, false>" }
%"struct.ssdm_int<1, false>" = type { i1 }
%"struct.ap_uint<19>" = type { %"struct.ap_int_base<19, false>" }
%"struct.ap_int_base<19, false>" = type { %"struct.ssdm_int<19, false>" }
%"struct.ssdm_int<19, false>" = type { i19 }
%"class.hls::stream<ap_uint<178>, 0>" = type { %"struct.ap_uint<178>" }
%"struct.ap_uint<178>" = type { %"struct.ap_int_base<178, false>" }
%"struct.ap_int_base<178, false>" = type { %"struct.ssdm_int<178, false>" }
%"struct.ssdm_int<178, false>" = type { i178 }
%"class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>" = type { %"struct.ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>" }
%"struct.ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>" = type { %"struct.ap_fixed_base<32, 24, false, AP_TRN, AP_WRAP, 0>" }
%"struct.ap_fixed_base<32, 24, false, AP_TRN, AP_WRAP, 0>" = type { %"struct.ssdm_int<32, false>" }
%"class.hls::stream<ap_uint<168>, 0>" = type { %"struct.ap_uint<168>" }
%"struct.ap_uint<168>" = type { %"struct.ap_int_base<168, false>" }
%"struct.ap_int_base<168, false>" = type { %"struct.ssdm_int<168, false>" }
%"struct.ssdm_int<168, false>" = type { i168 }

; Function Attrs: inaccessiblememonly nounwind willreturn
declare void @llvm.sideeffect() #0

; Function Attrs: noinline
define void @apatb_FPGA_simulator_ir(%"class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>"* noalias nocapture nonnull dereferenceable(4) %snr_strm, %"struct.ssdm_int<32, false>"* noalias nocapture nonnull dereferenceable(4) %f_shift_strm, %"class.hls::stream<dynamic_information_init, 0>"* noalias nocapture nonnull dereferenceable(12) %dynamic_information_init_strm, %"class.hls::stream<falsification_information, 0>"* noalias nocapture nonnull dereferenceable(12) %falsification_information_strm, %"class.hls::stream<static_information, 0>"* noalias nocapture nonnull dereferenceable(24) %static_information_strm, %"struct.ssdm_int<1, false>"* noalias nocapture nonnull dereferenceable(1) %start_e, %"class.hls::stream<ap_uint<178>, 0>"* noalias nocapture nonnull dereferenceable(32) %data_obs_strm, %"class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>"* noalias nocapture nonnull dereferenceable(4) %I_obs_strm_e, %"class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>"* noalias nocapture nonnull dereferenceable(4) %Q_obs_strm_e, %"class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>"* noalias nocapture nonnull dereferenceable(4) %I_obs_strm_c, %"class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>"* noalias nocapture nonnull dereferenceable(4) %Q_obs_strm_c, %"class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>"* noalias nocapture nonnull dereferenceable(4) %longitude_strm_out, %"class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>"* noalias nocapture nonnull dereferenceable(4) %latitude_strm_out, %"class.hls::stream<ap_uint<168>, 0>"* noalias nocapture nonnull dereferenceable(32) %data_out_strm) local_unnamed_addr #1 {
entry:
  %snr_strm_copy = alloca i32, align 512
  call void @llvm.sideeffect() #7 [ "stream_interface"(i32* %snr_strm_copy, i32 0) ]
  %f_shift_strm_copy = alloca i32, align 512
  call void @llvm.sideeffect() #7 [ "stream_interface"(i32* %f_shift_strm_copy, i32 0) ]
  %dynamic_information_init_strm_copy = alloca %"class.hls::stream<dynamic_information_init, 0>", align 512
  call void @llvm.sideeffect() #8 [ "stream_interface"(%"class.hls::stream<dynamic_information_init, 0>"* %dynamic_information_init_strm_copy, i32 0) ]
  %falsification_information_strm_copy = alloca %"class.hls::stream<falsification_information, 0>", align 512
  call void @llvm.sideeffect() #8 [ "stream_interface"(%"class.hls::stream<falsification_information, 0>"* %falsification_information_strm_copy, i32 0) ]
  %static_information_strm_copy = alloca %"class.hls::stream<static_information, 0>", align 512
  call void @llvm.sideeffect() #9 [ "stream_interface"(%"class.hls::stream<static_information, 0>"* %static_information_strm_copy, i32 0) ]
  %start_e_copy = alloca i1, align 512
  call void @llvm.sideeffect() #10 [ "stream_interface"(i1* %start_e_copy, i32 0) ]
  %data_obs_strm_copy = alloca i178, align 512
  call void @llvm.sideeffect() #11 [ "stream_interface"(i178* %data_obs_strm_copy, i32 0) ]
  %I_obs_strm_e_copy = alloca i32, align 512
  call void @llvm.sideeffect() #7 [ "stream_interface"(i32* %I_obs_strm_e_copy, i32 0) ]
  %Q_obs_strm_e_copy = alloca i32, align 512
  call void @llvm.sideeffect() #7 [ "stream_interface"(i32* %Q_obs_strm_e_copy, i32 0) ]
  %I_obs_strm_c_copy = alloca i32, align 512
  call void @llvm.sideeffect() #7 [ "stream_interface"(i32* %I_obs_strm_c_copy, i32 0) ]
  %Q_obs_strm_c_copy = alloca i32, align 512
  call void @llvm.sideeffect() #7 [ "stream_interface"(i32* %Q_obs_strm_c_copy, i32 0) ]
  %longitude_strm_out_copy = alloca i32, align 512
  call void @llvm.sideeffect() #7 [ "stream_interface"(i32* %longitude_strm_out_copy, i32 0) ]
  %latitude_strm_out_copy = alloca i32, align 512
  call void @llvm.sideeffect() #7 [ "stream_interface"(i32* %latitude_strm_out_copy, i32 0) ]
  %data_out_strm_copy = alloca i168, align 512
  call void @llvm.sideeffect() #11 [ "stream_interface"(i168* %data_out_strm_copy, i32 0) ]
  call fastcc void @copy_in(%"class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>"* nonnull %snr_strm, i32* nonnull align 512 %snr_strm_copy, %"struct.ssdm_int<32, false>"* nonnull %f_shift_strm, i32* nonnull align 512 %f_shift_strm_copy, %"class.hls::stream<dynamic_information_init, 0>"* nonnull %dynamic_information_init_strm, %"class.hls::stream<dynamic_information_init, 0>"* nonnull align 512 %dynamic_information_init_strm_copy, %"class.hls::stream<falsification_information, 0>"* nonnull %falsification_information_strm, %"class.hls::stream<falsification_information, 0>"* nonnull align 512 %falsification_information_strm_copy, %"class.hls::stream<static_information, 0>"* nonnull %static_information_strm, %"class.hls::stream<static_information, 0>"* nonnull align 512 %static_information_strm_copy, %"struct.ssdm_int<1, false>"* nonnull %start_e, i1* nonnull align 512 %start_e_copy, %"class.hls::stream<ap_uint<178>, 0>"* nonnull %data_obs_strm, i178* nonnull align 512 %data_obs_strm_copy, %"class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>"* nonnull %I_obs_strm_e, i32* nonnull align 512 %I_obs_strm_e_copy, %"class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>"* nonnull %Q_obs_strm_e, i32* nonnull align 512 %Q_obs_strm_e_copy, %"class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>"* nonnull %I_obs_strm_c, i32* nonnull align 512 %I_obs_strm_c_copy, %"class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>"* nonnull %Q_obs_strm_c, i32* nonnull align 512 %Q_obs_strm_c_copy, %"class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>"* nonnull %longitude_strm_out, i32* nonnull align 512 %longitude_strm_out_copy, %"class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>"* nonnull %latitude_strm_out, i32* nonnull align 512 %latitude_strm_out_copy, %"class.hls::stream<ap_uint<168>, 0>"* nonnull %data_out_strm, i168* nonnull align 512 %data_out_strm_copy)
  call void @apatb_FPGA_simulator_hw(i32* %snr_strm_copy, i32* %f_shift_strm_copy, %"class.hls::stream<dynamic_information_init, 0>"* %dynamic_information_init_strm_copy, %"class.hls::stream<falsification_information, 0>"* %falsification_information_strm_copy, %"class.hls::stream<static_information, 0>"* %static_information_strm_copy, i1* %start_e_copy, i178* %data_obs_strm_copy, i32* %I_obs_strm_e_copy, i32* %Q_obs_strm_e_copy, i32* %I_obs_strm_c_copy, i32* %Q_obs_strm_c_copy, i32* %longitude_strm_out_copy, i32* %latitude_strm_out_copy, i168* %data_out_strm_copy)
  call void @copy_back(%"class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>"* %snr_strm, i32* %snr_strm_copy, %"struct.ssdm_int<32, false>"* %f_shift_strm, i32* %f_shift_strm_copy, %"class.hls::stream<dynamic_information_init, 0>"* %dynamic_information_init_strm, %"class.hls::stream<dynamic_information_init, 0>"* %dynamic_information_init_strm_copy, %"class.hls::stream<falsification_information, 0>"* %falsification_information_strm, %"class.hls::stream<falsification_information, 0>"* %falsification_information_strm_copy, %"class.hls::stream<static_information, 0>"* %static_information_strm, %"class.hls::stream<static_information, 0>"* %static_information_strm_copy, %"struct.ssdm_int<1, false>"* %start_e, i1* %start_e_copy, %"class.hls::stream<ap_uint<178>, 0>"* %data_obs_strm, i178* %data_obs_strm_copy, %"class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>"* %I_obs_strm_e, i32* %I_obs_strm_e_copy, %"class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>"* %Q_obs_strm_e, i32* %Q_obs_strm_e_copy, %"class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>"* %I_obs_strm_c, i32* %I_obs_strm_c_copy, %"class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>"* %Q_obs_strm_c, i32* %Q_obs_strm_c_copy, %"class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>"* %longitude_strm_out, i32* %longitude_strm_out_copy, %"class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>"* %latitude_strm_out, i32* %latitude_strm_out_copy, %"class.hls::stream<ap_uint<168>, 0>"* %data_out_strm, i168* %data_out_strm_copy)
  ret void
}

; Function Attrs: argmemonly noinline willreturn
define internal fastcc void @copy_in(%"class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>"* noalias "unpacked"="0", i32* noalias nocapture align 512 "unpacked"="1.0", %"struct.ssdm_int<32, false>"* noalias "unpacked"="2", i32* noalias nocapture align 512 "unpacked"="3.0", %"class.hls::stream<dynamic_information_init, 0>"* noalias "unpacked"="4", %"class.hls::stream<dynamic_information_init, 0>"* noalias align 512 "unpacked"="5", %"class.hls::stream<falsification_information, 0>"* noalias "unpacked"="6", %"class.hls::stream<falsification_information, 0>"* noalias align 512 "unpacked"="7", %"class.hls::stream<static_information, 0>"* noalias "unpacked"="8", %"class.hls::stream<static_information, 0>"* noalias align 512 "unpacked"="9", %"struct.ssdm_int<1, false>"* noalias "unpacked"="10", i1* noalias nocapture align 512 "unpacked"="11.0", %"class.hls::stream<ap_uint<178>, 0>"* noalias "unpacked"="12", i178* noalias nocapture align 512 "unpacked"="13.0", %"class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>"* noalias "unpacked"="14", i32* noalias nocapture align 512 "unpacked"="15.0", %"class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>"* noalias "unpacked"="16", i32* noalias nocapture align 512 "unpacked"="17.0", %"class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>"* noalias "unpacked"="18", i32* noalias nocapture align 512 "unpacked"="19.0", %"class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>"* noalias "unpacked"="20", i32* noalias nocapture align 512 "unpacked"="21.0", %"class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>"* noalias "unpacked"="22", i32* noalias nocapture align 512 "unpacked"="23.0", %"class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>"* noalias "unpacked"="24", i32* noalias nocapture align 512 "unpacked"="25.0", %"class.hls::stream<ap_uint<168>, 0>"* noalias "unpacked"="26", i168* noalias nocapture align 512 "unpacked"="27.0") unnamed_addr #2 {
entry:
  call fastcc void @"onebyonecpy_hls.p0class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>"(i32* align 512 %1, %"class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>"* %0)
  call fastcc void @"onebyonecpy_hls.p0struct.ssdm_int<32, false>.744"(i32* align 512 %3, %"struct.ssdm_int<32, false>"* %2)
  call fastcc void @"onebyonecpy_hls.p0class.hls::stream<dynamic_information_init, 0>"(%"class.hls::stream<dynamic_information_init, 0>"* align 512 %5, %"class.hls::stream<dynamic_information_init, 0>"* %4)
  call fastcc void @"onebyonecpy_hls.p0class.hls::stream<falsification_information, 0>"(%"class.hls::stream<falsification_information, 0>"* align 512 %7, %"class.hls::stream<falsification_information, 0>"* %6)
  call fastcc void @"onebyonecpy_hls.p0class.hls::stream<static_information, 0>"(%"class.hls::stream<static_information, 0>"* align 512 %9, %"class.hls::stream<static_information, 0>"* %8)
  call fastcc void @"onebyonecpy_hls.p0struct.ssdm_int<1, false>"(i1* align 512 %11, %"struct.ssdm_int<1, false>"* %10)
  call fastcc void @"onebyonecpy_hls.p0class.hls::stream<ap_uint<178>, 0>.718"(i178* align 512 %13, %"class.hls::stream<ap_uint<178>, 0>"* %12)
  call fastcc void @"onebyonecpy_hls.p0class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>"(i32* align 512 %15, %"class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>"* %14)
  call fastcc void @"onebyonecpy_hls.p0class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>"(i32* align 512 %17, %"class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>"* %16)
  call fastcc void @"onebyonecpy_hls.p0class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>"(i32* align 512 %19, %"class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>"* %18)
  call fastcc void @"onebyonecpy_hls.p0class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>"(i32* align 512 %21, %"class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>"* %20)
  call fastcc void @"onebyonecpy_hls.p0class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>"(i32* align 512 %23, %"class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>"* %22)
  call fastcc void @"onebyonecpy_hls.p0class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>"(i32* align 512 %25, %"class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>"* %24)
  call fastcc void @"onebyonecpy_hls.p0class.hls::stream<ap_uint<168>, 0>"(i168* align 512 %27, %"class.hls::stream<ap_uint<168>, 0>"* %26)
  ret void
}

; Function Attrs: argmemonly noinline willreturn
define internal fastcc void @"onebyonecpy_hls.p0struct.ssdm_int<32, false>"(%"struct.ssdm_int<32, false>"* noalias "unpacked"="0" %dst, i32* noalias nocapture align 512 "unpacked"="1.0" %src) unnamed_addr #3 {
entry:
  %0 = icmp eq %"struct.ssdm_int<32, false>"* %dst, null
  br i1 %0, label %ret, label %copy

copy:                                             ; preds = %entry
  call fastcc void @"streamcpy_hls.p0struct.ssdm_int<32, false>"(%"struct.ssdm_int<32, false>"* nonnull %dst, i32* align 512 %src)
  br label %ret

ret:                                              ; preds = %copy, %entry
  ret void
}

; Function Attrs: argmemonly noinline willreturn
define internal fastcc void @"streamcpy_hls.p0struct.ssdm_int<32, false>"(%"struct.ssdm_int<32, false>"* noalias nocapture "unpacked"="0", i32* noalias nocapture align 512 "unpacked"="1.0") unnamed_addr #4 {
entry:
  %2 = alloca i32
  %3 = alloca %"struct.ssdm_int<32, false>"
  br label %empty

empty:                                            ; preds = %push, %entry
  %4 = bitcast i32* %1 to i8*
  %5 = call i1 @fpga_fifo_not_empty_4(i8* %4)
  br i1 %5, label %push, label %ret

push:                                             ; preds = %empty
  %6 = bitcast i32* %2 to i8*
  %7 = bitcast i32* %1 to i8*
  call void @fpga_fifo_pop_4(i8* %6, i8* %7)
  %8 = load volatile i32, i32* %2
  %.ivi = insertvalue %"struct.ssdm_int<32, false>" undef, i32 %8, 0
  store %"struct.ssdm_int<32, false>" %.ivi, %"struct.ssdm_int<32, false>"* %3
  %9 = bitcast %"struct.ssdm_int<32, false>"* %3 to i8*
  %10 = bitcast %"struct.ssdm_int<32, false>"* %0 to i8*
  call void @fpga_fifo_push_4(i8* %9, i8* %10)
  br label %empty, !llvm.loop !5

ret:                                              ; preds = %empty
  ret void
}

; Function Attrs: argmemonly noinline willreturn
define internal fastcc void @"onebyonecpy_hls.p0class.hls::stream<dynamic_information_init, 0>"(%"class.hls::stream<dynamic_information_init, 0>"* noalias align 512 %dst, %"class.hls::stream<dynamic_information_init, 0>"* noalias %src) unnamed_addr #3 {
entry:
  %0 = icmp eq %"class.hls::stream<dynamic_information_init, 0>"* %dst, null
  %1 = icmp eq %"class.hls::stream<dynamic_information_init, 0>"* %src, null
  %2 = or i1 %0, %1
  br i1 %2, label %ret, label %copy

copy:                                             ; preds = %entry
  call fastcc void @"streamcpy_hls.p0class.hls::stream<dynamic_information_init, 0>"(%"class.hls::stream<dynamic_information_init, 0>"* nonnull align 512 %dst, %"class.hls::stream<dynamic_information_init, 0>"* nonnull %src)
  br label %ret

ret:                                              ; preds = %copy, %entry
  ret void
}

; Function Attrs: argmemonly noinline willreturn
define internal fastcc void @"streamcpy_hls.p0class.hls::stream<dynamic_information_init, 0>"(%"class.hls::stream<dynamic_information_init, 0>"* noalias nocapture align 512, %"class.hls::stream<dynamic_information_init, 0>"* noalias nocapture) unnamed_addr #4 {
entry:
  %2 = alloca %"class.hls::stream<dynamic_information_init, 0>"
  br label %empty

empty:                                            ; preds = %push, %entry
  %3 = bitcast %"class.hls::stream<dynamic_information_init, 0>"* %1 to i8*
  %4 = call i1 @fpga_fifo_not_empty_12(i8* %3)
  br i1 %4, label %push, label %ret

push:                                             ; preds = %empty
  %5 = bitcast %"class.hls::stream<dynamic_information_init, 0>"* %2 to i8*
  %6 = bitcast %"class.hls::stream<dynamic_information_init, 0>"* %1 to i8*
  call void @fpga_fifo_pop_12(i8* %5, i8* %6)
  %7 = load volatile %"class.hls::stream<dynamic_information_init, 0>", %"class.hls::stream<dynamic_information_init, 0>"* %2
  %8 = bitcast %"class.hls::stream<dynamic_information_init, 0>"* %2 to i8*
  %9 = bitcast %"class.hls::stream<dynamic_information_init, 0>"* %0 to i8*
  call void @fpga_fifo_push_12(i8* %8, i8* %9)
  br label %empty, !llvm.loop !7

ret:                                              ; preds = %empty
  ret void
}

; Function Attrs: argmemonly noinline willreturn
define internal fastcc void @"onebyonecpy_hls.p0class.hls::stream<falsification_information, 0>"(%"class.hls::stream<falsification_information, 0>"* noalias align 512 %dst, %"class.hls::stream<falsification_information, 0>"* noalias %src) unnamed_addr #3 {
entry:
  %0 = icmp eq %"class.hls::stream<falsification_information, 0>"* %dst, null
  %1 = icmp eq %"class.hls::stream<falsification_information, 0>"* %src, null
  %2 = or i1 %0, %1
  br i1 %2, label %ret, label %copy

copy:                                             ; preds = %entry
  call fastcc void @"streamcpy_hls.p0class.hls::stream<falsification_information, 0>"(%"class.hls::stream<falsification_information, 0>"* nonnull align 512 %dst, %"class.hls::stream<falsification_information, 0>"* nonnull %src)
  br label %ret

ret:                                              ; preds = %copy, %entry
  ret void
}

; Function Attrs: argmemonly noinline willreturn
define internal fastcc void @"streamcpy_hls.p0class.hls::stream<falsification_information, 0>"(%"class.hls::stream<falsification_information, 0>"* noalias nocapture align 512, %"class.hls::stream<falsification_information, 0>"* noalias nocapture) unnamed_addr #4 {
entry:
  %2 = alloca %"class.hls::stream<falsification_information, 0>"
  br label %empty

empty:                                            ; preds = %push, %entry
  %3 = bitcast %"class.hls::stream<falsification_information, 0>"* %1 to i8*
  %4 = call i1 @fpga_fifo_not_empty_12(i8* %3)
  br i1 %4, label %push, label %ret

push:                                             ; preds = %empty
  %5 = bitcast %"class.hls::stream<falsification_information, 0>"* %2 to i8*
  %6 = bitcast %"class.hls::stream<falsification_information, 0>"* %1 to i8*
  call void @fpga_fifo_pop_12(i8* %5, i8* %6)
  %7 = load volatile %"class.hls::stream<falsification_information, 0>", %"class.hls::stream<falsification_information, 0>"* %2
  %8 = bitcast %"class.hls::stream<falsification_information, 0>"* %2 to i8*
  %9 = bitcast %"class.hls::stream<falsification_information, 0>"* %0 to i8*
  call void @fpga_fifo_push_12(i8* %8, i8* %9)
  br label %empty, !llvm.loop !8

ret:                                              ; preds = %empty
  ret void
}

; Function Attrs: argmemonly noinline willreturn
define internal fastcc void @"onebyonecpy_hls.p0class.hls::stream<static_information, 0>"(%"class.hls::stream<static_information, 0>"* noalias align 512 %dst, %"class.hls::stream<static_information, 0>"* noalias %src) unnamed_addr #3 {
entry:
  %0 = icmp eq %"class.hls::stream<static_information, 0>"* %dst, null
  %1 = icmp eq %"class.hls::stream<static_information, 0>"* %src, null
  %2 = or i1 %0, %1
  br i1 %2, label %ret, label %copy

copy:                                             ; preds = %entry
  call fastcc void @"streamcpy_hls.p0class.hls::stream<static_information, 0>"(%"class.hls::stream<static_information, 0>"* nonnull align 512 %dst, %"class.hls::stream<static_information, 0>"* nonnull %src)
  br label %ret

ret:                                              ; preds = %copy, %entry
  ret void
}

; Function Attrs: argmemonly noinline willreturn
define internal fastcc void @"streamcpy_hls.p0class.hls::stream<static_information, 0>"(%"class.hls::stream<static_information, 0>"* noalias nocapture align 512, %"class.hls::stream<static_information, 0>"* noalias nocapture) unnamed_addr #4 {
entry:
  %2 = alloca %"class.hls::stream<static_information, 0>"
  br label %empty

empty:                                            ; preds = %push, %entry
  %3 = bitcast %"class.hls::stream<static_information, 0>"* %1 to i8*
  %4 = call i1 @fpga_fifo_not_empty_24(i8* %3)
  br i1 %4, label %push, label %ret

push:                                             ; preds = %empty
  %5 = bitcast %"class.hls::stream<static_information, 0>"* %2 to i8*
  %6 = bitcast %"class.hls::stream<static_information, 0>"* %1 to i8*
  call void @fpga_fifo_pop_24(i8* %5, i8* %6)
  %7 = load volatile %"class.hls::stream<static_information, 0>", %"class.hls::stream<static_information, 0>"* %2
  %8 = bitcast %"class.hls::stream<static_information, 0>"* %2 to i8*
  %9 = bitcast %"class.hls::stream<static_information, 0>"* %0 to i8*
  call void @fpga_fifo_push_24(i8* %8, i8* %9)
  br label %empty, !llvm.loop !9

ret:                                              ; preds = %empty
  ret void
}

; Function Attrs: argmemonly noinline willreturn
define internal fastcc void @"onebyonecpy_hls.p0struct.ssdm_int<1, false>"(i1* noalias nocapture align 512 "unpacked"="0.0" %dst, %"struct.ssdm_int<1, false>"* noalias "unpacked"="1" %src) unnamed_addr #3 {
entry:
  %0 = icmp eq %"struct.ssdm_int<1, false>"* %src, null
  br i1 %0, label %ret, label %copy

copy:                                             ; preds = %entry
  call fastcc void @"streamcpy_hls.p0struct.ssdm_int<1, false>"(i1* align 512 %dst, %"struct.ssdm_int<1, false>"* nonnull %src)
  br label %ret

ret:                                              ; preds = %copy, %entry
  ret void
}

; Function Attrs: argmemonly noinline willreturn
define internal fastcc void @"streamcpy_hls.p0struct.ssdm_int<1, false>"(i1* noalias nocapture align 512 "unpacked"="0.0", %"struct.ssdm_int<1, false>"* noalias nocapture "unpacked"="1") unnamed_addr #4 {
entry:
  %2 = alloca %"struct.ssdm_int<1, false>"
  %3 = alloca i1
  br label %empty

empty:                                            ; preds = %push, %entry
  %4 = bitcast %"struct.ssdm_int<1, false>"* %1 to i8*
  %5 = call i1 @fpga_fifo_not_empty_1(i8* %4)
  br i1 %5, label %push, label %ret

push:                                             ; preds = %empty
  %6 = bitcast %"struct.ssdm_int<1, false>"* %2 to i8*
  %7 = bitcast %"struct.ssdm_int<1, false>"* %1 to i8*
  call void @fpga_fifo_pop_1(i8* %6, i8* %7)
  %8 = load volatile %"struct.ssdm_int<1, false>", %"struct.ssdm_int<1, false>"* %2
  %.evi = extractvalue %"struct.ssdm_int<1, false>" %8, 0
  store i1 %.evi, i1* %3
  %9 = bitcast i1* %3 to i8*
  %10 = bitcast i1* %0 to i8*
  call void @fpga_fifo_push_1(i8* %9, i8* %10)
  br label %empty, !llvm.loop !10

ret:                                              ; preds = %empty
  ret void
}

; Function Attrs: argmemonly noinline willreturn
define internal fastcc void @"onebyonecpy_hls.p0class.hls::stream<ap_uint<178>, 0>"(%"class.hls::stream<ap_uint<178>, 0>"* noalias "unpacked"="0" %dst, i178* noalias nocapture align 512 "unpacked"="1.0" %src) unnamed_addr #3 {
entry:
  %0 = icmp eq %"class.hls::stream<ap_uint<178>, 0>"* %dst, null
  br i1 %0, label %ret, label %copy

copy:                                             ; preds = %entry
  call fastcc void @"streamcpy_hls.p0class.hls::stream<ap_uint<178>, 0>"(%"class.hls::stream<ap_uint<178>, 0>"* nonnull %dst, i178* align 512 %src)
  br label %ret

ret:                                              ; preds = %copy, %entry
  ret void
}

; Function Attrs: argmemonly noinline willreturn
define internal fastcc void @"streamcpy_hls.p0class.hls::stream<ap_uint<178>, 0>"(%"class.hls::stream<ap_uint<178>, 0>"* noalias nocapture "unpacked"="0", i178* noalias nocapture align 512 "unpacked"="1.0") unnamed_addr #4 {
entry:
  %2 = alloca i178
  %3 = alloca %"class.hls::stream<ap_uint<178>, 0>"
  br label %empty

empty:                                            ; preds = %push, %entry
  %4 = bitcast i178* %1 to i8*
  %5 = call i1 @fpga_fifo_not_empty_32(i8* %4)
  br i1 %5, label %push, label %ret

push:                                             ; preds = %empty
  %6 = bitcast i178* %2 to i8*
  %7 = bitcast i178* %1 to i8*
  call void @fpga_fifo_pop_32(i8* %6, i8* %7)
  %8 = bitcast i178* %2 to i184*
  %9 = load i184, i184* %8
  %10 = trunc i184 %9 to i178
  %.ivi = insertvalue %"class.hls::stream<ap_uint<178>, 0>" undef, i178 %10, 0, 0, 0, 0
  store %"class.hls::stream<ap_uint<178>, 0>" %.ivi, %"class.hls::stream<ap_uint<178>, 0>"* %3
  %11 = bitcast %"class.hls::stream<ap_uint<178>, 0>"* %3 to i8*
  %12 = bitcast %"class.hls::stream<ap_uint<178>, 0>"* %0 to i8*
  call void @fpga_fifo_push_32(i8* %11, i8* %12)
  br label %empty, !llvm.loop !11

ret:                                              ; preds = %empty
  ret void
}

; Function Attrs: argmemonly noinline willreturn
define internal fastcc void @"onebyonecpy_hls.p0class.hls::stream<ap_uint<168>, 0>"(i168* noalias nocapture align 512 "unpacked"="0.0" %dst, %"class.hls::stream<ap_uint<168>, 0>"* noalias "unpacked"="1" %src) unnamed_addr #3 {
entry:
  %0 = icmp eq %"class.hls::stream<ap_uint<168>, 0>"* %src, null
  br i1 %0, label %ret, label %copy

copy:                                             ; preds = %entry
  call fastcc void @"streamcpy_hls.p0class.hls::stream<ap_uint<168>, 0>"(i168* align 512 %dst, %"class.hls::stream<ap_uint<168>, 0>"* nonnull %src)
  br label %ret

ret:                                              ; preds = %copy, %entry
  ret void
}

; Function Attrs: argmemonly noinline willreturn
define internal fastcc void @"streamcpy_hls.p0class.hls::stream<ap_uint<168>, 0>"(i168* noalias nocapture align 512 "unpacked"="0.0", %"class.hls::stream<ap_uint<168>, 0>"* noalias nocapture "unpacked"="1") unnamed_addr #4 {
entry:
  %2 = alloca %"class.hls::stream<ap_uint<168>, 0>"
  %3 = alloca i168
  br label %empty

empty:                                            ; preds = %push, %entry
  %4 = bitcast %"class.hls::stream<ap_uint<168>, 0>"* %1 to i8*
  %5 = call i1 @fpga_fifo_not_empty_32(i8* %4)
  br i1 %5, label %push, label %ret

push:                                             ; preds = %empty
  %6 = bitcast %"class.hls::stream<ap_uint<168>, 0>"* %2 to i8*
  %7 = bitcast %"class.hls::stream<ap_uint<168>, 0>"* %1 to i8*
  call void @fpga_fifo_pop_32(i8* %6, i8* %7)
  %8 = load volatile %"class.hls::stream<ap_uint<168>, 0>", %"class.hls::stream<ap_uint<168>, 0>"* %2
  %.evi = extractvalue %"class.hls::stream<ap_uint<168>, 0>" %8, 0, 0, 0, 0
  store i168 %.evi, i168* %3
  %9 = bitcast i168* %3 to i8*
  %10 = bitcast i168* %0 to i8*
  call void @fpga_fifo_push_32(i8* %9, i8* %10)
  br label %empty, !llvm.loop !12

ret:                                              ; preds = %empty
  ret void
}

; Function Attrs: argmemonly noinline willreturn
define internal fastcc void @copy_out(%"class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>"* noalias "unpacked"="0", i32* noalias nocapture align 512 "unpacked"="1.0", %"struct.ssdm_int<32, false>"* noalias "unpacked"="2", i32* noalias nocapture align 512 "unpacked"="3.0", %"class.hls::stream<dynamic_information_init, 0>"* noalias "unpacked"="4", %"class.hls::stream<dynamic_information_init, 0>"* noalias align 512 "unpacked"="5", %"class.hls::stream<falsification_information, 0>"* noalias "unpacked"="6", %"class.hls::stream<falsification_information, 0>"* noalias align 512 "unpacked"="7", %"class.hls::stream<static_information, 0>"* noalias "unpacked"="8", %"class.hls::stream<static_information, 0>"* noalias align 512 "unpacked"="9", %"struct.ssdm_int<1, false>"* noalias "unpacked"="10", i1* noalias nocapture align 512 "unpacked"="11.0", %"class.hls::stream<ap_uint<178>, 0>"* noalias "unpacked"="12", i178* noalias nocapture align 512 "unpacked"="13.0", %"class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>"* noalias "unpacked"="14", i32* noalias nocapture align 512 "unpacked"="15.0", %"class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>"* noalias "unpacked"="16", i32* noalias nocapture align 512 "unpacked"="17.0", %"class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>"* noalias "unpacked"="18", i32* noalias nocapture align 512 "unpacked"="19.0", %"class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>"* noalias "unpacked"="20", i32* noalias nocapture align 512 "unpacked"="21.0", %"class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>"* noalias "unpacked"="22", i32* noalias nocapture align 512 "unpacked"="23.0", %"class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>"* noalias "unpacked"="24", i32* noalias nocapture align 512 "unpacked"="25.0", %"class.hls::stream<ap_uint<168>, 0>"* noalias "unpacked"="26", i168* noalias nocapture align 512 "unpacked"="27.0") unnamed_addr #5 {
entry:
  call fastcc void @"onebyonecpy_hls.p0class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>.681"(%"class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>"* %0, i32* align 512 %1)
  call fastcc void @"onebyonecpy_hls.p0struct.ssdm_int<32, false>"(%"struct.ssdm_int<32, false>"* %2, i32* align 512 %3)
  call fastcc void @"onebyonecpy_hls.p0class.hls::stream<dynamic_information_init, 0>"(%"class.hls::stream<dynamic_information_init, 0>"* %4, %"class.hls::stream<dynamic_information_init, 0>"* align 512 %5)
  call fastcc void @"onebyonecpy_hls.p0class.hls::stream<falsification_information, 0>"(%"class.hls::stream<falsification_information, 0>"* %6, %"class.hls::stream<falsification_information, 0>"* align 512 %7)
  call fastcc void @"onebyonecpy_hls.p0class.hls::stream<static_information, 0>"(%"class.hls::stream<static_information, 0>"* %8, %"class.hls::stream<static_information, 0>"* align 512 %9)
  call fastcc void @"onebyonecpy_hls.p0struct.ssdm_int<1, false>.732"(%"struct.ssdm_int<1, false>"* %10, i1* align 512 %11)
  call fastcc void @"onebyonecpy_hls.p0class.hls::stream<ap_uint<178>, 0>"(%"class.hls::stream<ap_uint<178>, 0>"* %12, i178* align 512 %13)
  call fastcc void @"onebyonecpy_hls.p0class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>.681"(%"class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>"* %14, i32* align 512 %15)
  call fastcc void @"onebyonecpy_hls.p0class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>.681"(%"class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>"* %16, i32* align 512 %17)
  call fastcc void @"onebyonecpy_hls.p0class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>.681"(%"class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>"* %18, i32* align 512 %19)
  call fastcc void @"onebyonecpy_hls.p0class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>.681"(%"class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>"* %20, i32* align 512 %21)
  call fastcc void @"onebyonecpy_hls.p0class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>.681"(%"class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>"* %22, i32* align 512 %23)
  call fastcc void @"onebyonecpy_hls.p0class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>.681"(%"class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>"* %24, i32* align 512 %25)
  call fastcc void @"onebyonecpy_hls.p0class.hls::stream<ap_uint<168>, 0>.656"(%"class.hls::stream<ap_uint<168>, 0>"* %26, i168* align 512 %27)
  ret void
}

; Function Attrs: argmemonly noinline willreturn
define internal fastcc void @"onebyonecpy_hls.p0class.hls::stream<ap_uint<168>, 0>.656"(%"class.hls::stream<ap_uint<168>, 0>"* noalias "unpacked"="0" %dst, i168* noalias nocapture align 512 "unpacked"="1.0" %src) unnamed_addr #3 {
entry:
  %0 = icmp eq %"class.hls::stream<ap_uint<168>, 0>"* %dst, null
  br i1 %0, label %ret, label %copy

copy:                                             ; preds = %entry
  call fastcc void @"streamcpy_hls.p0class.hls::stream<ap_uint<168>, 0>.659"(%"class.hls::stream<ap_uint<168>, 0>"* nonnull %dst, i168* align 512 %src)
  br label %ret

ret:                                              ; preds = %copy, %entry
  ret void
}

; Function Attrs: argmemonly noinline willreturn
define internal fastcc void @"streamcpy_hls.p0class.hls::stream<ap_uint<168>, 0>.659"(%"class.hls::stream<ap_uint<168>, 0>"* noalias nocapture "unpacked"="0", i168* noalias nocapture align 512 "unpacked"="1.0") unnamed_addr #4 {
entry:
  %2 = alloca i168
  %3 = alloca %"class.hls::stream<ap_uint<168>, 0>"
  br label %empty

empty:                                            ; preds = %push, %entry
  %4 = bitcast i168* %1 to i8*
  %5 = call i1 @fpga_fifo_not_empty_32(i8* %4)
  br i1 %5, label %push, label %ret

push:                                             ; preds = %empty
  %6 = bitcast i168* %2 to i8*
  %7 = bitcast i168* %1 to i8*
  call void @fpga_fifo_pop_32(i8* %6, i8* %7)
  %8 = load volatile i168, i168* %2
  %.ivi = insertvalue %"class.hls::stream<ap_uint<168>, 0>" undef, i168 %8, 0, 0, 0, 0
  store %"class.hls::stream<ap_uint<168>, 0>" %.ivi, %"class.hls::stream<ap_uint<168>, 0>"* %3
  %9 = bitcast %"class.hls::stream<ap_uint<168>, 0>"* %3 to i8*
  %10 = bitcast %"class.hls::stream<ap_uint<168>, 0>"* %0 to i8*
  call void @fpga_fifo_push_32(i8* %9, i8* %10)
  br label %empty, !llvm.loop !13

ret:                                              ; preds = %empty
  ret void
}

; Function Attrs: argmemonly noinline willreturn
define internal fastcc void @"onebyonecpy_hls.p0class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>"(i32* noalias nocapture align 512 "unpacked"="0.0" %dst, %"class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>"* noalias "unpacked"="1" %src) unnamed_addr #3 {
entry:
  %0 = icmp eq %"class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>"* %src, null
  br i1 %0, label %ret, label %copy

copy:                                             ; preds = %entry
  call fastcc void @"streamcpy_hls.p0class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>.673"(i32* align 512 %dst, %"class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>"* nonnull %src)
  br label %ret

ret:                                              ; preds = %copy, %entry
  ret void
}

; Function Attrs: argmemonly noinline willreturn
define internal fastcc void @"streamcpy_hls.p0class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>.673"(i32* noalias nocapture align 512 "unpacked"="0.0", %"class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>"* noalias nocapture "unpacked"="1") unnamed_addr #4 {
entry:
  %2 = alloca %"class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>"
  %3 = alloca i32
  br label %empty

empty:                                            ; preds = %push, %entry
  %4 = bitcast %"class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>"* %1 to i8*
  %5 = call i1 @fpga_fifo_not_empty_4(i8* %4)
  br i1 %5, label %push, label %ret

push:                                             ; preds = %empty
  %6 = bitcast %"class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>"* %2 to i8*
  %7 = bitcast %"class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>"* %1 to i8*
  call void @fpga_fifo_pop_4(i8* %6, i8* %7)
  %8 = load volatile %"class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>", %"class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>"* %2
  %.evi = extractvalue %"class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>" %8, 0, 0, 0, 0
  store i32 %.evi, i32* %3
  %9 = bitcast i32* %3 to i8*
  %10 = bitcast i32* %0 to i8*
  call void @fpga_fifo_push_4(i8* %9, i8* %10)
  br label %empty, !llvm.loop !14

ret:                                              ; preds = %empty
  ret void
}

; Function Attrs: argmemonly noinline willreturn
define internal fastcc void @"onebyonecpy_hls.p0class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>.681"(%"class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>"* noalias "unpacked"="0" %dst, i32* noalias nocapture align 512 "unpacked"="1.0" %src) unnamed_addr #3 {
entry:
  %0 = icmp eq %"class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>"* %dst, null
  br i1 %0, label %ret, label %copy

copy:                                             ; preds = %entry
  call fastcc void @"streamcpy_hls.p0class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>.684"(%"class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>"* nonnull %dst, i32* align 512 %src)
  br label %ret

ret:                                              ; preds = %copy, %entry
  ret void
}

; Function Attrs: argmemonly noinline willreturn
define internal fastcc void @"streamcpy_hls.p0class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>.684"(%"class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>"* noalias nocapture "unpacked"="0", i32* noalias nocapture align 512 "unpacked"="1.0") unnamed_addr #4 {
entry:
  %2 = alloca i32
  %3 = alloca %"class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>"
  br label %empty

empty:                                            ; preds = %push, %entry
  %4 = bitcast i32* %1 to i8*
  %5 = call i1 @fpga_fifo_not_empty_4(i8* %4)
  br i1 %5, label %push, label %ret

push:                                             ; preds = %empty
  %6 = bitcast i32* %2 to i8*
  %7 = bitcast i32* %1 to i8*
  call void @fpga_fifo_pop_4(i8* %6, i8* %7)
  %8 = load volatile i32, i32* %2
  %.ivi = insertvalue %"class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>" undef, i32 %8, 0, 0, 0, 0
  store %"class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>" %.ivi, %"class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>"* %3
  %9 = bitcast %"class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>"* %3 to i8*
  %10 = bitcast %"class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>"* %0 to i8*
  call void @fpga_fifo_push_4(i8* %9, i8* %10)
  br label %empty, !llvm.loop !15

ret:                                              ; preds = %empty
  ret void
}

; Function Attrs: argmemonly noinline willreturn
define internal fastcc void @"onebyonecpy_hls.p0class.hls::stream<ap_uint<178>, 0>.718"(i178* noalias nocapture align 512 "unpacked"="0.0" %dst, %"class.hls::stream<ap_uint<178>, 0>"* noalias "unpacked"="1" %src) unnamed_addr #3 {
entry:
  %0 = icmp eq %"class.hls::stream<ap_uint<178>, 0>"* %src, null
  br i1 %0, label %ret, label %copy

copy:                                             ; preds = %entry
  call fastcc void @"streamcpy_hls.p0class.hls::stream<ap_uint<178>, 0>.721"(i178* align 512 %dst, %"class.hls::stream<ap_uint<178>, 0>"* nonnull %src)
  br label %ret

ret:                                              ; preds = %copy, %entry
  ret void
}

; Function Attrs: argmemonly noinline willreturn
define internal fastcc void @"streamcpy_hls.p0class.hls::stream<ap_uint<178>, 0>.721"(i178* noalias nocapture align 512 "unpacked"="0.0", %"class.hls::stream<ap_uint<178>, 0>"* noalias nocapture "unpacked"="1") unnamed_addr #4 {
entry:
  %2 = alloca %"class.hls::stream<ap_uint<178>, 0>"
  %3 = alloca i178
  br label %empty

empty:                                            ; preds = %push, %entry
  %4 = bitcast %"class.hls::stream<ap_uint<178>, 0>"* %1 to i8*
  %5 = call i1 @fpga_fifo_not_empty_32(i8* %4)
  br i1 %5, label %push, label %ret

push:                                             ; preds = %empty
  %6 = bitcast %"class.hls::stream<ap_uint<178>, 0>"* %2 to i8*
  %7 = bitcast %"class.hls::stream<ap_uint<178>, 0>"* %1 to i8*
  call void @fpga_fifo_pop_32(i8* %6, i8* %7)
  %8 = load volatile %"class.hls::stream<ap_uint<178>, 0>", %"class.hls::stream<ap_uint<178>, 0>"* %2
  %.evi = extractvalue %"class.hls::stream<ap_uint<178>, 0>" %8, 0, 0, 0, 0
  store i178 %.evi, i178* %3
  %9 = bitcast i178* %3 to i8*
  %10 = bitcast i178* %0 to i8*
  call void @fpga_fifo_push_32(i8* %9, i8* %10)
  br label %empty, !llvm.loop !16

ret:                                              ; preds = %empty
  ret void
}

; Function Attrs: argmemonly noinline willreturn
define internal fastcc void @"onebyonecpy_hls.p0struct.ssdm_int<1, false>.732"(%"struct.ssdm_int<1, false>"* noalias "unpacked"="0" %dst, i1* noalias nocapture align 512 "unpacked"="1.0" %src) unnamed_addr #3 {
entry:
  %0 = icmp eq %"struct.ssdm_int<1, false>"* %dst, null
  br i1 %0, label %ret, label %copy

copy:                                             ; preds = %entry
  call fastcc void @"streamcpy_hls.p0struct.ssdm_int<1, false>.735"(%"struct.ssdm_int<1, false>"* nonnull %dst, i1* align 512 %src)
  br label %ret

ret:                                              ; preds = %copy, %entry
  ret void
}

; Function Attrs: argmemonly noinline willreturn
define internal fastcc void @"streamcpy_hls.p0struct.ssdm_int<1, false>.735"(%"struct.ssdm_int<1, false>"* noalias nocapture "unpacked"="0", i1* noalias nocapture align 512 "unpacked"="1.0") unnamed_addr #4 {
entry:
  %2 = alloca i1
  %3 = alloca %"struct.ssdm_int<1, false>"
  br label %empty

empty:                                            ; preds = %push, %entry
  %4 = bitcast i1* %1 to i8*
  %5 = call i1 @fpga_fifo_not_empty_1(i8* %4)
  br i1 %5, label %push, label %ret

push:                                             ; preds = %empty
  %6 = bitcast i1* %2 to i8*
  %7 = bitcast i1* %1 to i8*
  call void @fpga_fifo_pop_1(i8* %6, i8* %7)
  %8 = bitcast i1* %2 to i8*
  %9 = load i8, i8* %8
  %10 = trunc i8 %9 to i1
  %.ivi = insertvalue %"struct.ssdm_int<1, false>" undef, i1 %10, 0
  store %"struct.ssdm_int<1, false>" %.ivi, %"struct.ssdm_int<1, false>"* %3
  %11 = bitcast %"struct.ssdm_int<1, false>"* %3 to i8*
  %12 = bitcast %"struct.ssdm_int<1, false>"* %0 to i8*
  call void @fpga_fifo_push_1(i8* %11, i8* %12)
  br label %empty, !llvm.loop !17

ret:                                              ; preds = %empty
  ret void
}

; Function Attrs: argmemonly noinline willreturn
define internal fastcc void @"onebyonecpy_hls.p0struct.ssdm_int<32, false>.744"(i32* noalias nocapture align 512 "unpacked"="0.0" %dst, %"struct.ssdm_int<32, false>"* noalias "unpacked"="1" %src) unnamed_addr #3 {
entry:
  %0 = icmp eq %"struct.ssdm_int<32, false>"* %src, null
  br i1 %0, label %ret, label %copy

copy:                                             ; preds = %entry
  call fastcc void @"streamcpy_hls.p0struct.ssdm_int<32, false>.747"(i32* align 512 %dst, %"struct.ssdm_int<32, false>"* nonnull %src)
  br label %ret

ret:                                              ; preds = %copy, %entry
  ret void
}

; Function Attrs: argmemonly noinline willreturn
define internal fastcc void @"streamcpy_hls.p0struct.ssdm_int<32, false>.747"(i32* noalias nocapture align 512 "unpacked"="0.0", %"struct.ssdm_int<32, false>"* noalias nocapture "unpacked"="1") unnamed_addr #4 {
entry:
  %2 = alloca %"struct.ssdm_int<32, false>"
  %3 = alloca i32
  br label %empty

empty:                                            ; preds = %push, %entry
  %4 = bitcast %"struct.ssdm_int<32, false>"* %1 to i8*
  %5 = call i1 @fpga_fifo_not_empty_4(i8* %4)
  br i1 %5, label %push, label %ret

push:                                             ; preds = %empty
  %6 = bitcast %"struct.ssdm_int<32, false>"* %2 to i8*
  %7 = bitcast %"struct.ssdm_int<32, false>"* %1 to i8*
  call void @fpga_fifo_pop_4(i8* %6, i8* %7)
  %8 = load volatile %"struct.ssdm_int<32, false>", %"struct.ssdm_int<32, false>"* %2
  %.evi = extractvalue %"struct.ssdm_int<32, false>" %8, 0
  store i32 %.evi, i32* %3
  %9 = bitcast i32* %3 to i8*
  %10 = bitcast i32* %0 to i8*
  call void @fpga_fifo_push_4(i8* %9, i8* %10)
  br label %empty, !llvm.loop !18

ret:                                              ; preds = %empty
  ret void
}

declare void @apatb_FPGA_simulator_hw(i32*, i32*, %"class.hls::stream<dynamic_information_init, 0>"*, %"class.hls::stream<falsification_information, 0>"*, %"class.hls::stream<static_information, 0>"*, i1*, i178*, i32*, i32*, i32*, i32*, i32*, i32*, i168*)

; Function Attrs: argmemonly noinline willreturn
define internal fastcc void @copy_back(%"class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>"* noalias "unpacked"="0", i32* noalias nocapture align 512 "unpacked"="1.0", %"struct.ssdm_int<32, false>"* noalias "unpacked"="2", i32* noalias nocapture align 512 "unpacked"="3.0", %"class.hls::stream<dynamic_information_init, 0>"* noalias "unpacked"="4", %"class.hls::stream<dynamic_information_init, 0>"* noalias align 512 "unpacked"="5", %"class.hls::stream<falsification_information, 0>"* noalias "unpacked"="6", %"class.hls::stream<falsification_information, 0>"* noalias align 512 "unpacked"="7", %"class.hls::stream<static_information, 0>"* noalias "unpacked"="8", %"class.hls::stream<static_information, 0>"* noalias align 512 "unpacked"="9", %"struct.ssdm_int<1, false>"* noalias "unpacked"="10", i1* noalias nocapture align 512 "unpacked"="11.0", %"class.hls::stream<ap_uint<178>, 0>"* noalias "unpacked"="12", i178* noalias nocapture align 512 "unpacked"="13.0", %"class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>"* noalias "unpacked"="14", i32* noalias nocapture align 512 "unpacked"="15.0", %"class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>"* noalias "unpacked"="16", i32* noalias nocapture align 512 "unpacked"="17.0", %"class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>"* noalias "unpacked"="18", i32* noalias nocapture align 512 "unpacked"="19.0", %"class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>"* noalias "unpacked"="20", i32* noalias nocapture align 512 "unpacked"="21.0", %"class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>"* noalias "unpacked"="22", i32* noalias nocapture align 512 "unpacked"="23.0", %"class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>"* noalias "unpacked"="24", i32* noalias nocapture align 512 "unpacked"="25.0", %"class.hls::stream<ap_uint<168>, 0>"* noalias "unpacked"="26", i168* noalias nocapture align 512 "unpacked"="27.0") unnamed_addr #5 {
entry:
  call fastcc void @"onebyonecpy_hls.p0class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>.681"(%"class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>"* %0, i32* align 512 %1)
  call fastcc void @"onebyonecpy_hls.p0struct.ssdm_int<32, false>"(%"struct.ssdm_int<32, false>"* %2, i32* align 512 %3)
  call fastcc void @"onebyonecpy_hls.p0class.hls::stream<dynamic_information_init, 0>"(%"class.hls::stream<dynamic_information_init, 0>"* %4, %"class.hls::stream<dynamic_information_init, 0>"* align 512 %5)
  call fastcc void @"onebyonecpy_hls.p0class.hls::stream<falsification_information, 0>"(%"class.hls::stream<falsification_information, 0>"* %6, %"class.hls::stream<falsification_information, 0>"* align 512 %7)
  call fastcc void @"onebyonecpy_hls.p0class.hls::stream<static_information, 0>"(%"class.hls::stream<static_information, 0>"* %8, %"class.hls::stream<static_information, 0>"* align 512 %9)
  call fastcc void @"onebyonecpy_hls.p0struct.ssdm_int<1, false>.732"(%"struct.ssdm_int<1, false>"* %10, i1* align 512 %11)
  call fastcc void @"onebyonecpy_hls.p0class.hls::stream<ap_uint<178>, 0>"(%"class.hls::stream<ap_uint<178>, 0>"* %12, i178* align 512 %13)
  call fastcc void @"onebyonecpy_hls.p0class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>.681"(%"class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>"* %14, i32* align 512 %15)
  call fastcc void @"onebyonecpy_hls.p0class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>.681"(%"class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>"* %16, i32* align 512 %17)
  call fastcc void @"onebyonecpy_hls.p0class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>.681"(%"class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>"* %18, i32* align 512 %19)
  call fastcc void @"onebyonecpy_hls.p0class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>.681"(%"class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>"* %20, i32* align 512 %21)
  call fastcc void @"onebyonecpy_hls.p0class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>.681"(%"class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>"* %22, i32* align 512 %23)
  call fastcc void @"onebyonecpy_hls.p0class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>.681"(%"class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>"* %24, i32* align 512 %25)
  call fastcc void @"onebyonecpy_hls.p0class.hls::stream<ap_uint<168>, 0>.656"(%"class.hls::stream<ap_uint<168>, 0>"* %26, i168* align 512 %27)
  ret void
}

define void @FPGA_simulator_hw_stub_wrapper(i32*, i32*, %"class.hls::stream<dynamic_information_init, 0>"*, %"class.hls::stream<falsification_information, 0>"*, %"class.hls::stream<static_information, 0>"*, i1*, i178*, i32*, i32*, i32*, i32*, i32*, i32*, i168*) #6 {
entry:
  %14 = alloca %"class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>"
  %15 = alloca %"struct.ssdm_int<32, false>"
  %16 = alloca %"struct.ssdm_int<1, false>"
  %17 = alloca %"class.hls::stream<ap_uint<178>, 0>"
  %18 = alloca %"class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>"
  %19 = alloca %"class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>"
  %20 = alloca %"class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>"
  %21 = alloca %"class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>"
  %22 = alloca %"class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>"
  %23 = alloca %"class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>"
  %24 = alloca %"class.hls::stream<ap_uint<168>, 0>"
  call void @copy_out(%"class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>"* %14, i32* %0, %"struct.ssdm_int<32, false>"* %15, i32* %1, %"class.hls::stream<dynamic_information_init, 0>"* null, %"class.hls::stream<dynamic_information_init, 0>"* %2, %"class.hls::stream<falsification_information, 0>"* null, %"class.hls::stream<falsification_information, 0>"* %3, %"class.hls::stream<static_information, 0>"* null, %"class.hls::stream<static_information, 0>"* %4, %"struct.ssdm_int<1, false>"* %16, i1* %5, %"class.hls::stream<ap_uint<178>, 0>"* %17, i178* %6, %"class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>"* %18, i32* %7, %"class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>"* %19, i32* %8, %"class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>"* %20, i32* %9, %"class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>"* %21, i32* %10, %"class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>"* %22, i32* %11, %"class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>"* %23, i32* %12, %"class.hls::stream<ap_uint<168>, 0>"* %24, i168* %13)
  call void @FPGA_simulator_hw_stub(%"class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>"* %14, %"struct.ssdm_int<32, false>"* %15, %"class.hls::stream<dynamic_information_init, 0>"* %2, %"class.hls::stream<falsification_information, 0>"* %3, %"class.hls::stream<static_information, 0>"* %4, %"struct.ssdm_int<1, false>"* %16, %"class.hls::stream<ap_uint<178>, 0>"* %17, %"class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>"* %18, %"class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>"* %19, %"class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>"* %20, %"class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>"* %21, %"class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>"* %22, %"class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>"* %23, %"class.hls::stream<ap_uint<168>, 0>"* %24)
  call void @copy_in(%"class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>"* %14, i32* %0, %"struct.ssdm_int<32, false>"* %15, i32* %1, %"class.hls::stream<dynamic_information_init, 0>"* null, %"class.hls::stream<dynamic_information_init, 0>"* %2, %"class.hls::stream<falsification_information, 0>"* null, %"class.hls::stream<falsification_information, 0>"* %3, %"class.hls::stream<static_information, 0>"* null, %"class.hls::stream<static_information, 0>"* %4, %"struct.ssdm_int<1, false>"* %16, i1* %5, %"class.hls::stream<ap_uint<178>, 0>"* %17, i178* %6, %"class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>"* %18, i32* %7, %"class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>"* %19, i32* %8, %"class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>"* %20, i32* %9, %"class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>"* %21, i32* %10, %"class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>"* %22, i32* %11, %"class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>"* %23, i32* %12, %"class.hls::stream<ap_uint<168>, 0>"* %24, i168* %13)
  ret void
}

declare void @FPGA_simulator_hw_stub(%"class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>"*, %"struct.ssdm_int<32, false>"*, %"class.hls::stream<dynamic_information_init, 0>"*, %"class.hls::stream<falsification_information, 0>"*, %"class.hls::stream<static_information, 0>"*, %"struct.ssdm_int<1, false>"*, %"class.hls::stream<ap_uint<178>, 0>"*, %"class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>"*, %"class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>"*, %"class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>"*, %"class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>"*, %"class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>"*, %"class.hls::stream<ap_ufixed<32, 24, AP_TRN, AP_WRAP, 0>, 0>"*, %"class.hls::stream<ap_uint<168>, 0>"*)

declare i1 @fpga_fifo_not_empty_4(i8*)

declare i1 @fpga_fifo_not_empty_12(i8*)

declare i1 @fpga_fifo_not_empty_24(i8*)

declare i1 @fpga_fifo_not_empty_1(i8*)

declare i1 @fpga_fifo_not_empty_32(i8*)

declare void @fpga_fifo_pop_4(i8*, i8*)

declare void @fpga_fifo_pop_1(i8*, i8*)

declare void @fpga_fifo_pop_12(i8*, i8*)

declare void @fpga_fifo_pop_24(i8*, i8*)

declare void @fpga_fifo_pop_32(i8*, i8*)

declare void @fpga_fifo_push_4(i8*, i8*)

declare void @fpga_fifo_push_1(i8*, i8*)

declare void @fpga_fifo_push_12(i8*, i8*)

declare void @fpga_fifo_push_24(i8*, i8*)

declare void @fpga_fifo_push_32(i8*, i8*)

attributes #0 = { inaccessiblememonly nounwind willreturn }
attributes #1 = { noinline "fpga.wrapper.func"="wrapper" }
attributes #2 = { argmemonly noinline willreturn "fpga.wrapper.func"="copyin" }
attributes #3 = { argmemonly noinline willreturn "fpga.wrapper.func"="onebyonecpy_hls" }
attributes #4 = { argmemonly noinline willreturn "fpga.wrapper.func"="streamcpy_hls" }
attributes #5 = { argmemonly noinline willreturn "fpga.wrapper.func"="copyout" }
attributes #6 = { "fpga.wrapper.func"="stub" }
attributes #7 = { inaccessiblememonly nounwind willreturn "xlx.port.bitwidth"="32" "xlx.source"="user" }
attributes #8 = { inaccessiblememonly nounwind willreturn "xlx.port.bitwidth"="96" "xlx.source"="user" }
attributes #9 = { inaccessiblememonly nounwind willreturn "xlx.port.bitwidth"="192" "xlx.source"="user" }
attributes #10 = { inaccessiblememonly nounwind willreturn "xlx.port.bitwidth"="8" "xlx.source"="user" }
attributes #11 = { inaccessiblememonly nounwind willreturn "xlx.port.bitwidth"="256" "xlx.source"="user" }

!llvm.dbg.cu = !{}
!llvm.ident = !{!0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0}
!llvm.module.flags = !{!1, !2, !3}
!blackbox_cfg = !{!4}

!0 = !{!"clang version 7.0.0 "}
!1 = !{i32 2, !"Dwarf Version", i32 4}
!2 = !{i32 2, !"Debug Info Version", i32 3}
!3 = !{i32 1, !"wchar_size", i32 4}
!4 = !{}
!5 = distinct !{!5, !6}
!6 = !{!"llvm.loop.rotate.disable"}
!7 = distinct !{!7, !6}
!8 = distinct !{!8, !6}
!9 = distinct !{!9, !6}
!10 = distinct !{!10, !6}
!11 = distinct !{!11, !6}
!12 = distinct !{!12, !6}
!13 = distinct !{!13, !6}
!14 = distinct !{!14, !6}
!15 = distinct !{!15, !6}
!16 = distinct !{!16, !6}
!17 = distinct !{!17, !6}
!18 = distinct !{!18, !6}
