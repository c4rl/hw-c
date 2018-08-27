#include <stdio.h>

int main() {
  int c;

  while ((c = getchar()) != EOF) {

    // If whitespace is encountered, print a newline.
    if (c == '\t' || c == ' ') {
      printf("\n");
    }
    else {
      putchar(c);
    }

  }

}
