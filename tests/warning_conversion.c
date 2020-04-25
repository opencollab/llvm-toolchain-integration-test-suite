// Test warning conversion https://bugs.debian.org/cgi-bin/bugreport.cgi?bug=914201
//
// REQUIRES: clang
// RUN: %clang -Wconversion -Werror %s

#include <math.h>
int main(void)
{
    double f = 2.0;
    if (isnan(f))
      return 1;
    return 0;
}
