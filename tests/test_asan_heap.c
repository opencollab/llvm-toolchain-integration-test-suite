// Test asan use after free
//
// REQUIRES: clang, compiler-rt
// RUN: %clang -o %t -fsanitize=address -O1 -fno-omit-frame-pointer -g %s
// RUN: env ASAN_OPTIONS="log_path=stdout:exitcode=0"  %t 2>&1 > %t.out
// RUN: grep -q "heap-use-after-free" %t.out
// XFAIL: arm

#include <stdlib.h>
int main() {
  char *x = (char*)malloc(10 * sizeof(char*));
  free(x);
  return x[5];
}
