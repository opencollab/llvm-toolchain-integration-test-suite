// Test check tidy check
// Verify that a checker finds something
//
// RUN: %clang-tidy -checks='modernize-concat-nested-namespaces'  %s -extra-arg=-std=c++17 | grep "nested namespaces can"
// REQUIRES: clang-tidy

namespace mozilla {
namespace dom {
void foo();
}
}
