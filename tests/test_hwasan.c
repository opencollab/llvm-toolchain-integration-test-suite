// Test hwasan use after free -- aarch64 only.
//
// REQUIRES: clang, compiler-rt, support_hwasan
// RUN: %clang -o %t -fsanitize=hwaddress -g %s
// RUN: env HWASAN_OPTIONS="log_path=stdout:exitcode=0"  %t 2>&1 > %t.out
// RUN: grep -q "HWAddressSanitizer: tag-mismatch" %t.out
// RUN: grep -q "Cause: use-after-free" %t.out

#include <stdlib.h>

int main() {
  int *p = malloc(sizeof(int));
  free(p); // The memory is leaked here.
  return *p;
}
