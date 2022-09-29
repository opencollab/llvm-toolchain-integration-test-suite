// Test the link against libclang-cppXX
//
// REQUIRES: llvm-config
// RUN: %cxx  -DCLANG_MAJOR=`%llvm-config --version | cut -d . -f 1` -v %s -o %t `%llvm-config --cxxflags --ldflags --libs` -lclang-cpp
// RUN: ldd %t 2>&1 > %t.lddoutput
// RUN: grep -q libclang-cpp %t.lddoutput

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

#if CLANG_MAJOR < 13
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
