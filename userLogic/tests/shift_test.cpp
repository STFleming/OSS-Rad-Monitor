#include "verilated.h"
#include "Vshift.h"
#include <iostream>

Vshift *dut;

vluint64_t main_time = 0;
int main(int argc, char** argv) {
//	VerilatedContext* contextp = new VerilatedContext;
////	contextp->commandArgs(argc, argv);

	dut = new Vshift;//{contextp};
	dut-> d = 0;
	dut->clk = 0;
	dut->clk = 1;
	assert(dut->q == 0);
	int prev_q = 0;
	for (int i=0; i < 100; i++) {
		bool r = (rand() % 2) == 0;
		dut->d = r;
		if (i % 2 == 0) {
			// On Clk fall
			dut -> clk = 0;
			assert(dut->q == prev_q);
			dut->eval();
		} else {
			// On clk rise
			dut->clk = 1;
			dut->eval();
			assert(dut->q == dut->d) ;
			prev_q = dut->q;
		}
	}
	return 0;
}
