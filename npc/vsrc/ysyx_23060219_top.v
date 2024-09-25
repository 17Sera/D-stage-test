// // // 只加握手

// `include "/home/zhong/ysyx-workbench/npc/vsrc/defines.v"

// module ysyx_23060219_top(
//   input  wire  clk,
//   input  wire  rst
// );

//   reg [2:0] clk_cnt;
//   always @(posedge clk) begin
//     if(rst == 1'b1)           clk_cnt <= 3'h0;
//     else if(clk_cnt == 3'h5)  clk_cnt <= 3'h1;
//     else                      clk_cnt <= clk_cnt + 3'h1;
//   end


//   //// IFU --------------------------------------------------
//   wire            w_ifu_valid;
//   wire [31:0]     w_ifu_pc;
//   wire [31:0]     w_ifu_inst;

//   ifu ifu_inst(
//     // system
//     .clk         (clk),
//     .rst         (rst),
//     // shake hands
//     .i_cycle_end (w_wbu_cycle_end),   // 连接WBU的o_cycle_end 
//     .o_post_valid(w_ifu_valid),  
//     .i_post_ready(w_idu_ready),  
//     // from BRU
//     .i_ifu_npc   (w_bru_npc),
//     // to IDU
//     .o_ifu_pc    (w_ifu_pc),
//     .o_ifu_inst  (w_ifu_inst)
//   );


//   // IDU --------------------------------------------------
//   wire            w_idu_ready;
//   wire            w_idu_valid;
//   wire [4:0]      w_idu_rs_id1;
//   wire [4:0]      w_idu_rs_id2;
//   wire [`CSR_Bus] w_idu_csr_rid;
//   wire            w_idu_csr_ren;  
//   wire            w_idu_is_mret;
//   wire            w_idu_is_ecall;
//   wire [1:0]      w_idu_csr_type;
//   wire [`ALU_Bus] w_idu_alu_type;
//   wire [1:0]      w_idu_num_sel;  // 0: rs1, 1: rs2, 2: imm
//   wire [31:0]     w_idu_imm;
//   wire            w_idu_is_load;
//   wire            w_idu_is_store;
//   wire [2:0]      w_idu_func3;
//   wire [31:0]     w_idu_pc;
//   wire            w_idu_is_jal;
//   wire            w_idu_is_jalr;
//   wire            w_idu_is_brch;
//   wire [4:0]      w_idu_rd_id;  
//   wire            w_idu_gpr_wen;

//   idu idu_inst(
//     // system
//     .clk           (clk),
//     .rst           (rst),
//     // shake hands
//     .i_pre_valid   (w_ifu_valid),   
//     .o_pre_ready   (w_idu_ready), 
//     .o_post_valid  (w_idu_valid),
//     .i_post_ready  (w_exu_ready),

//     // from IFU
//     .i_idu_pc      (w_ifu_pc),
//     .i_idu_inst    (w_ifu_inst),
//     // to Register File
//     .o_idu_rs_id1  (w_idu_rs_id1),
//     .o_idu_rs_id2  (w_idu_rs_id2),
//     // to CSR Ctrl
//     .o_idu_csr_rid (w_idu_csr_rid),
//     .o_idu_csr_ren (w_idu_csr_ren),  
//     .o_idu_is_mret (w_idu_is_mret),
//     .o_idu_is_ecall(w_idu_is_ecall),
//     // to EXU
//     .o_idu_csr_type(w_idu_csr_type),
//     .o_idu_alu_type(w_idu_alu_type),
//     .o_idu_num_sel (w_idu_num_sel),
//     .o_idu_imm     (w_idu_imm),
//     // to LSU
//     .o_idu_is_load (w_idu_is_load),
//     .o_idu_is_store(w_idu_is_store),
//     .o_idu_func3   (w_idu_func3),
//     // to BRU 
//     .o_idu_pc      (w_idu_pc),
//     .o_idu_is_jal  (w_idu_is_jal),
//     .o_idu_is_jalr (w_idu_is_jalr),
//     .o_idu_is_brch (w_idu_is_brch),
//     // to WEU
//     .o_idu_rd_id   (w_idu_rd_id),
//     .o_idu_gpr_wen (w_idu_gpr_wen)
//   );


//   // EXU --------------------------------------------------
//     wire            w_exu_ready;   
//     wire            w_exu_valid;  
//     wire [31:0]     w_exu_exu_res;
//     wire            w_exu_is_load;
//     wire            w_exu_is_store;
//     wire [2:0]      w_exu_func3;
//     wire [31:0]     w_exu_rs1;
//     wire [31:0]     w_exu_rs2;
//     wire [31:0]     w_exu_csr_npc;
//     wire            w_exu_is_mret;
//     wire            w_exu_is_ecall;
//     wire [31:0]     w_exu_imm;
//     wire [31:0]     w_exu_pc;
//     wire            w_exu_is_jal;
//     wire            w_exu_is_jalr;
//     wire            w_exu_brch;
//     wire [4:0]      w_exu_rd_id;
//     wire            w_exu_gpr_wen;
//     wire [`CSR_Bus] w_exu_csr_wid;
//     wire [31:0]     w_exu_csr_rd;
//     wire            w_exu_csr_wen;

