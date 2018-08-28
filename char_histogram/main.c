#include <stdio.h>

#define START_CHAR 'a'

#define END_CHAR 'z'

int main() {
  int i, j, c, char_index, max_char_index;

  max_char_index = END_CHAR - START_CHAR + 1;
  // The counts we care about will be for all indexes.
  int char_counts[max_char_index];

  // Initialize values.
  for (i = 0; i < max_char_index; i++) {
    char_counts[i] = 0;
  }

  while ((c = getchar()) != EOF) {
    if (c >= START_CHAR && c <= END_CHAR) {
      char_index = c - START_CHAR;
      char_counts[char_index]++;
    }
  }

  // Display count histogram (horizontal is fine, eh?)
  for (i = 0; i < max_char_index; i++) {
    putchar(START_CHAR + i);
    printf(": ");
    for (j = 0; j < char_counts[i]; j++) {
      printf("#");
    }
    printf("\n");
  }
  printf("\n");

}
