//==============================================================================================================
// add arbiter

`include "/home/zhong/ysyx-workbench/npc/vsrc/ysyx_23060219_defines.v"
`define LSU_PKG_WDITH (`CPU_Width+`CPU_Width+`CPU_Width+1+1+1+`CPU_Width+1+`CPU_Width+5+1+1+1+1+12+`CPU_Width)

module ysyx_23060219_lsu(
    // system
    input  wire             clk,
    input  wire             rst,
    // shake hands
    input  wire             i_pre_valid,   //来自EXU，代表EXU的数据有效
    output wire             o_pre_ready,   //传递给WBU，代表LSU准备好处理新数据了
    output reg              o_post_valid,  //传递给WBU，代表此时数据包寄存器的数据有效
    input  wire             i_post_ready,  //来自WBU，代表WBU准备好处理新数据了
    // from IFU
    input  wire [`CPU_Bus]  i_lsu_pc,
    // from IDU
    input  wire             i_lsu_is_load,
    input  wire             i_lsu_is_store,
    input  wire [2:0]       i_lsu_func3,
    input  wire [`CPU_Bus]  i_lsu_imm,
    input  wire             i_lsu_is_jal,
    input  wire             i_lsu_is_jalr,
    input  wire             i_lsu_brch,
    input  wire [4:0]       i_lsu_rd_id,
    input  wire             i_lsu_gpr_wen,  
    // from Register File
    input  wire [31:0]      i_lsu_rs1,
    input  wire [31:0]      i_lsu_rs2,
    // from CSR Ctrl
    input  wire [`CPU_Bus]  i_lsu_csr_npc,
    input  wire [`CSR_Bus]  i_lsu_csr_wid,
    input  wire [31:0]      i_lsu_csr_rd,
    input  wire             i_lsu_csr_wen,  
    input  wire             i_lsu_is_mret,
    input  wire             i_lsu_is_ecall,
    // from EXU
    input  wire [`CPU_Bus]  i_lsu_exu_res,
    // to BRU
    output wire [`CPU_Bus]  o_lsu_imm,
    output wire [`CPU_Bus]  o_lsu_pc,
    output wire [31:0]      o_lsu_rs1,
    output wire             o_lsu_is_jal,
    output wire             o_lsu_is_jalr,
    output wire             o_lsu_brch,    
    output wire [`CPU_Bus]  o_lsu_csr_npc,
    output wire             o_lsu_is_ejump,  // exception jump    
    // to WBU
    output wire [31:0]      o_lsu_rd,
    output wire [4:0]       o_lsu_rd_id,
    output wire             o_lsu_gpr_wen,
    output wire             o_lsu_csr_wen,
    output wire             o_lsu_is_mret,
    output wire             o_lsu_is_ecall,
    output wire [`CSR_Bus]  o_lsu_csr_wid,
    output wire [31:0]      o_lsu_csr_rd,
    
    output reg              o_lsu_req,
    // to SRAM
    /*---------------- 读地址 ----------------*/
    output  reg  [31:0]     o_araddr,
    output  reg             o_arvalid, //写使能
    input   reg             i_arready,
    // output  reg  [3:0]      o_arid,     //0 ###
    // output  reg  [7:0]      o_arlen,
    // output  reg  [2:0]      o_arsize,
    // output  reg  [1:0]      o_arburst,
    /*---------------- 读数据 ----------------*/
    input   reg  [31:0]     i_rdata,
    input   reg  [1:0]      i_rresp,
    input   reg             i_rvalid,
    output  reg             o_rready,
    // input   reg             i_rlast,    //悬空 ###
    // input   reg  [3:0]      i_rid,
    /*---------------- 写地址 ----------------*/
    output  reg  [31:0]     o_awaddr,
    output  reg             o_awvalid,
    input   reg             i_awready,
    // output  wire [3:0]      o_awid,     // 0 ###
    // output  wire [7:0]      o_awlen,
    // output  wire [2:0]      o_awsize,
    // output  wire [1:0]      o_awburst,
    /*---------------- 写数据 ----------------*/
    output  reg  [31:0]     o_wdata, 
    output  reg  [3:0]      o_wstrb,  // 写字节使能  写掩码
    output  reg             o_wvalid,
    input   reg             i_wready,
    // output  wire            o_wlast,    //0 ###
    /*---------------- 写回复 ----------------*/
    input   reg  [1:0]      i_bresp,
    input   reg             i_bvalid,
    output  reg             o_bready,
    // input   reg  [3:0]      i_bid,

    input   reg             i_exu_success
);

    import "DPI-C" function int  dmem_read(input int raddr);
    import "DPI-C" function void pmem_write(input int waddr, input int wdata, input byte wmask);
    import "DPI-C" function void TRAP(input int station, input byte unit);

/*-------------- output set 0 --------------- */
    // assign o_arid = 0;
    // assign o_arlen = 0;
    // assign o_arsize = 0;
    // assign o_arburst = 0;

    // assign o_awid = 0;
    // assign o_awlen = 0;
    // assign o_awsize = 0;
    // assign o_awburst = 0;

    // assign o_wlast = 0;
/*-------------------------------------------*/

    // to BRU
    wire [`CPU_Bus] lsu_imm      = i_lsu_imm;
    wire [`CPU_Bus] lsu_pc       = i_lsu_pc; 
    wire [31:0]     lsu_rs1      = i_lsu_rs1; 
    wire            lsu_is_jal   = i_lsu_is_jal;
    wire            lsu_is_jalr  = i_lsu_is_jalr;
    wire            lsu_brch     = i_lsu_brch;
    wire [`CPU_Bus] lsu_csr_npc  = i_lsu_csr_npc;
    wire            lsu_is_ejump = i_lsu_is_mret | i_lsu_is_ecall; 
    // to WEU
    wire [`CPU_Bus] lsu_rd;
    wire [4:0]      lsu_rd_id    = i_lsu_rd_id;
    wire            lsu_gpr_wen  = i_lsu_gpr_wen;  
    wire            lsu_csr_wen  = i_lsu_csr_wen;
    wire            lsu_is_mret  = i_lsu_is_mret;
    wire            lsu_is_ecall = i_lsu_is_ecall;
    wire [`CSR_Bus] lsu_csr_wid  = i_lsu_csr_wid;
    wire [`CPU_Bus] lsu_csr_rd   = i_lsu_csr_rd;


    /************ read dmem ************/
    wire [`CPU_Bus] dmem_raddr = i_lsu_exu_res;
    reg  [`CPU_Bus] dmem_rdata_t;
    reg  [`CPU_Bus] dmem_rdata;
    reg  [`CPU_Bus] dmem_rdata_tmp;


    always@(posedge clk or posedge rst) begin
        if(rst) begin
            o_rready <= 0; 
            o_arvalid <= 0;
            o_lsu_req <= 0;
        end else begin      // load 读RAM 
            if(i_lsu_is_load == `TRUE && i_exu_success && !o_arvalid) begin
                o_araddr  <= dmem_raddr;
                o_arvalid <= 1;
                o_lsu_req <= 1;
            end
            if(o_arvalid && i_arready) begin
                o_rready <= 1;
                o_arvalid <= 0; 
            end
            if(i_rvalid && o_rready) begin
                o_rready <= 0;
                o_lsu_req <= 0;
                dmem_rdata_tmp <= i_rdata;      // 读到的数据放dmem_rdata_tmp
            end
        end
    end    


    always @(*) begin
        dmem_rdata = `CPU_Width'd0;
        dmem_rdata_t = `CPU_Width'd0;
         // 位移后的数据放dmem_rdata_t
        if(i_lsu_is_load == `TRUE)  begin
            if( (i_lsu_func3 == `INST_LBU) || (i_lsu_func3 == `INST_LB) ) begin         // 单字节
                if ( dmem_raddr[1:0] == 2'b01 ) begin           // 位移一个字节
                    dmem_rdata_t = dmem_rdata_tmp >> 4'd8;     
                end
                else if ( dmem_raddr[1:0] == 2'b10 ) begin      // 位移二个字节
                    dmem_rdata_t = dmem_rdata_tmp >> 5'd16;
                end
                else if ( dmem_raddr[1:0] == 2'b11 ) begin      // 位移三个字节
                    dmem_rdata_t = dmem_rdata_tmp >> 5'd24;
                end
                else dmem_rdata_t = dmem_rdata_tmp >> 1'd0;             // dmem_raddr[1:0] == 2'b00保持不变
            end
            else if( (i_lsu_func3 == `INST_LHU) || (i_lsu_func3 == `INST_LH) ) begin    // 双字节
                if ( dmem_raddr[1:0] == 2'b10 ) begin           // 位移2个字节
                    dmem_rdata_t = dmem_rdata_tmp >> 5'd16;
                end
                else dmem_rdata_t = dmem_rdata_tmp >> 1'd0;             // dmem_raddr[1:0] == 2'b00保持不变
            end
            else dmem_rdata_t = dmem_rdata_tmp >> 1'd0;                 // LW保持不变   // 四字节

            // 截取后的最终数据放dmem_rdata
            case (i_lsu_func3)
                `INST_LBU:  dmem_rdata = {24'd0, dmem_rdata_t[7:0]};
                `INST_LHU:  dmem_rdata = {16'd0, dmem_rdata_t[15:0]};
                `INST_LB:   dmem_rdata = {{24{dmem_rdata_t[7]}}, dmem_rdata_t[7:0]};
                `INST_LH:   dmem_rdata = {{16{dmem_rdata_t[15]}}, dmem_rdata_t[15:0]};
                `INST_LW:   dmem_rdata = dmem_rdata_t;
                default:    TRAP(`ABORT, `Unit_LSU1);  
            endcase
        end
        else dmem_rdata_t = dmem_rdata_tmp >> 1'd0; //i_lsu_is_load 不为 `TRUE，保持不变
    end           

    assign o_lsu_rd = (i_lsu_is_load == `TRUE) ? dmem_rdata : i_lsu_exu_res; 



    /*------------------ write dmem ------------------*/
    wire [`CPU_Bus] dmem_waddr = i_lsu_exu_res;
    wire [`CPU_Bus] dmem_wdata_tmp = i_lsu_rs2;         // 想要写入的数据放在dmem_wdata
    reg  [3:0]      wmask , wmask_init;
    reg  [`CPU_Bus] dmem_wdata;
    // wmask
    always @(*) begin
        dmem_wdata = 32'd0;
        wmask_init = 4'd0;
        if(i_lsu_is_store == `TRUE) begin // 有写请求时
            case (i_lsu_func3)
                `INST_SB: wmask_init = `WByte;  //4'b0001
                `INST_SH: wmask_init = `WHalf;  //4'b0011
                `INST_SW: wmask_init = `WWord;  //4'b1111
                default:  TRAP(`ABORT, `Unit_LSU2);
            endcase

            if( i_lsu_func3 == `INST_SB ) begin         // 单字节
                if ( dmem_waddr[1:0] == 2'b01 ) begin               // 位移一个字节
                    dmem_wdata = dmem_wdata_tmp << 4'd8;    
                    wmask = wmask_init << 2'd1;
                end
                else if ( dmem_waddr[1:0] == 2'b10 ) begin          // 位移二个字节
                    dmem_wdata = dmem_wdata_tmp << 5'd16;
                    wmask = wmask_init << 2'd2;
                end
                else if ( dmem_waddr[1:0] == 2'b11 ) begin          // 位移三个字节
                    dmem_wdata = dmem_wdata_tmp << 5'd24;
                    wmask = wmask_init << 2'd3;
                end
                else begin
                    dmem_wdata = dmem_wdata_tmp << 1'd0;            // dmem_waddr[1:0] == 2'b00保持不变
                    wmask = wmask_init << 2'd0;
                end
            end

            else if( i_lsu_func3 == `INST_SH ) begin    // 双字节
                if ( dmem_waddr[1:0] == 2'b10 ) begin               // 位移2个字节
                    dmem_wdata = dmem_wdata_tmp << 5'd16;
                    wmask = wmask_init << 2'd2;
                end
                else begin
                    dmem_wdata = dmem_wdata_tmp << 1'd0;            // dmem_waddr[1:0] == 2'b00保持不变
                    wmask = wmask_init << 2'd0;
                end
            end
            else begin
                dmem_wdata = dmem_wdata_tmp << 1'd0;    // 四字节    // SW保持不变
                wmask = wmask_init << 2'd0;
            end
        end
    end



    always@(posedge clk or posedge rst) begin
        if(rst) begin
            o_awvalid <= 1'b0;
            o_wvalid <= 1'b0;
            o_lsu_req <= 0;
        end else begin
            if(i_lsu_is_store == `TRUE && i_exu_success && !o_awvalid) begin
                o_awvalid <= 1'b1;
                o_awaddr <= dmem_waddr;
                o_lsu_req <= 1;
            end
            if(i_awready && o_awvalid) begin
                o_wvalid <= 1'b1;
                o_wdata <= dmem_wdata;
                o_wstrb <= wmask;
                o_awvalid <= 1'b0;
            end
            if(i_wready && o_wvalid) begin
                o_wvalid <= 1'b0;
                o_lsu_req <= 0;
                o_awaddr <= 0;
                o_wstrb <= 0;
                o_wdata <= 0;
            end
        end
    end


    // data package
    wire  lsu_reg_wen  = i_pre_valid & o_pre_ready; 
    reg  [`LSU_PKG_WDITH-1 : 0] lsu_valid_data_reg;  

    always @(posedge clk) begin
        if(rst == 1'b1) 
            lsu_valid_data_reg <= 0;
        else if(lsu_reg_wen == 1'b1) begin
            lsu_valid_data_reg <= { lsu_imm, lsu_pc, lsu_rs1, lsu_is_jal, lsu_is_jalr, lsu_brch, 
            lsu_csr_npc, lsu_is_ejump, o_lsu_rd, lsu_rd_id, lsu_gpr_wen, lsu_csr_wen, lsu_is_mret, lsu_is_ecall, lsu_csr_wid, lsu_csr_rd };
            
        end
    end



    assign{ o_lsu_imm, o_lsu_pc, o_lsu_rs1, o_lsu_is_jal, o_lsu_is_jalr, o_lsu_brch, o_lsu_csr_npc, o_lsu_is_ejump, o_lsu_rd, o_lsu_rd_id, o_lsu_gpr_wen, 
    o_lsu_csr_wen, o_lsu_is_mret, o_lsu_is_ecall, o_lsu_csr_wid, o_lsu_csr_rd } = lsu_valid_data_reg;


    reg post_valid_reg;
    reg post_valid_delay_1, post_valid_delay_2, post_valid_delay_3, post_valid_delay_4, post_valid_delay_5;

    // 寄存器用于保存前一个周期的状态
    always @(posedge clk) begin
        if (rst) begin
            post_valid_reg <= 1'b0;
            post_valid_delay_1 <= 1'b0;
            post_valid_delay_2 <= 1'b0;
            post_valid_delay_3 <= 1'b0;
            post_valid_delay_4 <= 1'b0;
            post_valid_delay_5 <= 1'b0;
        end else begin
            // 更新 post_valid_reg
            post_valid_reg <= i_pre_valid;

            // 检测 i_lsu_is_load 指令
            if (i_lsu_is_load | i_lsu_is_store) begin
                // 当 i_lsu_is_load 为高时，推迟两个周期
                post_valid_delay_1 <= post_valid_reg; // 第一个周期
                post_valid_delay_2 <= post_valid_delay_1; // 第二个周期
                post_valid_delay_3 <= post_valid_delay_2; // 第二个周期
                post_valid_delay_4 <= post_valid_delay_3; // 第二个周期
                post_valid_delay_5 <= post_valid_delay_4; // 第二个周期
            end else begin
                // 当 i_lsu_is_load 为低时，立即使用 post_valid_reg 的值
                post_valid_delay_1 <= 1'b0;
                post_valid_delay_2 <= 1'b0;
                post_valid_delay_3 <= 1'b0;
                post_valid_delay_4 <= 1'b0;
                post_valid_delay_5 <= 1'b0;
            end
        end
    end

    // assign o_post_valid = 

    always@(*) begin
        if(i_lsu_is_load) o_post_valid = post_valid_delay_5;
        else if(i_lsu_is_store) o_post_valid = post_valid_delay_1;
        else o_post_valid = post_valid_reg;
    end

    // 输出信号
    assign o_pre_ready = ~o_post_valid;




endmodule
