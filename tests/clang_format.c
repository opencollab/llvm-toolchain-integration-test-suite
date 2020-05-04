// Test clang-format availability
//
// RUN: %clang-format %s | grep -E '^#include <stdio.h>'
// REQUIRES: clang-format

  #include <stdio.h>

int

main() { puts("hello"
    "world")
  ;
return

       0;
}
