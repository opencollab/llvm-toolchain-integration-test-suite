// Test lib(std)c++ static
// https://bugs.llvm.org/show_bug.cgi?id=43604
//
// Check static linking with libstdc++
// RUN: %clangxx -o %t %s -fPIC -pie -static-libstdc++
// RUN: %t
// RUN: ldd %t 2>&1|grep -v libstdc++
//
// Check static linking with libc++. As of now, this fails:
// FAIL: %clangxx -o %t -fPIC %s -pie -stdlib=libc++ -static-libstdc++
//
// REQUIRES: clangxx, libc++

#include <iostream>
int main () {
    std::cout << "Hello World!" << std::endl;
}
