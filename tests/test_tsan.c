// Test tsan with config variables
//
// REQUIRES: clang, llvm-nm, compiler-rt
// RUN: %clang -o %t -fsanitize=thread -g -O1 %s
// RUN: %llvm-nm %t | grep __tsan
// RUN: env TSAN_OPTIONS="log_path=stdout:exitcode=0"  %t 2>&1 > %t.out
// RUN: grep -q "data race" %t.out
// XFAIL: arm, i686, i386

#include <pthread.h>
#include <stdio.h>

int Global;

void *Thread1(void *x) {
  Global++;
  return NULL;
}

void *Thread2(void *x) {
  Global--;
  return NULL;
}

int main() {
  pthread_t t[2];
  pthread_create(&t[0], NULL, Thread1, NULL);
  pthread_create(&t[1], NULL, Thread2, NULL);
  pthread_join(t[0], NULL);
  pthread_join(t[1], NULL);
}

