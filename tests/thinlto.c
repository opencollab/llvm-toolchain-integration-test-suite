// verify that thinlto is available
// REQUIRES: clang, lld
// RUN: %clang -flto=thin -O2 %S/Inputs/foo.c %s -o %t
// RUN: %t

int foo(void);
int main() {
    foo();
    return 0;
}
