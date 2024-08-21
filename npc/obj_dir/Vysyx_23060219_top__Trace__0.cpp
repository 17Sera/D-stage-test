// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_fst_c.h"
#include "Vysyx_23060219_top__Syms.h"


void Vysyx_23060219_top___024root__trace_chg_sub_0(Vysyx_23060219_top___024root* vlSelf, VerilatedFst::Buffer* bufp);

void Vysyx_23060219_top___024root__trace_chg_top_0(void* voidSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_23060219_top___024root__trace_chg_top_0\n"); );
    // Init
    Vysyx_23060219_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vysyx_23060219_top___024root*>(voidSelf);
    Vysyx_23060219_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vysyx_23060219_top___024root__trace_chg_sub_0((&vlSymsp->TOP), bufp);
}

void Vysyx_23060219_top___024root__trace_chg_sub_0(Vysyx_23060219_top___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_23060219_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_23060219_top___024root__trace_chg_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    VlWide<3>/*95:0*/ __Vtemp_hf04b4229__0;
    VlWide<5>/*159:0*/ __Vtemp_h0168a123__0;
    VlWide<3>/*95:0*/ __Vtemp_hbaf4f1d1__0;
    VlWide<3>/*95:0*/ __Vtemp_hf226ec2e__0;
    VlWide<5>/*159:0*/ __Vtemp_h532fcdf4__0;
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[0U])) {
        bufp->chgBit(oldp+0,(vlSelf->ysyx_23060219_top__DOT__PC_inst__DOT__i1__DOT__i0__DOT__key_list[0]));
        bufp->chgBit(oldp+1,(vlSelf->ysyx_23060219_top__DOT__PC_inst__DOT__i1__DOT__i0__DOT__key_list[1]));
        bufp->chgCData(oldp+2,(vlSelf->ysyx_23060219_top__DOT__PC_inst__DOT__i2__DOT__i0__DOT__key_list[0]),2);
        bufp->chgCData(oldp+3,(vlSelf->ysyx_23060219_top__DOT__PC_inst__DOT__i2__DOT__i0__DOT__key_list[1]),2);
        bufp->chgCData(oldp+4,(vlSelf->ysyx_23060219_top__DOT__PC_inst__DOT__i2__DOT__i0__DOT__key_list[2]),2);
        bufp->chgCData(oldp+5,(vlSelf->ysyx_23060219_top__DOT__PC_inst__DOT__i2__DOT__i0__DOT__key_list[3]),2);
        bufp->chgBit(oldp+6,(vlSelf->ysyx_23060219_top__DOT__i3__DOT__i0__DOT__key_list[0]));
        bufp->chgBit(oldp+7,(vlSelf->ysyx_23060219_top__DOT__i3__DOT__i0__DOT__key_list[1]));
        bufp->chgBit(oldp+8,(vlSelf->ysyx_23060219_top__DOT__i4__DOT__i0__DOT__key_list[0]));
        bufp->chgBit(oldp+9,(vlSelf->ysyx_23060219_top__DOT__i4__DOT__i0__DOT__key_list[1]));
        bufp->chgCData(oldp+10,(vlSelf->ysyx_23060219_top__DOT__i5__DOT__i0__DOT__key_list[0]),2);
        bufp->chgCData(oldp+11,(vlSelf->ysyx_23060219_top__DOT__i5__DOT__i0__DOT__key_list[1]),2);
        bufp->chgCData(oldp+12,(vlSelf->ysyx_23060219_top__DOT__i5__DOT__i0__DOT__key_list[2]),2);
        bufp->chgCData(oldp+13,(vlSelf->ysyx_23060219_top__DOT__i5__DOT__i0__DOT__key_list[3]),2);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgCData(oldp+14,((0x1fU & (vlSelf->ysyx_23060219_top__DOT__inst 
                                          >> 0xfU))),5);
        bufp->chgCData(oldp+15,((0x1fU & (vlSelf->ysyx_23060219_top__DOT__inst 
                                          >> 0x14U))),5);
        bufp->chgCData(oldp+16,((0x1fU & (vlSelf->ysyx_23060219_top__DOT__inst 
                                          >> 7U))),5);
        bufp->chgCData(oldp+17,((7U & (vlSelf->ysyx_23060219_top__DOT__inst 
                                       >> 0xcU))),3);
        bufp->chgCData(oldp+18,((vlSelf->ysyx_23060219_top__DOT__inst 
                                 >> 0x19U)),7);
        bufp->chgIData(oldp+19,(vlSelf->ysyx_23060219_top__DOT__inst),32);
        bufp->chgIData(oldp+20,(vlSelf->ysyx_23060219_top__DOT__pc),32);
        bufp->chgCData(oldp+21,(vlSelf->ysyx_23060219_top__DOT__IType),3);
        bufp->chgBit(oldp+22,(vlSelf->ysyx_23060219_top__DOT__is_ecall));
        bufp->chgBit(oldp+23,(vlSelf->ysyx_23060219_top__DOT__csr_wen));
        bufp->chgBit(oldp+24,(vlSelf->ysyx_23060219_top__DOT__reg_wen));
        bufp->chgBit(oldp+25,(vlSelf->ysyx_23060219_top__DOT__mem_wen));
        bufp->chgBit(oldp+26,(vlSelf->ysyx_23060219_top__DOT__mem_ren));
        bufp->chgCData(oldp+27,(vlSelf->ysyx_23060219_top__DOT__wmask),8);
        bufp->chgCData(oldp+28,(vlSelf->ysyx_23060219_top__DOT__rmask),3);
        bufp->chgBit(oldp+29,(vlSelf->ysyx_23060219_top__DOT__m1));
        bufp->chgCData(oldp+30,(vlSelf->ysyx_23060219_top__DOT__m2),2);
        bufp->chgBit(oldp+31,(vlSelf->ysyx_23060219_top__DOT__m3));
        bufp->chgBit(oldp+32,(vlSelf->ysyx_23060219_top__DOT__m4));
        bufp->chgCData(oldp+33,(vlSelf->ysyx_23060219_top__DOT__m5),2);
        bufp->chgCData(oldp+34,(vlSelf->ysyx_23060219_top__DOT__aluc),5);
        bufp->chgIData(oldp+35,(((IData)(4U) + vlSelf->ysyx_23060219_top__DOT__pc)),32);
        bufp->chgIData(oldp+36,(vlSelf->ysyx_23060219_top__DOT__result),32);
        bufp->chgIData(oldp+37,(vlSelf->ysyx_23060219_top__DOT__reg_in),32);
        bufp->chgIData(oldp+38,(vlSelf->ysyx_23060219_top__DOT__src1),32);
        bufp->chgIData(oldp+39,(vlSelf->ysyx_23060219_top__DOT__src2),32);
        bufp->chgIData(oldp+40,(vlSelf->ysyx_23060219_top__DOT__imm32),32);
        bufp->chgIData(oldp+41,(vlSelf->ysyx_23060219_top__DOT__num1),32);
        bufp->chgIData(oldp+42,(vlSelf->ysyx_23060219_top__DOT__num2),32);
        bufp->chgIData(oldp+43,(vlSelf->ysyx_23060219_top__DOT__mem_rdata),32);
        bufp->chgIData(oldp+44,(vlSelf->ysyx_23060219_top__DOT__csr_npc),32);
        bufp->chgIData(oldp+45,(vlSelf->ysyx_23060219_top__DOT__csr_val),32);
        bufp->chgIData(oldp+46,(vlSelf->ysyx_23060219_top__DOT__PC_inst__DOT__npc),32);
        bufp->chgIData(oldp+47,(vlSelf->ysyx_23060219_top__DOT__PC_inst__DOT__npc_temp),32);
        bufp->chgIData(oldp+48,((vlSelf->ysyx_23060219_top__DOT__imm32 
                                 + vlSelf->ysyx_23060219_top__DOT__pc)),32);
        bufp->chgBit(oldp+49,(vlSelf->ysyx_23060219_top__DOT__PC_inst__DOT____Vcellinp__i1____pinNumber2));
        __Vtemp_hf04b4229__0[0U] = (IData)((0x100000000ULL 
                                            | (QData)((IData)(
                                                              (vlSelf->ysyx_23060219_top__DOT__imm32 
                                                               + vlSelf->ysyx_23060219_top__DOT__pc)))));
        __Vtemp_hf04b4229__0[1U] = ((vlSelf->ysyx_23060219_top__DOT__PC_inst__DOT__npc_temp 
                                     << 1U) | (IData)(
                                                      ((0x100000000ULL 
                                                        | (QData)((IData)(
                                                                          (vlSelf->ysyx_23060219_top__DOT__imm32 
                                                                           + vlSelf->ysyx_23060219_top__DOT__pc)))) 
                                                       >> 0x20U)));
        __Vtemp_hf04b4229__0[2U] = (vlSelf->ysyx_23060219_top__DOT__PC_inst__DOT__npc_temp 
                                    >> 0x1fU);
        bufp->chgWData(oldp+50,(__Vtemp_hf04b4229__0),66);
        bufp->chgQData(oldp+53,(vlSelf->ysyx_23060219_top__DOT__PC_inst__DOT__i1__DOT__i0__DOT__pair_list[0]),33);
        bufp->chgQData(oldp+55,(vlSelf->ysyx_23060219_top__DOT__PC_inst__DOT__i1__DOT__i0__DOT__pair_list[1]),33);
        bufp->chgIData(oldp+57,(vlSelf->ysyx_23060219_top__DOT__PC_inst__DOT__i1__DOT__i0__DOT__data_list[0]),32);
        bufp->chgIData(oldp+58,(vlSelf->ysyx_23060219_top__DOT__PC_inst__DOT__i1__DOT__i0__DOT__data_list[1]),32);
        bufp->chgIData(oldp+59,(vlSelf->ysyx_23060219_top__DOT__PC_inst__DOT__i1__DOT__i0__DOT__lut_out),32);
        bufp->chgBit(oldp+60,(vlSelf->ysyx_23060219_top__DOT__PC_inst__DOT__i1__DOT__i0__DOT__hit));
        __Vtemp_h0168a123__0[0U] = 0xdead000cU;
        __Vtemp_h0168a123__0[1U] = (3U | (vlSelf->ysyx_23060219_top__DOT__csr_npc 
                                          << 2U));
        __Vtemp_h0168a123__0[2U] = (8U | ((vlSelf->ysyx_23060219_top__DOT__result 
                                           << 4U) | 
                                          (vlSelf->ysyx_23060219_top__DOT__csr_npc 
                                           >> 0x1eU)));
        __Vtemp_h0168a123__0[3U] = (0x10U | ((((IData)(4U) 
                                               + vlSelf->ysyx_23060219_top__DOT__pc) 
                                              << 6U) 
                                             | (vlSelf->ysyx_23060219_top__DOT__result 
                                                >> 0x1cU)));
        __Vtemp_h0168a123__0[4U] = (((IData)(4U) + vlSelf->ysyx_23060219_top__DOT__pc) 
                                    >> 0x1aU);
        bufp->chgWData(oldp+61,(__Vtemp_h0168a123__0),136);
        bufp->chgQData(oldp+66,(vlSelf->ysyx_23060219_top__DOT__PC_inst__DOT__i2__DOT__i0__DOT__pair_list[0]),34);
        bufp->chgQData(oldp+68,(vlSelf->ysyx_23060219_top__DOT__PC_inst__DOT__i2__DOT__i0__DOT__pair_list[1]),34);
        bufp->chgQData(oldp+70,(vlSelf->ysyx_23060219_top__DOT__PC_inst__DOT__i2__DOT__i0__DOT__pair_list[2]),34);
        bufp->chgQData(oldp+72,(vlSelf->ysyx_23060219_top__DOT__PC_inst__DOT__i2__DOT__i0__DOT__pair_list[3]),34);
        bufp->chgIData(oldp+74,(vlSelf->ysyx_23060219_top__DOT__PC_inst__DOT__i2__DOT__i0__DOT__data_list[0]),32);
        bufp->chgIData(oldp+75,(vlSelf->ysyx_23060219_top__DOT__PC_inst__DOT__i2__DOT__i0__DOT__data_list[1]),32);
        bufp->chgIData(oldp+76,(vlSelf->ysyx_23060219_top__DOT__PC_inst__DOT__i2__DOT__i0__DOT__data_list[2]),32);
        bufp->chgIData(oldp+77,(vlSelf->ysyx_23060219_top__DOT__PC_inst__DOT__i2__DOT__i0__DOT__data_list[3]),32);
        bufp->chgIData(oldp+78,(vlSelf->ysyx_23060219_top__DOT__PC_inst__DOT__i2__DOT__i0__DOT__lut_out),32);
        bufp->chgBit(oldp+79,(vlSelf->ysyx_23060219_top__DOT__PC_inst__DOT__i2__DOT__i0__DOT__hit));
        bufp->chgIData(oldp+80,(((IData)(1U) + (~ vlSelf->ysyx_23060219_top__DOT__num2))),32);
        bufp->chgIData(oldp+81,((0x1fU & vlSelf->ysyx_23060219_top__DOT__num2)),32);
        bufp->chgCData(oldp+82,((0x7fU & vlSelf->ysyx_23060219_top__DOT__inst)),7);
        bufp->chgSData(oldp+83,((vlSelf->ysyx_23060219_top__DOT__inst 
                                 >> 0x14U)),12);
        bufp->chgIData(oldp+84,(vlSelf->ysyx_23060219_top__DOT__csr_regs_inst__DOT__csr_wdata),32);
        __Vtemp_hbaf4f1d1__0[0U] = (IData)((0x100000000ULL 
                                            | (QData)((IData)(vlSelf->ysyx_23060219_top__DOT__imm32))));
        __Vtemp_hbaf4f1d1__0[1U] = ((vlSelf->ysyx_23060219_top__DOT__src2 
                                     << 1U) | (IData)(
                                                      ((0x100000000ULL 
                                                        | (QData)((IData)(vlSelf->ysyx_23060219_top__DOT__imm32))) 
                                                       >> 0x20U)));
        __Vtemp_hbaf4f1d1__0[2U] = (vlSelf->ysyx_23060219_top__DOT__src2 
                                    >> 0x1fU);
        bufp->chgWData(oldp+85,(__Vtemp_hbaf4f1d1__0),66);
        bufp->chgQData(oldp+88,(vlSelf->ysyx_23060219_top__DOT__i3__DOT__i0__DOT__pair_list[0]),33);
        bufp->chgQData(oldp+90,(vlSelf->ysyx_23060219_top__DOT__i3__DOT__i0__DOT__pair_list[1]),33);
        bufp->chgIData(oldp+92,(vlSelf->ysyx_23060219_top__DOT__i3__DOT__i0__DOT__data_list[0]),32);
        bufp->chgIData(oldp+93,(vlSelf->ysyx_23060219_top__DOT__i3__DOT__i0__DOT__data_list[1]),32);
        bufp->chgIData(oldp+94,(vlSelf->ysyx_23060219_top__DOT__i3__DOT__i0__DOT__lut_out),32);
        bufp->chgBit(oldp+95,(vlSelf->ysyx_23060219_top__DOT__i3__DOT__i0__DOT__hit));
        __Vtemp_hf226ec2e__0[0U] = (IData)((0x100000000ULL 
                                            | (QData)((IData)(vlSelf->ysyx_23060219_top__DOT__src1))));
        __Vtemp_hf226ec2e__0[1U] = ((vlSelf->ysyx_23060219_top__DOT__pc 
                                     << 1U) | (IData)(
                                                      ((0x100000000ULL 
                                                        | (QData)((IData)(vlSelf->ysyx_23060219_top__DOT__src1))) 
                                                       >> 0x20U)));
        __Vtemp_hf226ec2e__0[2U] = (vlSelf->ysyx_23060219_top__DOT__pc 
                                    >> 0x1fU);
        bufp->chgWData(oldp+96,(__Vtemp_hf226ec2e__0),66);
        bufp->chgQData(oldp+99,(vlSelf->ysyx_23060219_top__DOT__i4__DOT__i0__DOT__pair_list[0]),33);
        bufp->chgQData(oldp+101,(vlSelf->ysyx_23060219_top__DOT__i4__DOT__i0__DOT__pair_list[1]),33);
        bufp->chgIData(oldp+103,(vlSelf->ysyx_23060219_top__DOT__i4__DOT__i0__DOT__data_list[0]),32);
        bufp->chgIData(oldp+104,(vlSelf->ysyx_23060219_top__DOT__i4__DOT__i0__DOT__data_list[1]),32);
        bufp->chgIData(oldp+105,(vlSelf->ysyx_23060219_top__DOT__i4__DOT__i0__DOT__lut_out),32);
        bufp->chgBit(oldp+106,(vlSelf->ysyx_23060219_top__DOT__i4__DOT__i0__DOT__hit));
        __Vtemp_h532fcdf4__0[0U] = (IData)((0x300000000ULL 
                                            | (QData)((IData)(vlSelf->ysyx_23060219_top__DOT__csr_val))));
        __Vtemp_h532fcdf4__0[1U] = ((vlSelf->ysyx_23060219_top__DOT__result 
                                     << 2U) | (IData)(
                                                      ((0x300000000ULL 
                                                        | (QData)((IData)(vlSelf->ysyx_23060219_top__DOT__csr_val))) 
                                                       >> 0x20U)));
        __Vtemp_h532fcdf4__0[2U] = (8U | ((vlSelf->ysyx_23060219_top__DOT__mem_rdata 
                                           << 4U) | 
                                          (vlSelf->ysyx_23060219_top__DOT__result 
                                           >> 0x1eU)));
        __Vtemp_h532fcdf4__0[3U] = (0x10U | ((((IData)(4U) 
                                               + vlSelf->ysyx_23060219_top__DOT__pc) 
                                              << 6U) 
                                             | (vlSelf->ysyx_23060219_top__DOT__mem_rdata 
                                                >> 0x1cU)));
        __Vtemp_h532fcdf4__0[4U] = (((IData)(4U) + vlSelf->ysyx_23060219_top__DOT__pc) 
                                    >> 0x1aU);
        bufp->chgWData(oldp+107,(__Vtemp_h532fcdf4__0),136);
        bufp->chgQData(oldp+112,(vlSelf->ysyx_23060219_top__DOT__i5__DOT__i0__DOT__pair_list[0]),34);
        bufp->chgQData(oldp+114,(vlSelf->ysyx_23060219_top__DOT__i5__DOT__i0__DOT__pair_list[1]),34);
        bufp->chgQData(oldp+116,(vlSelf->ysyx_23060219_top__DOT__i5__DOT__i0__DOT__pair_list[2]),34);
        bufp->chgQData(oldp+118,(vlSelf->ysyx_23060219_top__DOT__i5__DOT__i0__DOT__pair_list[3]),34);
        bufp->chgIData(oldp+120,(vlSelf->ysyx_23060219_top__DOT__i5__DOT__i0__DOT__data_list[0]),32);
        bufp->chgIData(oldp+121,(vlSelf->ysyx_23060219_top__DOT__i5__DOT__i0__DOT__data_list[1]),32);
        bufp->chgIData(oldp+122,(vlSelf->ysyx_23060219_top__DOT__i5__DOT__i0__DOT__data_list[2]),32);
        bufp->chgIData(oldp+123,(vlSelf->ysyx_23060219_top__DOT__i5__DOT__i0__DOT__data_list[3]),32);
        bufp->chgIData(oldp+124,(vlSelf->ysyx_23060219_top__DOT__i5__DOT__i0__DOT__lut_out),32);
        bufp->chgBit(oldp+125,(vlSelf->ysyx_23060219_top__DOT__i5__DOT__i0__DOT__hit));
        bufp->chgSData(oldp+126,(vlSelf->ysyx_23060219_top__DOT__imm_extend_inst__DOT__imm_12),12);
        bufp->chgIData(oldp+127,(vlSelf->ysyx_23060219_top__DOT__imm_extend_inst__DOT__imm_20),20);
        bufp->chgIData(oldp+128,(vlSelf->ysyx_23060219_top__DOT__imm_extend_inst__DOT__imm_12_to_32),32);
        bufp->chgIData(oldp+129,(vlSelf->ysyx_23060219_top__DOT__imm_extend_inst__DOT__imm_20_to_32),32);
        bufp->chgIData(oldp+130,(vlSelf->ysyx_23060219_top__DOT__mem_inst__DOT__rdata_temp),32);
        bufp->chgIData(oldp+131,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__i),32);
        bufp->chgIData(oldp+132,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[0]),32);
        bufp->chgIData(oldp+133,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[1]),32);
        bufp->chgIData(oldp+134,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[2]),32);
        bufp->chgIData(oldp+135,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[3]),32);
        bufp->chgIData(oldp+136,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[4]),32);
        bufp->chgIData(oldp+137,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[5]),32);
        bufp->chgIData(oldp+138,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[6]),32);
        bufp->chgIData(oldp+139,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[7]),32);
        bufp->chgIData(oldp+140,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[8]),32);
        bufp->chgIData(oldp+141,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[9]),32);
        bufp->chgIData(oldp+142,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[10]),32);
        bufp->chgIData(oldp+143,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[11]),32);
        bufp->chgIData(oldp+144,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[12]),32);
        bufp->chgIData(oldp+145,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[13]),32);
        bufp->chgIData(oldp+146,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[14]),32);
        bufp->chgIData(oldp+147,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[15]),32);
        bufp->chgIData(oldp+148,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[16]),32);
        bufp->chgIData(oldp+149,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[17]),32);
        bufp->chgIData(oldp+150,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[18]),32);
        bufp->chgIData(oldp+151,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[19]),32);
        bufp->chgIData(oldp+152,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[20]),32);
        bufp->chgIData(oldp+153,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[21]),32);
        bufp->chgIData(oldp+154,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[22]),32);
        bufp->chgIData(oldp+155,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[23]),32);
        bufp->chgIData(oldp+156,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[24]),32);
        bufp->chgIData(oldp+157,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[25]),32);
        bufp->chgIData(oldp+158,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[26]),32);
        bufp->chgIData(oldp+159,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[27]),32);
        bufp->chgIData(oldp+160,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[28]),32);
        bufp->chgIData(oldp+161,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[29]),32);
        bufp->chgIData(oldp+162,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[30]),32);
        bufp->chgIData(oldp+163,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[31]),32);
        bufp->chgIData(oldp+164,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__src1_temp),32);
    }
    bufp->chgBit(oldp+165,(vlSelf->clk));
    bufp->chgBit(oldp+166,(vlSelf->rst));
    bufp->chgIData(oldp+167,(vlSelf->mstatus),32);
    bufp->chgIData(oldp+168,(vlSelf->mepc),32);
    bufp->chgIData(oldp+169,(vlSelf->mtvec),32);
    bufp->chgIData(oldp+170,(vlSelf->mcause),32);
}

void Vysyx_23060219_top___024root__trace_cleanup(void* voidSelf, VerilatedFst* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_23060219_top___024root__trace_cleanup\n"); );
    // Init
    Vysyx_23060219_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vysyx_23060219_top___024root*>(voidSelf);
    Vysyx_23060219_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}
