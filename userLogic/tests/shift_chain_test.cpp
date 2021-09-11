#include <verilated.h>
#include "Vshift_chain.h"
#include <iostream>

Vshift_chain *chain;
double sc_time_stamp() { return 0; }

vluint64_t main_time = 0;
int main(int argc, char** argv) {
	Verilated::traceEverOn(true);
	Verilated::commandArgs(argc, argv);
	chain = new Vshift_chain;//{contextp};
	const int chain_length = 16;
	chain-> d = 0;
	chain->clk = 0;
	assert(chain->q == 0);
	int data = 0;
	for (int i=0; i < 100; i++) {
		// Generate a random bit;
		int r = (rand() % 2);
		// put random bit on D
		chain->d = r;
		// Put r on the end of data
		r = r << chain_length;
		// shift data
		data = data >> 1;
		data = data | r;

		// pluse clock 
		//TODO Ask if there is a better way of doing this?
		chain->clk = 0;
		chain->eval();
		chain->clk = 1;
		chain->eval();

		// Check first bit is correct
		if (data & 1) {
			 assert(chain->q == 1);
		 } else {
			 assert(chain->q == 0);
		 }
	}
	return 0;
}
