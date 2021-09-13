module pattern_generator (
	input logic clk,
	output logic out
);
	initial out = 0;

	always_ff@(posedge clk) begin
		out  <= !out;
	end


endmodule;
