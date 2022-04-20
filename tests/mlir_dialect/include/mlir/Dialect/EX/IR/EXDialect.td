#ifndef EX_DIALECT
#define EX_DIALECT

include "mlir/IR/OpBase.td"

//===----------------------------------------------------------------------===//
// EX dialect definition.
//===----------------------------------------------------------------------===//

def EX_Dialect : Dialect {
    let name = "EX";
    let summary = "A out-of-tree MLIR dialect for the EX programming language.";
    let description = [{
        This dialect is used to represent EX programs to enable high level apps like static analysis, compiler.
        Ideally, this dialect only contains ops for equivalent concepts in EX.Kernel.
    }];
    let cppNamespace = "::mlir::EX";
}

//===----------------------------------------------------------------------===//
// Base EX operation definition.
//===----------------------------------------------------------------------===//

class EX_Op<string mnemonic, list<Trait> traits = []> :
        Op<EX_Dialect, mnemonic, traits>;

#endif // EX_DIALECT
