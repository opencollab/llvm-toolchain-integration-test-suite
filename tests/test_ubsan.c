// Test ubsan with config variables
//
// REQUIRES: clang, llvm-nm, compiler-rt
// RUN: %clang -o %t -fsanitize=undefined -g -O1 %s
// RUN: env UBSAN_OPTIONS="log_path=stdout:exitcode=0"  %t 2>&1 > %t.out
// RUN: grep "cannot be represented in type" %t.out
// XFAIL: arm

int main(int argc, char **argv) {
  int k = 0x7fffffff;
  k += argc;
  return 0;
}
