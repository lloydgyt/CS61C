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
	//
		// (not helpful)
		// if v == 0, then flip x then set bit to 1 and then flip back
		// if v == 1, simply set bit to 1
		// the key is how to directly use v
		// and not using v as a condition!
	//
	v = v << n;
	unsigned mask_left = ~(-1 << n);
	unsigned x_left = *x & mask_left;

	unsigned mask_right = -1 << (n + 1);
	unsigned x_right = *x & mask_right;
	v = v | x_left;
	v = v | x_right;
	*x = v;
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

