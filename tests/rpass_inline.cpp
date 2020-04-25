// Test a Rpass=inline
//
// RUN: %clangxx -O2 -Rpass=inline %s -c &> %t.log
// RUN: grep -q "cost=always" %t.log
// REQUIRES: clangxx

int foo(int x, int y) __attribute__((always_inline));
int foo(int x, int y) { return x + y; }
int bar(int j) { return foo(j, j - 2); }
