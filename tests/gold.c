// Test gold support
// REQUIRES: clang
// RUN: %clang -fuse-ld=gold %s -o %t
// RUN: %t

#include <stdio.h>
int main() {
if (1==1) {
  printf("true");
}else{
  printf("false");
  return 42;
}
return 0;
}
