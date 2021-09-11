module shift_chain(
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
																shift s(.d(d), .q(wires[i]), .clk(clk));
												end
												else if (i < shift_length) begin
																shift s(.d(wires[i-1]), .q(wires[i]), .clk(clk));
												end
												else begin
																shift s(.d(wires[i-1]), .q(q), .clk(clk));

												end
								end
				endgenerate


endmodule

