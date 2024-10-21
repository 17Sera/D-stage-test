//=============================================================================================================
// add arbiter
`include "/home/zhong/ysyx-workbench/npc/vsrc/ysyx_23060219_defines.v"

module ysyx_23060219(
  input  wire           clock,
  input  wire           reset,
  input                 io_interrupt,
  // Master
  input    wire         io_master_awready, 
  output   wire         io_master_awvalid, 
  output   wire [31:0]  io_master_awaddr, 
  output   wire [3:0]   io_master_awid, //唯一标识符，用于区分多个写请求
  output   wire [7:0]   io_master_awlen,  //表示传输长度，通常是一次传输的字节数
  output   wire [2:0]   io_master_awsize, //表示每个传输的数据宽度
  output   wire [1:0]   io_master_awburst, //表示突发传输类型，可以是固定、递增或包装模式

  input    wire         io_master_wready, 
  output   wire         io_master_wvalid, 
  output   wire [31:0]  io_master_wdata, 
  output   wire [3:0]   io_master_wstrb, //写掩码
  output   wire         io_master_wlast, //表示这是最后一个写数据传输的信号

  output   wire         io_master_bready, 
  input    wire         io_master_bvalid, 
  input    wire [1:0]   io_master_bresp, //从设备返回的写响应状态，表示成功或错误
  input    wire [3:0]   io_master_bid,  //唯一标识符，用于确认响应

  input    wire         io_master_arready, 
  output   wire         io_master_arvalid, 
  output   wire [31:0]  io_master_araddr, 
  output   wire [3:0]   io_master_arid, //唯一标识符，用于区分多个读请求
  output   wire [7:0]   io_master_arlen, //表示传输的长度，通常是一次传输的字节数
  output   wire [2:0]   io_master_arsize, //每个传输的数据宽度
  output   wire [1:0]   io_master_arburst, //表示突发传输的类型，固定、递增或包装模式

  output   wire         io_master_rready, 
  input    wire         io_master_rvalid, 
  input    wire [1:0]   io_master_rresp, //从设备返回的读响应状态，表示成功或错误
  input    wire [31:0]  io_master_rdata, 
  input    wire         io_master_rlast, //表示这是最后一个读数据传输的信号
  input    wire [3:0]   io_master_rid, //唯一标识符，用于确认响应

  // Slave
  output   wire          io_slave_awready,
  input    wire          io_slave_awvalid,
  input    wire [31:0]   io_slave_awaddr,
  input    wire [3:0]    io_slave_awid,   
  input    wire [7:0]    io_slave_awlen,  
  input    wire [2:0]    io_slave_awsize, 
  input    wire [1:0]    io_slave_awburst,

  output   wire          io_slave_wready, 
  input    wire          io_slave_wvalid, 
  input    wire [31:0]   io_slave_wdata,  
  input    wire [3:0]    io_slave_wstrb, 
  input    wire          io_slave_wlast, 

  input    wire          io_slave_bready, 
  output   wire          io_slave_bvalid, 
  output   wire  [1:0]   io_slave_bresp,  
  output   wire  [3:0]   io_slave_bid,

  output   wire          io_slave_arready,
  input    wire          io_slave_arvalid,
  input    wire [31:0]   io_slave_araddr,
  input    wire [3:0]    io_slave_arid,
  input    wire [7:0]    io_slave_arlen,
  input    wire [2:0]    io_slave_arsize, 
  input    wire [1:0]    io_slave_arburst,

  input    wire          io_slave_rready,
  output   wire          io_slave_rvalid, 
  output   wire  [1:0]   io_slave_rresp, 
  output   wire  [31:0]  io_slave_rdata, 
  output   wire          io_slave_rlast,  
  output   wire  [3:0]   io_slave_rid       
);

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
  wire  [1:0]      i_rresp_ifu;
  wire             i_rlast_ifu;
  wire  [3:0]      i_rid_ifu;
  wire             i_awready_ifu;
  wire             i_wready_ifu;
  wire             i_bvalid_ifu;
  wire  [1:0]      i_bresp_ifu;
  wire  [3:0]      i_bid_ifu;


  ysyx_23060219_ifu ifu_inst(
    // system
    .clk         (clock),
    .rst         (reset),
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
    .o_arid    (  ),
    .o_arlen   (  ),
    .o_arsize  (  ),
    .o_arburst (  ),

    .i_rdata   ( i_rdata_ifu   ),
    .i_rresp   ( i_rresp_ifu   ),
    .i_rvalid  ( i_rvalid_ifu  ),
    .o_rready  ( o_rready_ifu  ),
    .i_rlast   ( i_rlast_ifu   ),
    .i_rid     ( i_rid_ifu     ),

    .o_awaddr  (  ),
    .o_awvalid (  ),
    .i_awready (i_awready_ifu),
    .o_awid    (  ),
    .o_awlen   (  ),
    .o_awsize  (  ),
    .o_awburst (  ),

    .o_wdata   (  ),
    .o_wstrb   (  ),
    .o_wvalid  (  ),
    .i_wready  (i_wready_ifu),
    .o_wlast   (  ),

    .i_bresp   (i_bresp_ifu),
    .i_bvalid  (i_bvalid_ifu),
    .o_bready  (  ),
    .i_bid     (i_bid_ifu)
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

  ysyx_23060219_idu idu_inst(
    // system
    .clk           (clock),
    .rst           (reset),
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
    // to LSU
    .o_idu_is_load (w_idu_is_load),
    .o_idu_is_store(w_idu_is_store),
    .o_idu_func3   (w_idu_func3),
    // to BRU
    .o_idu_pc      (w_idu_pc),
    .o_idu_is_jal  (w_idu_is_jal),
    .o_idu_is_jalr (w_idu_is_jalr),
    .o_idu_is_brch (w_idu_is_brch),
    // to WEU
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

  ysyx_23060219_exu exu_inst(
    // system
    .clk           (clock),
    .rst           (reset),
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
  wire [31:0]     w_lsu_rs1;
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
  wire [31:0]     w_lsu_csr_rd;


  wire  [`CPU_Bus] o_araddr_lsu;
  wire             o_arvalid_lsu;
  wire             i_arready_lsu;
  wire  [`CPU_Bus] i_rdata_lsu;
  wire             i_rvalid_lsu;
  wire             o_rready_lsu;

  wire  [`CPU_Bus] o_awaddr_lsu;
  wire             o_awvalid_lsu;
  wire             i_awready_lsu;
  wire  [`CPU_Bus] o_wdata_lsu;
  wire  [3:0]      o_wstrb_lsu;
  wire             o_wvalid_lsu;
  wire             i_wready_lsu;
  wire  [1:0]      i_rresp_lsu;
  wire             i_rlast_lsu;
  wire  [3:0]      i_rid_lsu;
  wire  [1:0]      i_bresp_lsu;
  wire             i_bvalid_lsu;
  wire  [3:0]      i_bid_lsu;




  ysyx_23060219_lsu lsu_inst( 
    // system
    .clk           (clock),
    .rst           (reset),
    // shake hands
    .i_pre_valid   (w_exu_valid),  
    .o_pre_ready   (w_lsu_ready),  
    .o_post_valid  (w_lsu_valid),
    .i_post_ready  (w_wbu_ready),  
    // from IFU
    .i_lsu_pc      (w_exu_pc),
    // from IDU
    .i_lsu_is_load (w_exu_is_load),
    .i_lsu_is_store(w_exu_is_store),
    .i_lsu_func3   (w_exu_func3),
    .i_lsu_imm     (w_exu_imm),
    .i_lsu_is_jal  (w_exu_is_jal),
    .i_lsu_is_jalr (w_exu_is_jalr),
    .i_lsu_brch    (w_exu_brch),
    .i_lsu_rd_id   (w_exu_rd_id),
    .i_lsu_gpr_wen (w_exu_gpr_wen),  
    // from Register File
    .i_lsu_rs1     (w_exu_rs1),
    .i_lsu_rs2     (w_exu_rs2),
    // from CSR Ctrl
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
    .o_arid    (  ),
    .o_arlen   (  ),
    .o_arsize  (  ),
    .o_arburst (  ),

    .i_rdata   ( i_rdata_lsu   ),
    .i_rresp   ( i_rresp_lsu   ),
    .i_rvalid  ( i_rvalid_lsu  ),
    .o_rready  ( o_rready_lsu  ),
    .i_rlast   ( i_rlast_lsu   ),
    .i_rid     ( i_rid_lsu     ),

//写操作
    .o_awaddr  ( o_awaddr_lsu ),
    .o_awvalid ( o_awvalid_lsu ),
    .i_awready ( i_awready_lsu ),
    .o_awid    (  ),
    .o_awlen   (  ),
    .o_awsize  (  ),
    .o_awburst (  ),

    .o_wdata   ( o_wdata_lsu ),
    .o_wstrb   ( o_wstrb_lsu ),
    .o_wvalid  ( o_wvalid_lsu ),
    .i_wready  ( i_wready_lsu ),
    .o_wlast   (  ),

    .i_bresp   ( i_bresp_lsu ),
    .i_bvalid  ( i_bvalid_lsu ),
    .o_bready  (  ),
    .i_bid     ( i_bid_lsu ),

    .i_exu_success(exu_success)

  );


  // WBU --------------------------------------------------
  wire            w_wbu_ready; 
  wire            w_wbu_cycle_end;  
  wire            w_wbu_npc_wen;
  wire [`CPU_Bus] w_wbu_rd;
  wire [4:0]      w_wbu_rd_id;
  wire            w_wbu_gpr_wen;
  wire [31:0]     w_wbu_mcause_in;
  wire [31:0]     w_wbu_mepc_in;
  wire            w_wbu_csr_wen;  
  wire [`CSR_Bus] w_wbu_csr_wid;
  wire [31:0]     w_wbu_csr_rd;
    
  ysyx_23060219_wbu wbu_inst(
    // system
    .clk           (clock),
    .rst           (reset),
    // shake hands
    .i_pre_valid   (w_lsu_valid),   
    .o_pre_ready   (w_wbu_ready),   
    .o_cycle_end   (w_wbu_cycle_end),   
    // from IFU
    .i_wbu_pc      (w_lsu_pc),
    // from IDU
    .i_wbu_rd_id   (w_lsu_rd_id),
    .i_wbu_gpr_wen (w_lsu_gpr_wen),  
    // from Register File
    .i_wbu_rs1     (w_lsu_rs1),
    // from CSR Ctrl
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
  
  ysyx_23060219_bru bru_inst(
    // system
    .clk          (clock),
    .rst          (reset),
    // from IFU
    .i_bru_pc     (w_lsu_pc),
    // from IFU
    .i_bru_imm    (w_lsu_imm),
    .i_bru_is_jal (w_lsu_is_jal),
    .i_bru_is_jalr(w_lsu_is_jalr),
    .i_bru_brch   (w_lsu_brch),
    .i_bru_ejump  (w_lsu_is_ejump),
    .i_bru_csr_npc(w_lsu_csr_npc),
    // from Register File
    .i_bru_rs1    (w_lsu_rs1),
    // from WBU
    .i_bru_npc_wen(w_wbu_npc_wen),
    // to IFU
    .o_bru_npc    (w_bru_npc)
  );

  // Arbiter --------------------------------------------------------
  ysyx_23060219_arbiter arbiter(
    // System
        .clk              (clock),
        .rst              (reset),
    /*------------------------ ifu -----------------------*/
    // Read Address IFU
        // .i_ifu_req        (    ),

        .i_ifu_araddr     (o_araddr_ifu ),
        .i_ifu_arvalid    (o_arvalid_ifu),
        .i_ifu_arready    (i_arready_ifu),
        .i_ifu_arid       (  ),
        .i_ifu_arlen      (  ),
        .i_ifu_arsize     (  ),
        .i_ifu_arburst    (  ),
    // Read Data  IFU
        .o_ifu_rdata      (i_rdata_ifu  ),
        .o_ifu_rresp      (i_rresp_ifu),
        .i_ifu_rready     (o_rready_ifu ),
        .o_ifu_rvalid     (i_rvalid_ifu ),
        .o_ifu_rlast      (i_rlast_ifu),
        .o_ifu_rid        (i_rid_ifu),
    // Write Address  IFU
        .i_ifu_awaddr     (   ),
        .i_ifu_awvalid    (   ),
        .o_ifu_awready    (i_awready_ifu),
        .i_ifu_awid       (   ),
        .i_ifu_awlen      (   ),
        .i_ifu_awsize     (   ),
        .i_ifu_awburst    (   ),
    // Write Data IFU
        .i_ifu_wdata      (   ), 
        .i_ifu_wstrb      (   ),
        .i_ifu_wvalid     (   ),
        .o_ifu_wready     (i_wready_ifu),
        .i_ifu_wlast      (   ),
    // Write Back IFU
        .o_ifu_bresp      (i_bresp_ifu),
        .o_ifu_bvalid     (i_bvalid_ifu),
        .i_ifu_bready     (   ),
        .o_ifu_bid        (i_bid_ifu),
    /*------------------------ lsu -----------------------*/
    // Read Address
        // .i_lsu_req        (    ),

        .i_lsu_araddr     (o_araddr_lsu ), 
        .i_lsu_arvalid    (o_arvalid_lsu),
        .o_lsu_arready    (i_arready_lsu),
        .i_lsu_arid       (   ),
        .i_lsu_arlen      (   ),
        .i_lsu_arsize     (   ),
        .i_lsu_arburst    (   ),
    // Read Data
        .o_lsu_rdata      (i_rdata_lsu  ),
        .o_lsu_rresp      (i_rresp_lsu),
        .i_lsu_rready     (o_rready_lsu ),
        .o_lsu_rvalid     (i_rvalid_lsu ),
        .o_lsu_rlast      (i_rlast_lsu),
        .o_lsu_rid        (i_rid_lsu),
    // Write Address
        .i_lsu_awaddr     (o_awaddr_lsu  ),
        .i_lsu_awvalid    (o_awvalid_lsu ),
        .o_lsu_awready    (i_awready_lsu ),
        .i_lsu_awid       (   ),
        .i_lsu_awlen      (   ),
        .i_lsu_awsize     (   ),
        .i_lsu_awburst    (   ),
    // Write Data
        .i_lsu_wdata      ( o_wdata_lsu  ),
        .i_lsu_wstrb      ( o_wstrb_lsu  ),
        .i_lsu_wvalid     ( o_wvalid_lsu ),
        .o_lsu_wready     ( i_wready_lsu ),
        .i_lsu_wlast      (   ),
    // Write Back
        .o_lsu_bresp      ( i_bresp_lsu  ), 
        .o_lsu_bvalid     ( i_bvalid_lsu ),
        .i_lsu_bready     (   ),
        .o_lsu_bid        ( i_bid_lsu  ),
    /*------------------------ soc -----------------------*/
        .io_master_awready   ( io_master_awready ),
        .io_master_awvalid   ( io_master_awvalid ),
        .io_master_awaddr    ( io_master_awaddr  ),
        .io_master_awid      ( io_master_awid    ),
        .io_master_awlen     ( io_master_awlen   ),
        .io_master_awsize    ( io_master_awsize  ),
        .io_master_awburst   ( io_master_awburst ),
 
        .io_master_wready    ( io_master_wready  ),
        .io_master_wvalid    ( io_master_wvalid  ),
        .io_master_wdata     ( io_master_wdata  ),
        .io_master_wstrb     ( io_master_wstrb  ),
        .io_master_wlast     ( io_master_wlast  ),

        .io_master_bready    ( io_master_bready ),
        .io_master_bvalid    ( io_master_bvalid  ), 
        .io_master_bresp     ( io_master_bresp   ),
        .io_master_bid       ( io_master_bid     ),

        .io_master_arready   ( io_master_arready ),
        .io_master_arvalid   ( io_master_arvalid ),
        .io_master_araddr    ( io_master_araddr  ),
        .io_master_arid      ( io_master_arid    ),
        .io_master_arlen     ( io_master_arlen  ),
        .io_master_arsize    ( io_master_arsize ),
        .io_master_arburst   ( io_master_arburst),

        .io_master_rready    ( io_master_rready ),
        .io_master_rvalid    ( io_master_rvalid ),
        .io_master_rresp    ( io_master_rresp  ), 
        .io_master_rdata    ( io_master_rdata  ),
        .io_master_rlast    ( io_master_rlast  ),
        .io_master_rid      ( io_master_rid    ),

    /*------------------------ sram -----------------------*/
        // .io_master_awready   (o_awready),
        // .io_master_awvalid   (i_awvalid),
        // .io_master_awaddr    (i_awaddr ),
        // .io_master_awid      (i_awid   ),
        // .io_master_awlen     (i_awlen  ),
        // .io_master_awsize    (i_awsize ),
        // .io_master_awburst   (i_awburst),
 
        // .io_master_wready    (o_wready ),
        // .io_master_wvalid    (i_wvalid ),
        // .io_master_wdata     (i_wdata ),
        // .io_master_wstrb     (i_wstrb ),
        // .io_master_wlast     (i_wlast ),

        // .io_master_bready    (i_bready),
        // .io_master_bvalid    (o_bvalid), 
        // .io_master_bresp     (o_bresp ),
        // .io_master_bid       (o_bid   ),

        // .io_master_arready   (o_arready ),
        // .io_master_arvalid   (i_arvalid ),
        // .io_master_araddr    (i_araddr  ),
        // .io_master_arid      (i_arid    ),
        // .io_master_arlen     (i_arlen  ),
        // .io_master_arsize    (i_arsize ),
        // .io_master_arburst   (i_arburst),

        // .io_master_rready    (i_rready),
        // .io_master_rvalid    (o_rvalid),
        // .io_master_rresp     (o_rresp ), 
        // .io_master_rdata     (o_rdata ),
        // .io_master_rlast     (o_rlast ),
        // .io_master_rid       (o_rid   ),

    /*------------------------ uart -----------------------*/
    // Read Address
        .o_uart_araddr    (),
        .o_uart_arvalid   (),
        .i_uart_arready   (),
        .o_uart_arid      (),
        .o_uart_arlen     (),
        .o_uart_arsize    (),
        .o_uart_arburst   (),
    // Read Data
        .i_uart_rdata     (),
        .i_uart_rresp     (),
        .i_uart_rvalid    (),
        .o_uart_rready    (),
        .i_uart_rlast     (),
        .i_uart_rid       (),
    // Write Address
        .o_uart_awaddr    (),
        .o_uart_awvalid   (),
        .i_uart_awready   (),
        .o_uart_awid      (),
        .o_uart_awlen     (),
        .o_uart_awsize    (),
        .o_uart_awburst   (),
    // Write Data
        .o_uart_wdata     (),
        .o_uart_wstrb     (),
        .o_uart_wvalid    (),
        .i_uart_wready    (),
        .o_uart_wlast     (),
    // Write Back
        .i_uart_bresp     (),
        .i_uart_bvalid    (),
        .o_uart_bready    (),
        .i_uart_bid       (),
    /*------------------------ clint -----------------------*/
    // Read Address
        .o_clint_araddr    (),
        .o_clint_arvalid   (),
        .i_clint_arready   (),
        .o_clint_arid      (),
        .o_clint_arlen     (),
        .o_clint_arsize    (),
        .o_clint_arburst   (),
    // Read Data
        .i_clint_rdata     (),
        .i_clint_rresp     (),
        .i_clint_rvalid    (),
        .o_clint_rready    (),
        .i_clint_rlast     (),
        .i_clint_rid       (),
    // Write Address
        .o_clint_awaddr    (),
        .o_clint_awvalid   (),
        .i_clint_awready   (),
        .o_clint_awid      (),
        .o_clint_awlen     (),
        .o_clint_awsize    (),
        .o_clint_awburst   (),
    // Write Data
        .o_clint_wdata     (),
        .o_clint_wstrb     (),
        .o_clint_wvalid    (),
        .i_clint_wready    (),
        .o_clint_wlast     (),
    // Write Back
        .i_clint_bresp     (),
        .i_clint_bvalid    (),
        .o_clint_bready    (),
        .i_clint_bid       ()
    );

//   // SRAM -----------------------------------------------------------
//     wire            o_awready;
//     wire            i_awvalid;
//     wire    [31:0]  i_awaddr;
//     wire    [3:0]   i_awid;
//     wire    [7:0]   i_awlen;
//     wire    [2:0]   i_awsize ;
//     wire    [1:0]   i_awburst;

//     wire            o_wready;
//     wire            i_wvalid;
//     wire    [31:0]  i_wdata;
//     wire    [3:0]   i_wstrb;
//     wire            i_wlast;

//     wire            i_bready;
//     wire            o_bvalid;
//     wire    [1:0]   o_bresp;
//     wire    [3:0]   o_bid;

//     wire            o_arready;
//     wire            i_arvalid;
//     wire    [31:0]  i_araddr;
//     wire    [3:0]   i_arid   ;
//     wire    [7:0]   i_arlen  ;
//     wire    [2:0]   i_arsize ;
//     wire    [1:0]   i_arburst;

//     wire            i_rready;
//     wire            o_rvalid;
//     wire    [1:0]   o_rresp;
//     wire    [31:0]  o_rdata;
//     wire            o_rlast;
//     wire    [3:0]   o_rid;

//   ysyx_23060219_SRAM SRAM(
//     .clk              (clock),
//     .rst              (reset),

//     .o_awready        (o_awready),
//     .i_awvalid        (i_awvalid),
//     .i_awaddr         (i_awaddr),
//     .i_awid           (i_awid),
//     .i_awlen          (i_awlen),
//     .i_awsize         (i_awsize ),
//     .i_awburst        (i_awburst),

//     .o_wready         (o_wready),
//     .i_wvalid         (i_wvalid),
//     .i_wdata          (i_wdata),
//     .i_wstrb          (i_wstrb),
//     .i_wlast          (i_wlast),

//     .i_bready         (i_bready),
//     .o_bvalid         (o_bvalid),
//     .o_bresp          (o_bresp),
//     .o_bid            (o_bid),

//     .o_arready        (o_arready),
//     .i_arvalid        (i_arvalid),
//     .i_araddr         (i_araddr),
//     .i_arid           (i_arid   ),
//     .i_arlen          (i_arlen  ),
//     .i_arsize         (i_arsize ),
//     .i_arburst        (i_arburst),

//     .i_rready         (i_rready),
//     .o_rvalid         (o_rvalid),
//     .o_rresp          (o_rresp),
//     .o_rdata          (o_rdata),
//     .o_rlast          (o_rlast),
//     .o_rid            (o_rid)
// );

  // Register File --------------------------------------------------
  wire [31:0] w_rf_rs1;
  wire [31:0] w_rf_rs2;
  
  ysyx_23060219_register_file  register_file_inst(
    // system
    .clk         (clock),
    .rst         (reset),
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
    
    ysyx_23060219_csr_ctrl  csr_ctrl_inst(
    // system
    .clk            (clock),
    .rst            (reset),
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

//===================================================================
// // // 只加握手

// `include "/home/zhong/ysyx-workbench/npc/vsrc/ysyx_23060219_defines.v"

// module ysyx_23060219(
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

