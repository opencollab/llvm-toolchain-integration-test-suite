// REQUIRES: clang, compiler-rt, float16
// RUN: %clangxx %s -o %t.float16 -rtlib=compiler-rt
// RUN: %t.float16 | grep '0.122986'

#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
  _Float16 one_f16 = 0.123;
  float one_f32 = one_f16;
  std::cout <<  one_f32 << std::endl;
  return 0;
}
