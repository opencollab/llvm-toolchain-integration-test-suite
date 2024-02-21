// Test libc++ static library linking into a shared library.
// See https://bugzilla.redhat.com/show_bug.cgi?id=2186531
//
// RUN: %clangxx -c -o %t.o -fPIC %s
// RUN: %clangxx -fuse-ld=lld -nostdlib++ -Wl,-Bstatic -lc++ -Wl,-Bdynamic -stdlib=libc++ -shared -o %t %t.o
//
// REQUIRES: clangxx, lld, static-libc++

#include <exception>

extern void test_shared() {
  std::get_terminate();
}
