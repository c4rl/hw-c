#include <stdio.h>

int main() {

  int result;
  int x;
  int p;
  int n;

  x = 0b01101100;
  p = 4;
  n = 3;

  result = (x >> (p+1-n)) & ~(~0 << n);

  printf("%d\n", result);

  return 0;
}
