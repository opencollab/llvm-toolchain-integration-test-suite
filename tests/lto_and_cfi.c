// Test compatibility between lto and CFI, see  https://bugzilla.redhat.com/show_bug.cgi?id=1794936
// RUN: %clang -flto -fsanitize=cfi -fvisibility=hidden %s -o %t
// REQUIRES: clang, compiler-rt
// XFAIL: s390x, ppc64le, ppc64

int main() {
  return 0;
}
