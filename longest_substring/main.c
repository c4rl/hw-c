#include <stdio.h>

#define MAX_LINE_LENGTH 1000

int gettheline(char line[]);

int main() {

  int c, i;
  char line[MAX_LINE_LENGTH];

  // Passed by reference.
  gettheline(line);



  int best, pos;
  best = 1;
  pos = 0;

  int start, end;

  char ch1, ch2;
  ch1 = line[0];
  ch2 = line[0];

  // Start with the first two characters, continue until
  // the line ends.
  for (start = 0, end = 1; line[end] != '\0'; ++end) {
    // If the end index does not match either of the
    // saved characters.

    printf("-----\n");
    printf("placeholder 1 is %c\n", ch1);
    printf("placeholder 2 is %c\n", ch2);
    printf("end index is %d\n", end);
    if (line[end] != ch1 && line[end] != ch2) {
      // Rewind the start index until the characters
      // differ.
      printf("non-matching end char is %c\n", line[end]);
      for (start = end - 1; start > 0; start--) {
        printf("start index is %d\n", start);
        if (line[start - 1] != line[end - 1]) {
          break;
        }
      }
      printf("saving placeholder 1 as %c\n", line[start]);
      printf("saving placeholder 2 as %c\n", line[end]);
      // Re-save the characters.
      ch1 = line[start];
      ch2 = line[end];
    }
    else {
      printf("the end index matches either of the placeholders, so we continue\n");
    }

    // Save the index difference.
    if (best < end - start + 1) {
      best = end - start + 1;
      printf("best is now %d\n", best);
      pos = start;
    }
  }

  printf("Best: %.*s\n", best, line + pos);

  return 0;
}

int gettheline(char line[]) {
  int c, i, length;
  length = 0;

  for (i = 0; i < MAX_LINE_LENGTH; i++) {
    c = getchar();
    if (c == '\n' || c == EOF) {
      break;
    }
    line[i] = c;
    length++;
  }

  line[i] = '\0';

  return length;
}


