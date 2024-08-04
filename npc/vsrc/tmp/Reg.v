//  //-----------------------------------------------------------------------------------------------------
// // D触发器模板  //复位值可自定义RESET_VAL
// //Reg #( 传输数据的位宽，复位值 ) 例化名称 （ 时钟，复位，写入信号(输入)，被写入信号(输出)，写使能 ）;
// module Reg #(WIDTH = 1, RESET_VAL = 0) (
//   input clk,
//   input rst,
//   input [WIDTH-1:0] din,
//   output reg [WIDTH-1:0] dout,
//   input wen
// );
//   always @(posedge clk) begin
//     if (rst) dout <= RESET_VAL;   //高电平复位
//     else if (wen) dout <= din;
//   end
// endmodule

