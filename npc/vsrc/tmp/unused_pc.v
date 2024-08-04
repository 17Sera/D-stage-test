// module ysyx_23060219_pc (
//     input   clk,
//     input   rst_n,
//     input [31:0] pc_new,    //下一条要取指的pc
//     output [31:0] pc_out    //现在要取指的指令，要输出到instr_mem里
// );  

//     Reg #( 32 , 32'b0 ) pc ( clk, rst_n, pc_new, pc_out, 1'b1 );


// endmodule


// // D触发器模板  //复位值可自定义RESET_VAL
// module Reg #(WIDTH = 1, RESET_VAL = 0) (
//   input clk,
//   input rst,
//   input [WIDTH-1:0] din,
//   output reg [WIDTH-1:0] dout,
//   input wen
// );
//   always @(posedge clk) begin
//     if (rst) dout <= RESET_VAL;
//     else if (wen) dout <= din;
//   end
// endmodule
