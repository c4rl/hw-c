#include <stdio.h>

// Write the function any(s1,s2), which returns the first location in the
// string s1 where any character from the string s2 occurs, or −1 if s1
// contains no characters from s2. (The standard library function strpbrk
// does the same job but returns a pointer to the location.)

int any(char s1[], char s2[]);

int main() {

  printf("Should return 0: %d\n", any("bob", "baby"));
  printf("Should return 1: %d\n", any("bob", "oval"));
  printf("Should return 3: %d\n", any("boba", "cali"));
  printf("Should return -1: %d\n", any("bob", "peas"));

  return 0;
}

int any(char s1[], char s2[]) {
  int i, j;
  signed int first_location = -1;
  
  i = 0;
  while (s1[i] != '\0') {
    j = 0;
    while (s2[j] != '\0') {
      if (first_location == -1 && s1[i] == s2[j]) {
        first_location = i;
      }
      j++;
    }
    i++;
  }

  return first_location;
}
