module dmem(
    input                   clk , 
    input                   rst_n,
    input                   we  ,
    input       [31:0]      a   , 
    input       [31:0]      wd  ,
    output      [31:0]      rd
    );

    reg [31:0] RAM [0:63];

    //assign rd = RAM [a[31:2]];   //指定内存地址的高30位, 低两位通常用于字节对齐
    assign rd = RAM [a[31:0]];

//Reg #( 传输数据的位宽，复位值 ) 例化名称 （ 时钟，复位，写入信号(输入)，被写入信号(输出)，写使能 ）;
   // Reg #( 32, 32'b0 ) datamem_reg ( clk, rst_n, wd, RAM[a[31:2]], we );
    Reg #( 32, 32'b0 ) datamem_reg ( clk, rst_n, wd, RAM[a[31:0]], we );

    // always @(posedge clk)
    //     if (we) RAM[a[31:2]] <= wd;

 endmodule












// module ysyx_23060219_instr_mem(
//     input clk,
//     input rst_n,
    
//     //控制器送来的信号
//     input write_en,     //写使能  store指令 从instr_mem写入到data_mem
//     input read_en,      //读使能  load指令  从data_mem写入到instr_mem
    
//     input [31:0] addr,
//     input [2:0] RW_type;  //根据func3区分  //读写类型 字节、字、半字、有符号、无符号(U)

//     input [31:0] din,   //写进去的数据
//     output [31:0] dout  //读出来的数据
// );

//     wire [31:0] ram[0:255];

//     wire [31:0] data;  //Rd_data 读入的待din替换的暂存量

//     //中间信号
//     wire [31:0] wri_data_B;  //Wr_data_B 字节拼接   按字节操作
//     wire [31:0] wri_data_H;  //Wr_data_H 半字拼接

//     wire [31:0] wri_data;   //最终写入mem的数

//     assign data = ram[addr[31:2]];     //数据对齐


//     MuxKey #( 4, 2, 32 ) data_mem_wirte ( wri_data_B, addr[1:0], {
//         2'b00 , { data[31:8],  din[7:0] } , 
//         2'b01 , { data[31:16], din[7:0], data[7:0] } ,
//         2'b10 , { data[31:24], din[7:0], data[15:0]} ,
//         2'b11 , { din[7:0], data[23:0] }
//     } );

// //addr[1]=0时对应低两个字节，addr[1]=1时对应高两个字节
//     assign wri_data_H = (addr[1]) ? {din[15:0], data[15:0]} : {data[31:16], din[15:0]} ;

// //最终写入的数据
//     assign wri_data = (RW_type[1:0]==2'b00) ? wri_data_B :( (RW_type[1:0]==2'b01) ? wri_data_H : din );

// //Reg #( 传输数据的位宽，复位值 ) 例化名称 （ 时钟，复位，写入信号(输入)，被写入信号(输出)，写使能 ）;
//     Reg #( 1, 1'b0 ) data_mem_reg ( clk, rst_n, wri_data, ram[addr[9:2]], 1'b1 );

//     wire [7:0] read_data_B;
//     wire [7:0] read_data_H;

//     wire [31:0] read_data_B_ext;
//     wire [31:0] read_data_H_ext;

//     MuxKey #( 4, 2, 8 ) data_mem_read ( read_data_B, addr[1:0], {
//         2'b00 , data[7:0] ,
//         2'b01 , data[15:8] ,
//         2'b10 , data[23:16] ,
//         2'b11 , data[31:24] 
//     } );

// //addr[1]=0时对应低两个字节，addr[1]=1时对应高两个字节
// assign read_data_H =(addr[1])? data[31:16]:data[15:0];

// //RW_type[2] 是 1，则执行零扩展；如果 RW_type[2] 是 0，则执行符号扩展
// assign read_data_B_ext =(RW_type[2]) ? {24'd0,read_data_B} : {{24{read_data_B[7]}},read_data_B};

// assign read_data_H_ext =(RW_type[2]) ? {16'd0,read_data_H} : {{16{read_data_H[15]}},read_data_H};

// assign dout = (RW_type[1:0]==2'b00) ? read_data_B_ext : ((RW_type[1:0]==2'b01) ? read_data_H_ext : data );


// endmodule


//---------------------------------------------------------------------------------------------------
