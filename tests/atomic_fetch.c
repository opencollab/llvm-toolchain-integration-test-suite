// Test atomic_init() https://bugs.debian.org/cgi-bin/bugreport.cgi?bug=903709
//
// REQUIRES: clang
// RUN: %clang -c %s

#include <stdatomic.h>
void increment(atomic_size_t *arg) {
    atomic_fetch_add(arg, 1);
}
