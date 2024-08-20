`include "/home/zhong/ysyx-workbench/npc/vsrc/defines.v"

module PC(
  input  wire           clk,
  input  wire           rst,
  input  wire           m1,       // 作为key参与PC选择
  input  wire [1:0]     m2,
  input  wire [`RegBus] result,   //  31:0
  input  wire [`RegBus] imm32,
  input  wire [`RegBus] csr_npc,
  output wire [`RegBus] PCadd4,
  output reg  [`RegBus] pc
);

  wire [`RegBus] npc;
  wire [`RegBus] npc_temp;
  wire [`RegBus] PCaddIMM32;
  
  assign PCadd4     = pc + `PC_INCREMENT;   //PC_INCREMENT = 32'd4
  assign PCaddIMM32 = pc + imm32;

  always @(posedge clk) begin
    if(rst == `RST_VAL)       // RST_VAL = 1 复位
      pc <= `RESET_VECTOR;    // 32'h8000_0000
    else if(clk == 1'b1)
      pc <= npc;
    else
      pc <= pc;     // 保证PC时序下都有赋值
  end

// MuxKey #(有多少对，key的位宽，输出的位宽)  名称  (输出，key，lut)  BitWidth = 32
  MuxKey #(2, 1, `BitWidth) i1  (npc, (m1 & result[0]), {
      1'b0, npc_temp,
      1'b1, PCaddIMM32}
  );

  // MUX2 module
  // MuxKey #(2, 1, `BitWidth) i2  (npc_temp, (m2), {
  //     `MUX2_PCadd4, PCadd4,   //  1'b0
  //     `MUX2_result, result}   //  1'b1 
  // );
  MuxKey #(4, 2, `BitWidth) i2  (npc_temp, (m2), {
    `MUX2_PCadd4, PCadd4,
    `MUX2_result, result,
    `MUX2_CsrNpc, csr_npc,
    `MUX2_IDLE,   32'hdead000c} 
  );

endmodule





module ysyx_23060219_top(
  input  wire       clk,
  input  wire       rst,
  output wire  [`RegBus]   mstatus,
  output wire  [`RegBus]   mepc,
  output wire  [`RegBus]   mtvec,
  output wire  [`RegBus]   mcause
);
  
  wire  [4:0]       rs1;
  wire  [4:0]       rs2;
  wire  [4:0]       rd;
  wire  [2:0]       funct3;
  wire  [6:0]       funct7;

  wire  [`RegBus]   inst;     
  wire  [`RegBus]   pc;     
  wire  [`TYPE_BUS] IType;      //inst type 2:0 
  wire              is_ecall;
  wire              csr_wen;    //csr write enable 
  wire              reg_wen;    //RegFile 写使能
  wire              mem_wen;    //mem 写使能
  wire              mem_ren;    //mem 读使能
  wire  [7:0]       wmask;      //mem 写掩码
  wire  [2:0]       rmask;      //mem 读掩码
  wire              m1;         //一系列选择器
  wire  [1:0]       m2;
  wire              m3;
  wire              m4;
  wire  [1:0]       m5;
  wire  [`AlucBus]  aluc;       //alu control  4:0
  wire  [`RegBus]   PCadd4;     //pc + 4
  wire  [`RegBus]   result;     //alu 结果
  wire  [`RegBus]   reg_in;     //regisrer file input value
  wire  [`RegBus]   src1;       //rs1 value
  wire  [`RegBus]   src2;       //rs2 value
  wire  [`RegBus]   imm32;      //32 bit imm ext
  wire  [`RegBus]   num1;       //alu operation number1       
  wire  [`RegBus]   num2;       //alu operation number2
  wire  [`RegBus]   mem_rdata;  //mem 读到的数据
  wire  [`RegBus]   csr_npc;    //next pc read from csr 
  wire  [`RegBus]   csr_val;    //csr value




  // PC module
  PC PC_inst(
    .clk      (clk),
    .rst      (rst),
    .m1       (m1),
    .m2       (m2),
    .result   (result),
    .imm32    (imm32),
    .csr_npc  (csr_npc),
    .PCadd4   (PCadd4),
    .pc       (pc)   
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
    .inst      (inst),
    .rd_11_7   (rd),
    .rs1_19_15 (rs1),
    .rs2_24_20 (rs2),
    .fun3_14_12(funct3),
    .fun7_31_25(funct7),
    .IType     (IType),
    .aluc      (aluc),
    .is_ecall  (is_ecall),
    .csr_wen   (csr_wen),
    .reg_wen   (reg_wen),    
    .mem_wen   (mem_wen),
    .mem_ren   (mem_ren),  
    .wmask     (wmask),
    .rmask     (rmask),
    .m1        (m1),    
    .m2        (m2),    
    .m3        (m3),   
    .m4        (m4),   
    .m5        (m5)
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
    .src1     (src1),
    .src2     (src2)
  );

  // CSR Registers  module
  csr_regs csr_regs_inst(
    .clk     (clk),
    .rst     (rst),
    .is_ecall(is_ecall),
    .csr_wen (csr_wen),
    .funct3  (funct3),
    .csr     ({funct7, rs2}),
    .src1    (src1),
    .pc      (pc),
    .csr_npc (csr_npc),
    .csr_val (csr_val) ,
    .mstatus (mstatus),
    .mepc    (mepc),
    .mtvec   (mtvec),
    .mcause  (mcause)
  );

  // Imm Extend module
  ysyx_23060219_imm_extend imm_extend_inst(
    .rs1   (rs1),
    .rs2   (rs2),
    .rd    (rd),
    .funct3(funct3),
    .funct7(funct7),
    .IType (IType),
    .imm32 (imm32)
  );

  // MUX3 module
  MuxKey #(2, 1, `BitWidth) i3 (num2, m3, {
      `MUX3_src2,  src2,
      `MUX3_imm32, imm32}
  );

  // MUX4 module
  MuxKey #(2, 1, `BitWidth) i4 (num1, m4, {
      `MUX4_pc,   pc,
      `MUX4_src1, src1}
  );

  // MUX5 module
  MuxKey #(4, 2, `BitWidth) i5 (reg_in, m5, {
      `MUX5_PCadd4, PCadd4,
      `MUX5_memdat, mem_rdata,
      `MUX5_result, result,
      `MUX5_CsrVal, csr_val} 
      //`MUX5_IDLE,   32'hdeadbeaf}       
  );
  
  // ALU module
  ysyx_23060219_alu alu_inst(
    .aluc  (aluc),
    .num1  (num1),
    .num2  (num2),
    .result(result)
  );


  // always@(*) begin
  //   $display("\n------------ top_mcause = 0x%x --------------\n",mcause);
  //   $display("\n------------ top_mepc = 0x%x --------------\n",mepc);
  //   $display("\n------------ top_mstatus = 0x%x --------------\n",mstatus);
  //   $display("\n------------ top_mtvec = 0x%x --------------\n",mtvec);
  // end









endmodule

