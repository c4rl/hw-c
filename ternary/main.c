#include <stdio.h>

char lower (char c);

int main() {

  putchar(lower('S'));
  printf("\n");
  putchar(lower('B'));
  printf("\n");

  return 0;
}

char lower (char c) {
  return c > 'A' || c < 'Z' ? c - ('A' - 'a') : c;
}
