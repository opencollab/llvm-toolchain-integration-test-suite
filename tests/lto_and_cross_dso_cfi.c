// Test compatibility between lto and CFI with cross -dso enabled
// RUN: rm -rf %t.dir
// RUN: mkdir %t.dir
// RUN: %clang -UMAIN -flto -fsanitize=cfi -fsanitize-cfi-cross-dso -fvisibility=default -fuse-ld=lld %s -shared -o %t.dir/liblocalcrossdso.so
// RUN: %clang -DMAIN -flto -fsanitize=cfi -fsanitize-cfi-cross-dso -fvisibility=default -fuse-ld=lld %s -o %t -L%t.dir -llocalcrossdso
// RUN: LD_LIBRARY_PATH=%t.dir %t
// RUN: rm -f liblocalcrossdso.so
// REQUIRES: clang, compiler-rt, lld
// XFAIL: s390x, ppc64le, ppc64

#ifdef MAIN
#include <stdio.h>

extern int greet(void(*greeter)(void));


void greeter(void) {
  puts("hello");
}

int main() {
  return greet(greeter);
}

#else

int greet(void(*greeter)(void)) {
  greeter();
  return 0;
}
#endif