//   exu exu_inst(
//     // system
//     .clk           (clk),
//     .rst           (rst),
//     // shake hands
//     .i_pre_valid   (w_idu_valid),   
//     .o_pre_ready   (w_exu_ready),  
//     .o_post_valid  (w_exu_valid),  
//     .i_post_ready  (w_lsu_ready),  
//     // from IFU
//     .i_exu_pc      (w_idu_pc),
//     // from IDU
//     .i_exu_alu_type(w_idu_alu_type),
//     .i_exu_num_sel (w_idu_num_sel),
//     .i_exu_imm     (w_idu_imm),
//     .i_exu_is_jal  (w_idu_is_jal),
//     .i_exu_is_jalr (w_idu_is_jalr),
//     .i_exu_is_brch (w_idu_is_brch),
//     .i_exu_is_load (w_idu_is_load),
//     .i_exu_is_store(w_idu_is_store),
//     .i_exu_func3   (w_idu_func3),
//     .i_exu_rd_id   (w_idu_rd_id),
//     .i_exu_gpr_wen (w_idu_gpr_wen),  
//     .i_exu_csr_type(w_idu_csr_type),  
//     .i_exu_csr_rid (w_idu_csr_rid),
//     .i_exu_csr_ren (w_idu_csr_ren),  
//     .i_exu_is_mret (w_idu_is_mret),
//     .i_exu_is_ecall(w_idu_is_ecall),    
//     // from Register File
//     .i_exu_rs1     (w_rf_rs1),
//     .i_exu_rs2     (w_rf_rs2),
//     // from CSR Ctrl
//     .i_exu_csr_src (w_cc_csr_src),
//     .i_exu_csr_npc (w_cc_csr_npc),
//     // to LSU
//     .o_exu_exu_res (w_exu_exu_res),
//     .o_exu_is_load (w_exu_is_load),
//     .o_exu_is_store(w_exu_is_store),
//     .o_exu_func3   (w_exu_func3),
//     .o_exu_rs1     (w_exu_rs1),
//     .o_exu_rs2     (w_exu_rs2),
//     .o_exu_csr_npc (w_exu_csr_npc),
//     .o_exu_is_mret (w_exu_is_mret),
//     .o_exu_is_ecall(w_exu_is_ecall),
//     // to BRU
//     .o_exu_imm     (w_exu_imm),
//     .o_exu_pc      (w_exu_pc),
//     .o_exu_is_jal  (w_exu_is_jal),
//     .o_exu_is_jalr (w_exu_is_jalr),
//     .o_exu_brch    (w_exu_brch),
//     // to WEU  EXU --> ⌈‾‾‾‾‾⌉ --> LSU --> ⌈‾‾‾‾‾⌉ --> WBU
//     .o_exu_rd_id   (w_exu_rd_id),
//     .o_exu_gpr_wen (w_exu_gpr_wen),
//     .o_exu_csr_wid (w_exu_csr_wid),
//     .o_exu_csr_rd  (w_exu_csr_rd),
//     .o_exu_csr_wen (w_exu_csr_wen)
// );


//   // LSU --------------------------------------------------
//   wire            w_lsu_ready;  
//   wire            w_lsu_valid;  
//   wire [31:0]     w_lsu_imm;
//   wire [31:0]     w_lsu_pc;
//   wire [31:0]     w_lsu_rs1;
//   wire            w_lsu_is_jal;
//   wire            w_lsu_is_jalr;
//   wire            w_lsu_brch;    
//   wire [31:0]     w_lsu_csr_npc;
//   wire            w_lsu_is_ejump;
//   wire [31:0]     w_lsu_rd;
//   wire [4:0]      w_lsu_rd_id;
//   wire            w_lsu_gpr_wen;
//   wire            w_lsu_csr_wen;
//   wire            w_lsu_is_mret;
//   wire            w_lsu_is_ecall;
//   wire [`CSR_Bus] w_lsu_csr_wid;
//   wire [31:0]     w_lsu_csr_rd;

