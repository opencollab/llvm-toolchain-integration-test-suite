// Test libc++ static
// https://bugs.llvm.org/show_bug.cgi?id=43604
//
// RUN: %clangxx -o %t %s -pie -static-libstdc++
// RUN: %t
// ldd %t 2>&1|grep -qv libc++.so.1
// ldd %t 2>&1|grep -qv libc++abi.so.1
//
// For now, the next command fails:
// RUN: %clangxx -o %t -fPIC %s -pie -stdlib=libc++ -static-libstdc++
// REQUIRES: clangxx, libc++
// XFAIL: *

#include <iostream>
int main () {
    std::cout << "Hello World!" << std::endl;
}
