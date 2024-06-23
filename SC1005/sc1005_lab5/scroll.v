module scroll (input clk, rst, output [15:0] display);

reg [3:0] count;
wire [3:0] a,b,c,d;

always@(posedge clk)
begin
    if(rst) begin
        count <= 4'b0;
    end else begin
        count <= count + 1'b1;
    end
end

assign a = count;
assign b = count +1;
assign c = count +2;
assign d = count +3;

convert aa(.in(a), .out(display[15:12]));
convert bb(.in(b), .out(display[11:8]));
convert cc(.in(c), .out(display[7:4]));
convert dd(.in(d), .out(display[3:0]));

endmodule
