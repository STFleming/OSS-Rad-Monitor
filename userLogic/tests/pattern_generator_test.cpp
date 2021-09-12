#include <verilated.h>
#include "Vpattern_generator.h"
#include <iostream>

// Should output a stream of alternating '0' and '1'
Vpattern_generator *dut;
// Here for legacy reasons \_,0,_/
double sc_time_stamp() { return 0; }

enum State {
	Starting, // Dont care what comes next
	One,      // Expecting a '1' next
	Zero,     // Expecting a '0' next
	Error     // Error state
}

vluint64_t main_time = 0;
int main(int argc, char** argv) {
	// Also needed for some methods to function
	Verilated::commandArgs(argc, argv);
	
	State state;
	for (int i = 0; i < 10; i++) {
		state = State::starting;
		dut = new Vpattern_generator;
		for (int j = 0; j <10; j++) {
			dut->clk = 0;

	// Set pins
	
	// Run module
	dut->eval();

	// Check state
	assert(dut->q = 0)
	return 0;
}


