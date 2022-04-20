#include "mlir/Dialect/EX/IR/EXDialect.h"
#include "mlir/Dialect/EX/IR/EXOps.h"

using namespace mlir;
using namespace mlir::EX;

#include "mlir/Dialect/EX/IR/EXOpsDialect.cpp.inc"

//===----------------------------------------------------------------------===//
// EX dialect.
//===----------------------------------------------------------------------===//

void EXDialect::initialize() {
  addOperations<
#define GET_OP_LIST
#include "mlir/Dialect/EX/IR/EXOps.cpp.inc"
      >();
}
