// Test a Rpass=inline (parse the output)
//
// RUN: %clangxx -O2 -Rpass=inline %s -c &> %t.log
// RUN: grep -q -E "(inlined into main with|inlined into 'main' with|cost=always)" %t.log
// REQUIRES: clangxx

int foo(int x, int y) __attribute__((always_inline));
int foo(int x, int y) { return x + y; }
int bar(int j) { return foo(j, j - 2); }

int sum = 0;

int main(int argc, const char *argv[]) {
  for (int i = 0; i < 30; i++)
    bar(argc);
  return sum;
}
