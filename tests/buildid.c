// Checks that we generate BuildID
//
// REQUIRES: clang, lld, llvm-objdump
// RUN: %clang -fuse-ld=lld -flto -O2 %S/Inputs/foo.c %s -o %t
// RUN: %t
// RUN: %llvm-objdump -s %t|grep note.gnu.build-id
// RUN: %clang -O2  %S/Inputs/foo.c %s -o %t
// RUN: %t
// RUN: %llvm-objdump -s %t|grep note.gnu.build-id
// RUN: strip %t
// RUN: %llvm-objdump -s %t|grep note.gnu.build-id

int foo(void);
int main() {
    foo();
    return 0;
}
