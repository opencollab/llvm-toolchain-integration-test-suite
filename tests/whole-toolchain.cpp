// Tests all components of the toolchain
// REQUIRES: clang, lld, compiler-rt, libc++
//
// NOTE: Adding -lgcc_eh here is required to provide unwinding information. An
// alternative would be to force usage of LLVM unwinder when building compiler-rt.
// RUN: %clangxx -fuse-ld=lld -rtlib=compiler-rt -stdlib=libc++ -lgcc_eh %s -o %t
// RUN: %t | grep "Hello World"

#include <iostream>
int main(int argc, char **argv) {
  std::cout << "Hello World" << std::endl;
  return 0;
}
