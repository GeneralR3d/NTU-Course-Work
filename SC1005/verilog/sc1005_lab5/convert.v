module convert (input [3:0] in, output reg [3:0] out);

always @*
begin
    case(in)
    4'd0: out = 4'hA;
    4'd1: out = 4'hA;
    4'd2: out = 4'hC;
    4'd3: out = 4'h0;
    4'd4: out = 4'hF;
    4'd5: out = 4'hF;
    4'd6: out = 4'hE;
    4'd7: out = 4'hE;
    4'd8: out = 4'hA;
    4'd9: out = 4'h1;
    4'd10: out = 4'h5;
    4'd11: out = 4'hA;
    4'd12: out = 4'h9;
    4'd13: out = 4'h0;
    4'd14: out = 4'h0;
    4'd15: out = 4'hD;
    default: out = 4'A;
end
endmodule