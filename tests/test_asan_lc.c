// Test asan with lc https://bugs.debian.org/cgi-bin/bugreport.cgi?bug=876973
//
// REQUIRES: clang
// RUN: %clang -fsanitize=address %s -o %t -lc
// RUN: %t

#include <stdio.h>
int main(int argc, char **argv)
{
   printf("Hello world!\n");
   return 0;
}
