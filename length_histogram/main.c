#include <stdio.h>

#define MAX_LENGTH 20

int main() {
  int c, i, j, current_word_length;
  // Assume words may be up to 20 characters in length.
  int lengths[MAX_LENGTH + 1];

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
  printf("{");
  for (i = 1; i < MAX_LENGTH + 1; i++) {
    printf("%d: %d", i, lengths[i]);
    if (i < MAX_LENGTH) {
      printf(", ");
    }
  }
  printf("}\n");

  // Ok, now print as a histogram.
  for (i = 1; i < MAX_LENGTH + 1; i++) {
    printf("%d: ", i);
    for (j = 0; j < lengths[i]; j++) {
      printf("#");
    }
    printf("\n");
  }

}
