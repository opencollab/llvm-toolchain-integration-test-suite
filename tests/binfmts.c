// Test LLVM IR
// RUN: %clang -O3 -emit-llvm %s -c -o %t.bc
// RUN: chmod +x %t.bc
// RUN: ./%t.bc | grep -q "lli foo"
// RUN: %llvm-dis < %t.bc | grep -q "lli foo"
// REQUIRES: clang, llvm-dis

#include <stdio.h>
int main() {
    puts("lli foo");
    return 0;
}
