// Test LLVM IR
// RUN: if ! ls /proc/sys/fs/binfmt_misc/*llvm* > /dev/null; then echo "No LLVM runtime found"; exit 0; fi
// RUN: %clang -O3 -emit-llvm %s -c -o %t.bc
// RUN: chmod +x %t.bc
// RUN: %t.bc | grep -q "lli foo"
// RUN: %llvm-dis < %t.bc | grep -q "lli foo"
// REQUIRES: clang, llvm-dis

#include <stdio.h>
int main() {
    puts("lli foo");
    return 0;
}
