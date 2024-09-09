`include "/home/zhong/ysyx-workbench/npc/vsrc/defines.v"

module PC(
  input  wire           clk,
  input  wire           rst,
  input  wire           m1,
  input  wire [1:0]     m2,
  input  wire [`RegBus] result,
  input  wire [`RegBus] imm32,
  input  wire [`RegBus] csr_npc,
  output wire [`RegBus] PCadd4, //计算后的下一条指令地址（PC+4）
  output reg  [`RegBus] pc //当前指令地址
);

  wire [`RegBus] npc;
  wire [`RegBus] npc_temp;
  wire [`RegBus] PCaddIMM32;
  
  assign PCadd4     = pc + `PC_INCREMENT; //PC+4
  assign PCaddIMM32 = pc + imm32;

  always @(posedge clk) begin
    if(rst == `RST_VAL) //rst=1
      pc <= `RESET_VECTOR; //pc复位为0x8000_0000
    else if(clk == 1'b1)
      pc <= npc;
    else
      pc <= pc;
  end

  // MUX1 module
  MuxKey #(2, 1, `BitWidth) i1(npc, (m1 & result[0]), { //输入npc和（m1 & result[0]）信号，根据后者选择一个作为npc的输出
      1'b0, npc_temp,
      1'b1, PCaddIMM32}
  );

  // MUX2 module //用于选择将pc
  MuxKey #(4, 2, `BitWidth) i2(npc_temp, (m2), { //输入npc_temp和(m2)信号，根据m2的值选择一个赋值给npc_temp
      `MUX2_PCadd4, PCadd4,  //0
      `MUX2_result, result,  //1
      `MUX2_CsrNpc, csr_npc, //2
      `MUX2_IDLE,   32'hdead000c} //3
  );

endmodule