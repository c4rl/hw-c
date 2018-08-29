#include <stdio.h>

#define MAX_LINE_LENGTH 1000

int gettheline(char line[], int max);
void copy(char to[], char from[]);

int main() {
  int current_length;
  int maximum_length;
  char current_line[MAX_LINE_LENGTH];
  char longest_line[MAX_LINE_LENGTH];

  maximum_length = 0;
  while ((current_length = gettheline(current_line, MAX_LINE_LENGTH)) > 0) {
    if (current_length > maximum_length) {
      copy(longest_line, current_line);
      maximum_length = current_length;
    }
  }

  // Display the longest line.
  if (maximum_length > 0) {
    printf("Longest line was \"%s\"\n", longest_line);
  }

  return 0;
}

/**
 * Gets the input line, saves to `line` if shorter length than max.
 *
 * @return int
 *   Length of line.
 */
int gettheline(char line[], int max) {
  int i, c, length;

  length = 0;
  for (i = 0; i < max; i++) {
    c = getchar();
    // Do not count newlines.
    if (c == EOF || c == '\n') {
      break;
    }
    else {
      line[i] = c;
      length++;
    }
  }

  line[i] = '\0';

  return length;
}


/**
 * Copies characters from the `from` to the `to`.
 */
void copy(char to[], char from[]) {
  int i;

  i = 0;
  while((to[i] = from[i]) != '\0') {
    i++;
  }

}
