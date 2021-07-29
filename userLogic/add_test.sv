// A simple adder module for testing file includes
// author: stf (shane)
//

module add_test(
	input logic [3:0] a_in,
	input logic [3:0] b_in,
	output logic [3:0] c_out
);

assign c_out = a_in + b_in;

endmodule
