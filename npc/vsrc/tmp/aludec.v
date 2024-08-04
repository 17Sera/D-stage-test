// //子控制器根据主控制器产生的ALUop信号，结合func3和func7信号来产生ALUctl信号。
// module aludec(    //idu次要译码模块   输入fun3 fun7
//   input                   opb5        ,   //op[5]
//   input       [2:0]       funct3      ,
//   input                   funct7b5    ,
//   input       [1:0]       ALUOp       ,   //maindec产生的
//   output      [2:0]       ALUControl
//   );

//   wire   RtypeSub ;
//   wire   [2:0]  tmp_ALUcontrol;


//   assign RtypeSub = funct7b5 & opb5;    //判断是否进行 R-type 的减法运算
//   assign tmp_ALUcontrol = (ALUOp == 2'b00)   ? 3'b000 :   // ALUOp = 00 -> 加法
//                           (ALUOp == 2'b01)   ? 3'b001 :   // ALUOp = 01 -> 减法
//                           (funct3 == 3'b000) ? (RtypeSub ? 3'b001 : 3'b000) : //减法 ： 加法
//                           (funct3 == 3'b010) ? 3'b101 :   // funct3 = 010 //// slt, slti
//                           (funct3 == 3'b110) ? 3'b011 :   // funct3 = 110 // or, ori
//                           (funct3 == 3'b111) ? 3'b010 :   // funct3 = 111 // and, andi
//                           3'bxxx;  // 默认情况下

//   assign ALUControl = tmp_ALUcontrol ;

//   // always@(*)begin
//   //   case( ALUOp )
//   //     2'b00:  ALUControl = 3'b000;      // 加法
//   //     2'b01:  ALUControl = 3'b001;      // 减法
//   //     default: 
//   //       case( funct3 )     // 根据funct3 的值进一步选择 R-type or I-type ALU
//   //         3'b000:begin
//   //                     if ( RtypeSub )
//   //                       ALUControl = 3'b001; // sub
//   //                     else
//   //                       ALUControl = 3'b000; // add, addi
//   //                 end
//   //         3'b010:       ALUControl = 3'b101; // slt, slti
//   //         3'b110:       ALUControl = 3'b011; // or, ori
//   //         3'b111:       ALUControl = 3'b010; // and, andi
//   //         default:      ALUControl = 3'bxxx; // ???
//   //     endcase
//   //   endcase
//   // end

// endmodule
