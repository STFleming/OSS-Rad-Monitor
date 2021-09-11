module D_type_flip_flop (
	input logic d,
	output logic q,
	input clk
);

always @(posedge clk) begin
	q <= d;
end


endmodule

