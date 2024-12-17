
// add arbiter

`include "/home/zhong/ysyx-workbench/npc/vsrc/ysyx_23060219_defines.v"
`define EXU_PKG_WDITH  (`CPU_Width+1+1+3+`CPU_Width+`CPU_Width+`CPU_Width+`CPU_Width+12+1+1+1+`CPU_Width+`CPU_Width+1+1+1+5+1)

module ysyx_23060219_exu(
    // system
    input  wire            clk,
    input  wire            rst,
    // shake hands
    input  wire            i_pre_valid,   //来自IDU，代表IDU的数据有效
    output wire            o_pre_ready,   //传递给LSU，代表EXU准备好处理新数据了
    output wire            o_post_valid,  //传递给LSU，代表此时数据包寄存器的数据有效
    input  wire            i_post_ready,  //来自LSU，代表LSU准备好处理新数据了
    // from from IFU
    input  wire [`CPU_Bus] i_exu_pc,
    // from IDU
    input  wire [`ALU_Bus] i_exu_alu_type,
    input  wire [1:0]      i_exu_num_sel,
    input  wire [`CPU_Bus] i_exu_imm,
    input  wire            i_exu_is_jal,
    input  wire            i_exu_is_jalr,
    input  wire            i_exu_is_brch,
    input  wire            i_exu_is_load,
    input  wire            i_exu_is_store,
    input  wire [2:0]      i_exu_func3,
    input  wire [4:0]      i_exu_rd_id,
    input  wire            i_exu_gpr_wen,  
    input  wire [1:0]      i_exu_csr_type,  
    output wire [`CSR_Bus] i_exu_csr_rid,
    output wire            i_exu_csr_ren,  
    output wire            i_exu_is_mret,
    output wire            i_exu_is_ecall,
    // from Register File
    input  wire [31:0]  i_exu_rs1,
    input  wire [31:0]  i_exu_rs2,
    // from CSR Ctrl
    input  wire [31:0]  i_exu_csr_src,
    input  wire [`CPU_Bus] i_exu_csr_npc,
    // to LSU
    output wire [`CPU_Bus] o_exu_exu_res, 
    output wire            o_exu_is_load,
    output wire            o_exu_is_store,
    output wire [2:0]      o_exu_func3,
    output wire [31:0]  o_exu_rs1,
    output wire [31:0]  o_exu_rs2,
    output wire [`CPU_Bus] o_exu_csr_npc,
    output wire            o_exu_is_mret,
    output wire            o_exu_is_ecall,
    // to to BRU
    output wire [`CPU_Bus] o_exu_imm,
    output wire [`CPU_Bus] o_exu_pc,
    output wire            o_exu_is_jal,
    output wire            o_exu_is_jalr,
    output wire            o_exu_brch,
    // to to WBU
    output wire [4:0]      o_exu_rd_id,
    output wire            o_exu_gpr_wen,  
    output wire [`CSR_Bus] o_exu_csr_wid,
    output wire [31:0]  o_exu_csr_rd,
    output wire            o_exu_csr_wen,

    output reg             o_exu_success
);

    import "DPI-C" function void TRAP(input int station, input byte unit);

    /************ data package ************/
    // to LSU
    wire [`CPU_Bus] exu_exu_res  = (i_exu_csr_ren == `Enable) ? i_exu_csr_src : exu_alu_res;
    wire            exu_is_load  = i_exu_is_load;
    wire            exu_is_store = i_exu_is_store;
    wire [2:0]      exu_func3    = i_exu_func3;
    wire [`CPU_Bus] exu_rs1      = i_exu_rs1;
    wire [`CPU_Bus] exu_rs2      = i_exu_rs2;
    wire [`CPU_Bus] exu_csr_npc  = i_exu_csr_npc; 
    wire            exu_is_mret  = i_exu_is_mret;
    wire            exu_is_ecall = i_exu_is_ecall;
    // to to BRU
    wire [`CPU_Bus] exu_imm      = i_exu_imm;
    wire [`CPU_Bus] exu_pc       = i_exu_pc;
    wire            exu_is_jal   = i_exu_is_jal;
    wire            exu_is_jalr  = i_exu_is_jalr;
    wire            exu_brch     = i_exu_is_brch & exu_alu_res[0];  //check if is branch inst while branch condition is true
    // to to WEU
    wire [4:0]      exu_rd_id    = i_exu_rd_id;
    wire            exu_gpr_wen  = i_exu_gpr_wen;
    wire [`CSR_Bus] exu_csr_wid   = i_exu_csr_rid;// 读和写同一个id
    wire [`CPU_Bus] exu_csr_rd;
    wire            exu_csr_wen  = i_exu_csr_ren; // 读和写同一个id

    ysyx_23060219_MuxKey #(4, 2, `CPU_Width) mux1(num1, i_exu_num_sel, {
        `RS1_RS2, i_exu_rs1,
        `RS1_IMM, i_exu_rs1,
        `PC_IMM,  i_exu_pc,
        `PC_4,    i_exu_pc}       
    );

    ysyx_23060219_MuxKey #(4, 2, `CPU_Width) mux2(num2, i_exu_num_sel, {
        `RS1_RS2, i_exu_rs2,
        `RS1_IMM, i_exu_imm,
        `PC_IMM,  i_exu_imm,
        `PC_4,    `CPU_Width'd4}       
    );

    ysyx_23060219_MuxKey #(4, 2, `CPU_Width) mux3(exu_csr_rd, i_exu_csr_type, {
        `CSR_Nop, `CPU_Width'd0,
        `CSR_RW,  i_exu_rs1,
        `CSR_RS,  i_exu_rs1 | i_exu_csr_src,
        `CSR_RC,  i_exu_rs1 & ~i_exu_csr_src}       
    );

    // alu
    reg  [`CPU_Bus] exu_alu_res;
    wire [`CPU_Bus] num1, num2;
    wire [`CPU_Bus] num2_cplm = ~num2 + `CPU_Width'h1;   // 补码
    always @(*) begin
        exu_alu_res = `CPU_Width'd0;
        case (i_exu_alu_type)
            `ALU_ADD:   exu_alu_res = num1 + num2;
            `ALU_SUB:   exu_alu_res = num1 + num2_cplm;
            `ALU_SLL:   exu_alu_res = num1 << num2[4:0];
            `ALU_XOR:   exu_alu_res = num1 ^ num2;
            `ALU_SRL:   exu_alu_res = num1 >> num2[4:0];
            `ALU_SRA:   exu_alu_res = ($signed(num1)) >>> num2[4:0];
            `ALU_OR:    exu_alu_res = num1 | num2;
            `ALU_AND:   exu_alu_res = num1 & num2;
            `ALU_EQ:    exu_alu_res = {{(`CPU_Width - 1){1'b0}}, (num1 == num2)};
            `ALU_NE:    exu_alu_res = {{(`CPU_Width - 1){1'b0}}, (num1 != num2)};
            `ALU_LT:    exu_alu_res = {{(`CPU_Width - 1){1'b0}}, (($signed(num1)) <  ($signed(num2)))};
            `ALU_GE:    exu_alu_res = {{(`CPU_Width - 1){1'b0}}, (($signed(num1)) >= ($signed(num2)))};
            `ALU_LTU:   exu_alu_res = {{(`CPU_Width - 1){1'b0}}, (num1 <  num2)};
            `ALU_GEU:   exu_alu_res = {{(`CPU_Width - 1){1'b0}}, (num1 >= num2)};
            default:    TRAP(`ABORT, `Unit_EXU1);  
        endcase
    end
    

    // data package
    wire exu_reg_wen  = i_pre_valid & o_pre_ready;   //数据包寄存器的写使能
    reg  [`EXU_PKG_WDITH-1 : 0] exu_valid_data_reg;  
    always @(posedge clk) begin
        if(rst == 1'b1) 
            exu_valid_data_reg <= 0;
        else if(exu_reg_wen == 1'b1) 
            exu_valid_data_reg <= { exu_exu_res, exu_is_load, exu_is_store, exu_func3, exu_rs1, exu_rs2, exu_csr_npc, exu_is_mret, exu_is_ecall, 
                                    exu_imm, exu_pc, exu_is_jal, exu_is_jalr, exu_brch, exu_rd_id, exu_gpr_wen, exu_csr_wid, exu_csr_rd, exu_csr_wen };
    end

    assign{ o_exu_exu_res, o_exu_is_load, o_exu_is_store, o_exu_func3, o_exu_rs1, o_exu_rs2, o_exu_csr_npc, o_exu_is_mret, o_exu_is_ecall, 
            o_exu_imm, o_exu_pc, o_exu_is_jal, o_exu_is_jalr, o_exu_brch, o_exu_rd_id, o_exu_gpr_wen, o_exu_csr_wid, o_exu_csr_rd, o_exu_csr_wen } = exu_valid_data_reg;



    // shake hands
    reg post_valid_reg;
    always @(posedge clk) begin
        if(rst == 1'b1) 
            post_valid_reg <= 1'h0;
        else
            post_valid_reg <= i_pre_valid;
    end
    assign o_post_valid = post_valid_reg;
    assign o_pre_ready  = ~o_post_valid;
    
    //reg o_exu_success;
    always@(posedge clk) begin
        if(exu_reg_wen) o_exu_success <= exu_reg_wen;
        else o_exu_success <= 0;
    end


endmodule

//=================================================================================================================

// // 都可

// `include "/home/zhong/ysyx-workbench/npc/vsrc/ysyx_23060219_defines.v"
// `define EXU_PKG_WDITH  (`CPU_Width+1+1+3+`CPU_Width+`CPU_Width+`CPU_Width+`CPU_Width+12+1+1+1+`CPU_Width+`CPU_Width+1+1+1+5+1)
// //EXU_PKG_WDITH 计算了一个数据包的总位宽度,若CPU_Width 是32位，则EXU_PKG_WDITH 为253

// module exu(
//     // system
//     input  wire             clk,
//     input  wire             rst,
//     // shake hands--------------------------
//     input  wire             i_pre_valid,   //来自IDU，代表IDU的数据有效
//     output wire             o_pre_ready,   //传递给IDU，代表EXU准备好处理新数据了
//     output wire             o_post_valid,  //传递给LSU，代表此时数据包寄存器的数据有效
//     input  wire             i_post_ready,  //来自LSU，代表LSU准备好处理新数据了
//     // from IFU----------------------------
//     input  wire [31:0]      i_exu_pc,       // 来自IFU的PC值
//     // from IDU--------------------------
//     input  wire [`ALU_Bus]  i_exu_alu_type,  //ALU类型
//     input  wire [1:0]       i_exu_num_sel,   //ALU操作数选择
//     input  wire [31:0]      i_exu_imm,
//     input  wire             i_exu_is_jal,
//     input  wire             i_exu_is_jalr,
//     input  wire             i_exu_is_brch,   //分支指令
//     input  wire             i_exu_is_load,   // 是否为加载指令
//     input  wire             i_exu_is_store,  // 是否为存储指令
//     input  wire [2:0]       i_exu_func3,
//     input  wire [4:0]       i_exu_rd_id,    // 目的寄存器ID
//     input  wire             i_exu_gpr_wen,  // 通用寄存器写使能
//     input  wire [1:0]       i_exu_csr_type, // CSR操作类型
//     output wire [`CSR_Bus]  i_exu_csr_rid,  // CSR读取ID
//     output wire             i_exu_csr_ren,  // CSR读取使能
//     output wire             i_exu_is_mret,
//     output wire             i_exu_is_ecall,
//     // from Register File--------------------------
//     input  wire [31:0]      i_exu_rs1,
//     input  wire [31:0]      i_exu_rs2,
//     // from CSR Ctrl------------------------------
//     input  wire [31:0]      i_exu_csr_src,   //来自CSR控制模块的来源
//     input  wire [31:0]      i_exu_csr_npc,   //来自CSR控制模块的新PC
//     // to LSU---------------------------------------
//     output wire [31:0]      o_exu_exu_res,   //EXU结果
//     output wire             o_exu_is_load,
//     output wire             o_exu_is_store,
//     output wire [2:0]       o_exu_func3,
//     output wire [31:0]      o_exu_rs1,
//     output wire [31:0]      o_exu_rs2,
//     output wire [31:0]      o_exu_csr_npc,   //新PC
//     output wire             o_exu_is_mret,
//     output wire             o_exu_is_ecall,
//     // to BRU---------------------------------------
//     output wire [31:0]      o_exu_imm,
//     output wire [31:0]      o_exu_pc,
//     output wire             o_exu_is_jal,
//     output wire             o_exu_is_jalr,
//     output wire             o_exu_brch,
//     // to WEU---------------------------------------
//     output wire [4:0]       o_exu_rd_id,     // 目的寄存器ID
//     output wire             o_exu_gpr_wen,   //GPR写入使能
//     output wire [`CSR_Bus]  o_exu_csr_wid,   //CSR写入ID
//     output wire [31:0]      o_exu_csr_rd,    //CSR读出数据
//     output wire             o_exu_csr_wen    //CSR写入使能
// );

//     import "DPI-C" function void TRAP(input int station, input byte unit);

// /*--------------------------------------------------------------------------------------------------------------*/    
//     // to LSU
//     wire [31:0]     exu_exu_res  = (i_exu_csr_ren == `Enable) ? i_exu_csr_src : exu_alu_res; // CSR读使能若开启则读取CSR的值，未开启则选择ALU结果
//     wire            exu_is_load  = i_exu_is_load;
//     wire            exu_is_store = i_exu_is_store;
//     wire [2:0]      exu_func3    = i_exu_func3;
//     wire [31:0]     exu_rs1      = i_exu_rs1;
//     wire [31:0]     exu_rs2      = i_exu_rs2;
//     wire [31:0]     exu_csr_npc  = i_exu_csr_npc; 
//     wire            exu_is_mret  = i_exu_is_mret;
//     wire            exu_is_ecall = i_exu_is_ecall;
//     // to BRU
//     wire [31:0]     exu_imm      = i_exu_imm;
//     wire [31:0]     exu_pc       = i_exu_pc;
//     wire            exu_is_jal   = i_exu_is_jal;
//     wire            exu_is_jalr  = i_exu_is_jalr;
//     wire            exu_brch     = i_exu_is_brch & exu_alu_res[0];  //当前指令是否为分支指令 & 检查该指令是否会执行分支操作
//     // to WEU
//     wire [4:0]      exu_rd_id    = i_exu_rd_id;
//     wire            exu_gpr_wen  = i_exu_gpr_wen;
//     wire [`CSR_Bus] exu_csr_wid   = i_exu_csr_rid;// 读和写同一个id
//     wire [31:0]     exu_csr_rd;
//     wire            exu_csr_wen  = i_exu_csr_ren; // 读和写同一个id
// /*--------------------------------------------------------------------------------------------------------------*/

//     // 选择ALU操作数
//     ysyx_23060219_MuxKey #(4, 2, `CPU_Width) mux1(num1, i_exu_num_sel, {  //ALU操作数选择num1
//         `RS1_RS2, i_exu_rs1,
//         `RS1_IMM, i_exu_rs1,
//         `PC_IMM,  i_exu_pc,
//         `PC_4,    i_exu_pc}       
//     );

//     ysyx_23060219_MuxKey #(4, 2, `CPU_Width) mux2(num2, i_exu_num_sel, {  //ALU操作数选择num2
//         `RS1_RS2, i_exu_rs2,
//         `RS1_IMM, i_exu_imm,
//         `PC_IMM,  i_exu_imm,
//         `PC_4,    `CPU_Width'd4}       
//     );

//     ysyx_23060219_MuxKey #(4, 2, `CPU_Width) mux3(exu_csr_rd, i_exu_csr_type, {
//         `CSR_Nop, `CPU_Width'd0,
//         `CSR_RW,  i_exu_rs1,                    // 把rs1的值写入CSR
//         `CSR_RS,  i_exu_rs1 | i_exu_csr_src,    // 把rs1或上csr_src的值写入CSR
//         `CSR_RC,  i_exu_rs1 & ~i_exu_csr_src}   // 把rs1与~csr_src的值写入CSR   ### 待修改有~？
//     );

// /*--------------------------------------------------------------------------------------------------------------*/
//     // 选择ALU操作方式
//     reg  [31:0] exu_alu_res;
//     wire [31:0] num1, num2;
//     wire [31:0] num2_cplm = ~num2 + `CPU_Width'h1;   // num2的补码
//     always @(*) begin
//         exu_alu_res = `CPU_Width'd0;
//         case (i_exu_alu_type)   //根据ALU类型进行ALU运算
//             `ALU_ADD:   exu_alu_res = num1 + num2;
//             `ALU_SUB:   exu_alu_res = num1 + num2_cplm;
//             `ALU_SLL:   exu_alu_res = num1 << num2[4:0];
//             `ALU_XOR:   exu_alu_res = num1 ^ num2;
//             `ALU_SRL:   exu_alu_res = num1 >> num2[4:0];
//             `ALU_SRA:   exu_alu_res = ($signed(num1)) >>> num2[4:0];    //num1算术右移num2[4:0]位 同时保留符号位
//             `ALU_OR:    exu_alu_res = num1 | num2;
//             `ALU_AND:   exu_alu_res = num1 & num2;
//             `ALU_EQ:    exu_alu_res = {{(`CPU_Width - 1){1'b0}}, (num1 == num2)};
//             `ALU_NE:    exu_alu_res = {{(`CPU_Width - 1){1'b0}}, (num1 != num2)};
//             `ALU_LT:    exu_alu_res = {{(`CPU_Width - 1){1'b0}}, (($signed(num1)) <  ($signed(num2)))};
//             `ALU_GE:    exu_alu_res = {{(`CPU_Width - 1){1'b0}}, (($signed(num1)) >= ($signed(num2)))};
//             `ALU_LTU:   exu_alu_res = {{(`CPU_Width - 1){1'b0}}, (num1 <  num2)};
//             `ALU_GEU:   exu_alu_res = {{(`CPU_Width - 1){1'b0}}, (num1 >= num2)};
//             default:    TRAP(`ABORT, `Unit_EXU1); 
//         endcase
//     end

// /*--------------------------------------------------------------------------------------------------------------*/

//     // data package 数据包寄存器---用于存储EXU中的计算结果和相关信号
//     wire exu_reg_wen  = i_pre_valid & o_pre_ready;   //数据包寄存器的写使能
//     reg  [`EXU_PKG_WDITH-1 : 0] exu_valid_data_reg;  

//     always @(posedge clk) begin     //每个时钟上升沿,更新数据包
//         if(rst == 1'b1) 
//             exu_valid_data_reg <= 0;
//         else if(exu_reg_wen == 1'b1)    // 写使能有效时
//             exu_valid_data_reg <= { exu_exu_res, exu_is_load, exu_is_store, exu_func3,
//                                     exu_rs1, exu_rs2, exu_csr_npc, exu_is_mret, exu_is_ecall, 
//                                     exu_imm, exu_pc, exu_is_jal, exu_is_jalr, exu_brch, exu_rd_id, 
//                                     exu_gpr_wen, exu_csr_wid, exu_csr_rd, exu_csr_wen };
//     end
//     //实现数据的传输和控制信号的传递
//     assign{ o_exu_exu_res, o_exu_is_load, o_exu_is_store, o_exu_func3,
//             o_exu_rs1, o_exu_rs2, o_exu_csr_npc, o_exu_is_mret, o_exu_is_ecall, 
//             o_exu_imm, o_exu_pc, o_exu_is_jal, o_exu_is_jalr, o_exu_brch, o_exu_rd_id, 
//             o_exu_gpr_wen, o_exu_csr_wid, o_exu_csr_rd, o_exu_csr_wen } = exu_valid_data_reg;



//     //o_post_valid 表示EXU的数据包已经准备好传输，而 o_pre_ready 则表示EXU准备好接收新数据

//     // 握手信号 shake hands
//     reg post_valid_reg;
//     always @(posedge clk) begin
//         if(rst == 1'b1) 
//             post_valid_reg <= 1'h0;
//         else
//             post_valid_reg <= i_pre_valid;
//     end
//     assign o_post_valid = post_valid_reg;
//     assign o_pre_ready  = ~o_post_valid;   //EXU前后不同时

// endmodule