//   lsu lsu_inst( 
//     // system
//     .clk           (clk),
//     .rst           (rst),
//     // shake hands
//     .i_pre_valid   (w_exu_valid),  
//     .o_pre_ready   (w_lsu_ready),  
//     .o_post_valid  (w_lsu_valid),
//     .i_post_ready  (w_wbu_ready),  
//     //from IFU
//     .i_lsu_pc      (w_exu_pc),
//     // from IDU
//     .i_lsu_is_load (w_exu_is_load),
//     .i_lsu_is_store(w_exu_is_store),
//     .i_lsu_func3   (w_exu_func3),
//     .i_lsu_imm     (w_exu_imm),
//     .i_lsu_is_jal  (w_exu_is_jal),
//     .i_lsu_is_jalr (w_exu_is_jalr),
//     .i_lsu_brch    (w_exu_brch),
//     .i_lsu_rd_id   (w_exu_rd_id),
//     .i_lsu_gpr_wen (w_exu_gpr_wen),  
//     // from Register File
//     .i_lsu_rs1     (w_exu_rs1),
//     .i_lsu_rs2     (w_exu_rs2),
//     // from CSR Ctrl
//     .i_lsu_csr_npc (w_exu_csr_npc),
//     .i_lsu_csr_wid (w_exu_csr_wid),
//     .i_lsu_csr_rd  (w_exu_csr_rd),
//     .i_lsu_csr_wen (w_exu_csr_wen),  
//     .i_lsu_is_mret (w_exu_is_mret),
//     .i_lsu_is_ecall(w_exu_is_ecall),
//     // from EXU
//     .i_lsu_exu_res (w_exu_exu_res),
//     // to BRU
//     .o_lsu_imm     (w_lsu_imm),
//     .o_lsu_pc      (w_lsu_pc),
//     .o_lsu_rs1     (w_lsu_rs1),
//     .o_lsu_is_jal  (w_lsu_is_jal),
//     .o_lsu_is_jalr (w_lsu_is_jalr),
//     .o_lsu_brch    (w_lsu_brch),    
//     .o_lsu_csr_npc (w_lsu_csr_npc),
//     .o_lsu_is_ejump(w_lsu_is_ejump),
//     // to WEU
//     .o_lsu_rd      (w_lsu_rd),
//     .o_lsu_rd_id   (w_lsu_rd_id),
//     .o_lsu_gpr_wen (w_lsu_gpr_wen),
//     .o_lsu_csr_wen (w_lsu_csr_wen),
//     .o_lsu_is_mret (w_lsu_is_mret),
//     .o_lsu_is_ecall(w_lsu_is_ecall),
//     .o_lsu_csr_wid (w_lsu_csr_wid),
//     .o_lsu_csr_rd  (w_lsu_csr_rd)
//   );


//   // WBU  写回寄存器--------------------------------------------------
//   wire            w_wbu_ready; 
//   wire            w_wbu_cycle_end;  
//   wire            w_wbu_npc_wen;
//   wire [31:0]     w_wbu_rd;
//   wire [4:0]      w_wbu_rd_id;
//   wire            w_wbu_gpr_wen;
//   wire [31:0]     w_wbu_mcause_in;
//   wire [31:0]     w_wbu_mepc_in;
//   wire            w_wbu_csr_wen;  
//   wire [`CSR_Bus] w_wbu_csr_wid;
//   wire [31:0]     w_wbu_csr_rd;
    
//   wbu wbu_inst(
//     // system
//     .clk           (clk),
//     .rst           (rst),
//     // shake hands
//     .i_pre_valid   (w_lsu_valid),   
//     .o_pre_ready   (w_wbu_ready),   
//     .o_cycle_end   (w_wbu_cycle_end),   
//     //from IFU
//     .i_wbu_pc      (w_lsu_pc),
//     // from IDU
//     .i_wbu_rd_id   (w_lsu_rd_id),
//     .i_wbu_gpr_wen (w_lsu_gpr_wen),  
//     //from Register File
//     .i_wbu_rs1     (w_lsu_rs1),
//     //from CSR Ctrl
//     .i_wbu_is_mret (w_lsu_is_mret),
//     .i_wbu_is_ecall(w_lsu_is_ecall),
//     .i_wbu_csr_wid (w_lsu_csr_wid),
//     .i_wbu_csr_rd  (w_lsu_csr_rd),
//     .i_wbu_csr_wen (w_lsu_csr_wen),
//     // from LSU
//     .i_wbu_rd      (w_lsu_rd),
//     // to BRU
//     .o_wbu_npc_wen (w_wbu_npc_wen),
//     // to Register File
//     .o_wbu_rd      (w_wbu_rd),
//     .o_wbu_rd_id   (w_wbu_rd_id),
//     .o_wbu_gpr_wen (w_wbu_gpr_wen),
//     // to CSR Ctrl
//     .o_wbu_mcause_in(w_wbu_mcause_in),
//     .o_wbu_mepc_in  (w_wbu_mepc_in),
//     .o_wbu_csr_wen  (w_wbu_csr_wen),  
//     .o_wbu_csr_wid  (w_wbu_csr_wid),
//     .o_wbu_csr_rd   (w_wbu_csr_rd)  
//   );


//   // BRU  处理和决策分支指令的执行路径 --------------------------------------------------
//   wire [31:0] w_bru_npc;
  
//   bru bru_inst(
//     // system
//     .clk          (clk),
//     .rst          (rst),
//     // from IFU
//     .i_bru_pc     (w_lsu_pc),
//     // from IFU
//     .i_bru_imm    (w_lsu_imm),
//     .i_bru_is_jal (w_lsu_is_jal),
//     .i_bru_is_jalr(w_lsu_is_jalr),
//     .i_bru_brch   (w_lsu_brch),
//     .i_bru_ejump  (w_lsu_is_ejump),
//     .i_bru_csr_npc(w_lsu_csr_npc),
//     //from Register File
//     .i_bru_rs1    (w_lsu_rs1),
//     // from WBU
//     .i_bru_npc_wen(w_wbu_npc_wen),
//     // to IFU
//     .o_bru_npc    (w_bru_npc)
//   );


