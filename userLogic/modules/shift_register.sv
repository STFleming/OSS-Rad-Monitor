module shift_register(
	input logic d,
	output logic q,
	input logic clk
);
	parameter shift_length = 16;
	wire wires[shift_length:0];

	generate
		genvar i;
		for (i = 0; i <= shift_length; i++) begin
			if (i == 0) begin 
				D_type_flip_flop s(.d(d), .q(wires[i]), .clk(clk));
			end
			else if (i < shift_length) begin
				D_type_flip_flop s(.d(wires[i-1]), .q(wires[i]), .clk(clk));
			end
			else begin
				D_type_flip_flop s(.d(wires[i-1]), .q(q), .clk(clk));
			end
		end
	endgenerate


endmodule

