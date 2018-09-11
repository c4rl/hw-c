#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 1024

// Write an alternate version of squeeze(s1,s2) that deletes each character in
// s1 that matches any character in the string s2.

void squeeze(char s1[], char s2[]);
int string_length(char s[]);

int main() {

  char s[MAX_LENGTH];

  strcpy(s, "bear");
  squeeze(s, "ear");
  printf("bear:ear becomes 'b': _%s_\n", s);

  strcpy(s, "foo");
  squeeze(s, "fools");
  printf("foo:fools becomes '': _%s_\n", s);

  strcpy(s, "monkey");
  squeeze(s, "pants");
  printf("monkey:pants becomes 'mokey': _%s_\n", s);

  return 0;
}

/**
 * Removes any char in s2 from s1.
 */
void squeeze(char s1[], char s2[]) {
  int i = 0, j = 0, k = 0;
  int c;
  int matches;

  while ((c = s1[i]) != '\0') {
    matches = 0;
    for (j = 0; j < string_length(s2); j++) {
      if (c == s2[j]) {
        matches = 1;
      }
    }
    if (!matches) {
      s1[k++] = c;
    }
    i++;
  }
  s1[k] = '\0';
}

int string_length(char s[]) {
  int i = 0;
  int c;
  
  while ((c = s[i]) && c != '\0')
    i++;


  return i;
}
