#include <stdio.h>
#include <limits.h>

int atoi(char s[]);
int rand(void);
void srand(unsigned int seed);

unsigned long int next = 1;

int rand(void)
{
    next = next * 1103515245 + 12345;
    printf("next: %ld\n", LONG_MAX + 1);
    return (unsigned int)(next/65536) % 32768;
}

void srand(unsigned int seed)
{
    next= seed;
}


int main() {

  // printf("INT_MAX  %d\n", INT_MAX);
  // printf("LONG_MAX %ld\n", LONG_MAX);
  printf("%ld\n", LONG_MAX);
  printf("%ld\n", LONG_MAX + 1);
  printf("%ld\n", LONG_MIN);
  printf("%ld\n", LONG_MIN - 1);
  // printf("%d\n", atoi("123") + 100);


  return 0;
}

int atoi(char s[])
{
    int i, n;
    n = 0;
    // We multiply the value time 10, then add the
    // one's place. Each subsequent turn "moves"
    // the numbers from right to left.
    for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
        n = 10 * n + (s[i] - '0');
    return n;
}

