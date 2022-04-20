#ifndef EX_EXOPS_H
#define EX_EXOPS_H

#include "mlir/IR/BuiltinTypes.h"
#include "mlir/IR/Dialect.h"
#include "mlir/IR/OpDefinition.h"
#include "mlir/Interfaces/SideEffectInterfaces.h"

#define GET_OP_CLASSES
#include "mlir/Dialect/EX/IR/EXOps.h.inc"

#endif // EX_EXOPS_H
