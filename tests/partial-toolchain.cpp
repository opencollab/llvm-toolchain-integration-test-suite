// Tests all components of the toolchain
// REQUIRES: clang, lld, libc++
// RUN: %clangxx -fuse-ld=lld -stdlib=libc++ %s -o %t
// RUN: %t | grep "Hello World"

#include <iostream>
int main(int argc, char **argv) {
  std::cout << "Hello World" << std::endl;
  return 0;
}

