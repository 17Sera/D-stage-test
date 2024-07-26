module riscv_top(
    input               clk,
    input               reset,
    output              MemWrite,
    output      [31:0]  DataAdr,    //alu_u的ALUResult
    output      [31:0]  WriteData
               
    );
    wire  [31:0] PC, Instr, ReadData;

    riscv_single riscv_single_u(
     .clk                   (clk)       , 
     .reset                 (reset)     , 
     .PC                    (PC)        , 
     .Instr                 (Instr)     , 
     .MemWrite              (MemWrite)  ,
     .ALUResult             (DataAdr) ,  
     .WriteData             (WriteData) , 
     .ReadData              (ReadData)
    );

    imem inst_mem(
     .A                     (PC)        , 
     .RD                    (Instr)
    );
    
    dmem data_mem(
    . clk                   (clk)       , 
    . rst_n                 (reset)     ,
    . we                    (MemWrite)  , 
    . a                     (DataAdr)   , 
    . wd                    (WriteData) , 
    . rd                    (ReadData)
    );
    
    
endmodule
