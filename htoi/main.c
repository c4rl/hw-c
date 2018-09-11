#include <stdio.h>

#define MAX_LINE_LENGTH 1024

// Write the function htoi(s), which converts a string of hexadecimal digits
// (including an optional 0x or 0X) into its equivalent integer value. The
// allowable digits are 0 through 9, a through f, and A through F.

int htoi(char hex_string[]);
int fetch_line(char line[]);

int main() {
  char line[MAX_LINE_LENGTH];
  int length;

  fetch_line(line);

  printf("Hex value: %s\n", line);
  printf("Decimal value: %d\n", htoi(line));

  return 0;
}

int htoi(char hex_string[]) {
  // We need to parse out the Hex string into decimal equivalents.
  int i = 0;
  int c;

  int decimal_equivalent = 0;

  int decimal_part;

  while ((c = hex_string[i++]) != '\0') {
    // Determine the quantity in decimal.
    // Native integer.
    if (c >= '0' && c <= '9') {
      decimal_part = c - '0';
    }
    else if (c >= 'a' && c <= 'f') {
      decimal_part = (c - 'a') + 10;
    }
    else if (c >= 'A' && c <= 'F') {
      decimal_part = (c - 'A') + 10;
    }
    else {
      decimal_part = 0;
    }
    decimal_equivalent = 16 * decimal_equivalent + decimal_part;
  }

  return decimal_equivalent;
}

int fetch_line(char line[]) {
  int i = 0;
  int c;

  while (i < MAX_LINE_LENGTH && (c = getchar()) != EOF && c != '\n') {
    line[i++] = c;
  }

  return i == 0 ? EOF : i;
}

