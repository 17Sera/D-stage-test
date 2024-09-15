`include "/home/zhong/ysyx-workbench/npc/vsrc/defines.v"
// `define LSU_PKG_WDITH (`CPU_Width+`CPU_Width+`CPU_Width+1+1+1+`CPU_Width+1+`CPU_Width+5+1+1+1+1+12+`CPU_Width)
`define LSU_PKG_WDITH (`CPU_Width+`CPU_Width+`CPU_Width+1+1+1+`CPU_Width+1+`CPU_Width+5+1+1+1+1+12)
//若CPU_Width为32，则LSU_PKG_WDITH为217

module lsu(     //Load/Store Unit  负责处理加载和存储指令的单元
    // system
    input  wire            clk,
    input  wire            rst,
    // 握手信号----------------------------
    input  wire            i_pre_valid,   //来自EXU，代表EXU的数据有效
    output wire            o_pre_ready,   //传递给EXU，代表LSU准备好处理新数据了
    output wire            o_post_valid,  //传递给WBU，代表此时数据包寄存器的数据有效
    input  wire            i_post_ready,  //来自WBU，代表WBU准备好处理新数据了
    // from IFU ---------------------------
    input  wire [31:0]     i_lsu_pc,
    // from IDU----------------------------
    input  wire            i_lsu_is_load,   // 判断指令类型
    input  wire            i_lsu_is_store,
    input  wire [2:0]      i_lsu_func3,
    input  wire [31:0]     i_lsu_imm,
    input  wire            i_lsu_is_jal,
    input  wire            i_lsu_is_jalr,
    input  wire            i_lsu_brch,      //branch指令
    input  wire [4:0]      i_lsu_rd_id,     
    input  wire            i_lsu_gpr_wen,   //代表是否需要写回GPR
    // from Register File--------------------
    input  wire [31:0]     i_lsu_rs1,
    input  wire [31:0]     i_lsu_rs2,
    // from CSR Ctrl-------------------------
    input  wire [31:0]     i_lsu_csr_npc,
    input  wire [`CSR_Bus] i_lsu_csr_wid,   //代表CSR寄存器的ID
    input  wire [31:0]     i_lsu_csr_rd,
    input  wire            i_lsu_csr_wen,   //代表CSR寄存器的写使能
    input  wire            i_lsu_is_mret,
    input  wire            i_lsu_is_ecall,
    // from EXU
    input  wire [31:0]     i_lsu_exu_res,   //代表EXU的计算结果
    // to BRU   给分支决策单元---------------
    output wire [31:0]     o_lsu_imm,
    output wire [31:0]     o_lsu_pc,
    output wire [31:0]     o_lsu_rs1,
    output wire            o_lsu_is_jal,
    output wire            o_lsu_is_jalr,
    output wire            o_lsu_brch,      // 输出给BRU的分支信号
    output wire [31:0]     o_lsu_csr_npc,   // 输出给BRU的CSR新PC值
    output wire            o_lsu_is_ejump,  // 异常跳转信号（mret或ecall）
    // to WEU   给写回单元--------------------
    output wire [31:0]     o_lsu_rd,         //代表LSU的计算结果
    output wire [4:0]      o_lsu_rd_id,     //代表LSU的计算结果的ID
    output wire            o_lsu_gpr_wen,   //代表是否需要写回GPR
    output wire            o_lsu_csr_wen,   //代表CSR寄存器的写使能
    output wire            o_lsu_is_mret,
    output wire            o_lsu_is_ecall,
    output wire [`CSR_Bus] o_lsu_csr_wid,   //代表CSR寄存器的ID
    output wire [31:0]     o_lsu_csr_rd     //代表CSR寄存器的读数据
);

    import "DPI-C" function int  dmem_read(input int raddr);    //数据内存读取函数
    import "DPI-C" function void pmem_write(input int waddr, input int wdata, input byte wmask);
    import "DPI-C" function void TRAP(input int station, input byte unit);


    // ⌈‾‾‾‾‾⌉ -->i_cycle_end --> ⌈‾‾‾‾‾⌉ --> o_post_valid-->i_pre_valid --> ⌈‾‾‾‾‾⌉ --> o_post_valid --> i_pre_valid -->⌈‾‾‾‾‾⌉ --> o_post_valid --> i_pre_valid -->⌈‾‾‾‾‾⌉ --> o_post_valid --> i_pre_valid -->⌈‾‾‾‾‾⌉   
    // | WBU |                   | IFU |                                   | IDU |                                     | EXU |                                    | LSU |                                    | WBU |
    // ⌊_____⌋                    ⌊_____⌋ <-- i_post_ready<-- o_pre_ready <--⌊_____⌋<-- i_post_ready <-- o_pre_ready <-- ⌊_____⌋<-- i_post_ready <-- o_pre_ready <-- ⌊_____⌋<-- i_post_ready <-- o_pre_ready <-- ⌊_____⌋     

    /****************************** data package ******************************/
    // to BRU
    wire [31:0]     lsu_imm      = i_lsu_imm;   //31:0
    wire [31:0]     lsu_pc       = i_lsu_pc; 
    wire [31:0]     lsu_rs1      = i_lsu_rs1; 
    wire            lsu_is_jal   = i_lsu_is_jal;
    wire            lsu_is_jalr  = i_lsu_is_jalr;
    wire            lsu_brch     = i_lsu_brch;
    wire [31:0]     lsu_csr_npc  = i_lsu_csr_npc;
    wire            lsu_is_ejump = i_lsu_is_mret | i_lsu_is_ecall; 
    // to WEU
    wire [31:0]     lsu_rd;
    wire [4:0]      lsu_rd_id    = i_lsu_rd_id;
    wire            lsu_gpr_wen  = i_lsu_gpr_wen;   //是否需要写回GPR
    wire            lsu_csr_wen  = i_lsu_csr_wen;   //是否需要写CSR
    wire            lsu_is_mret  = i_lsu_is_mret;
    wire            lsu_is_ecall = i_lsu_is_ecall;
    wire [`CSR_Bus] lsu_csr_wid  = i_lsu_csr_wid;   //CSR寄存器的ID
    wire [31:0]     lsu_csr_rd   = i_lsu_csr_rd;    //CSR寄存器的读数据


    /****************************** read dmem ******************************/

    wire [31:0]     dmem_raddr   = i_lsu_exu_res; 
    reg  [31:0]     dmem_rdata_t;
    reg  [31:0]     dmem_rdata; 
    // 有读请求时
    always @(posedge clk) begin     // 识别出 load 指令后，由时序逻辑等下一个上升沿赋值给 dmem_rdata_t
        if(i_lsu_is_load == `TRUE)  begin 
            dmem_rdata_t <= dmem_read(dmem_raddr); 
        end else begin
            dmem_rdata_t <= 32'h00000001;    //没有读dmem请求时，dmem_rdata_t置1
        end
    end    


    always @(*) begin               // 识别出 load 指令后，由组合逻辑马上赋值给 dmem_rdata
        dmem_rdata = `CPU_Width'd0;
        if(i_lsu_is_load == `TRUE)  begin 
            case (i_lsu_func3)   // 根据func3分类 决定数据的处理方式,确定不同类型的加载指令
                `INST_LBU:  dmem_rdata = {24'd0, dmem_rdata_t[7:0]};
                `INST_LHU:  dmem_rdata = {16'd0, dmem_rdata_t[15:0]};
                `INST_LB:   dmem_rdata = {{24{dmem_rdata_t[7]}}, dmem_rdata_t[7:0]};
                `INST_LH:   dmem_rdata = {{16{dmem_rdata_t[15]}}, dmem_rdata_t[15:0]};
                `INST_LW:   dmem_rdata = dmem_rdata_t;
                default:    TRAP(`ABORT, `Unit_LSU1); 
            endcase
        end
    end      


    // assign lsu_rd = (i_lsu_is_load == `TRUE) ? dmem_rdata : i_lsu_exu_res;  // 根据是否是加载指令决定 lsu_rd 的值 ---- 组合逻辑与dmem_rdata同步变化
    assign o_lsu_rd = (i_lsu_is_load == `TRUE) ? dmem_rdata : i_lsu_exu_res;  // 根据是否是加载指令决定 lsu_rd 的值 ---- 组合逻辑与dmem_rdata同步变化

    /************************************ write dmem ************************************/
    wire [31:0] dmem_waddr = i_lsu_exu_res;   //数据内存写入地址 lsu exu 结果
    wire [31:0] dmem_wdata = i_lsu_rs2;       //数据内存写入数据 lsu rs2
    reg  [7:0]    wmask;    

    always @(*) begin
        if(i_lsu_is_store == `TRUE) begin // 有写请求时
            case (i_lsu_func3)   // 根据func3分类 决定写操作的类型
                `INST_SB: wmask = `WByte;   // byte  8'b0000_0001 字节写操作  8位
                `INST_SH: wmask = `WHalf;   // half  8'b0000_0011 半字写操作  16位
                `INST_SW: wmask = `WWord;   // word  8'b0000_1111 字写操作  32位
                default:  TRAP(`ABORT, `Unit_LSU2); 
            endcase
        end
    end  


    always @(*) begin
        if(i_lsu_is_store == `TRUE) begin   // 有写请求时（存储请求）
            pmem_write(dmem_waddr, dmem_wdata, wmask);  //调用 pmem_write 函数将dmem_wdata写入地址dmem_waddr，wmask用于选择写入的字节
        end
    end


    // data package
    wire  lsu_reg_wen  = i_pre_valid & o_pre_ready;   //数据包寄存器的写使能---两个信号相与---> 确保数据写入操作 在数据有效和寄存器准备好的情况下进行
    reg  [`LSU_PKG_WDITH-1 : 0] lsu_valid_data_reg;   //负责存储 LSU 的所有关键信号信息

    always @(posedge clk) begin
        if(rst == 1'b1) 
            lsu_valid_data_reg <= 0;
        else if(lsu_reg_wen == 1'b1)    //数据包寄存器的写使能开启,数据包被写入寄存器，并通过 assign 语句将存储的数据包解包
            lsu_valid_data_reg <= { lsu_imm, lsu_pc, lsu_rs1, lsu_is_jal, lsu_is_jalr, lsu_brch, 
                                    lsu_csr_npc, lsu_is_ejump, lsu_rd_id, lsu_gpr_wen, 
                                    lsu_csr_wen, lsu_is_mret, lsu_is_ecall, lsu_csr_wid, lsu_csr_rd };
    end
    

    // 数据拆分并分配给各个输出信号
    assign{ o_lsu_imm, o_lsu_pc, o_lsu_rs1, o_lsu_is_jal, o_lsu_is_jalr, o_lsu_brch, 
            o_lsu_csr_npc, o_lsu_is_ejump, o_lsu_rd_id, o_lsu_gpr_wen, 
            o_lsu_csr_wen, o_lsu_is_mret, o_lsu_is_ecall, o_lsu_csr_wid, o_lsu_csr_rd } = lsu_valid_data_reg;



    // shake hands
    reg post_valid_reg;
    always @(posedge clk) begin
        if(rst == 1'b1) 
            post_valid_reg <= 1'h0;
        else
            post_valid_reg <= i_pre_valid;  //延迟一周期
    end
    assign o_post_valid = post_valid_reg;   //传递给WBU，代表LSU准备好处理新数据了
    assign o_pre_ready  = ~o_post_valid;     //传递给WBU，代表LSU准备好处理新数据了

endmodule
