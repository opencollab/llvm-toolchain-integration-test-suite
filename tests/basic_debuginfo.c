// Test that debuginfo produced by clang is compatible with basic dwarf tool
// from https://rosettacode.org/wiki/Guess_the_number#C

// RUN: %clang -g3 -gdwarf-4 %s -o %t && objdump -g --dwarf-check %t | grep -E 'DWARF Version:\s*4'
// REQUIRES: clang

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(void)
{
  srand(time(NULL));
  int n = 1 + (rand() % 10);

  puts("I'm thinking of a number between 1 and 10.");
  puts("Try to guess it:");

  int g;
  while (1) {
    if (scanf("%d", &g) != 1) {
      /* ignore one char, in case user gave a non-number */
      char c;
      scanf("%c", &c);
      continue;
    }

    if (g == n) {
      puts("Correct!");
      return 0;
    }
    puts("That's not my number. Try another guess:");
  }
}
