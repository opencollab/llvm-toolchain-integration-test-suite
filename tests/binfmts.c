// Test LLVM IR
// RUN: %clang -O3 -emit-llvm %s -c -o foo.bc
// RUN: chmod +x foo.bc
// RUN: ./foo.bc|grep -q "lli foo"
// RUN: %llvm-dis < foo.bc|grep -q "lli foo"
// REQUIRES: clang, llvm-dis

#include <stdio.h>
int main() {
    printf("lli foo\n");
    return 0;
}
