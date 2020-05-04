// RUN: %clangxx -g -o %t %s
// RUN: %lldb -s %S/basic_lldb2.in %t | grep "stop reason = step over"
// REQUIRES: lldb, clangxx

#include <vector>
int main (void)
{  std::vector<int> a;
  a.push_back (0);
}
