// Test code coverage
//
// RUN: %clang -fprofile-instr-generate %s -o foo
// RUN: LLVM_PROFILE_FILE="foo.profraw" ./foo
// RUN: %llvm-profdata merge -output=foo.profdata foo.profraw
// RUN: %clang -fprofile-instr-use=foo.profdata %s -o foo
// RUN: ./foo
// REQUIRES: clang, llvm-profdata

#include <stdio.h>
int main() {
    if (1==1) {
	printf("true");
    } else {
	printf("false");
	return 42;
    }
return 0;
}
