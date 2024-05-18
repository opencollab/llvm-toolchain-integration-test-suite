// Tests all components of the toolchain
// REQUIRES: clang, lld, compiler-rt
// RUN: %clang -fuse-ld=lld -rtlib=compiler-rt %s -o %t
// RUN: %t | grep "Hello World"
// s390x now runs but fails because it does not support compiler-rt builtins.
// XFAIL: s390x

#include<stdio.h>
int main(int argc, char **argv) {
  printf("Hello World\n");
  return 0;
}

