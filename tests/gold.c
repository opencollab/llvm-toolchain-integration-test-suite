// Test gold support
// REQUIRES: clang
// RUN: %clang -fuse-ld=gold %s -o %t
// RUN: %t

#include <stdio.h>
int main() {
    puts("I like to std::move(it)");
    return 0;
}
