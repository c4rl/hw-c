#include <stdio.h>

int main() {

  int c, i, count_white, count_other;
  int counts_digit[10];

  // Initialize counts;
  count_white = count_other = 0;
  for (i = 0; i < 10; i++) {
    counts_digit[i] = 0;
  }

  while ((c = getchar()) != EOF) {
    if (c > '0' && c <= '9') {
      ++counts_digit[c - '0'];
    }
    else if (c == ' ' || c == '\n' || c == '\t') {
      ++count_white;
    }
    else {
      ++count_other;
    }
  }

  printf("{digits: {");
  for (i = 0; i < 10; i++) {
    printf("%d: %d", i, counts_digit[i]);
    if (i < 9) {
      printf(", ");
    }
  }

  printf("}, whitespace: %d, other: %d}\n", count_white, count_other);

}

