// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vysyx_23060219_top.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "Vysyx_23060219_top__Syms.h"
#include "Vysyx_23060219_top___024root.h"

extern "C" int pmem_read(int raddr, int num);

VL_INLINE_OPT void Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__mem_inst__DOT__pmem_read_TOP(IData/*31:0*/ raddr, IData/*31:0*/ num, IData/*31:0*/ &pmem_read__Vfuncrtn) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__mem_inst__DOT__pmem_read_TOP\n"); );
    // Body
    int raddr__Vcvt;
    for (size_t raddr__Vidx = 0; raddr__Vidx < 1; ++raddr__Vidx) raddr__Vcvt = raddr;
    int num__Vcvt;
    for (size_t num__Vidx = 0; num__Vidx < 1; ++num__Vidx) num__Vcvt = num;
    int pmem_read__Vfuncrtn__Vcvt;
    pmem_read__Vfuncrtn__Vcvt = pmem_read(raddr__Vcvt, num__Vcvt);
    pmem_read__Vfuncrtn = pmem_read__Vfuncrtn__Vcvt;
}

extern "C" void pmem_write(int waddr, int wdata, char wmask);

VL_INLINE_OPT void Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__mem_inst__DOT__pmem_write_TOP(IData/*31:0*/ waddr, IData/*31:0*/ wdata, CData/*7:0*/ wmask) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__mem_inst__DOT__pmem_write_TOP\n"); );
    // Body
    int waddr__Vcvt;
    for (size_t waddr__Vidx = 0; waddr__Vidx < 1; ++waddr__Vidx) waddr__Vcvt = waddr;
    int wdata__Vcvt;
    for (size_t wdata__Vidx = 0; wdata__Vidx < 1; ++wdata__Vidx) wdata__Vcvt = wdata;
    char wmask__Vcvt;
    for (size_t wmask__Vidx = 0; wmask__Vidx < 1; ++wmask__Vidx) wmask__Vcvt = wmask;
    pmem_write(waddr__Vcvt, wdata__Vcvt, wmask__Vcvt);
}

extern "C" void ebreak(int station, int inst, char unit);

VL_INLINE_OPT void Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__mem_inst__DOT__ebreak_TOP(IData/*31:0*/ station, IData/*31:0*/ inst, CData/*7:0*/ unit) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__mem_inst__DOT__ebreak_TOP\n"); );
    // Body
    int station__Vcvt;
    for (size_t station__Vidx = 0; station__Vidx < 1; ++station__Vidx) station__Vcvt = station;
    int inst__Vcvt;
    for (size_t inst__Vidx = 0; inst__Vidx < 1; ++inst__Vidx) inst__Vcvt = inst;
    char unit__Vcvt;
    for (size_t unit__Vidx = 0; unit__Vidx < 1; ++unit__Vidx) unit__Vcvt = unit;
    ebreak(station__Vcvt, inst__Vcvt, unit__Vcvt);
}

extern "C" void etrace(int inst);

VL_INLINE_OPT void Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__control_unit_inst__DOT__etrace_TOP(IData/*31:0*/ inst) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__control_unit_inst__DOT__etrace_TOP\n"); );
    // Body
    int inst__Vcvt;
    for (size_t inst__Vidx = 0; inst__Vidx < 1; ++inst__Vidx) inst__Vcvt = inst;
    etrace(inst__Vcvt);
}

VL_INLINE_OPT void Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__csr_reg_inst__DOT__ebreak_TOP(IData/*31:0*/ station, IData/*31:0*/ inst, CData/*7:0*/ uint) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__csr_reg_inst__DOT__ebreak_TOP\n"); );
    // Body
    int station__Vcvt;
    for (size_t station__Vidx = 0; station__Vidx < 1; ++station__Vidx) station__Vcvt = station;
    int inst__Vcvt;
    for (size_t inst__Vidx = 0; inst__Vidx < 1; ++inst__Vidx) inst__Vcvt = inst;
    char uint__Vcvt;
    for (size_t uint__Vidx = 0; uint__Vidx < 1; ++uint__Vidx) uint__Vcvt = uint;
    ebreak(station__Vcvt, inst__Vcvt, uint__Vcvt);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vysyx_23060219_top___024root___dump_triggers__act(Vysyx_23060219_top___024root* vlSelf);
#endif  // VL_DEBUG

void Vysyx_23060219_top___024root___eval_triggers__act(Vysyx_23060219_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_23060219_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_23060219_top___024root___eval_triggers__act\n"); );
    // Body
    vlSelf->__VactTriggered.at(0U) = ((IData)(vlSelf->clk) 
                                      & (~ (IData)(vlSelf->__Vtrigrprev__TOP__clk)));
    vlSelf->__Vtrigrprev__TOP__clk = vlSelf->clk;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vysyx_23060219_top___024root___dump_triggers__act(vlSelf);
    }
#endif
}
