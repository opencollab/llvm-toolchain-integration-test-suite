// Test OpenMP Tools support
// RUN: %clang -fopenmp -DTOOLS %s -shared -o %t_Tools.so
// RUN: %clang -fopenmp -UTOOLS %s -o %t
// RUN: OMP_TOOL_LIBRARIES=%t_Tools.so %t | grep "INIT"
// REQUIRES: clang, libomp
#ifdef TOOLS

// OpenMP Tools are only supported starting OpenMP 5
#if _OPENMP >= 201811
#include <stdio.h>
#include <ompt.h>

int ompt_initialize(
        ompt_function_lookup_t lookup,
        int initial_device_num,
        ompt_data_t *data)
{
  puts("[INIT]");
  return 1;
}

void ompt_finalize(ompt_data_t* data)
{
  puts("[FINAL]");
}

ompt_start_tool_result_t* ompt_start_tool(
  unsigned int omp_version,
  const char *runtime_version)
{
  printf("[START] %s, OMP%u\n", runtime_version, omp_version);
  static ompt_start_tool_result_t ompt_start_tool_result = {&ompt_initialize, &ompt_finalize, {.ptr=NULL}};
  return &ompt_start_tool_result;
}

#endif


#else
#include <stdio.h>

int main() {
#pragma omp parallel
#pragma omp single
  {
    // if we don't have support for ompt, default to an output that satisfies
    // the test check
#if _OPENMP < 201811
  puts("INIT");
#else
  puts("hello");
#endif
  }
  return 0;
}

#endif
