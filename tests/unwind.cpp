// Test libunwind - only packaged from -12
//
// REQUIRES: clang, libunwind, llvm-nm
// RUN: %clangxx %s -o %t.gcc -unwindlib=libgcc
// RUN: %llvm-nm %t.gcc | grep _Unwind_Resume
// RUN: %t.gcc
// RUN: %clangxx %s -o %t.llvm -unwindlib=libunwind -rtlib=compiler-rt
// RUN: %llvm-nm %t.gcc | grep _Unwind_Resume
// RUN: %t.llvm

struct f { ~f() { }};
int foo(int n) {
    f  _;
    if(n > 2)
    throw int();
    return 0;
}
int main(int argc, char** argv) {
    try {
      return foo(argc);
    }
    catch(...) {
        return 0;
    }
}
