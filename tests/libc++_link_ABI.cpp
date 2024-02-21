// Check that libc++ & libc++abi are built with the options:
// -DLIBCXX_ENABLE_STATIC_ABI_LIBRARY=ON
// -DLIBCXX_STATICALLY_LINK_ABI_IN_STATIC_LIBRARY=ON
// -DLIBCXX_STATICALLY_LINK_ABI_IN_SHARED_LIBRARY=OFF

// REQUIRES: clang
// RUN: %clang %s -o %t -stdlib=libc++ -static-libstdc++ -fuse-ld=lld -l:libc++abi.a
// RUN: %t
// RUN: %clang %s -stdlib=libc++ -nostdlib++ test.cpp -l:libc++.a -l:libc++abi.a -pthread -o %t
// RUN: %t

#include <iostream>
int main() {
  std::cout << "Hello World!" << std::endl;
}
