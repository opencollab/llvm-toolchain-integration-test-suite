// Test OpenMP headers install
//
// RUN: %clang -fopenmp -E %s -o %t
// REQUIRES: clang, libomp

#include <omp.h>
#if _OPENMP >= 201811
#include <ompt.h>

// Still not fixed upstream
#if 0
#define CLIENT_TOOL_LIBRARIES_VAR "SAMPLE"
#include <ompt-multiplex.h>
#endif

#endif
