#include <stdio.h>
#include "bit_ops.h"

// Return the nth bit of x.
// Assume 0 <= n <= 31
unsigned get_bit(unsigned x,
		unsigned n) {
	// assuming that, when n == 0, get the LSB
	// first shift x by n to the right
	x = x >> n;
	// then use 00...001 to AND x
	return x & 1;
}

// Set the nth bit of the value of x to v.
// Assume 0 <= n <= 31, and v is 0 or 1
void set_bit(unsigned * x,
		unsigned n,
		unsigned v) {
	// use OR to set bit to v
	// other bits should remain the same
	// x | 00..010..00
	unsigned mask = (1 << n);
	// set bit to 1
	*x = *x | mask;
	// AND it will 111..0..111
	*x = *x & (~(v << n));
	flip_bit(x, n);
}

// the code below effectively set nth bit to 1
void set_bit_to1(unsigned * x, unsigned n) {
	unsigned mask = 1;
	mask = mask << n;
	*x = *x | n;
}

// Flip the nth bit of the value of x.
// Assume 0 <= n <= 31
void flip_bit(unsigned * x,
		unsigned n) {
	*x = *x ^ (1 << n);
}

