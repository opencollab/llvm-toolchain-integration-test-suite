// verify that target to aarch64 works
// REQUIRES: clang
// RUN: %clang -c -target aarch64-linux-gnu %s
// RUN: file %s.o|grep -i -q "aarch64"

bool testAndSet(void *atomic) {
    return __atomic_test_and_set(atomic, __ATOMIC_SEQ_CST);
}
