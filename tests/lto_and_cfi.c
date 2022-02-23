// Test compatibility between lto and CFI, see  https://bugzilla.redhat.com/show_bug.cgi?id=1794936
// RUN: %clang -flto -fsanitize=cfi -fvisibility=hidden %s -o %t
// XFAIL: s390x, ppc64le

int main() {
  return 0;
}