//   // Register File --------------------------------------------------
//   wire [31:0]   w_rf_rs1;
//   wire [31:0]   w_rf_rs2;
  
//   register_file  register_file_inst(
//     // system
//     .clk         (clk),
//     .rst         (rst),
//     // from WBU
//     .i_rf_gpr_wen(w_wbu_gpr_wen),
//     .i_rf_rd_id  (w_wbu_rd_id),
//     .i_rf_rd     (w_wbu_rd),
//     // from IDU
//     .i_rf_rs_id1 (w_idu_rs_id1),
//     .i_rf_rs_id2 (w_idu_rs_id2),
//     // to EXU
//     .o_rf_rs1    (w_rf_rs1),
//     .o_rf_rs2    (w_rf_rs2)
//   );


//   // CSR Control --------------------------------------------------
//     wire [31:0]   w_cc_csr_src;
//     wire [31:0]   w_cc_csr_npc;
    
//     csr_ctrl  csr_ctrl_inst(
//     // system
//     .clk            (clk),
//     .rst            (rst),
//     // from IDU
//     .i_ccu_csr_ren  (w_idu_csr_ren),
//     .i_ccu_csr_rid  (w_idu_csr_rid),
//     .i_ccu_is_mret  (w_idu_is_mret),
//     .i_ccu_is_ecall (w_idu_is_ecall),
//     // from WBU
//     .i_ccu_csr_wen  (w_wbu_csr_wen),
//     .i_ccu_csr_wid  (w_wbu_csr_wid),
//     .i_ccu_csr_rd   (w_wbu_csr_rd),
//     .i_ccu_macuse_in(w_wbu_mcause_in),
//     .i_ccu_mepc_in  (w_wbu_mepc_in),
//     // to EXU
//     .o_exu_csr_src  (w_cc_csr_src),
//     .o_exu_csr_npc  (w_cc_csr_npc)
// );

// endmodule


