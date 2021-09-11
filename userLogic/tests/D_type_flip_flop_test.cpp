#include "verilated.h"
#include "VD_type_flip_flop.h"
#include <iostream>

VD_type_flip_flop *dut;

vluint64_t main_time = 0;
int main(int argc, char** argv) {
//	VerilatedContext* contextp = new VerilatedContext;
////	contextp->commandArgs(argc, argv);

	dut = new VD_type_flip_flop;//{contextp};
	dut-> d = 0;
	dut->clk = 0;
	dut->clk = 1;
	assert(dut->q == 0);
	int prev_q = 0;
	for (int i=0; i < 100; i++) {
		bool r = (rand() % 2) == 0;
		// Set random bit to D
		dut->d = r;

		// Lower the clock
		dut -> clk = 0;
		// Check that Q doesn't change
		assert(dut->q == prev_q);
		dut->eval();

		// Raise the clock
		dut->clk = 1;
		dut->eval();
		// Check that D updates
		assert(dut->q == dut->d) ;
		prev_q = dut->q;

		// Lower clock with rst high
		dut->clk = 0;
		dut->rst = 1;
		dut->eval();

		// Check that nothing has changed
		assert(dut->q == prev_q);

		// Raise the clock
		dut->clk = 1;
		dut->eval();

		// Check that D is low
		assert(dut->d == 0);
		prev_q = 0;
	}
}
return 0;
}
