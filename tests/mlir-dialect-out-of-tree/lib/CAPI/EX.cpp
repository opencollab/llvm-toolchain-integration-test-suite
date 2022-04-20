#include "mlir-c/Dialect/EX.h"

#include "mlir/CAPI/Registration.h"
#include "mlir/Dialect/EX/IR/EXDialect.h"

MLIR_DEFINE_CAPI_DIALECT_REGISTRATION(EX, EX, mlir::EX::EXDialect)
