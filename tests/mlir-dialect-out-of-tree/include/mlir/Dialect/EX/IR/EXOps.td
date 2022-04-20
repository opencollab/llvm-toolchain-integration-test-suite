#ifndef EX_OPS
#define EX_OPS

include "mlir/Dialect/EX/IR/EXDialect.td"
include "mlir/Interfaces/InferTypeOpInterface.td"
include "mlir/Interfaces/SideEffectInterfaces.td"

def EX_AddOp : EX_Op<"add", [NoSideEffect]> {
    let summary = "+/2 in EX.Kernel";
    let arguments = (ins AnyType:$left, AnyType:$right);
    let results = (outs AnyType:$res);
}

#endif // EX_OPS
