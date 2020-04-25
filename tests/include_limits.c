// Test includes limits.h https://bugs.debian.org/cgi-bin/bugreport.cgi?bug=913213
//
// REQUIRES: clang
// RUN: %clang -E %s

#include <limits.h>
