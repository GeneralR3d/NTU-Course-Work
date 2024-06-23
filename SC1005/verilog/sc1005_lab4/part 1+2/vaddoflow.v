module(input [3:0]a,b,
        output [6:0] seg_L,
        output oflow
);

wire[4:0]x;
assign x=a+b;
vsevenseg hi(.x(x[3:0]),.seg_L(seg_L));
assign oflow=x[4];

endmodule