`include "/home/zhong/ysyx-workbench/npc/vsrc/defines.v"

module ysyx_23060219_mem(
    input  wire           clk,
    input  wire           mem_wen,
    input  wire [7:0]     wmask, //写内存掩码
    input  wire [`RegBus] waddr, //写入数据存储器的地址
    input  wire [`RegBus] wdata, //写入数据存储器的数据
    input  wire           mem_ren, //数据存储器使能信号
    input  wire [2:0]     rmask, //读内存掩码
    input  wire [`RegBus] raddr,
    input  wire [`RegBus] inst_addr,
    output reg  [`RegBus] rdata, //读到的数据
    // output reg  [`RegBus] inst_data
    output wire  [`RegBus] inst_data //读到的指令
);
    
    import "DPI-C" function int  pmem_read(input int raddr, input int num); //用于利用从软件读取指令、数据
    import "DPI-C" function void pmem_write(input int waddr, input int wdata, input byte wmask); //用于将数据写入软件
    import "DPI-C" function void ebreak(input int station, input int inst, input byte unit); //指令终止

    reg  [`RegBus] rdata_temp; //32，暂存读到的数据


    assign inst_data = pmem_read(inst_addr, 32'hdead000c); //读指令

    always @(*) begin
        if(mem_wen) begin // 有写请求时
            pmem_write(waddr, wdata, wmask);
        end
    end


    always @(*) begin
        if(mem_ren) begin // 有读数据请求时
            rdata_temp = pmem_read(raddr, 32'hdead000d); //读数据
        end else begin
            rdata_temp = 32'heae; //随便传入的值，确保在任何情况下，rdata_temp都有一个定义的值
        end
    end


    // rdata_temp -> rdata
    always @(*) begin
        case (rmask)
            `LoadBU:  rdata = {24'd0, rdata_temp[7:0]}; //仅读取低一个字节的数据
            `LoadHU:  rdata = {16'd0, rdata_temp[15:0]}; //仅读取低两个字节的数据
            `LoadB:   rdata = {{24{rdata_temp[7]}}, rdata_temp[7:0]};
            `LoadH:   rdata = {{16{rdata_temp[15]}}, rdata_temp[15:0]}; //读低两个字节的数据，高两个字节填充
            `LoadW:   rdata = rdata_temp; //四个字节都读
            default:  begin
                        rdata = 32'hdead0005;
                        ebreak(`ABORT, 32'hdead0006, `Unit_MEM);
                      end
        endcase
    end

endmodule
