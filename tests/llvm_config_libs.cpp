// Test if llvm-config correctly finds headers and libs
// RUN: %clangxx `%llvm-config --cxxflags --ldflags --libs` %s -o %t
// RUN: %clangxx `%llvm-config  --link-shared --cxxflags --ldflags --libs` %s -o %t
//
// Check that warnings are not exported
// RUN: %llvm-config --cxxflags | grep -v " \-W"
//
// REQUIRES: clangxx, llvm-config
#include <llvm/IR/LLVMContext.h>

int main(int argc, char** argv) {
  llvm::LLVMContext ctxt;
  return 0;
}
