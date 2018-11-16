#include <stdio.h>

#define NULL_CHAR '\0'
#define MAX_LENGTH 1024

void expand(char str1[], char str2[]);

int length(char str[]);

int identical_class(char c1, char c2);

int main() {

  // char str1[] = "-f-i-j1-ua-c0-9-";
  char str1[] = "a-z0-9";
  char str2[MAX_LENGTH];

  expand(str1, str2);

  printf("s1: %s\n", str1);
  printf("s2: %s\n", str2);

  return 0;
}

int length(char str[]) {
  int i = 0;

  while (str[i] != NULL_CHAR) i++;

  return i;
}

int identical_class(char c1, char c2) {
  if (c1 >= '0' && c1 <= '9') {
    return c2 >= '0' && c2 <= '9';
  }

  if (c1 >= 'a' && c1 <= 'z') {
    return c2 >= 'a' && c2 <= 'z';
  }

  return 0;
}

void expand(char str1[], char str2[]) {
  
  // Run through the characters, considering where we have sequence starts
  // and sequence ends.

  int str1_length = length(str1);

  // For each sequence, determine starting character and ending character.
  int i = 0, ii, j = 0;

  int start_i;
  int end_i;

  char start_char, end_char, c;

  while (str1[i] != NULL_CHAR) {
    if ('-' == str1[i] && (i - 1 >= 0) && (i + 1 < str1_length)) {
      // The minimum conditions are met for a sequence.
      start_i = i - 1;
      end_i = i + 1;
      // Increment the end of the sequence if there are additional
      // concluding characters.
      while (end_i + 2 < str1_length && str1[end_i + 1] == '-') {
        end_i += 2;
      }
      start_char = str1[start_i];
      end_char = str1[end_i];

      if (identical_class(start_char, end_char)) {
        for (c = start_char; c <= end_char; c++) { 
          str2[j++] = c;
        }
      }

      i = end_i + 1;
    }
    else {
      i++;
    }
  }
  str2[j] = NULL_CHAR;

}
