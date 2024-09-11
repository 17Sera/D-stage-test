`include "/home/zhong/ysyx-workbench/npc/vsrc/defines.v"

module ysyx_23060219_top(
  input  wire           clk,
  input  wire           rst
);
  
  wire[4:0]       rs1;
  wire[4:0]       rs2;
  wire[4:0]       rd;
  wire[2:0]       funct3;
  wire[6:0]       funct7;
/* verilator lint_off UNOPTFLAT */
  wire[31:0]   inst;     
/* verilator lint_off UNOPTFLAT */
  wire[31:0]   pc;     
  wire[`TYPE_BUS] IType;      //inst type
  wire            is_ecall;
  wire            csr_wen;
  wire            reg_wen;    //RegFile write enable
  wire            mem_wen;    //mem write enable
  wire            mem_ren;    //mem read  enable
  wire[7:0]       wmask;      //mem write mask //用于内存写入操作的写入掩码，不是每一个字节都需要写入内存，wmask的每一位
  wire[2:0]       rmask;      //mem read  mask //用于内存读出操作的读出掩码，对应位置为1才将对应的字节读出
  wire            m1;         //mux1 sel
  wire[1:0]       m2;         //mux2 sel
  wire            m3;         //mux3 sel
  wire            m4;         //mux4 sel
  wire[1:0]       m5;         //mux5 sel
  wire[`AlucBus]  aluc;       //alu operation type, like add, sub...
  wire[31:0]   PCadd4;     //pc + 4
  wire[31:0]   result;     //alu operation result
  wire[31:0]   reg_in;     //regisrer file input value
  wire[31:0]   src1;       //rs1 value
  wire[31:0]   src2;       //rs2 value
  wire[31:0]   imm32;      //extended 32 bit immediate
  wire[31:0]   num1;       //alu operation number1       
  wire[31:0]   num2;       //alu operation number2
  wire[31:0]   mem_rdata;  //mem read data
  wire[31:0]   csr_npc;
  wire[31:0]   csr_val;


  // PC module
  PC PC_inst(
    .clk      (clk), //input
    .rst      (rst), //input
    .m1       (m1),  //input
    .m2       (m2),  //input
    .result   (result), //input
    .imm32    (imm32),  //input
    .csr_npc  (csr_npc),//input
    .PCadd4   (PCadd4), //output
    .pc       (pc)      //output
  );

  // mem module
  ysyx_23060219_mem mem_inst(
    .clk      (clk),  
    .mem_wen  (mem_wen),  
    .wmask    (wmask),
    .waddr    (result),
    .wdata    (src2),
    .mem_ren  (mem_ren),  
    .rmask    (rmask),
    .raddr    (result),
    .inst_addr(pc),
    .rdata    (mem_rdata),
    .inst_data(inst)
  );

  // Control Unit module
  ysyx_23060219_control_unit control_unit_inst(
    .inst      (inst),   //input
    .rd_11_7   (rd),     //output
    .rs1_19_15 (rs1),    //output
    .rs2_24_20 (rs2),    //output
    .fun3_14_12(funct3), //output
    .fun7_31_25(funct7), //output
    .IType     (IType),  //output
    .aluc      (aluc),   //output
    .is_ecall  (is_ecall),//outout, csr
    .csr_wen   (csr_wen), //output, csr
    .reg_wen   (reg_wen),//output    
    .mem_wen   (mem_wen),//output
    .mem_ren   (mem_ren),//output  
    .wmask     (wmask),  //output
    .rmask     (rmask),  //output
    .m1        (m1),     //output
    .m2        (m2),     //output
    .m3        (m3),     //output
    .m4        (m4),     //output
    .m5        (m5)      //output
  );

  ysyx_23060219_csr_regs csr_reg_inst(
    .clk       (clk),          
    .rst       (rst),
    .csr_wen   (csr_wen),
    .is_ecall  (is_ecall),
    .csr       ({funct7, rs2}),
    .src1      (src1),
    .funct3    (funct3),
    .pc        (pc),
    .csr_val   (csr_val),   //output
    .csr_npc   (csr_npc)    //output
  );

  // Register File module
  ysyx_23060219_register_file register_file_inst(
    .clk      (clk),
    .rst      (rst),
    .is_ecall (is_ecall),
    .reg_wen  (reg_wen),
    .rs1      (rs1),
    .rs2      (rs2),
    .rd       (rd),
    .reg_in   (reg_in),
    .src1     (src1), //output
    .src2     (src2)  //output
  );

  // Imm Extend module
  ysyx_23060219_imm_extend imm_extend_inst(
    .rs1   (rs1),   //input
    .rs2   (rs2),   //input
    .rd    (rd),    //input
    .funct3(funct3),//input
    .funct7(funct7),//input
    .IType (IType), //input
    .imm32 (imm32)  //output
  );

  // MUX3 module  //选择输入到alu的数据2
  MuxKey #(2, 1, `BitWidth) i3(num2, m3, {
      `MUX3_src2,  src2,
      `MUX3_imm32, imm32}
  );

  // MUX4 module  选择输入到alu的数据1
  MuxKey #(2, 1, `BitWidth) i4(num1, m4, {
      `MUX4_pc,   pc,
      `MUX4_src1, src1}
  );

  // MUX5 module  选择写入寄存器堆的数据
  MuxKey #(4, 2, `BitWidth) i5(reg_in, m5, {
      `MUX5_PCadd4, PCadd4,
      `MUX5_memdat, mem_rdata,
      `MUX5_result, result,
      `MUX5_CsrVal, csr_val}       //zhong
  );
  
  // ALU module
  ysyx_23060219_alu alu_inst(
    .aluc  (aluc),  //input
    .num1  (num1),  //input
    .num2  (num2),  //input
    .result(result) //output
  );
endmodule


