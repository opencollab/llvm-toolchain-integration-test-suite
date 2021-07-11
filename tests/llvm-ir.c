// Test LLVM IR
// RUN: %clang -S -emit-llvm %s -o a.ll
// RUN: %llc a.ll && touch a.s
// RUN: %lli a.ll|grep -q "lli foo"
// RUN: %opt -S -O3 a.ll -o opt.ll
// RUN: %lli opt.ll|grep -q "lli foo"
// REQUIRES: clang, llc, lli, opt

#include <stdio.h>
int main() {
    printf("lli foo\n");
    return 0;
}
