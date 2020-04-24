// Test code coverage

// RUN: mkdir -p %t/test && cd %t/test
// RUN: %clang --coverage %s -o foo
// RUN: ./foo
// RUN: test ! -f foo.gcno
// RUN: test ! -f foo.gcda
#include <stdio.h>
int main() {
if (1==1) {
	printf("true");
}else{
	printf("false");
	return 42;
}
return 0;}
