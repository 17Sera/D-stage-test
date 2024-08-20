// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_fst_c.h"
#include "Vysyx_23060219_top__Syms.h"


VL_ATTR_COLD void Vysyx_23060219_top___024root__trace_init_sub__TOP__0(Vysyx_23060219_top___024root* vlSelf, VerilatedFst* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_23060219_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_23060219_top___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+166,"clk",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+167,"rst",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+168,"mstatus",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+169,"mepc",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+170,"mtvec",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+171,"mcause",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->pushNamePrefix("ysyx_23060219_top ");
    tracep->declBit(c+166,"clk",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+167,"rst",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+168,"mstatus",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+169,"mepc",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+170,"mtvec",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+171,"mcause",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+15,"rs1",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBus(c+16,"rs2",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBus(c+17,"rd",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBus(c+18,"funct3",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 2,0);
    tracep->declBus(c+19,"funct7",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 6,0);
    tracep->declBus(c+20,"inst",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+21,"pc",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+22,"IType",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 2,0);
    tracep->declBit(c+23,"is_ecall",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+24,"csr_wen",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+25,"reg_wen",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+26,"mem_wen",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+27,"mem_ren",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+28,"wmask",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 7,0);
    tracep->declBus(c+29,"rmask",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 2,0);
    tracep->declBit(c+30,"m1",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+31,"m2",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 1,0);
    tracep->declBit(c+32,"m3",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+33,"m4",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+34,"m5",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 1,0);
    tracep->declBus(c+35,"aluc",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBus(c+36,"PCadd4",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+37,"result",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+38,"reg_in",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+39,"src1",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+40,"src2",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+41,"imm32",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+42,"num1",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+43,"num2",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+44,"mem_rdata",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+45,"csr_npc",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+46,"csr_val",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->pushNamePrefix("PC_inst ");
    tracep->declBit(c+166,"clk",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+167,"rst",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+30,"m1",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+31,"m2",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 1,0);
    tracep->declBus(c+37,"result",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+41,"imm32",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+45,"csr_npc",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+36,"PCadd4",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+21,"pc",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+47,"npc",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+48,"npc_temp",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+49,"PCaddIMM32",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->pushNamePrefix("i1 ");
    tracep->declBus(c+172,"NR_KEY",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
    tracep->declBus(c+173,"KEY_LEN",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
    tracep->declBus(c+174,"DATA_LEN",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
    tracep->declBus(c+47,"out",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+50,"key",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 0,0);
    tracep->declArray(c+51,"lut",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 65,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+172,"NR_KEY",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
    tracep->declBus(c+173,"KEY_LEN",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
    tracep->declBus(c+174,"DATA_LEN",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
    tracep->declBus(c+175,"HAS_DEFAULT",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
    tracep->declBus(c+47,"out",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+50,"key",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 0,0);
    tracep->declBus(c+176,"default_out",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declArray(c+51,"lut",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 65,0);
    tracep->declBus(c+177,"PAIR_LEN",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
    for (int i = 0; i < 2; ++i) {
        tracep->declQuad(c+54+i*2,"pair_list",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, true,(i+0), 32,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1+i*1,"key_list",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, true,(i+0), 0,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+58+i*1,"data_list",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, true,(i+0), 31,0);
    }
    tracep->declBus(c+60,"lut_out",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 31,0);
    tracep->declBit(c+61,"hit",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1);
    tracep->declBus(c+178,"i",-1, FST_VD_IMPLICIT,FST_VT_VCD_INTEGER, false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("i2 ");
    tracep->declBus(c+179,"NR_KEY",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
    tracep->declBus(c+172,"KEY_LEN",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
    tracep->declBus(c+174,"DATA_LEN",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
    tracep->declBus(c+48,"out",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+31,"key",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 1,0);
    tracep->declArray(c+62,"lut",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 135,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+179,"NR_KEY",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
    tracep->declBus(c+172,"KEY_LEN",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
    tracep->declBus(c+174,"DATA_LEN",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
    tracep->declBus(c+175,"HAS_DEFAULT",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
    tracep->declBus(c+48,"out",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+31,"key",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 1,0);
    tracep->declBus(c+176,"default_out",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declArray(c+62,"lut",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 135,0);
    tracep->declBus(c+180,"PAIR_LEN",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
    for (int i = 0; i < 4; ++i) {
        tracep->declQuad(c+67+i*2,"pair_list",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, true,(i+0), 33,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+3+i*1,"key_list",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, true,(i+0), 1,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+75+i*1,"data_list",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, true,(i+0), 31,0);
    }
    tracep->declBus(c+79,"lut_out",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 31,0);
    tracep->declBit(c+80,"hit",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1);
    tracep->declBus(c+181,"i",-1, FST_VD_IMPLICIT,FST_VT_VCD_INTEGER, false,-1, 31,0);
    tracep->popNamePrefix(3);
    tracep->pushNamePrefix("alu_inst ");
    tracep->declBus(c+35,"aluc",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBus(c+42,"num1",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+43,"num2",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+37,"result",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+182,"temp",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+81,"num2_cplm",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+82,"num2_temp",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("control_unit_inst ");
    tracep->declBus(c+20,"inst",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+17,"rd_11_7",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBus(c+15,"rs1_19_15",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBus(c+16,"rs2_24_20",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBus(c+18,"fun3_14_12",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 2,0);
    tracep->declBus(c+19,"fun7_31_25",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 6,0);
    tracep->declBus(c+22,"IType",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 2,0);
    tracep->declBus(c+35,"aluc",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBit(c+23,"is_ecall",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+24,"csr_wen",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+25,"reg_wen",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+26,"mem_wen",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+27,"mem_ren",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+28,"wmask",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 7,0);
    tracep->declBus(c+29,"rmask",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 2,0);
    tracep->declBit(c+30,"m1",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+31,"m2",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 1,0);
    tracep->declBit(c+32,"m3",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+33,"m4",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+34,"m5",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 1,0);
    tracep->declBus(c+83,"opcode_6_0",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 6,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("csr_regs_inst ");
    tracep->declBit(c+166,"clk",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+167,"rst",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+23,"is_ecall",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+24,"csr_wen",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+18,"funct3",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 2,0);
    tracep->declBus(c+84,"csr",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 11,0);
    tracep->declBus(c+39,"src1",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+21,"pc",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+45,"csr_npc",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+46,"csr_val",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+168,"mstatus",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+170,"mtvec",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+169,"mepc",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+171,"mcause",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+85,"csr_wdata",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("i3 ");
    tracep->declBus(c+172,"NR_KEY",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
    tracep->declBus(c+173,"KEY_LEN",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
    tracep->declBus(c+174,"DATA_LEN",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
    tracep->declBus(c+43,"out",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+32,"key",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 0,0);
    tracep->declArray(c+86,"lut",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 65,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+172,"NR_KEY",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
    tracep->declBus(c+173,"KEY_LEN",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
    tracep->declBus(c+174,"DATA_LEN",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
    tracep->declBus(c+175,"HAS_DEFAULT",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
    tracep->declBus(c+43,"out",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+32,"key",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 0,0);
    tracep->declBus(c+176,"default_out",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declArray(c+86,"lut",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 65,0);
    tracep->declBus(c+177,"PAIR_LEN",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
    for (int i = 0; i < 2; ++i) {
        tracep->declQuad(c+89+i*2,"pair_list",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, true,(i+0), 32,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+7+i*1,"key_list",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, true,(i+0), 0,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+93+i*1,"data_list",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, true,(i+0), 31,0);
    }
    tracep->declBus(c+95,"lut_out",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 31,0);
    tracep->declBit(c+96,"hit",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1);
    tracep->declBus(c+178,"i",-1, FST_VD_IMPLICIT,FST_VT_VCD_INTEGER, false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("i4 ");
    tracep->declBus(c+172,"NR_KEY",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
    tracep->declBus(c+173,"KEY_LEN",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
    tracep->declBus(c+174,"DATA_LEN",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
    tracep->declBus(c+42,"out",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+33,"key",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 0,0);
    tracep->declArray(c+97,"lut",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 65,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+172,"NR_KEY",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
    tracep->declBus(c+173,"KEY_LEN",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
    tracep->declBus(c+174,"DATA_LEN",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
    tracep->declBus(c+175,"HAS_DEFAULT",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
    tracep->declBus(c+42,"out",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+33,"key",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 0,0);
    tracep->declBus(c+176,"default_out",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declArray(c+97,"lut",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 65,0);
    tracep->declBus(c+177,"PAIR_LEN",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
    for (int i = 0; i < 2; ++i) {
        tracep->declQuad(c+100+i*2,"pair_list",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, true,(i+0), 32,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+9+i*1,"key_list",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, true,(i+0), 0,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+104+i*1,"data_list",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, true,(i+0), 31,0);
    }
    tracep->declBus(c+106,"lut_out",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 31,0);
    tracep->declBit(c+107,"hit",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1);
    tracep->declBus(c+178,"i",-1, FST_VD_IMPLICIT,FST_VT_VCD_INTEGER, false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("i5 ");
    tracep->declBus(c+179,"NR_KEY",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
    tracep->declBus(c+172,"KEY_LEN",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
    tracep->declBus(c+174,"DATA_LEN",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
    tracep->declBus(c+38,"out",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+34,"key",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 1,0);
    tracep->declArray(c+108,"lut",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 135,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+179,"NR_KEY",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
    tracep->declBus(c+172,"KEY_LEN",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
    tracep->declBus(c+174,"DATA_LEN",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
    tracep->declBus(c+175,"HAS_DEFAULT",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
    tracep->declBus(c+38,"out",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+34,"key",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 1,0);
    tracep->declBus(c+176,"default_out",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declArray(c+108,"lut",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 135,0);
    tracep->declBus(c+180,"PAIR_LEN",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
    for (int i = 0; i < 4; ++i) {
        tracep->declQuad(c+113+i*2,"pair_list",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, true,(i+0), 33,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+11+i*1,"key_list",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, true,(i+0), 1,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+121+i*1,"data_list",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, true,(i+0), 31,0);
    }
    tracep->declBus(c+125,"lut_out",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 31,0);
    tracep->declBit(c+126,"hit",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1);
    tracep->declBus(c+181,"i",-1, FST_VD_IMPLICIT,FST_VT_VCD_INTEGER, false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("imm_extend_inst ");
    tracep->declBus(c+15,"rs1",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBus(c+16,"rs2",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBus(c+17,"rd",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBus(c+18,"funct3",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 2,0);
    tracep->declBus(c+19,"funct7",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 6,0);
    tracep->declBus(c+22,"IType",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 2,0);
    tracep->declBus(c+41,"imm32",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+127,"imm_12",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 11,0);
    tracep->declBus(c+128,"imm_20",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 19,0);
    tracep->declBus(c+129,"imm_12_to_32",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+130,"imm_20_to_32",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->pushNamePrefix("Extend_12_inst ");
    tracep->declBus(c+127,"imm_12",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 11,0);
    tracep->declBus(c+129,"imm_12_to_32",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("Extend_20_inst ");
    tracep->declBus(c+128,"imm_20",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 19,0);
    tracep->declBus(c+130,"imm_20_to_32",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("RISB_type_inst ");
    tracep->declBus(c+16,"rs2",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBus(c+17,"rd",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBus(c+19,"funct7",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 6,0);
    tracep->declBus(c+22,"IType",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 2,0);
    tracep->declBus(c+127,"imm_12",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 11,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("UJ_type_inst ");
    tracep->declBus(c+15,"rs1",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBus(c+16,"rs2",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBus(c+18,"funct3",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 2,0);
    tracep->declBus(c+19,"funct7",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 6,0);
    tracep->declBus(c+22,"IType",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 2,0);
    tracep->declBus(c+128,"imm_20",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 19,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("mem_inst ");
    tracep->declBit(c+166,"clk",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+26,"mem_wen",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+28,"wmask",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 7,0);
    tracep->declBus(c+37,"waddr",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+40,"wdata",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBit(c+27,"mem_ren",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+29,"rmask",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 2,0);
    tracep->declBus(c+37,"raddr",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+21,"inst_addr",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+44,"rdata",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+20,"inst_data",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+131,"rdata_temp",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("register_file_inst ");
    tracep->declBit(c+166,"clk",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+167,"rst",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+23,"is_ecall",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+25,"reg_wen",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+15,"rs1",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBus(c+16,"rs2",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBus(c+17,"rd",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBus(c+38,"reg_in",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+39,"src1",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+40,"src2",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+132,"i",-1, FST_VD_IMPLICIT,FST_VT_VCD_INTEGER, false,-1, 31,0);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+133+i*1,"regs",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, true,(i+0), 31,0);
    }
    tracep->declBus(c+165,"src1_temp",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->popNamePrefix(2);
}

VL_ATTR_COLD void Vysyx_23060219_top___024root__trace_init_top(Vysyx_23060219_top___024root* vlSelf, VerilatedFst* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_23060219_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_23060219_top___024root__trace_init_top\n"); );
    // Body
    Vysyx_23060219_top___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vysyx_23060219_top___024root__trace_full_top_0(void* voidSelf, VerilatedFst::Buffer* bufp);
void Vysyx_23060219_top___024root__trace_chg_top_0(void* voidSelf, VerilatedFst::Buffer* bufp);
void Vysyx_23060219_top___024root__trace_cleanup(void* voidSelf, VerilatedFst* /*unused*/);

VL_ATTR_COLD void Vysyx_23060219_top___024root__trace_register(Vysyx_23060219_top___024root* vlSelf, VerilatedFst* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_23060219_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_23060219_top___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&Vysyx_23060219_top___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&Vysyx_23060219_top___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&Vysyx_23060219_top___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vysyx_23060219_top___024root__trace_full_sub_0(Vysyx_23060219_top___024root* vlSelf, VerilatedFst::Buffer* bufp);

VL_ATTR_COLD void Vysyx_23060219_top___024root__trace_full_top_0(void* voidSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_23060219_top___024root__trace_full_top_0\n"); );
    // Init
    Vysyx_23060219_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vysyx_23060219_top___024root*>(voidSelf);
    Vysyx_23060219_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vysyx_23060219_top___024root__trace_full_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vysyx_23060219_top___024root__trace_full_sub_0(Vysyx_23060219_top___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_23060219_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_23060219_top___024root__trace_full_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    VlWide<3>/*95:0*/ __Vtemp_hf04b4229__0;
    VlWide<5>/*159:0*/ __Vtemp_h0168a123__0;
    VlWide<3>/*95:0*/ __Vtemp_hbaf4f1d1__0;
    VlWide<3>/*95:0*/ __Vtemp_hf226ec2e__0;
    VlWide<5>/*159:0*/ __Vtemp_h532fcdf4__0;
    // Body
    bufp->fullBit(oldp+1,(vlSelf->ysyx_23060219_top__DOT__PC_inst__DOT__i1__DOT__i0__DOT__key_list[0]));
    bufp->fullBit(oldp+2,(vlSelf->ysyx_23060219_top__DOT__PC_inst__DOT__i1__DOT__i0__DOT__key_list[1]));
    bufp->fullCData(oldp+3,(vlSelf->ysyx_23060219_top__DOT__PC_inst__DOT__i2__DOT__i0__DOT__key_list[0]),2);
    bufp->fullCData(oldp+4,(vlSelf->ysyx_23060219_top__DOT__PC_inst__DOT__i2__DOT__i0__DOT__key_list[1]),2);
    bufp->fullCData(oldp+5,(vlSelf->ysyx_23060219_top__DOT__PC_inst__DOT__i2__DOT__i0__DOT__key_list[2]),2);
    bufp->fullCData(oldp+6,(vlSelf->ysyx_23060219_top__DOT__PC_inst__DOT__i2__DOT__i0__DOT__key_list[3]),2);
    bufp->fullBit(oldp+7,(vlSelf->ysyx_23060219_top__DOT__i3__DOT__i0__DOT__key_list[0]));
    bufp->fullBit(oldp+8,(vlSelf->ysyx_23060219_top__DOT__i3__DOT__i0__DOT__key_list[1]));
    bufp->fullBit(oldp+9,(vlSelf->ysyx_23060219_top__DOT__i4__DOT__i0__DOT__key_list[0]));
    bufp->fullBit(oldp+10,(vlSelf->ysyx_23060219_top__DOT__i4__DOT__i0__DOT__key_list[1]));
    bufp->fullCData(oldp+11,(vlSelf->ysyx_23060219_top__DOT__i5__DOT__i0__DOT__key_list[0]),2);
    bufp->fullCData(oldp+12,(vlSelf->ysyx_23060219_top__DOT__i5__DOT__i0__DOT__key_list[1]),2);
    bufp->fullCData(oldp+13,(vlSelf->ysyx_23060219_top__DOT__i5__DOT__i0__DOT__key_list[2]),2);
    bufp->fullCData(oldp+14,(vlSelf->ysyx_23060219_top__DOT__i5__DOT__i0__DOT__key_list[3]),2);
    bufp->fullCData(oldp+15,((0x1fU & (vlSelf->ysyx_23060219_top__DOT__inst 
                                       >> 0xfU))),5);
    bufp->fullCData(oldp+16,((0x1fU & (vlSelf->ysyx_23060219_top__DOT__inst 
                                       >> 0x14U))),5);
    bufp->fullCData(oldp+17,((0x1fU & (vlSelf->ysyx_23060219_top__DOT__inst 
                                       >> 7U))),5);
    bufp->fullCData(oldp+18,((7U & (vlSelf->ysyx_23060219_top__DOT__inst 
                                    >> 0xcU))),3);
    bufp->fullCData(oldp+19,((vlSelf->ysyx_23060219_top__DOT__inst 
                              >> 0x19U)),7);
    bufp->fullIData(oldp+20,(vlSelf->ysyx_23060219_top__DOT__inst),32);
    bufp->fullIData(oldp+21,(vlSelf->ysyx_23060219_top__DOT__pc),32);
    bufp->fullCData(oldp+22,(vlSelf->ysyx_23060219_top__DOT__IType),3);
    bufp->fullBit(oldp+23,(vlSelf->ysyx_23060219_top__DOT__is_ecall));
    bufp->fullBit(oldp+24,(vlSelf->ysyx_23060219_top__DOT__csr_wen));
    bufp->fullBit(oldp+25,(vlSelf->ysyx_23060219_top__DOT__reg_wen));
    bufp->fullBit(oldp+26,(vlSelf->ysyx_23060219_top__DOT__mem_wen));
    bufp->fullBit(oldp+27,(vlSelf->ysyx_23060219_top__DOT__mem_ren));
    bufp->fullCData(oldp+28,(vlSelf->ysyx_23060219_top__DOT__wmask),8);
    bufp->fullCData(oldp+29,(vlSelf->ysyx_23060219_top__DOT__rmask),3);
    bufp->fullBit(oldp+30,(vlSelf->ysyx_23060219_top__DOT__m1));
    bufp->fullCData(oldp+31,(vlSelf->ysyx_23060219_top__DOT__m2),2);
    bufp->fullBit(oldp+32,(vlSelf->ysyx_23060219_top__DOT__m3));
    bufp->fullBit(oldp+33,(vlSelf->ysyx_23060219_top__DOT__m4));
    bufp->fullCData(oldp+34,(vlSelf->ysyx_23060219_top__DOT__m5),2);
    bufp->fullCData(oldp+35,(vlSelf->ysyx_23060219_top__DOT__aluc),5);
    bufp->fullIData(oldp+36,(((IData)(4U) + vlSelf->ysyx_23060219_top__DOT__pc)),32);
    bufp->fullIData(oldp+37,(vlSelf->ysyx_23060219_top__DOT__result),32);
    bufp->fullIData(oldp+38,(vlSelf->ysyx_23060219_top__DOT__reg_in),32);
    bufp->fullIData(oldp+39,(vlSelf->ysyx_23060219_top__DOT__src1),32);
    bufp->fullIData(oldp+40,(vlSelf->ysyx_23060219_top__DOT__src2),32);
    bufp->fullIData(oldp+41,(vlSelf->ysyx_23060219_top__DOT__imm32),32);
    bufp->fullIData(oldp+42,(vlSelf->ysyx_23060219_top__DOT__num1),32);
    bufp->fullIData(oldp+43,(vlSelf->ysyx_23060219_top__DOT__num2),32);
    bufp->fullIData(oldp+44,(vlSelf->ysyx_23060219_top__DOT__mem_rdata),32);
    bufp->fullIData(oldp+45,(vlSelf->ysyx_23060219_top__DOT__csr_npc),32);
    bufp->fullIData(oldp+46,(vlSelf->ysyx_23060219_top__DOT__csr_val),32);
    bufp->fullIData(oldp+47,(vlSelf->ysyx_23060219_top__DOT__PC_inst__DOT__npc),32);
    bufp->fullIData(oldp+48,(vlSelf->ysyx_23060219_top__DOT__PC_inst__DOT__npc_temp),32);
    bufp->fullIData(oldp+49,((vlSelf->ysyx_23060219_top__DOT__imm32 
                              + vlSelf->ysyx_23060219_top__DOT__pc)),32);
    bufp->fullBit(oldp+50,(vlSelf->ysyx_23060219_top__DOT__PC_inst__DOT____Vcellinp__i1____pinNumber2));
    __Vtemp_hf04b4229__0[0U] = (IData)((0x100000000ULL 
                                        | (QData)((IData)(
                                                          (vlSelf->ysyx_23060219_top__DOT__imm32 
                                                           + vlSelf->ysyx_23060219_top__DOT__pc)))));
    __Vtemp_hf04b4229__0[1U] = ((vlSelf->ysyx_23060219_top__DOT__PC_inst__DOT__npc_temp 
                                 << 1U) | (IData)((
                                                   (0x100000000ULL 
                                                    | (QData)((IData)(
                                                                      (vlSelf->ysyx_23060219_top__DOT__imm32 
                                                                       + vlSelf->ysyx_23060219_top__DOT__pc)))) 
                                                   >> 0x20U)));
    __Vtemp_hf04b4229__0[2U] = (vlSelf->ysyx_23060219_top__DOT__PC_inst__DOT__npc_temp 
                                >> 0x1fU);
    bufp->fullWData(oldp+51,(__Vtemp_hf04b4229__0),66);
    bufp->fullQData(oldp+54,(vlSelf->ysyx_23060219_top__DOT__PC_inst__DOT__i1__DOT__i0__DOT__pair_list[0]),33);
    bufp->fullQData(oldp+56,(vlSelf->ysyx_23060219_top__DOT__PC_inst__DOT__i1__DOT__i0__DOT__pair_list[1]),33);
    bufp->fullIData(oldp+58,(vlSelf->ysyx_23060219_top__DOT__PC_inst__DOT__i1__DOT__i0__DOT__data_list[0]),32);
    bufp->fullIData(oldp+59,(vlSelf->ysyx_23060219_top__DOT__PC_inst__DOT__i1__DOT__i0__DOT__data_list[1]),32);
    bufp->fullIData(oldp+60,(vlSelf->ysyx_23060219_top__DOT__PC_inst__DOT__i1__DOT__i0__DOT__lut_out),32);
    bufp->fullBit(oldp+61,(vlSelf->ysyx_23060219_top__DOT__PC_inst__DOT__i1__DOT__i0__DOT__hit));
    __Vtemp_h0168a123__0[0U] = 0xdead000cU;
    __Vtemp_h0168a123__0[1U] = (3U | (vlSelf->ysyx_23060219_top__DOT__csr_npc 
                                      << 2U));
    __Vtemp_h0168a123__0[2U] = (8U | ((vlSelf->ysyx_23060219_top__DOT__result 
                                       << 4U) | (vlSelf->ysyx_23060219_top__DOT__csr_npc 
                                                 >> 0x1eU)));
    __Vtemp_h0168a123__0[3U] = (0x10U | ((((IData)(4U) 
                                           + vlSelf->ysyx_23060219_top__DOT__pc) 
                                          << 6U) | 
                                         (vlSelf->ysyx_23060219_top__DOT__result 
                                          >> 0x1cU)));
    __Vtemp_h0168a123__0[4U] = (((IData)(4U) + vlSelf->ysyx_23060219_top__DOT__pc) 
                                >> 0x1aU);
    bufp->fullWData(oldp+62,(__Vtemp_h0168a123__0),136);
    bufp->fullQData(oldp+67,(vlSelf->ysyx_23060219_top__DOT__PC_inst__DOT__i2__DOT__i0__DOT__pair_list[0]),34);
    bufp->fullQData(oldp+69,(vlSelf->ysyx_23060219_top__DOT__PC_inst__DOT__i2__DOT__i0__DOT__pair_list[1]),34);
    bufp->fullQData(oldp+71,(vlSelf->ysyx_23060219_top__DOT__PC_inst__DOT__i2__DOT__i0__DOT__pair_list[2]),34);
    bufp->fullQData(oldp+73,(vlSelf->ysyx_23060219_top__DOT__PC_inst__DOT__i2__DOT__i0__DOT__pair_list[3]),34);
    bufp->fullIData(oldp+75,(vlSelf->ysyx_23060219_top__DOT__PC_inst__DOT__i2__DOT__i0__DOT__data_list[0]),32);
    bufp->fullIData(oldp+76,(vlSelf->ysyx_23060219_top__DOT__PC_inst__DOT__i2__DOT__i0__DOT__data_list[1]),32);
    bufp->fullIData(oldp+77,(vlSelf->ysyx_23060219_top__DOT__PC_inst__DOT__i2__DOT__i0__DOT__data_list[2]),32);
    bufp->fullIData(oldp+78,(vlSelf->ysyx_23060219_top__DOT__PC_inst__DOT__i2__DOT__i0__DOT__data_list[3]),32);
    bufp->fullIData(oldp+79,(vlSelf->ysyx_23060219_top__DOT__PC_inst__DOT__i2__DOT__i0__DOT__lut_out),32);
    bufp->fullBit(oldp+80,(vlSelf->ysyx_23060219_top__DOT__PC_inst__DOT__i2__DOT__i0__DOT__hit));
    bufp->fullIData(oldp+81,(((IData)(1U) + (~ vlSelf->ysyx_23060219_top__DOT__num2))),32);
    bufp->fullIData(oldp+82,((0x1fU & vlSelf->ysyx_23060219_top__DOT__num2)),32);
    bufp->fullCData(oldp+83,((0x7fU & vlSelf->ysyx_23060219_top__DOT__inst)),7);
    bufp->fullSData(oldp+84,((vlSelf->ysyx_23060219_top__DOT__inst 
                              >> 0x14U)),12);
    bufp->fullIData(oldp+85,(vlSelf->ysyx_23060219_top__DOT__csr_regs_inst__DOT__csr_wdata),32);
    __Vtemp_hbaf4f1d1__0[0U] = (IData)((0x100000000ULL 
                                        | (QData)((IData)(vlSelf->ysyx_23060219_top__DOT__imm32))));
    __Vtemp_hbaf4f1d1__0[1U] = ((vlSelf->ysyx_23060219_top__DOT__src2 
                                 << 1U) | (IData)((
                                                   (0x100000000ULL 
                                                    | (QData)((IData)(vlSelf->ysyx_23060219_top__DOT__imm32))) 
                                                   >> 0x20U)));
    __Vtemp_hbaf4f1d1__0[2U] = (vlSelf->ysyx_23060219_top__DOT__src2 
                                >> 0x1fU);
    bufp->fullWData(oldp+86,(__Vtemp_hbaf4f1d1__0),66);
    bufp->fullQData(oldp+89,(vlSelf->ysyx_23060219_top__DOT__i3__DOT__i0__DOT__pair_list[0]),33);
    bufp->fullQData(oldp+91,(vlSelf->ysyx_23060219_top__DOT__i3__DOT__i0__DOT__pair_list[1]),33);
    bufp->fullIData(oldp+93,(vlSelf->ysyx_23060219_top__DOT__i3__DOT__i0__DOT__data_list[0]),32);
    bufp->fullIData(oldp+94,(vlSelf->ysyx_23060219_top__DOT__i3__DOT__i0__DOT__data_list[1]),32);
    bufp->fullIData(oldp+95,(vlSelf->ysyx_23060219_top__DOT__i3__DOT__i0__DOT__lut_out),32);
    bufp->fullBit(oldp+96,(vlSelf->ysyx_23060219_top__DOT__i3__DOT__i0__DOT__hit));
    __Vtemp_hf226ec2e__0[0U] = (IData)((0x100000000ULL 
                                        | (QData)((IData)(vlSelf->ysyx_23060219_top__DOT__src1))));
    __Vtemp_hf226ec2e__0[1U] = ((vlSelf->ysyx_23060219_top__DOT__pc 
                                 << 1U) | (IData)((
                                                   (0x100000000ULL 
                                                    | (QData)((IData)(vlSelf->ysyx_23060219_top__DOT__src1))) 
                                                   >> 0x20U)));
    __Vtemp_hf226ec2e__0[2U] = (vlSelf->ysyx_23060219_top__DOT__pc 
                                >> 0x1fU);
    bufp->fullWData(oldp+97,(__Vtemp_hf226ec2e__0),66);
    bufp->fullQData(oldp+100,(vlSelf->ysyx_23060219_top__DOT__i4__DOT__i0__DOT__pair_list[0]),33);
    bufp->fullQData(oldp+102,(vlSelf->ysyx_23060219_top__DOT__i4__DOT__i0__DOT__pair_list[1]),33);
    bufp->fullIData(oldp+104,(vlSelf->ysyx_23060219_top__DOT__i4__DOT__i0__DOT__data_list[0]),32);
    bufp->fullIData(oldp+105,(vlSelf->ysyx_23060219_top__DOT__i4__DOT__i0__DOT__data_list[1]),32);
    bufp->fullIData(oldp+106,(vlSelf->ysyx_23060219_top__DOT__i4__DOT__i0__DOT__lut_out),32);
    bufp->fullBit(oldp+107,(vlSelf->ysyx_23060219_top__DOT__i4__DOT__i0__DOT__hit));
    __Vtemp_h532fcdf4__0[0U] = (IData)((0x300000000ULL 
                                        | (QData)((IData)(vlSelf->ysyx_23060219_top__DOT__csr_val))));
    __Vtemp_h532fcdf4__0[1U] = ((vlSelf->ysyx_23060219_top__DOT__result 
                                 << 2U) | (IData)((
                                                   (0x300000000ULL 
                                                    | (QData)((IData)(vlSelf->ysyx_23060219_top__DOT__csr_val))) 
                                                   >> 0x20U)));
    __Vtemp_h532fcdf4__0[2U] = (8U | ((vlSelf->ysyx_23060219_top__DOT__mem_rdata 
                                       << 4U) | (vlSelf->ysyx_23060219_top__DOT__result 
                                                 >> 0x1eU)));
    __Vtemp_h532fcdf4__0[3U] = (0x10U | ((((IData)(4U) 
                                           + vlSelf->ysyx_23060219_top__DOT__pc) 
                                          << 6U) | 
                                         (vlSelf->ysyx_23060219_top__DOT__mem_rdata 
                                          >> 0x1cU)));
    __Vtemp_h532fcdf4__0[4U] = (((IData)(4U) + vlSelf->ysyx_23060219_top__DOT__pc) 
                                >> 0x1aU);
    bufp->fullWData(oldp+108,(__Vtemp_h532fcdf4__0),136);
    bufp->fullQData(oldp+113,(vlSelf->ysyx_23060219_top__DOT__i5__DOT__i0__DOT__pair_list[0]),34);
    bufp->fullQData(oldp+115,(vlSelf->ysyx_23060219_top__DOT__i5__DOT__i0__DOT__pair_list[1]),34);
    bufp->fullQData(oldp+117,(vlSelf->ysyx_23060219_top__DOT__i5__DOT__i0__DOT__pair_list[2]),34);
    bufp->fullQData(oldp+119,(vlSelf->ysyx_23060219_top__DOT__i5__DOT__i0__DOT__pair_list[3]),34);
    bufp->fullIData(oldp+121,(vlSelf->ysyx_23060219_top__DOT__i5__DOT__i0__DOT__data_list[0]),32);
    bufp->fullIData(oldp+122,(vlSelf->ysyx_23060219_top__DOT__i5__DOT__i0__DOT__data_list[1]),32);
    bufp->fullIData(oldp+123,(vlSelf->ysyx_23060219_top__DOT__i5__DOT__i0__DOT__data_list[2]),32);
    bufp->fullIData(oldp+124,(vlSelf->ysyx_23060219_top__DOT__i5__DOT__i0__DOT__data_list[3]),32);
    bufp->fullIData(oldp+125,(vlSelf->ysyx_23060219_top__DOT__i5__DOT__i0__DOT__lut_out),32);
    bufp->fullBit(oldp+126,(vlSelf->ysyx_23060219_top__DOT__i5__DOT__i0__DOT__hit));
    bufp->fullSData(oldp+127,(vlSelf->ysyx_23060219_top__DOT__imm_extend_inst__DOT__imm_12),12);
    bufp->fullIData(oldp+128,(vlSelf->ysyx_23060219_top__DOT__imm_extend_inst__DOT__imm_20),20);
    bufp->fullIData(oldp+129,(vlSelf->ysyx_23060219_top__DOT__imm_extend_inst__DOT__imm_12_to_32),32);
    bufp->fullIData(oldp+130,(vlSelf->ysyx_23060219_top__DOT__imm_extend_inst__DOT__imm_20_to_32),32);
    bufp->fullIData(oldp+131,(vlSelf->ysyx_23060219_top__DOT__mem_inst__DOT__rdata_temp),32);
    bufp->fullIData(oldp+132,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__i),32);
    bufp->fullIData(oldp+133,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[0]),32);
    bufp->fullIData(oldp+134,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[1]),32);
    bufp->fullIData(oldp+135,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[2]),32);
    bufp->fullIData(oldp+136,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[3]),32);
    bufp->fullIData(oldp+137,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[4]),32);
    bufp->fullIData(oldp+138,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[5]),32);
    bufp->fullIData(oldp+139,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[6]),32);
    bufp->fullIData(oldp+140,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[7]),32);
    bufp->fullIData(oldp+141,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[8]),32);
    bufp->fullIData(oldp+142,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[9]),32);
    bufp->fullIData(oldp+143,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[10]),32);
    bufp->fullIData(oldp+144,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[11]),32);
    bufp->fullIData(oldp+145,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[12]),32);
    bufp->fullIData(oldp+146,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[13]),32);
    bufp->fullIData(oldp+147,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[14]),32);
    bufp->fullIData(oldp+148,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[15]),32);
    bufp->fullIData(oldp+149,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[16]),32);
    bufp->fullIData(oldp+150,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[17]),32);
    bufp->fullIData(oldp+151,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[18]),32);
    bufp->fullIData(oldp+152,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[19]),32);
    bufp->fullIData(oldp+153,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[20]),32);
    bufp->fullIData(oldp+154,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[21]),32);
    bufp->fullIData(oldp+155,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[22]),32);
    bufp->fullIData(oldp+156,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[23]),32);
    bufp->fullIData(oldp+157,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[24]),32);
    bufp->fullIData(oldp+158,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[25]),32);
    bufp->fullIData(oldp+159,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[26]),32);
    bufp->fullIData(oldp+160,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[27]),32);
    bufp->fullIData(oldp+161,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[28]),32);
    bufp->fullIData(oldp+162,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[29]),32);
    bufp->fullIData(oldp+163,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[30]),32);
    bufp->fullIData(oldp+164,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[31]),32);
    bufp->fullIData(oldp+165,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__src1_temp),32);
    bufp->fullBit(oldp+166,(vlSelf->clk));
    bufp->fullBit(oldp+167,(vlSelf->rst));
    bufp->fullIData(oldp+168,(vlSelf->mstatus),32);
    bufp->fullIData(oldp+169,(vlSelf->mepc),32);
    bufp->fullIData(oldp+170,(vlSelf->mtvec),32);
    bufp->fullIData(oldp+171,(vlSelf->mcause),32);
    bufp->fullIData(oldp+172,(2U),32);
    bufp->fullIData(oldp+173,(1U),32);
    bufp->fullIData(oldp+174,(0x20U),32);
    bufp->fullIData(oldp+175,(0U),32);
    bufp->fullIData(oldp+176,(0U),32);
    bufp->fullIData(oldp+177,(0x21U),32);
    bufp->fullIData(oldp+178,(2U),32);
    bufp->fullIData(oldp+179,(4U),32);
    bufp->fullIData(oldp+180,(0x22U),32);
    bufp->fullIData(oldp+181,(4U),32);
    bufp->fullIData(oldp+182,(0xfffffffeU),32);
}
