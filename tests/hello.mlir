// REQUIRES: clang, mlir-translate
// RUN: %mlir-translate --mlir-to-cpp %s > %t.c
// RUN: %clang %t.c -o %t
// RUN: %t

module {
  emitc.include <"stdio.h">
  emitc.include <"stdint.h">
  func @main(%argc: i32, %argv: !emitc.opaque<"char**">) -> i32 {
    %msg = "emitc.apply"(%argv) {applicableOperator = "*"} : (!emitc.opaque<"char**">) -> !emitc.opaque<"char*">
    emitc.call "puts" (%msg) : (!emitc.opaque<"char*">) -> ()
    %ret = "emitc.constant"(){value = 0 : i32} : () -> i32
    return %ret : i32
  }
}

