#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "lfsr.h"
#include "bit_ops.h"

#define MSB 15
void lfsr_calculate(uint16_t *reg) {
	unsigned taps[4];
	// use current 0, 2, 3 and 5th bit to generate new bit
	taps[0] = get_bit(*reg, 0);
	taps[1] = get_bit(*reg, 2);
	taps[2] = get_bit(*reg, 3);
	taps[3] = get_bit(*reg, 5);

	/*why use 16bit? will there be a problem converting 
	 * 16bit to 32bit unsigned?*/
	unsigned new_bit = taps[0];
	for (int i = 1; i < sizeof(taps) / sizeof(taps[0]); i++) {	
		new_bit = new_bit ^ taps[i];
	}
	// shift the register 1 bit to the right
	*reg = (*reg) >> 1;
	// put the new bit to the MSB
	set_bit(reg, MSB, new_bit);
}
