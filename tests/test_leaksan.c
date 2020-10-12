// Test asan use after free
//
// REQUIRES: clang
// RUN: %clang -o %t -fsanitize=address -g %s
// RUN: env ASAN_OPTIONS="log_path=stdout:exitcode=0"  %t 2>&1 > %t.out
// RUN: grep -q "detected memory leaks" %t.out

#include <stdlib.h>

void *p;

int main() {
  p = malloc(7);
  p = 0; // The memory is leaked here.
  return 0;
}
