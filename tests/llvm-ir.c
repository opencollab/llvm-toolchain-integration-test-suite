// Test LLVM IR
// RUN: %clang -S -emit-llvm %s -o %t.ll
// RUN: %llc %t.ll && touch %t.s
// RUN: %lli %t.ll | grep -q "lli foo"
// RUN: %opt -S -O3 %t.ll -o %t.opt.ll
// RUN: %lli %t.opt.ll | grep -q "lli foo"
// REQUIRES: clang, llc, lli, opt

#include <stdio.h>
int main() {
    printf("lli foo\n");
    return 0;
}
