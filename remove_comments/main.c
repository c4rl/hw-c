#include <stdio.h>

// Write a program to remove all comments from a C program.
// Don’t forget to handle quoted strings and character
// constants properly. C comments do not nest.

#define MAX_LINE_LENGTH 1024
#define MAX_COLUMN 10

int get_the_line();
int line_length(char line[]);

int main() {

  int c, i;
  char line[MAX_LINE_LENGTH];
  char new_line[MAX_LINE_LENGTH];

  int inline_comment_active = 0;
  int block_comment_active = 0;

  int initial_whitespace = 1;
  int became_unwhitespaced = 0;

  int length;

  while (get_the_line(line) != EOF) {
    length = line_length(line);
    initial_whitespace = 1;
    became_unwhitespaced = 0;
    // Go through the characters of the line.
    // If we see the start of a comment delimiter,
    // indicate comment is active.
    // If we see the end of a comment delimiter,
    // indicate comment is inactive.
    for (i = 0; i < length; i++) {
      // Have we just become unwhitespaced?
      became_unwhitespaced = initial_whitespace && line[i] != ' ';
      // Otherwise, are we initially whitespace?
      if (line[i] != ' ') {
        initial_whitespace = 0;
      }
      if (i < length - 2 && !block_comment_active && line[i] == '/' && line[i + 1] == '*') {
        block_comment_active = 1;
      }
      if (i > 2 && block_comment_active && line[i - 2] == '*' && line[i - 1] == '/') {
        block_comment_active = 0;
      }
      // We also have "// this style"
      if (became_unwhitespaced && !inline_comment_active && line[i] == '/' && line[i + 1] == '/') {
        inline_comment_active = 1;
      }
      if (became_unwhitespaced && inline_comment_active && line[i] != '/' && line[i + 1] != '/') {
        inline_comment_active = 0;
      }
      if (!block_comment_active && !inline_comment_active) {
        new_line[i] = line[i];
        new_line[i + 1] = line[i + 1];
      }
      else {
        new_line[i] = ' ';
        new_line[i + 1] = ' ';
      }
    }
    printf("%s\n", new_line);

  }

}


int get_the_line(char line[]) {
  int i;
  int c;
  int was_eof;

  was_eof = 0;

  for (i = 0; i < MAX_LINE_LENGTH; i++) {
    c = getchar();
    if (c == EOF) {
      was_eof = 1;
      break;
    }
    if (c == '\n') {
      line[i] = '\0';
      break;
    }
    line[i] = c;
  }


  if (was_eof) {
    return EOF;
  }

  return 1;
}

int line_length(char line[]) {
  int i;

  for (i = 0; i < MAX_LINE_LENGTH; i++) {
    if (line[i] == '\0') {
      return i + 1;
    }
  }

  return MAX_LINE_LENGTH;
}

