// module regfile( 
// 	input		        clk,
// 	input 		      rst_n,
// 	input   [4:0]	  A1,         //rs1在寄存器堆中的序号
// 	input   [4:0]	  A2,         //rs2在寄存器堆中的序号
// 	input   [4:0]	  A3,        //rd 目标寄存器序号
// 	input 		      WE3,        //寄存器的写使能信号
// 	input   [31:0]	WD3,        //rd 目标寄存器 写入的值
// 	output  [31:0]  RD1,        //从rs1中读出的值
// 	output  [31:0]  RD2         //从rs2中读出的值
// );

// 	reg [31:0] register [0:31]; 
 

// // always @ (negedge clk or negedge rst_n) begin
// //   if(!rst_n) 
// //   begin    //reset_all_registers
// //     integer i;
// //   for(i=0;i<32;i=i+1)
// //     register[i] <= 32'd00000001;
// //   end
// //   else begin
// //   if((WE3 == 1'b1) && (A3 != 5'h0)) begin  //写使能开启且写入的不是零寄存器
// //     register[A3] <= WD3;
// //     end
// //   end
// // end


// //Reg #( 传输数据的位宽，复位值 ) 例化名称 （ 时钟，复位，写入信号(输入)，被写入信号(输出)，写使能 ）;
// //针对 rd 目标寄存器的写入功能
//   Reg #( 32, 32'd0 ) write_rd_reg ( clk, rst_n, WD3, register[A3], WE3 );  //模板未检查写入的是不是零寄存器

// //针对复位全部寄存器
//   Reg #( 32, 32'd0 ) reset_reg_0 ( clk, rst_n, 0, register[0], 1'b1 );    //模板未检查写入的是不是零寄存器
//   Reg #( 32, 32'd0 ) reset_reg_1 ( clk, rst_n, register[1], register[1], 1'b1 );
//   Reg #( 32, 32'd0 ) reset_reg_2 ( clk, rst_n, register[2], register[2], 1'b1 );
//   Reg #( 32, 32'd0 ) reset_reg_3 ( clk, rst_n, register[3], register[3], 1'b1 );
//   Reg #( 32, 32'd0 ) reset_reg_4 ( clk, rst_n, register[4], register[4], 1'b1 );

//   Reg #( 32, 32'd0 ) reset_reg_5 ( clk, rst_n, register[5], register[5], 1'b1 );
//   Reg #( 32, 32'd0 ) reset_reg_6 ( clk, rst_n, register[6], register[6], 1'b1 );
//   Reg #( 32, 32'd0 ) reset_reg_7 ( clk, rst_n, register[7], register[7], 1'b1 );
//   Reg #( 32, 32'd0 ) reset_reg_8 ( clk, rst_n, register[8], register[8], 1'b1 );

//   Reg #( 32, 32'd0 ) reset_reg_9 ( clk, rst_n, register[9], register[9], 1'b1 );
//   Reg #( 32, 32'd0 ) reset_reg_10 ( clk, rst_n, register[10], register[10], 1'b1 );
//   Reg #( 32, 32'd0 ) reset_reg_11 ( clk, rst_n, register[11], register[11], 1'b1 );
//   Reg #( 32, 32'd0 ) reset_reg_12 ( clk, rst_n, register[12], register[12], 1'b1 );

//   Reg #( 32, 32'd0 ) reset_reg_13 ( clk, rst_n, register[13], register[13], 1'b1 );
//   Reg #( 32, 32'd0 ) reset_reg_14 ( clk, rst_n, register[14], register[14], 1'b1 );
//   Reg #( 32, 32'd0 ) reset_reg_15 ( clk, rst_n, register[15], register[15], 1'b1 );
//   Reg #( 32, 32'd0 ) reset_reg_16 ( clk, rst_n, register[16], register[16], 1'b1 );

//   Reg #( 32, 32'd0 ) reset_reg_17 ( clk, rst_n, register[17], register[17], 1'b1 );
//   Reg #( 32, 32'd0 ) reset_reg_18 ( clk, rst_n, register[18], register[18], 1'b1 );
//   Reg #( 32, 32'd0 ) reset_reg_19 ( clk, rst_n, register[19], register[19], 1'b1 );
//   Reg #( 32, 32'd0 ) reset_reg_20 ( clk, rst_n, register[20], register[20], 1'b1 );

//   Reg #( 32, 32'd0 ) reset_reg_21 ( clk, rst_n, register[21], register[21], 1'b1 );
//   Reg #( 32, 32'd0 ) reset_reg_22 ( clk, rst_n, register[22], register[22], 1'b1 );
//   Reg #( 32, 32'd0 ) reset_reg_23 ( clk, rst_n, register[23], register[23], 1'b1 );
//   Reg #( 32, 32'd0 ) reset_reg_24 ( clk, rst_n, register[24], register[24], 1'b1 );

//   Reg #( 32, 32'd0 ) reset_reg_25 ( clk, rst_n, register[25], register[25], 1'b1 );
//   Reg #( 32, 32'd0 ) reset_reg_26 ( clk, rst_n, register[26], register[26], 1'b1 );
//   Reg #( 32, 32'd0 ) reset_reg_27 ( clk, rst_n, register[27], register[27], 1'b1 );
//   Reg #( 32, 32'd0 ) reset_reg_28 ( clk, rst_n, register[28], register[28], 1'b1 );

//   Reg #( 32, 32'd0 ) reset_reg_29 ( clk, rst_n, register[29], register[29], 1'b1 );
//   Reg #( 32, 32'd0 ) reset_reg_30 ( clk, rst_n, register[30], register[30], 1'b1 );
//   Reg #( 32, 32'd0 ) reset_reg_31 ( clk, rst_n, register[31], register[31], 1'b1 );


//   assign RD1 = (A1 == 5'd0) ? 32'd0 : register[A1];    //条件：读的不是零寄存器

//   assign RD2 = (A2 == 5'd0) ? 32'd0 : register[A2];

// endmodule
