#include <stdio.h>

/**
 * Converts F to C.
 * 
 * @param int f
 *   Temp in F.
 *
 * @return int
 *   Temp in C.
 */
int convert_f_to_c(int f) {
  // Integer division truncates, yo.
  return 5 * (f - 32) / 9;
}

/**
 * This prints out a temperature table, yo.
 */
int main()
{
  int index_f, c;
  int lower_f, upper_f, step_f;

  lower_f = 0;
  upper_f = 300;
  step_f = 20;

  index_f = lower_f;
  while (index_f <= upper_f) {
    c = convert_f_to_c(index_f);
    printf("%d\t%d\n", index_f, c);
    index_f += step_f;
  }

}

