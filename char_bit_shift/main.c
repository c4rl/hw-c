#include <stdio.h>

int main() {

  int result;
  result = 0;

  // Multiple characters are not counted.
  result |= 1 << ('s' - 'a');
  result |= 1 << ('c' - 'a');
  result |= 1 << ('o' - 'a');
  result |= 1 << ('t' - 'a');
  result |= 1 << ('t' - 'a');

  printf("%d\n", result);
}
