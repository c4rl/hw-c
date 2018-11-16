#include <stdio.h>

#define N 100000

int binsearch_b(unsigned long x, unsigned long arr[]);

int binsearch_a(int x, unsigned long v[], int n);

int main() {

  unsigned long arr[N];
  unsigned long i = 0;

  // Pupular.
  while (i < N) {
    arr[i] = i * i;
    i++;
  }

  // printf("32490000: %d\n", binsearch_a(32490000, arr, N));
  // printf("32490001: %d\n", binsearch_a(32490001, arr, N));
  // printf("32489999: %d\n", binsearch_a(32489999, arr, N));

  printf("32490000: %d\n", binsearch_b(32490000, arr));
  printf("32490001: %d\n", binsearch_b(32490001, arr));
  printf("32489999: %d\n", binsearch_b(32489999, arr));

  return 0;
}

int binsearch_b(unsigned long x, unsigned long arr[]) {
  int min, max, p;

  min = 0;
  max = N - 1;

  while (min <= max) {
    p = (min + max) / 2;
    if (x < arr[p]) {
      max = p - 1;
    }
    else {
      min = p + 1;
    }

  }

  if (x == arr[p - 1]) {
    return p - 1;
  }
  else if (x == arr[p]) {
    return p;
  }
  
  return -1;
}


int binsearch_a(int x, unsigned long v[], int n) {
    int low, high, mid;
     low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low+high) / 2;
        if (x < v[mid])
          high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else    /* found match */
            return mid;
    }
    return -1;
}

