// `include "/home/zhong/ysyx-workbench/npc/vsrc/ysyx_23060219_defines.v"

// module ysyx_23060219_wbu(
//     input  wire             clk,
//     input  wire             rst,
//     // shake hands
//     input  reg              i_pre_valid,   //来自LSU，代表LSU的数据有效
//     output wire             o_pre_ready,   //传递给LSU，代表WBU准备好处理新数据了，用不上
//     output reg              o_cycle_end,   //传递给IFU，代表一个指令周期的结束
//     // from IFU
//     input  wire [`CPU_Bus]  i_wbu_pc,
//     // from IDU
//     input  wire [4:0]       i_wbu_rd_id,
//     input  wire             i_wbu_gpr_wen,  
//     // from Register File
//     input  wire [31:0]      i_wbu_rs1,
//     // from LSU
//     input  wire             i_wbu_is_mret,
//     input  wire             i_wbu_is_ecall,
//     input  wire [`CSR_Bus]  i_wbu_csr_wid,
//     input  wire [31:0]      i_wbu_csr_rd,
//     input  wire             i_wbu_csr_wen,
//     // from LSU
//     input  wire [31:0]      i_wbu_rd,
//     // to BRU
//     output wire             o_wbu_npc_wen,
//     // to Register File
//     output wire [31:0]      o_wbu_rd,
//     output wire [4:0]       o_wbu_rd_id,
//     output wire             o_wbu_gpr_wen,
//     // to CSR Ctrl
//     output wire [31:0]      o_wbu_mcause_in,
//     output wire [31:0]      o_wbu_mepc_in,
//     output wire             o_wbu_csr_wen,  
//     output wire [`CSR_Bus]  o_wbu_csr_wid,
//     output wire [31:0]      o_wbu_csr_rd
// );

// /* -------------------------------------------------------------------------------- */

//     reg pre_valid_reg;
//     always @(posedge clk) begin
//         if(rst == 1'b1) 
//             pre_valid_reg <= 1'b0;
//         else
//             pre_valid_reg <= i_pre_valid;
//     end

// /* -------------------------------------------------------------------------------- */

//     reg delay_cycle_end_1, delay_cycle_end_2, delay_cycle_end_3;

// /* -------------------------------------------------------------------------------- */

// always @(posedge clk) begin
//     if (rst == 1'b1) 
//         delay_cycle_end_1 <= 1'b0;
//     else 
//         delay_cycle_end_1 <= i_pre_valid & ~pre_valid_reg;  // WBU和LSU握手的一周期
// end

// always @(posedge clk) begin
//     if (rst == 1'b1) 
//         delay_cycle_end_2 <= 1'b0;
//     else 
//         delay_cycle_end_2 <= delay_cycle_end_1;
// end

// always @(posedge clk) begin
//     if (rst == 1'b1) 
//         delay_cycle_end_3 <= 1'b0;
//     else 
//         delay_cycle_end_3 <= delay_cycle_end_2;
// end

// /* -------------------------------------------------------------------------------- */

// always @(posedge clk) begin
//     if (rst == 1'b1) 
//         o_cycle_end   <= 1'b1;
//     else begin
//         o_cycle_end   <= delay_cycle_end_3; 
//         o_wbu_npc_wen <= delay_cycle_end_2;
//     end
// end

// /* -------------------------------------------------------------------------------- */

//     // to LSU
//     // assign o_pre_ready     = ~o_cycle_end;      // 反不反都可以过
//     assign o_pre_ready     = delay_cycle_end_1;     // WBU LSU 用不上该变量

//     // to Register File
//     assign o_wbu_rd        = i_wbu_rd;
//     assign o_wbu_rd_id     = i_wbu_rd_id;
//     assign o_wbu_gpr_wen   = i_wbu_gpr_wen & o_wbu_npc_wen;    //只有效一周期，防止反复写入gpr  // o_wbu_gpr_wen 可以从LSU多加一个控制信号，有效数据传的同时拉高

//     // to CSR Ctrl
//     assign o_wbu_mcause_in = i_wbu_rs1;
//     assign o_wbu_mepc_in   = i_wbu_pc;
//     assign o_wbu_csr_wen   = i_wbu_csr_wen;
//     assign o_wbu_csr_wid   = i_wbu_csr_wid;
//     assign o_wbu_csr_rd    = i_wbu_csr_rd;

// endmodule



// // delay -----------------------------------------------------------------------------


// // reg delay_cycle_end_4, delay_cycle_end_5;
// // reg delay_cycle_end_6, delay_cycle_end_7, delay_cycle_end_8;
// // reg delay_cycle_end_9, delay_cycle_end_10;


// // always @(posedge clk) begin
// //     if (rst == 1'b1) 
// //         delay_cycle_end_4 <= 1'b0;
// //     else 
// //         delay_cycle_end_4 <= delay_cycle_end_3;
// // end

// // always @(posedge clk) begin
// //     if (rst == 1'b1) 
// //         delay_cycle_end_5 <= 1'b0;
// //     else 
// //         delay_cycle_end_5 <= delay_cycle_end_4;
// // end

// // always @(posedge clk) begin
// //     if (rst == 1'b1) 
// //         delay_cycle_end_6 <= 1'b0;
// //     else 
// //         delay_cycle_end_6 <= delay_cycle_end_5;
// // end

// // always @(posedge clk) begin
// //     if (rst == 1'b1) 
// //         delay_cycle_end_7 <= 1'b0;
// //     else 
// //         delay_cycle_end_7 <= delay_cycle_end_6;
// // end

// // always @(posedge clk) begin
// //     if (rst == 1'b1) 
// //         delay_cycle_end_8 <= 1'b0;
// //     else 
// //         delay_cycle_end_8 <= delay_cycle_end_7;
// // end

// // always @(posedge clk) begin
// //     if (rst == 1'b1) 
// //         delay_cycle_end_9 <= 1'b0;
// //     else 
// //         delay_cycle_end_9 <= delay_cycle_end_8;
// // end

// // always @(posedge clk) begin
// //     if (rst == 1'b1) 
// //         delay_cycle_end_10 <= 1'b0;
// //     else 
// //         delay_cycle_end_10 <= delay_cycle_end_9;
// // end