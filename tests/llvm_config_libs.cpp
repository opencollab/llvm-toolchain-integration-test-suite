// Test if llvm-config correctly finds headers and libs
// RUN: %clangxx `%llvm-config --cxxflags --ldflags --libs` %s -o %t
#include <llvm/IR/LLVMContext.h>

int main(int argc, char** argv) {
  llvm::LLVMContext ctxt;
  return 0;
}
