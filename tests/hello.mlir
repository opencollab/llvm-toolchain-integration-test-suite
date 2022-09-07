// REQUIRES: clang, mlir-translate, llvm-config
// RUN: if `%llvm-config --version | grep -q 14`; then sed 's/func.func/func/' %s; else cat %s; fi | %mlir-translate --mlir-to-cpp > %t.c
// RUN: %clang %t.c -o %t
// RUN: %t

module {
  emitc.include <"stdint.h">
  func.func @main() -> i32 {
    %ret = "emitc.constant"(){value = 0 : i32} : () -> i32
    return %ret : i32
  }
}

