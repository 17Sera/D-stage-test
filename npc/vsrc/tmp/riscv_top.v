// module riscv_top(
//     input               clk     ,
//     input               reset   ,
//     input       [31:0]  Instr   ,
//     output      [31:0]  PC      ,
//     output              MemWrite,
//     output      [31:0]  DataAdr ,    //alu_u的ALUResult
//     output      [31:0]  WriteData
               
//     );
//     wire  [31:0] PC_u, Instr_u, ReadData;

//     assign PC       =  PC_u;
//     assign Instr_u  =  Instr;

//     riscv_single riscv_single_u(
//      .clk                   (clk)           , 
//      .reset                 (reset)         , 
//      .PC                    (PC_u)          , 
//      .Instr                 (Instr_u)       , 
//      .MemWrite              (MemWrite)      ,
//      .ALUResult             (DataAdr)       ,  
//      .WriteData             (WriteData)     , 
//      .ReadData              (ReadData)
//     );

//     // imem inst_mem(
//     //  .A                     (PC_u)        ,    //address    PC
//     //  .RD                    (Instr_u)   
//     // );
    
//     dmem data_mem(
//     . clk                   (clk)       , 
//     . rst_n                 (reset)     ,
//     . we                    (MemWrite)  , 
//     . a                     (DataAdr)   , 
//     . wd                    (WriteData) , 
//     . rd                    (ReadData)
//     );

//     EBREAK  npc_trap    (                       //ebreak
//         .inst_i             (Instr_u)
//     );
    
// endmodule


