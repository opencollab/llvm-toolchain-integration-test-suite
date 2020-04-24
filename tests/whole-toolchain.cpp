// Tests all components of the toolchain
// REQUIRES: clang, lld, compiler-rt, libc++
// RUN: %clangxx -fuse-ld=lld -rtlib=compiler-rt -stdlib=libc++ %s -o %t
// RUN: %t | grep "Hello World"

#include <iostream>
int main(int argc, char **argv) {
  std::cout << "Hello World" << std::endl;
  return 0;
}

