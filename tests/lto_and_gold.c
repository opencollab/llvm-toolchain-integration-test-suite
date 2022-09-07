// Test LTO support within ld.gold
// REQUIRES: clang
// RUN: %clang -c -flto %s -DLIB -o %t-obj.o
// RUN: %clang -c -flto %s -ULIB -o %t-main.o
// RUN: %clang -fuse-ld=gold -flto %t-obj.o %t-main.o -o %t
// RUN: %t | grep "hello lita"

#ifdef LIB
#include <stdio.h>
void greet() {
  puts("hello lita");
}
#else
extern void greet();

int main() {
  greet();
  return 0;
}
#endif
