#include <stdio.h>

#define MAX_LENGTH 15

int main() {
  int c, i, j, current_word_length;
  // Assume words may be up to 20 characters in length.
  int lengths[MAX_LENGTH + 1];

  // Some values for the vertical histogram.
  int vh_index, vh_max;

  // Initialize values.
  current_word_length = 0;
  for (i = 0; i < MAX_LENGTH + 1; i++) {
    lengths[i] = 0;
  }

  while ((c = getchar()) != EOF) {
    // Check if character is whitespace, which denotes a
    // new word.
    if (c == ' ' || c == '\t' || c == '\n') {
      // If we are in-bounds for the length, increment
      // the lengths array value.
      if (current_word_length <= MAX_LENGTH) {
        lengths[current_word_length]++;
      }
      current_word_length = 0;
    }
    else {
      // Increment the length of the current word.
      current_word_length++;
    }
  }

  // Print out the results, first as JSON.
  printf("## AS JSON ##\n");
  printf("{");
  for (i = 1; i < MAX_LENGTH + 1; i++) {
    printf("%d: %d", i, lengths[i]);
    if (i < MAX_LENGTH) {
      printf(", ");
    }
  }
  printf("}\n");
  printf("\n");

  printf("## AS HORIZONTAL HISTOGRAM ##\n");
  // Ok, now print as a horizontal histogram.
  for (i = 1; i < MAX_LENGTH + 1; i++) {
    printf("%d: ", i);
    for (j = 0; j < lengths[i]; j++) {
      printf("#");
    }
    printf("\n");
  }
  printf("\n");

  // Next, we want to make a vertical histogram. This is going to be more challenging.
  printf("## AS VERTICAL HISTOGRAM ##\n");
  // The width of the histogram is the MAX_LENGTH.
  // The height of the histogram is the maximum count.
  vh_max = 0;
  for (i = 1; i < MAX_LENGTH + 1; i++) {
    if (lengths[i] > vh_max) {
      vh_max = lengths[i];
    }
  }

  for (j = 0; j < vh_max; j++) {
    for (i = 1; i < MAX_LENGTH + 1; i++) {
      // As items are printed, a mark should only be printed if it in fact reaches the
      // pertinent line, which will exist in descending order.
      // These will be 3 characters wide.
      if ((vh_max - j) <= lengths[i]) {
        printf("  #");
      }
      else {
        printf("   ");
      }
    }
    printf("\n");
  }
  // Print a divider
  for (i = 1; i < MAX_LENGTH + 1; i++) {
    printf(" --");
  }
  printf("\n");
  // Finally, print labels below.
  for (i = 1; i < MAX_LENGTH + 1; i++) {
    printf("% 3d", i);
  }
  printf("\n");
}
