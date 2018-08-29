#include <stdio.h>

/**
 * Prototype for power.
 */
int power(int, int);

/**
 * Main.
 */
int main() {
  printf("%d\n", power(2, 3));
  printf("%d\n", power(3, 3));

  return 0;
}

/**
 * Raises x^y
 *
 * @param int x
 *   Base.
 * @param int x
 *   Exponent.
 *
 * @return int
 *   Result.
 */
int power(int x, int y) {
  int i, result;

  result = 1;
  for (i = 0; i < y; i++) {
    result = x * result;
  }

  return result;
}
