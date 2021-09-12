#include <verilated.h>
#include "V<module_name>.h"
#include <iostream>

## Basic starting point to a module test.
# replace <module_name> with correct name
# and add tests.
# Optional change dut to useful name

V<module_name> *dut;
// Here for legacy reasons \_,0,_/
double sc_time_stamp() { return 0; }

vluint64_t main_time = 0;
int main(int argc, char** argv) {
	// Also needed for some methods to function
	Verilated::commandArgs(argc, argv);
	
	// Make new module
	dut = new V<module_name>;
	
	// Set pins
	dut-> d = 0;
	dut->clk = 0;
	
	// Run module
	dut->eval();

	// Check state
	assert(dut->q = 0)
	return 0;
}


