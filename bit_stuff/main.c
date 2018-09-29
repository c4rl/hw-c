#include <stdio.h>

unsigned getbits(unsigned x, int p, int n);

unsigned setbits(unsigned x, int p, int n, unsigned y);

unsigned invert(unsigned x, int p, int n);

int main() {

  int z;

  int a;
  a = 0b11111111;
  z = a & ~077;
  printf("0b11000000 %d\n", z);

  z = getbits(0b01101100, 4, 3);
  printf("Should be 3 (0b011): %d\n", z);

  z = setbits(0b01101100, 4, 3, 0b10111);
  printf("Should be 124 (0b01111100): %d\n", z);
  z = setbits(0b01101100, 7, 5, 0b10111);
  printf("Should be 188 (0b10111100): %d\n", z);

  // orig 819
  z = invert(0b1100110011, 6, 4);
  printf("Should be 843 (0b1101001011): %d\n", z);
  z = invert(0b1100110011, 7, 2);
  printf("Should be 1011 (0b1111110011): %d\n", z);

  return 0;
}

unsigned getbits(unsigned x, int p, int n) {
  return (x >> (p+1-n)) & ~(~0 << n);
}

unsigned setbits(unsigned x, int p, int n, unsigned y) {
  // returns x with the n bits that begin at position p (from right) set to the rightmost n bits of y, leaving the other bits unchanged.
  unsigned rightmost_y, subset_y, leftover_x, right_zeroed_x;
  
  // First, get rightmost n bits of y.
  rightmost_y = getbits(y, n - 1, n);

  // Shift these by (p + 1 - n)
  subset_y = rightmost_y << (p + 1 - n);

  // Take x with all bits starting at p to be 0.
  right_zeroed_x = (x & (~0 << p));

  // Take the leftovers from x
  leftover_x = getbits(x, (p + 1 - n) - 1, (p + 1 - n));

  // Combine all.
  return right_zeroed_x | subset_y | leftover_x;
}

unsigned invert(unsigned x, int p, int n) {
  // returns x with the n bits that begin at position p inverted (i.e., 1
  // changed into 0 and vice versa), leaving the others unchanged.
  unsigned rightmost_x, subset, inverted_subset, inverted_subset_with_space, zeroed_x, leftover_x;

  // get the rightmost p + 1 bits.
  rightmost_x = getbits(x, p, p + 1);
  leftover_x = getbits(x, (p - n), (p - n) + 1);

  // shift these right by (p + 1 - n), results with the meaningful subset
  subset = rightmost_x >> (p + 1 - n);

  // invert the subset
  inverted_subset = getbits(~subset, n - 1, n);

  // shift the subset left by (p + 1 - n)
  inverted_subset_with_space = inverted_subset << (p + 1 - n);

  // re-zero out the rightmost p of x
  zeroed_x = (x >> p) << p;

  // combine
  return zeroed_x | inverted_subset_with_space | leftover_x;
}

