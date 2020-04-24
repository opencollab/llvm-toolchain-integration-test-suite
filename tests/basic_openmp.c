// Test OpenMP headers and lib detection
//
// RUN: %clang -fopenmp %s -o %t
// RUN: %t | grep "Num Threads: 1"
// REQUIRES: clang

#include <omp.h>
#include <stdio.h>

int main(int argc, char **argv) {
  int nthreads = omp_get_num_threads();
  printf("Num Threads: %d\n", nthreads);
  return 0;
}

