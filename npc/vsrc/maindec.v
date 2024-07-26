module maindec(     //idu主要的译码模块   输入opcode
  input       [6:0]       op          ,   //会被controler模块连起来，然后被riscv-single连起来，然后被top连起来
  output      [1:0]       ResultSrc   ,   //MemtoReg，控制把什么写回给寄存器堆（alu的计算结果 还是 数据存储器中的值）
  output                  MemWrite    ,   //存储器写使能信号
  output                  Branch      ,   //跳转使能信号
  output                  ALUSrc      ,   //输入到ALU的数选器选择信号，指令的两个源操作数为寄存器还是imm
  output                  RegWrite    ,   //寄存器写使能信号
  output                  Jump        ,   //跳转使能信号
  output      [1:0]       ImmSrc      ,   //控制着立即数扩展单元
  output      [1:0]       ALUOp           //输入ALU_control的控制信号
  );

  wire [10:0] controls;

  assign {RegWrite, ImmSrc, ALUSrc, MemWrite, ResultSrc, Branch, ALUOp, Jump} = controls;

//  MuxKey #(有多少对，key的位宽，输出的位宽)  名称  (输出，key，lut)
  MuxKey #( 6, 7, 11 ) maindec_muxkey ( controls, op, {
    7'b0010011 , 11'b1_00_1_0_00_0_10_0 , // I-type ALU  addi
    7'b0000011 , 11'b1_00_1_0_01_0_00_0 , // lw
    7'b0100011 , 11'b0_01_1_1_00_0_00_0 , // sw
    7'b0110011 , 11'b1_xx_0_0_00_0_10_0 , // R-type
    7'b1100011 , 11'b0_10_0_0_00_1_01_0 , // beq
    7'b1101111 , 11'b1_11_0_0_10_0_00_1  // jal
  } );


  // always@(*)begin
  //     case( op )
  //     // RegWrite_ImmSrc_ALUSrc_MemWrite_ResultSrc_Branch_ALUOp_Jump
  //       7'b0010011: controls = 11'b1_00_1_0_00_0_10_0; // I-type ALU  addi
  //       7'b0000011: controls = 11'b1_00_1_0_01_0_00_0; // lw
  //       7'b0100011: controls = 11'b0_01_1_1_00_0_00_0; // sw
  //       7'b0110011: controls = 11'b1_xx_0_0_00_0_10_0; // R-type
  //       7'b1100011: controls = 11'b0_10_0_0_00_1_01_0; // beq
  //       7'b1101111: controls = 11'b1_11_0_0_10_0_00_1; // jal
  //       default:    controls = 11'b0_00_0_0_00_0_00_0; // ??? 
  //       //default:    controls = 11'bx_xx_x_x_xx_x_xx_x; // ??? 
  //     endcase
  // end
endmodule


