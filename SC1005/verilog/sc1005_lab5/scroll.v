module (input clk, rst, output [15:0] display);

reg [3:0] count;

always@(posedge clk)
begin
    if(rst) begin
        count <= 16'b0;
    end else begin
        count <= count + 1'b1;
    end
end

endmodule
