#include <stdio.h>

int main() {
  int c, nl, last_char;

  nl = 0;
  while ((c = getchar()) != EOF) {
    if (c != ' ' || last_char != ' ') {
      putchar(c);
    }
    last_char = c;
  }

  printf("%d\n", nl);
}
