#include <stdio.h>

/**
 * Converts F to C.
 * 
 * @param float f
 *   Temp in F.
 *
 * @return float
 *   Temp in C.
 */
float convert_f_to_c(float f) {
  return 5.0 * (f - 32.0) / 9.0;
}

/**
 * This prints out a temperature table, yo.
 */
int main()
{
  float index_f, c;
  int lower_f, upper_f, step_f;

  lower_f = 0;
  upper_f = 300;
  step_f = 20;

  for (index_f = lower_f; index_f < upper_f; index_f += step_f) {
    printf("%3.0f\t%6.1f\n", index_f, convert_f_to_c(index_f));
  }

}

