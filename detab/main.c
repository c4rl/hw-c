#include <stdio.h>

#define MAX_LINE_LENGTH 1024

#define CHAR_TO_REPLACE   '\t'
#define REPLACE_WITH_CHAR '*'
#define REPLACE_WIDTH     8 

int main() {

  int c, i, j;
  int remain;
  char line[MAX_LINE_LENGTH];
  char newline[MAX_LINE_LENGTH];

  i = 0;
  while ((c = getchar()) != EOF) {
    if (c != '\n') {
      line[i++] = c;
    }
  }
  line[i] = '\0';

  i = 0;
  j = 0;
  while ((c = line[i++]) != '\0') {
    if (c == CHAR_TO_REPLACE) {
      remain = REPLACE_WIDTH - (j % REPLACE_WIDTH);
      while (remain-- > 0) {
        newline[j++] = REPLACE_WITH_CHAR;
      }
    }
    else {
      newline[j++] = c;
    }
  }
  newline[j] = '\0';

  printf("%s\n", newline);

  return 0;
}
