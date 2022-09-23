// Test libunwind - only packaged from -12
//
// REQUIRES: clang, libunwind, llvm-nm
// NOTE: the extra -L flag is only required by Fedora
// RUN: %clangxx %s -o %t.llvm -unwindlib=libunwind -rtlib=compiler-rt -L/usr/lib64/llvm-unwind
// RUN: %llvm-nm %t.llvm | grep _Unwind_Resume
// RUN: %t.llvm
// XFAIL: s390x

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
