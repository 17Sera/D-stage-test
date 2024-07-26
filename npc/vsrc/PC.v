
module PC (
    input           clk     ,
    input           rst_n   ,
    input   [31:0]  PCNext  ,
    output  [31:0]  PC
);
    
//Reg #( 传输数据的位宽，复位值 ) 例化名称 （ 时钟，复位，写入信号(输入)，被写入信号(输出)，写使能 ）;

    Reg #( 32 , 32'h80000000 ) PC_u ( clk , rst_n , PCNext , PC , 1'b1 );

endmodule




// module PC#(parameter WIDTH=8)(
//     input                       clk,
//     input                       reset,
//     input       [WIDTH-1:0]     d,  //PCNext
//     output  reg [WIDTH-1:0]     q   //PC

//     );
//     always@(posedge clk)begin
//         if(reset)
//             q <= 32'h80000000;
//         else
//             q <= d;
//     end
           
// endmodule
