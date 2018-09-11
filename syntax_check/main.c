#include <stdio.h>

// WIP

// Write a program to check a C program for rudimentary syntax errors
// like unbalanced parentheses, brackets and braces. Don’t forget
// about quotes, both single and double, escape sequences, and
// comments. (This program is hard if you do it in full generality.)

// Let's just check for
// * balanced paren
// * balanced bracket
// * balanced brace
// * balanced single quote
// * balanced double quote
// * balanced comments

#define MAX_LINE_LENGTH 1024
#define MAX_COLUMN 10

#define REGISTER_PAREN   0b000001
#define REGISTER_BRACKET 0b000010
#define REGISTER_BRACE   0b000100
#define REGISTER_SQUOTE  0b001000
#define REGISTER_DQUOTE  0b010000
#define REGISTER_COMMENT 0b100000

#define PAREN_OPEN    '('
#define PAREN_CLOSE   ')'
#define BRACKET_OPEN  '['
#define BRACKET_CLOSE ']'
#define BRACE_OPEN    '{'
#define BRACE_CLOSE   '}'
#define SQUOTE_OPEN   '\''
#define SQUOTE_CLOSE  '\''
#define DQUOTE_OPEN   '"'
#define DQUOTE_CLOSE  '"'
#define COMMENT_OPEN  '/'

int get_the_line();
int line_length(char line[]);

int main() {

  int c;

  char line[MAX_LINE_LENGTH];

  int registry = 0b0;

  int line_no = 0;

  int paren_opens[1024];
  int paren_closes[1024];

  while (get_the_line(line) != EOF) {
    line_no++;
    for (i = 0; i < line_length(line); i++) {

      if (c == PAREN_OPEN && (registry & REGISTER_PAREN == REGISTER_PAREN)) {
        printf("Error: unbalanced paren on line %d, char %d\n", line_no, i);
      }
      else {
        registry |= REGISTER_PAREN;
        paren_opens
      }
    }

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

