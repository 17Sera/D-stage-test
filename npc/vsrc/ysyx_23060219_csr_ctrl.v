// `include "/home/zhong/ysyx-workbench/npc/vsrc/ysyx_23060219_defines.v"
// module ysyx_23060219_csr_ctrl(
//     // system
//     input  wire            clk,
//     input  wire            rst,
//     // from IDU
//     input  wire             i_ccu_csr_ren,
//     input  wire [`CSR_Bus]  i_ccu_csr_rid,  // 直接从 IDU 连接过来
//     input  wire             i_ccu_is_mret,
//     input  wire             i_ccu_is_ecall,
//     // from WBU
//     input  wire             i_ccu_csr_wen,
//     input  wire [`CSR_Bus]  i_ccu_csr_wid,  // 和i_ccu_csr_rid是同一个数据源。但从 IDU--->EXU--->LSU--->WBU传过来
//     input  wire [31:0]      i_ccu_csr_rd,
//     input  wire [31:0]      i_ccu_macuse_in,
//     input  wire [31:0]      i_ccu_mepc_in,
//     // to EXU
//     output reg  [31:0]      o_exu_csr_src,
//     output wire [`CPU_Bus]  o_exu_csr_npc
// );

//     import "DPI-C" function void TRAP(input int station, input byte unit);

//     reg [31:0] mstatus;
//     reg [31:0] mtvec;
//     reg [31:0] mepc;
//     reg [31:0] mcause;

//     reg [31:0] mvendorid; 
//     reg [31:0] marchid_1;
//     reg [31:0] marchid_2;


//     // write register
//     always @(posedge clk) begin
//         if(rst == `RST_VAL) begin
//             mstatus     <=  `RegRstVal;  
//             mtvec       <=  `RegRstVal;  
//             mepc        <=  `RegRstVal;  
//             mcause      <=  `RegRstVal;  
//             mvendorid   <=  32'h79737978;               //  ysyx_23060219 ， 0x32333036 , 0x30323139
//             marchid_1   <=  32'h32333036;               //  每个数字的ASCII码值 转16进制
//             marchid_2   <=  32'h30323139;
//         end 
//         else if (i_ccu_is_ecall == `TRUE) begin
//             mcause  <= i_ccu_macuse_in;
//             mepc    <= i_ccu_mepc_in;
//         end 
//         else if (i_ccu_csr_wen == `Enable) begin
//             case (i_ccu_csr_wid)
//                 12'h300 : mstatus   <= i_ccu_csr_rd;
//                 12'h305 : mtvec     <= i_ccu_csr_rd;
//                 12'h341 : mepc      <= i_ccu_csr_rd;
//                 12'h342 : mcause    <= i_ccu_csr_rd;
//                 12'hFC0 : mvendorid <= i_ccu_csr_rd;     ///  CSR  0xC00 ~ 0xFFF：调试用途
//                 12'hFC1 : marchid_1 <= i_ccu_csr_rd;
//                 12'hFC2 : marchid_2 <= i_ccu_csr_rd;
//                 default: TRAP(`ABORT, `Unit_CC1);  
//             endcase
//         end 
//     end

//     // read register
//     always @(*) begin
//         if (i_ccu_csr_ren == `Enable)
//             case (i_ccu_csr_rid)
//                 12'h300 : o_exu_csr_src = mstatus;
//                 12'h305 : o_exu_csr_src = mtvec;
//                 12'h341 : o_exu_csr_src = mepc;
//                 12'h342 : o_exu_csr_src = mcause;
//                 12'hFC0 : o_exu_csr_src = mvendorid;     ///  CSR  0xC00 ~ 0xFFF：调试用途
//                 12'hFC1 : o_exu_csr_src = marchid_1;
//                 12'hFC2 : o_exu_csr_src = marchid_2;
//                 default: begin 
//                     o_exu_csr_src = 32'hdead001c;
//                     TRAP(`ABORT, `Unit_CC2);                
//                 end
//             endcase
//         else begin
//                 mstatus   = mstatus;
//                 mtvec     = mtvec  ;
//                 mepc      = mepc   ;
//                 mcause    = mcause ;
//                 mvendorid = mvendorid;
//                 marchid_1 = marchid_1;
//                 marchid_2 = marchid_2;
//         end
//     end

//     assign o_exu_csr_npc = (i_ccu_is_mret  == `TRUE) ? mepc  : 
//                            (i_ccu_is_ecall == `TRUE) ? mtvec : 32'hdead005a;

// endmodule
