// Make sure that libc++ and asan work correctly
// can be caused by -Bsymbolic-functions
// https://github.com/llvm/llvm-project/issues/59432
// RUN: %clangxx -xc++ - -stdlib=libc++ -fsanitize=address %s -o %t
// RUN: %t
// REQUIRES: clang, compiler-rt, libc++
//

#include <stdexcept>
int main() {
#if __clang_major__ > 18
    std::logic_error("");
#endif
}
