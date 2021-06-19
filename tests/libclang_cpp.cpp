// Test the link against libclang-cppXX
//
// REQUIRES: clang, llvm-config
// RUN: %clangxx -lclang-cpp -v %s -o %t `%llvm-config --cxxflags  --libs`
// RUN: ldd %t 2>&1|grep -q libclang-cpp

#include "clang/Tooling/CommonOptionsParser.h"
#include "llvm/Support/CommandLine.h"

using namespace clang::tooling;
using clang::tooling::CommonOptionsParser;

// Apply a custom category to all command-line options so that they are the
// only ones displayed.
static llvm::cl::OptionCategory MyToolCategory("my-tool options");

int main(int argc, const char **argv) {
    // CommonOptionsParser constructor will parse arguments and create a
    // CompilationDatabase.  In case of error it will terminate the program.

#if __clang_major__ < 13
    clang::tooling::CommonOptionsParser OptionsParser(argc, argv,
                                               MyToolCategory);
#else
    auto ExpectedParser = CommonOptionsParser::create(argc, argv, MyToolCategory);
    if (!ExpectedParser) {
        // Fail gracefully for unsupported options.
        llvm::errs() << ExpectedParser.takeError();
        return 1;
    }
    CommonOptionsParser& OptionsParser = ExpectedParser.get();
#endif

    // Use OptionsParser.getCompilations() and OptionsParser.getSourcePathList()
    // to retrieve CompilationDatabase and the list of input file paths.
}
