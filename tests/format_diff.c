// Make sure clang-format-diff works as expected
//
// REQUIRES: clang-format-diff, clang
// RUN: %clang -E -Wp,-P %s -DV0 > %t.0.c
// RUN: %clang -E -Wp,-P %s -DV1 > %t.1.c
// RUN: diff -u %t.0.c %t.1.c %clang-format-diff

#if defined(V0)
int main() { }
#elif defined(V1)
int main() { return 0; }
#endif
