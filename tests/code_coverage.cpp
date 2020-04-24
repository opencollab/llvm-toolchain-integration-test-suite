// Test code coverage
//
// RUN: mkdir -p %t/test && cd %t/test
// RUN: %clang --coverage %s -o foo
// RUN: ./foo
// RUN: test -f code_coverage.gcno
// RUN: test -f code_coverage.gcda
// REQUIRES: clang

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
