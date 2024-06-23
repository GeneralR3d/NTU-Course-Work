`timescale 1ns / 1ps

module vsevenseg(input [3:0]x,output [6:0] seg_L);

reg [6:0] seg_H;//internal
assign seg_L= ~seg_H;//flip it


always @*
begin
    case(x)
    4'd0: seg_H=7'b011_1111;
    4'd1: seg_H=7'b000_0110;
    4'd2: seg_H=7'b101_1011;
    4'd3: seg_H=7'b100_1111;
    4'd4: seg_H=7'b110_0110;
    4'd5: seg_H=7'b110_1101;
    4'd6: seg_H=7'b111_1101;
    4'd7: seg_H=7'b000_0111;
    4'd8: seg_H=7'b111_1111;
    4'd9: seg_H=7'b110_1111;
    4'd10: seg_H=7'b111_0111;
    4'd11: seg_H=7'b111_1100;
    4'd12: seg_H=7'b011_1001;
    4'd13: seg_H=7'b101_1110;
    4'd14: seg_H=7'b111_1001;
    4'd15: seg_H=7'b111_0001;
    default: seg_H=7'b000_0000;
    endcase



end

endmodule