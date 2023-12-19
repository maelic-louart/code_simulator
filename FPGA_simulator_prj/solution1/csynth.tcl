############################################################
## This file is generated automatically by Vitis HLS.
## Please DO NOT edit it.
## Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
## Copyright 2022-2023 Advanced Micro Devices, Inc. All Rights Reserved.
############################################################
open_project FPGA_simulator_prj
set_top FPGA_simulator
add_files CPS.cpp
add_files FPGA_simulator.cpp
add_files FPGA_simulator.h
add_files channel.cpp
add_files emitter.cpp
add_files piloting.cpp
add_files receiver.cpp
add_files -tb FPGA_simulator_tb.cpp
add_files -tb data
open_solution "solution1" -flow_target vivado
set_part {xc7vx485tffg1157-1}
create_clock -period 10 -name default
#source "./FPGA_simulator_prj/solution1/directives.tcl"
csynth_design
