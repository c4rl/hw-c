#include <stdio.h>

#define LOWER_F 0

#define UPPER_F 300

#define STEP_F 20

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

  for (index_f = UPPER_F; index_f >= LOWER_F; index_f -= STEP_F) {
    printf("%3.0f\t%6.1f\n", index_f, convert_f_to_c(index_f));
  }

}