//=============================================================================================================
// add arbiter
`include "/home/zhong/ysyx-workbench/npc/vsrc/defines.v"

module ysyx_23060219_top(
  input  wire           clk,
  input  wire           rst
);

  reg [3:0] clk_cnt;
  always @(posedge clk) begin
    if(rst == 1'b1) 
      clk_cnt <= 4'd0;
    else if(clk_cnt == 4'd15)
      clk_cnt <= 4'd1;
    else
      clk_cnt <= clk_cnt + 3'd1;
  end


  // IFU --------------------------------------------------
  wire             w_ifu_valid;
  wire  [`CPU_Bus] w_ifu_pc;
  wire  [`CPU_Bus] w_ifu_inst;

  wire  [`CPU_Bus] o_araddr_ifu;
  wire             o_arvalid_ifu;
  wire             i_arready_ifu;
  wire  [`CPU_Bus] i_rdata_ifu;
  wire             i_rvalid_ifu;
  wire             o_rready_ifu;

  ifu ifu_inst(
    // system
    .clk         (clk),
    .rst         (rst),
    // shake hands
    .i_cycle_end (w_wbu_cycle_end),   
    .o_post_valid(w_ifu_valid),  
    .i_post_ready(w_idu_ready),  
    // from BRU
    .i_ifu_npc   (w_bru_npc),
    // to IDU
    .o_ifu_pc    (w_ifu_pc),
    .o_ifu_inst  (w_ifu_inst),

    .o_araddr  ( o_araddr_ifu  ),
    .o_arvalid ( o_arvalid_ifu ),
    .i_arready ( i_arready_ifu ),

    .i_rdata   ( i_rdata_ifu   ),
    .i_rresp   (           ),
    .i_rvalid  ( i_rvalid_ifu  ),
    .o_rready  ( o_rready_ifu  ),

    .o_awaddr  (  ),
    .o_awvalid (  ),
    .i_awready (  ),

    .o_wdata   (  ),
    .o_wstrb   (  ),
    .o_wvalid  (  ),
    .i_wready  (  ),

    .i_bresp   (  ),
    .i_bvalid  (  ),
    .o_bready  (  )
  );


  // IDU --------------------------------------------------
  wire            w_idu_ready;
  wire            w_idu_valid;
  wire [4:0]      w_idu_rs_id1;
  wire [4:0]      w_idu_rs_id2;
  wire [`CSR_Bus] w_idu_csr_rid;
  wire            w_idu_csr_ren;  
  wire            w_idu_is_mret;
  wire            w_idu_is_ecall;
  wire [1:0]      w_idu_csr_type;
  wire [`ALU_Bus] w_idu_alu_type;
  wire [1:0]      w_idu_num_sel;
  wire [`CPU_Bus] w_idu_imm;
  wire            w_idu_is_load;
  wire            w_idu_is_store;
  wire [2:0]      w_idu_func3;
  wire [`CPU_Bus] w_idu_pc;
  wire            w_idu_is_jal;
  wire            w_idu_is_jalr;
  wire            w_idu_is_brch;
  wire [4:0]      w_idu_rd_id;
  wire            w_idu_gpr_wen;

  idu idu_inst(
    // system
    .clk           (clk),
    .rst           (rst),
    // shake hands
    .i_pre_valid   (w_ifu_valid),   
    .o_pre_ready   (w_idu_ready), 
    .o_post_valid  (w_idu_valid),
    .i_post_ready  (w_exu_ready),
    // from IFU
    .i_idu_pc      (w_ifu_pc),
    .i_idu_inst    (w_ifu_inst),
    // to Register File
    .o_idu_rs_id1  (w_idu_rs_id1),
    .o_idu_rs_id2  (w_idu_rs_id2),
    // to CSR Ctrl
    .o_idu_csr_rid (w_idu_csr_rid),
    .o_idu_csr_ren (w_idu_csr_ren),  
    .o_idu_is_mret (w_idu_is_mret),
    .o_idu_is_ecall(w_idu_is_ecall),
    // to EXU
    .o_idu_csr_type(w_idu_csr_type),
    .o_idu_alu_type(w_idu_alu_type),
    .o_idu_num_sel (w_idu_num_sel),
    .o_idu_imm     (w_idu_imm),
    // to to LSU
    .o_idu_is_load (w_idu_is_load),
    .o_idu_is_store(w_idu_is_store),
    .o_idu_func3   (w_idu_func3),
    // to to to BRU
    .o_idu_pc      (w_idu_pc),
    .o_idu_is_jal  (w_idu_is_jal),
    .o_idu_is_jalr (w_idu_is_jalr),
    .o_idu_is_brch (w_idu_is_brch),
    // to to to WEU
    .o_idu_rd_id   (w_idu_rd_id),
    .o_idu_gpr_wen (w_idu_gpr_wen)
  );


  // EXU --------------------------------------------------
    wire            w_exu_ready;   
    wire            w_exu_valid;  
    wire [`CPU_Bus] w_exu_exu_res;
    wire            w_exu_is_load;
    wire            w_exu_is_store;
    wire [2:0]      w_exu_func3;
    wire [`CPU_Bus] w_exu_rs1;
    wire [`CPU_Bus] w_exu_rs2;
    wire [`CPU_Bus] w_exu_csr_npc;
    wire            w_exu_is_mret;
    wire            w_exu_is_ecall;
    wire [`CPU_Bus] w_exu_imm;
    wire [`CPU_Bus] w_exu_pc;
    wire            w_exu_is_jal;
    wire            w_exu_is_jalr;
    wire            w_exu_brch;
    wire [4:0]      w_exu_rd_id;
    wire            w_exu_gpr_wen;
    wire [`CSR_Bus] w_exu_csr_wid;
    wire [31:0]  w_exu_csr_rd;
    wire            w_exu_csr_wen;
    wire            exu_success;

  exu exu_inst(
    // system
    .clk           (clk),
    .rst           (rst),
    // shake hands
    .i_pre_valid   (w_idu_valid),   
    .o_pre_ready   (w_exu_ready),  
    .o_post_valid  (w_exu_valid),  
    .i_post_ready  (w_lsu_ready),  
    // from from IFU
    .i_exu_pc      (w_idu_pc),
    // from IDU
    .i_exu_alu_type(w_idu_alu_type),
    .i_exu_num_sel (w_idu_num_sel),
    .i_exu_imm     (w_idu_imm),
    .i_exu_is_jal  (w_idu_is_jal),
    .i_exu_is_jalr (w_idu_is_jalr),
    .i_exu_is_brch (w_idu_is_brch),
    .i_exu_is_load (w_idu_is_load),
    .i_exu_is_store(w_idu_is_store),
    .i_exu_func3   (w_idu_func3),
    .i_exu_rd_id   (w_idu_rd_id),
    .i_exu_gpr_wen (w_idu_gpr_wen),  
    .i_exu_csr_type(w_idu_csr_type),  
    .i_exu_csr_rid (w_idu_csr_rid),
    .i_exu_csr_ren (w_idu_csr_ren),  
    .i_exu_is_mret (w_idu_is_mret),
    .i_exu_is_ecall(w_idu_is_ecall),    
    // from Register File
    .i_exu_rs1     (w_rf_rs1),
    .i_exu_rs2     (w_rf_rs2),
    // from CSR Ctrl
    .i_exu_csr_src (w_cc_csr_src),
    .i_exu_csr_npc (w_cc_csr_npc),
    // to LSU
    .o_exu_exu_res (w_exu_exu_res),
    .o_exu_is_load (w_exu_is_load),
    .o_exu_is_store(w_exu_is_store),
    .o_exu_func3   (w_exu_func3),
    .o_exu_rs1     (w_exu_rs1),
    .o_exu_rs2     (w_exu_rs2),
    .o_exu_csr_npc (w_exu_csr_npc),
    .o_exu_is_mret (w_exu_is_mret),
    .o_exu_is_ecall(w_exu_is_ecall),
    // to to BRU
    .o_exu_imm     (w_exu_imm),
    .o_exu_pc      (w_exu_pc),
    .o_exu_is_jal  (w_exu_is_jal),
    .o_exu_is_jalr (w_exu_is_jalr),
    .o_exu_brch    (w_exu_brch),
    // to to WEU
    .o_exu_rd_id   (w_exu_rd_id),
    .o_exu_gpr_wen (w_exu_gpr_wen),
    .o_exu_csr_wid (w_exu_csr_wid),
    .o_exu_csr_rd  (w_exu_csr_rd),
    .o_exu_csr_wen (w_exu_csr_wen),

    .o_exu_success (exu_success)
);


  // LSU --------------------------------------------------
  wire            w_lsu_ready;  
  reg             w_lsu_valid;  
  wire [`CPU_Bus] w_lsu_imm;
  wire [`CPU_Bus] w_lsu_pc;
  wire [31:0]  w_lsu_rs1;
  wire            w_lsu_is_jal;
  wire            w_lsu_is_jalr;
  wire            w_lsu_brch;    
  wire [`CPU_Bus] w_lsu_csr_npc;
  wire            w_lsu_is_ejump;
  wire [`CPU_Bus] w_lsu_rd;
  wire [4:0]      w_lsu_rd_id;
  wire            w_lsu_gpr_wen;
  wire            w_lsu_csr_wen;
  wire            w_lsu_is_mret;
  wire            w_lsu_is_ecall;
  wire [`CSR_Bus] w_lsu_csr_wid;
  wire [31:0]  w_lsu_csr_rd;

  //读操作
  wire  [`CPU_Bus] o_araddr_lsu;
  wire             o_arvalid_lsu;
  wire             i_arready_lsu;
  wire  [`CPU_Bus] i_rdata_lsu;
  wire             i_rvalid_lsu;
  wire             o_rready_lsu;
  //写操作
  wire  [`CPU_Bus] o_awaddr_lsu;
  wire             o_awvalid_lsu;
  wire             i_awready_lsu;
  wire  [`CPU_Bus] o_wdata_lsu;
  wire  [7:0]      o_wstrb_lsu;
  wire             o_wvalid_lsu;
  wire             i_wready_lsu;

  lsu lsu_inst( 
    // system
    .clk           (clk),
    .rst           (rst),
    // shake hands
    .i_pre_valid   (w_exu_valid),  
    .o_pre_ready   (w_lsu_ready),  
    .o_post_valid  (w_lsu_valid),
    .i_post_ready  (w_wbu_ready),  
    // from from from IFU
    .i_lsu_pc      (w_exu_pc),
    // from from IDU
    .i_lsu_is_load (w_exu_is_load),
    .i_lsu_is_store(w_exu_is_store),
    .i_lsu_func3   (w_exu_func3),
    .i_lsu_imm     (w_exu_imm),
    .i_lsu_is_jal  (w_exu_is_jal),
    .i_lsu_is_jalr (w_exu_is_jalr),
    .i_lsu_brch    (w_exu_brch),
    .i_lsu_rd_id   (w_exu_rd_id),
    .i_lsu_gpr_wen (w_exu_gpr_wen),  
    // from from Register File
    .i_lsu_rs1     (w_exu_rs1),
    .i_lsu_rs2     (w_exu_rs2),
    // from from CSR Ctrl
    .i_lsu_csr_npc (w_exu_csr_npc),
    .i_lsu_csr_wid (w_exu_csr_wid),
    .i_lsu_csr_rd  (w_exu_csr_rd),
    .i_lsu_csr_wen (w_exu_csr_wen),  
    .i_lsu_is_mret (w_exu_is_mret),
    .i_lsu_is_ecall(w_exu_is_ecall),
    // from EXU
    .i_lsu_exu_res (w_exu_exu_res),
    // to BRU
    .o_lsu_imm     (w_lsu_imm),
    .o_lsu_pc      (w_lsu_pc),
    .o_lsu_rs1     (w_lsu_rs1),
    .o_lsu_is_jal  (w_lsu_is_jal),
    .o_lsu_is_jalr (w_lsu_is_jalr),
    .o_lsu_brch    (w_lsu_brch),    
    .o_lsu_csr_npc (w_lsu_csr_npc),
    .o_lsu_is_ejump(w_lsu_is_ejump),
    // to WEU
    .o_lsu_rd      (w_lsu_rd),
    .o_lsu_rd_id   (w_lsu_rd_id),
    .o_lsu_gpr_wen (w_lsu_gpr_wen),
    .o_lsu_csr_wen (w_lsu_csr_wen),
    .o_lsu_is_mret (w_lsu_is_mret),
    .o_lsu_is_ecall(w_lsu_is_ecall),
    .o_lsu_csr_wid (w_lsu_csr_wid),
    .o_lsu_csr_rd  (w_lsu_csr_rd),

  //读操作
    .o_araddr  ( o_araddr_lsu  ),
    .o_arvalid ( o_arvalid_lsu ),
    .i_arready ( i_arready_lsu ),

    .i_rdata   ( i_rdata_lsu   ),
    .i_rresp   (           ),
    .i_rvalid  ( i_rvalid_lsu  ),
    .o_rready  ( o_rready_lsu  ),
//写操作
    .o_awaddr  ( o_awaddr_lsu ),
    .o_awvalid ( o_awvalid_lsu ),
    .i_awready ( i_awready_lsu ),

    .o_wdata   ( o_wdata_lsu ),
    .o_wstrb   ( o_wstrb_lsu ),
    .o_wvalid  ( o_wvalid_lsu ),
    .i_wready  ( i_wready_lsu ),

    .i_bresp   (  ),
    .i_bvalid  (  ),
    .o_bready  (  ),

    .i_exu_success(exu_success)

  );


  // WBU --------------------------------------------------
  wire            w_wbu_ready; 
  wire            w_wbu_cycle_end;  
  wire            w_wbu_npc_wen;
  wire [`CPU_Bus] w_wbu_rd;
  wire [4:0]      w_wbu_rd_id;
  wire            w_wbu_gpr_wen;
  wire [31:0]  w_wbu_mcause_in;
  wire [31:0]  w_wbu_mepc_in;
  wire            w_wbu_csr_wen;  
  wire [`CSR_Bus] w_wbu_csr_wid;
  wire [31:0]  w_wbu_csr_rd;
    
  wbu wbu_inst(
    // system
    .clk           (clk),
    .rst           (rst),
    // shake hands
    .i_pre_valid   (w_lsu_valid),   
    .o_pre_ready   (w_wbu_ready),   
    .o_cycle_end   (w_wbu_cycle_end),   
    // from from from IFU
    .i_wbu_pc      (w_lsu_pc),
    // from from from IDU
    .i_wbu_rd_id   (w_lsu_rd_id),
    .i_wbu_gpr_wen (w_lsu_gpr_wen),  
    // from from from Register File
    .i_wbu_rs1     (w_lsu_rs1),
    // from from from CSR Ctrl
    .i_wbu_is_mret (w_lsu_is_mret),
    .i_wbu_is_ecall(w_lsu_is_ecall),
    .i_wbu_csr_wid (w_lsu_csr_wid),
    .i_wbu_csr_rd  (w_lsu_csr_rd),
    .i_wbu_csr_wen (w_lsu_csr_wen),
    // from LSU
    .i_wbu_rd      (w_lsu_rd),
    // to BRU
    .o_wbu_npc_wen (w_wbu_npc_wen),
    // to Register File
    .o_wbu_rd      (w_wbu_rd),
    .o_wbu_rd_id   (w_wbu_rd_id),
    .o_wbu_gpr_wen (w_wbu_gpr_wen),
    // to CSR Ctrl
    .o_wbu_mcause_in(w_wbu_mcause_in),
    .o_wbu_mepc_in  (w_wbu_mepc_in),
    .o_wbu_csr_wen  (w_wbu_csr_wen),  
    .o_wbu_csr_wid  (w_wbu_csr_wid),
    .o_wbu_csr_rd   (w_wbu_csr_rd)  
  );


  // BRU --------------------------------------------------
  wire [`CPU_Bus] w_bru_npc;
  
  bru bru_inst(
    // system
    .clk          (clk),
    .rst          (rst),
    // from from from from IFU
    .i_bru_pc     (w_lsu_pc),
    // from from from IFU
    .i_bru_imm    (w_lsu_imm),
    .i_bru_is_jal (w_lsu_is_jal),
    .i_bru_is_jalr(w_lsu_is_jalr),
    .i_bru_brch   (w_lsu_brch),
    .i_bru_ejump  (w_lsu_is_ejump),
    .i_bru_csr_npc(w_lsu_csr_npc),
    // from from from Register File
    .i_bru_rs1    (w_lsu_rs1),
    // from WBU
    .i_bru_npc_wen(w_wbu_npc_wen),
    // to IFU
    .o_bru_npc    (w_bru_npc)
  );

  // Arbiter --------------------------------------------------------
  arbiter arbiter(
        // System
        .clk              (clk),
        .rst              (rst),
/**/
        .i_ifu_araddr     (o_araddr_ifu ),   //读地址
        .i_ifu_arvalid    (o_arvalid_ifu),
        .o_ifu_arready    (i_arready_ifu),

        .o_ifu_rdata      (i_rdata_ifu  ),    //读数据
        .o_ifu_rresp      (         ),
        .i_ifu_rready     (o_rready_ifu ),
        .o_ifu_rvalid     (i_rvalid_ifu ),

        .i_ifu_awaddr     (   ),   //写地址
        .i_ifu_awvalid    (   ),
        .o_ifu_awready    (   ),

        .i_ifu_wdata      (   ),    //写数据
        .i_ifu_wstrb      (   ),
        .i_ifu_wvalid     (   ),
        .o_ifu_wready     (   ),

        .o_ifu_bresp      (   ),   //写回复
        .o_ifu_bvalid     (   ),
        .i_ifu_bready     (   ),
/**/
        .i_lsu_araddr     (o_araddr_lsu ),   //读地址
        .i_lsu_arvalid    (o_arvalid_lsu),
        .o_lsu_arready    (i_arready_lsu),

        .o_lsu_rdata      (i_rdata_lsu  ),    //读数据
        .o_lsu_rresp      (   ),
        .i_lsu_rready     (o_rready_lsu ),
        .o_lsu_rvalid     (i_rvalid_lsu ),

        .i_lsu_awaddr     (o_awaddr_lsu  ),   //写地址
        .i_lsu_awvalid    (o_awvalid_lsu ),
        .o_lsu_awready    (i_awready_lsu ),

        .i_lsu_wdata      ( o_wdata_lsu  ),    //写数据
        .i_lsu_wstrb      ( o_wstrb_lsu  ),
        .i_lsu_wvalid     ( o_wvalid_lsu ),
        .o_lsu_wready     ( i_wready_lsu ),

        .o_lsu_bresp      (   ),   //写回复
        .o_lsu_bvalid     (   ),
        .i_lsu_bready     (   ),
/**/
        .o_sram_araddr    (i_araddr ),   //读地址
        .o_sram_arvalid   (i_arvalid),
        .i_sram_arready   (o_arready),

        .i_sram_rdata     (o_rdata  ),    //读数据
        .i_sram_rresp     (    ),
        .i_sram_rvalid    (o_rvalid ),
        .o_sram_rready    (i_rready ),

        .o_sram_awaddr    (i_awaddr ),   //写地址
        .o_sram_awvalid   (i_awvalid),
        .i_sram_awready   (o_awready),

        .o_sram_wdata     (i_wdata  ),    //写数据
        .o_sram_wstrb     (i_wstrb  ),
        .o_sram_wvalid    (i_wvalid ),
        .i_sram_wready    (o_wready ),

        .i_sram_bresp     (   ),   //写回复
        .i_sram_bvalid    (   ),
        .o_sram_bready    (   ),
/**/
        .o_uart_araddr    (),
        .o_uart_arvalid   (),
        .i_uart_arready   (),

        .i_uart_rdata     (),
        .i_uart_rresp     (),
        .i_uart_rvalid    (),
        .o_uart_rready    (),

        .o_uart_awaddr    (),
        .o_uart_awvalid   (),
        .i_uart_awready   (),

        .o_uart_wdata     (),
        .o_uart_wstrb     (),
        .o_uart_wvalid    (),
        .i_uart_wready    (),

        .i_uart_bresp     (),
        .i_uart_bvalid    (),
        .o_uart_bready    ()
    );

  // SRAM -----------------------------------------------------------
  wire [31:0]   i_araddr;
  wire             i_arvalid;
  wire             o_arready;

  wire [31:0]   o_rdata;
  wire             o_rvalid;
  wire            i_rready;

  reg [31:0]   i_awaddr;
  reg             i_awvalid;
  reg             o_awready;
  reg  [31:0]  i_wdata; 
  reg  [7:0]      i_wstrb; 
  reg             i_wvalid;
  reg             o_wready;
  SRAM SRAM(
    // system
    .clk              (clk),
    .rst              (rst),
    // Read Address
    .i_araddr         (i_araddr ),
    .i_arvalid        (i_arvalid),
    .o_arready        (o_arready),
    // Read Data
    .o_rdata          (o_rdata  ),
    .o_rresp          (         ),
    .o_rvalid         (o_rvalid ),
    .i_rready         (i_rready ),
    // Write Address
    .i_awaddr         ( i_awaddr  ),
    .i_awvalid        ( i_awvalid ),
    .o_awready        ( o_awready ),
    // Write Data
    .i_wdata          ( i_wdata  ),
    .i_wstrb          ( i_wstrb  ),
    .i_wvalid         ( i_wvalid ),
    .o_wready         ( o_wready ),
    // Write Back
    .o_bresp          (  ),
    .o_bvalid         (  ),
    .i_bready         (  )
);

  // Register File --------------------------------------------------
  wire [31:0] w_rf_rs1;
  wire [31:0] w_rf_rs2;
  
  register_file  register_file_inst(
    // system
    .clk         (clk),
    .rst         (rst),
    // from WBU
    .i_rf_gpr_wen(w_wbu_gpr_wen),
    .i_rf_rd_id  (w_wbu_rd_id),
    .i_rf_rd     (w_wbu_rd),
    // from IDU
    .i_rf_rs_id1 (w_idu_rs_id1),
    .i_rf_rs_id2 (w_idu_rs_id2),
    // to EXU
    .o_rf_rs1    (w_rf_rs1),
    .o_rf_rs2    (w_rf_rs2)
  );


  // CSR Control --------------------------------------------------
    wire [31:0]  w_cc_csr_src;
    wire [`CPU_Bus] w_cc_csr_npc;
    
    csr_ctrl  csr_ctrl_inst(
    // system
    .clk            (clk),
    .rst            (rst),
    // from IDU
    .i_ccu_csr_ren  (w_idu_csr_ren),
    .i_ccu_csr_rid  (w_idu_csr_rid),
    .i_ccu_is_mret  (w_idu_is_mret),
    .i_ccu_is_ecall (w_idu_is_ecall),
    // from WBU
    .i_ccu_csr_wen  (w_wbu_csr_wen),
    .i_ccu_csr_wid  (w_wbu_csr_wid),
    .i_ccu_csr_rd   (w_wbu_csr_rd),
    .i_ccu_macuse_in(w_wbu_mcause_in),
    .i_ccu_mepc_in  (w_wbu_mepc_in),
    // to EXU
    .o_exu_csr_src  (w_cc_csr_src),
    .o_exu_csr_npc  (w_cc_csr_npc)
);

endmodule
