//=== Example code from "Writing an LLVM Pass" ----------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file implements a simple LLVM Pass using the new pass manager, based on
// the version described in docs/WritingAnLLVMNewPMPass.html
//
//===----------------------------------------------------------------------===//


#include "llvm/IR/PassManager.h"
#include "llvm/Passes/PassBuilder.h"
#include "llvm/Passes/PassPlugin.h"
#include "llvm/Support/raw_ostream.h"

namespace llvm {
class HelloWorldNewPMPass : public PassInfoMixin<HelloWorldNewPMPass> {
public:
    PreservedAnalyses run(Function &F, FunctionAnalysisManager &AM);
    static bool isRequired() { return true; }
};

PreservedAnalyses HelloWorldNewPMPass::run(
        Function &F,
        FunctionAnalysisManager &AM)
{
    errs() << "Function name: " << F.getName() << "\n";
    return PreservedAnalyses::all();
}

// Documented in https://llvm.org/doxygen/PassPlugin_8h_source.html
extern "C" ::llvm::PassPluginLibraryInfo LLVM_ATTRIBUTE_WEAK
llvmGetPassPluginInfo() {
    return {
        LLVM_PLUGIN_API_VERSION, "HelloWorldNewPM", "v0.1", [](PassBuilder &PB) {
            PB.registerPipelineParsingCallback(
                [](StringRef Name, FunctionPassManager &FPM,
                    ArrayRef<PassBuilder::PipelineElement>) {
                    if (Name == "hellonewpm") {
                        FPM.addPass(HelloWorldNewPMPass());
                        return true;
                    }
                    return false;
                }
            );
        }
    };
}
} // namespace llvm
