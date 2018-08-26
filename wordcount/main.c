#include <stdio.h>

// Inside a word.
#define IN  1

// Outside a word.
#define OUT 0

int main() {

  int c, nl, nw, nc, state;

  nl = nw = nc = 0;
  while ((c = getchar()) != EOF) {
    ++nc;
    if (c == '\n')
      ++nl;
    if (c == ' ' || c == '\n' || c == '\t')
      state = OUT;
    else if (state == OUT) {
      state = IN;
      ++nw;
    }
  }

  printf("%d %d %d\n", nl, nw, nc);
}
