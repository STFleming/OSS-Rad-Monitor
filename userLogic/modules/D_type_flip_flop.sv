module D_type_flip_flop (
	input logic d,
	output logic q,
	input clk,
	input rst
);
	initial begin
		q = 0;
	end

	always @(posedge clk) begin
		q <= d;
		if (rst == 1) q <= 0;
	end


endmodule

