// module mux3 #(parameter WITHD = 8)(
//     input       [WITHD-1:0]     d0,
//     input       [WITHD-1:0]     d1, 
//     input       [WITHD-1:0]     d2,
//     input       [WITHD-1:0]     d3,
//     input       [1:0]           s,
//     output      [WITHD-1:0]     y   
//     );
//     assign y =  (s==2'b00)? d0:
//                 (s==2'b01)? d1:
//                 (s==2'b10)? d2:
//                             d3;
//     //assign y = s[1]?d2:(s[0]?d1:d0);
// endmodule
