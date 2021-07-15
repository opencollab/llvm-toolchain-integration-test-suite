// Checks that we generate BuildID
//
// REQUIRES: clang, lld
// RUN: %clang -fuse-ld=lld -flto -O2 %S/Inputs/foo.c %s -o %t
// RUN: %t
// RUN: file %t|grep -q BuildID
// RUN: %clang -O2  %S/Inputs/foo.c %s -o %t
// RUN: %t
// RUN: file %t|grep -q BuildID
// RUN: strip %t
// RUN: file %t|grep -q BuildID

int foo(void);
int main() {
    foo();
    return 0;
}
