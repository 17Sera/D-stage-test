// module maindec(     //idu主要的译码模块   输入opcode
//   input       [6:0]       op          ,   //会被controler模块连起来，然后被riscv-single连起来，然后被top连起来
//   output      [1:0]       ResultSrc   ,   //MemtoReg，控制把什么写回给寄存器堆（alu的计算结果 还是 数据存储器中的值）
//   output                  MemWrite    ,   //存储器写使能信号
//   output                  Branch      ,   //跳转使能信号
//   output                  ALUSrc      ,   //输入到ALU的数选器选择信号，指令的两个源操作数为寄存器还是imm
//   output                  RegWrite    ,   //寄存器写使能信号
//   output                  Jump        ,   //跳转使能信号
//   output      [2:0]       ImmSrc      ,   //控制着立即数扩展单元
//   output      [1:0]       ALUOp           //输入ALU_control的控制信号
//   );

//   wire [11:0] controls;

//   assign {RegWrite, ImmSrc, ALUSrc, MemWrite, ResultSrc, Branch, ALUOp, Jump} = controls;

// //  MuxKey #(有多少对，key的位宽，输出的位宽)  名称  (输出，key，lut)
//   MuxKey #( 9, 7, 12 ) maindec_muxkey ( controls, op, {
//       7'b0010011 , 12'b1_000_1_0_00_0_10_0 ,   // I-type ALU  addi
//       7'b0000011 , 12'b1_000_1_0_01_0_00_0 ,   // lw
//       7'b0100011 , 12'b0_001_1_1_00_0_00_0 ,   // sw
//       7'b0110011 , 12'b1_xxx_0_0_00_0_10_0 ,   // R-type
//       7'b1100011 , 12'b0_010_0_0_00_1_01_0 ,   // beq
//       7'b1101111 , 12'b1_011_0_0_10_0_00_1 ,   // jal  把PC+4写回寄存器堆
//       7'b1100111 , 12'b1_000_0_0_10_0_00_1 ,   // jalr                 ////////////////////////////
//       7'b0010111 , 12'b1_100_x_0_11_0_xx_0 ,   // auipc
//       7'b0110111 , 12'b1_101_1_0_00_0_xx_0     // lui
//   } );

// //RegWrite=1，ResultSrc = 10，因为需要将PC+4写到寄存器文件中
// //RegWrite 寄存器堆的写使能
// //ResultSrc是MemtoReg，控制把什么写回给寄存器堆
// //ResultSrc = 00(ALUResult)-----ResultSrc = 01(ReadData)-----ResultSrc = 10(PCPlus4) --- ResultSrc = 11(PC + immext)

// //没有用到立即数，ImmSrc为xx
// //immsrc 用于选择I S B J 类型，imm有多少位
// //immsrc 000 --- I-type ，， 001 --- S-type ，，010 --- B-type ，， 011 --- J-type ,, 100 --- auipc ,, 101 --- lui

// //两个源操作数为寄存器操---ALUSrc=0，，，其中一个是imm---ALUSrc=1
// //MemWrite = 0，因为不需要写入存储器
// //Branch=0，因为指令不是分支，控制模块的PCSrc就是Branch---Branch和zero的相与
// //最后jump=1，因为要跳转。分支和跳转是有区别的。
// //ALUOp 只用于得到 ALUControl  ， aludec中
// //// ALUOp = 00 -> 加法 ，，，// ALUOp = 01 -> 减法


// endmodule






