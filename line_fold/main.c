#include <stdio.h>

// Write a program to “fold” long input lines into two or more shorter lines
// after the last non-blank character that occurs before the n-th column of
// input. Make sure your program does something intelligent with very long
// lines, and if there are no blanks or tabs before the specified column.

#define MAX_LINE_LENGTH 1024
#define MAX_COLUMN 30

int get_the_line();
void print_line_as_segments(char line[]);
int line_length(char line[]);
void print_substring(int n, int length, char line[]);

int main() {

  int c, i;
  char line[MAX_LINE_LENGTH];

  while (get_the_line(line) != EOF) {
    print_line_as_segments(line);
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

void print_line_as_segments(char line[]) {

  int length = line_length(line);
  int printed_char_count = 0;
  int start_index = 0;
  int substring_length = MAX_COLUMN;
  int i = 0;

  // Then, for each line, determine if the line exceeds the column count.
  if (length > MAX_COLUMN) {
    while (printed_char_count < length) {
      substring_length = 1;
      start_index = printed_char_count;
      while (line[start_index] == ' ') {
        printed_char_count++;
        start_index++;
      }
      while (substring_length < MAX_COLUMN && line[start_index + substring_length] != '\0') {
        substring_length++;
      }
      while (line[start_index + substring_length] != ' ' && line[start_index + substring_length] != '\0' && substring_length > 1) {
        substring_length--;
      }
      
      print_substring(start_index, substring_length, line);

      for (i = 0; i < MAX_COLUMN - substring_length; i++) {
        printf(".");
      }

      printf("\n");

      printed_char_count += substring_length;
      if (line[start_index + substring_length] == '\0') {
        printed_char_count += 1;
      }
    }
  }
  else {
    // If not, just print the line.
    printf("%s\n", line);
  }
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

void print_substring(int n, int length, char line[]) {
  int i;

  for (i = n; i < n + length; i++) {
    putchar(line[i]);
  }

}



