// An example main file to interact with the hardware
//
// author: stf

#include "regItf.hpp" // the interface to the registers 
#include <stdio.h>

int main() {
	RegItf regs;

	fprintf(stderr, "A simple adder hardware check\n");
	regs.write(1, 8); // write this into register a
	regs.write(2, 2); // write this into register b

	fprintf(stderr, "%u + %u = %u\n", regs.read(1), regs.read(2), regs.read(3));

	if(regs.read(3) == 10) {
		fprintf(stderr, "PASSED\n");
	} else {
		fprintf(stderr, "FAILED (Expected 10)\n");
		
		regs.dump(4);
	}

	fprintf(stderr, "Value at the base %u\n", regs.read(0));

	return 0;
}
