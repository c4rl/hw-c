#include <stdio.h>

unsigned getbits(unsigned x, int p, int n);

unsigned setbits(unsigned x, int p, int n, unsigned y);

int main() {

  int z;

  z = getbits(0b01101100, 4, 3);
  printf("Should be 3 (0b011): %d\n", z);

  z = setbits(0b01101100, 4, 3, 0b10111);
  printf("Should be 124 (0b01111100): %d\n", z);
  z = setbits(0b01101100, 7, 5, 0b10111);
  printf("Should be 188 (0b10111100): %d\n", z);

  return 0;
}

unsigned getbits(unsigned x, int p, int n) {
  return (x >> (p+1-n)) & ~(~0 << n);
}

unsigned setbits(unsigned x, int p, int n, unsigned y) {
  // returns x with the n bits that begin at position p (from right) set to the rightmost n bits of y, leaving the other bits unchanged.
  unsigned rightmost_y, subset_y, leftover_x;
  
  // First, get rightmost n bits of y.
  rightmost_y = getbits(y, n - 1, n);

  // Shift these by (p + 1 - n)
  subset_y = rightmost_y << (p + 1 - n);

  // Take x with all bits starting at p to be 0.
  right_zeroed_x = (x & (~0 << p));

  // Take the leftovers from x
  leftover_x = getbits(x, (p + 1 - n) - 1, (p + 1 - n));

  return right_zeroed_x | subset_y | leftover_x;
}
