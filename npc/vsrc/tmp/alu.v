// // module ysyx_23060219_ALU(   //rv32_dd_sub
// //   input [31:0] a,
// //   input [31:0] b,
// //   input [2:0] alu_control,
// //   output overflow,
// //   output carry, 
// //   output negative,
// //   output zero,
// //   output [31:0]result
// // );
// //   wire [31:0] my_addsub;
// //   wire [31:0] my_and;
// //   wire [31:0] my_or;
// //   wire cout;
// //   wire [31:0] b_selected;
// //   wire over1, over2;

// //   assign b_selected = b ^ { 32{ alu_control[0] } };
// //   assign { cout, my_addsub } = a + b_selected + alu_control[0];
// //   assign over1 = ~( alu_control[0] ^ a[31] ^ b[31] );
// //   assign over2 = a[31] ^ my_addsub[31];
// //   assign my_and = a & b;
// //   assign my_or = a | b;

// //   MuxKey #(4,3,32) alu_muxkey( result , alu_control, {
// //     3'b000 , my_addsub,
// //     3'b001 , my_addsub,
// //     3'b010 , my_and,
// //     3'b011 , my_or
// //   } );

// //   assign overflow = over1 & over2 & (~alu_control[1]);
// //   assign carry = cout & (~alu_control[1]);
// //   assign zero = ~( |result );
// //   assign negative = result[31];

// // endmodule

// //-----------------------------------------------------------------------
// module alu(
//     input       [2:0]       ALUControl,
//     input       [31:0]      SrcA,
//     input       [31:0]      SrcB,
//     output                  Zero,
//     output      [31:0]      ALUResult
//     );

//   wire [31:0] condinvb, sum; 
//   wire        cout ;
//   wire tmp;
//   assign tmp = cout ;
//   assign tmp = tmp;
   
//   assign condinvb = ALUControl[0] ? ~SrcB : SrcB; 
//   //assign {cout, sum} = SrcA + condinvb + ALUControl[0]; 
//   assign {cout, sum} = SrcA + condinvb + {31'b0, ALUControl[0]}; 
//   assign Zero = (SrcA-SrcB==0)?1:0;
   

// //  MuxKey #(有多少对，key的位宽，输出的位宽)  名称  (输出，key，lut)
//   MuxKey #( 5, 3, 32 ) alu_mux ( ALUResult, ALUControl, {
//     3'b000 , sum ,
//     3'b001 , sum ,
//     3'b010 , SrcA & SrcB , 
//     3'b011 , SrcA | SrcB ,
//     3'b101 , {31'b0,sum[31]}
//     //3'b101 , sum[31]            // 位宽不对齐
//   } );

// endmodule

