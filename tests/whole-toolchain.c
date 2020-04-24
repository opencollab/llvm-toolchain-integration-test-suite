// Tests all components of the toolchain
// REQUIRES: clang, lld, compiler-rt
// RUN: %clang -fuse-ld=lld -rtlib=compiler-rt %s -o %t
// RUN: %t | grep "Hello World"

#include<stdio.h>
int main(int argc, char **argv) {
  printf("Hello World\n");
  return 0;
}

