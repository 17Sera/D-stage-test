`include "/home/zhong/ysyx-workbench/npc/vsrc/defines.v"

module ysyx_23060219_alu(
    input  wire [`Aluc_width] aluc,
    input  wire [31:0]  num1,
    input  wire [31:0]  num2,
    output reg  [31:0]  result
);

    import "DPI-C" function void ebreak(input int station, input int inst, input byte unit);
    
    wire [31:0] temp = {{(`BitWidth - 1){1'b1}}, 1'b0};     //for example, BitWidth = 32，then temp = 0xfffffffe
    // wire [31:0] num1_cplm = ~num1 + `RegNum'h1;          // 补码
    wire [31:0] num2_cplm = ~num2 + `RegNum'h1;             // 第二个数取补码
    wire [31:0] num2_temp = (num2 & 32'h1f);                // 32'h1f只有第五位为1--->num2只保留第五位的数

    always @(*) begin       // 按aluc分类计算
        case (aluc)
            `ADD:      result = num1 + num2;
            `SUB:      result = num1 + num2_cplm;
            `SLL:      result = num1 << num2_temp;
            `SLLI:     result = num1 << num2;
            `XOR:      result = num1 ^ num2;
            `SRL:      result = num1 >> (num2 & 32'h1f);
            `SRA:      result = ($signed(num1)) >>> (num2 & 32'h1f);
            //`SLT:      result = (num1 < num2) ? 32'd1 : 32'd0;
            `OR:       result = num1 | num2;
            `AND:      result = num1 & num2;
            `EQ:       result = {{(`BitWidth - 1){1'b0}}, (num1 == num2)};
            `NE:       result = {{(`BitWidth - 1){1'b0}}, (num1 != num2)};
            `LT:       result = {{(`BitWidth - 1){1'b0}}, (($signed(num1)) <  ($signed(num2)))};
            `GE:       result = {{(`BitWidth - 1){1'b0}}, (($signed(num1)) >= ($signed(num2)))};
            `LTU:      result = {{(`BitWidth - 1){1'b0}}, (num1 <  num2)};
            `GEU:      result = {{(`BitWidth - 1){1'b0}}, (num1 >= num2)};
            `ADD_LUI:  result = num2;
            `ADD_JALR: result = (num1 + num2) & temp;
            default:   begin
                        ebreak(`ABORT, 32'hdeafbeaf, `Unit_ALU);
                        result = 0;
                       end
        endcase
    end

endmodule
