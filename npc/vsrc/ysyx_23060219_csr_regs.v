`include "/home/zhong/ysyx-workbench/npc/vsrc/defines.v"

module csr_regs(
    input  wire           clk,
    input  wire           rst,
    input  wire           is_ecall,
    input  wire           csr_wen,
    input  wire [2:0]     funct3,
    input  wire [11:0]    csr,      // {funct7, rs2}    CSR的地址
    input  wire [`RegBus] src1,
    input  wire [`RegBus] pc,
    output wire [`RegBus] csr_npc,
    output reg  [`RegBus] csr_val
);

    import "DPI-C" function void ebreak(input int station, input int inst, input byte unit);

    reg [`RegBus] mstatus;
    reg [`RegBus] mtvec;
    reg [`RegBus] mepc;
    reg [`RegBus] mcause;
    wire[`RegBus] csr_wdata;


    // csr_wdata 写入csr的值
    // (funct3[1] == 1'b1) : csrrs      010              --- csr的值和rs1按位或的结果写入csr
    // (funct3[1] == 1'b0) : csrrw or ecall  001 or 000  --- rs1的值写入csr
    assign csr_wdata = (funct3[1] == 1'b0) ? src1 : (src1 | csr_val);

    // csr_npc 下一个PC
    // {csr} = {funct7, rs2}------inst[31:20]
    // inst[21] = csr[1] == 1, mret,  npc = MEPC  ---> mepc  指向发生异常的指令 / 异常发生时的PC值
    // inst[21] = csr[1] == 0, ecall, npc = MTVEC ---> mtvec 指定了异常处理程序的入口地址 / 异常时处理器需要跳转到的地址
    assign csr_npc = (csr[1] == 1'b0) ? mtvec : mepc;


    // write register
    always @(posedge clk) begin
        if(rst == `RST_VAL) begin           // 复位
                mstatus <=  32'h1800;
                mtvec   <= `RESET_VECTOR;
                mepc    <= `RESET_VECTOR;
                mcause  <=  32'hb;
                //mtvec   <= `RegRstVal;  
                //mepc    <= `RegRstVal;  
                //mcause  <= `RegRstVal;  
        end else if(is_ecall == 1'b1) begin // The inst is 'ecall', and the src1 is gpr[15] (for riscv-32e)            
            mepc   <= pc;                   // 保存引发异常的指令地址
            //mcause <= csr_wdata;          // 设置异常号
            mcause <= 32'hb;

            $display("\n----------- mepc = 0x%x , mcause = 0x%x , mtvec = 0x%x , mstatus = 0x%x ---------in ecall -------\n" , mepc, mcause, mtvec, mstatus);      // mtvec 指向的是am_asm_trap

        end else if(csr_wen == 1'b1) begin
            case (csr)
                12'h300: mstatus <= csr_wdata;
                12'h305: mtvec   <= csr_wdata;
                12'h341: mepc    <= csr_wdata;
                12'h342: mcause  <= csr_wdata;
                default: ebreak(`ABORT, 32'hdead000a, `Unit_CR);
            endcase
        end 
    end


    //read register
    always @(*) begin
        case (csr)
            12'h300: begin  csr_val = mstatus;         $display("\n--------------- csr_val = mstatus = 0x%x ------------------\n",csr_val); end
            12'h305: begin  csr_val = mtvec;           $display("\n--------------- csr_val = mtvec = 0x%x ------------------\n",csr_val);   end
            12'h341: begin  csr_val = mepc;            $display("\n--------------- csr_val = mepc = 0x%x ------------------\n",csr_val);    end
            12'h342: begin  csr_val = mcause;          $display("\n--------------- csr_val = mcause = 0x%x ------------------\n",csr_val);  end
            default: begin  csr_val = 32'hdead000b;    end //$display("\n--------------- csr_val = mstatus = dead ! ------------------\n");       end
        endcase
    end

endmodule
