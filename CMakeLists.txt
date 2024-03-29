cmake_minimum_required(VERSION 3.4.3)
project(LLVMToolchainIntegrationTestSuite VERSION 1.0 LANGUAGES NONE)

enable_language(C)
enable_language(CXX)

message(STATUS "Checking for lit")
find_program(LIT lit)
if(NOT LIT)
    message(FATAL_ERROR "lit program not found")
endif()

macro(find_program_or_warn OUT_VAR name)
    message(STATUS "Checking for ${name}")
    find_program(${OUT_VAR} ${name})
    if (NOT ${OUT_VAR})
        message(STATUS "Disabling tests related to ${name}")
    endif()
endmacro()

find_program_or_warn(CLANGXX_BINARY clang++)
find_program_or_warn(CLANG_BINARY clang)
find_program_or_warn(CLANG_TIDY_BINARY clang-tidy)
find_program_or_warn(CLANG_FORMAT_BINARY clang-format)
find_program_or_warn(CLANG_FORMAT_DIFF_BINARY clang-format-diff)
find_program_or_warn(CLANGD_BINARY clangd)
find_program_or_warn(OPT_BINARY opt)
find_program_or_warn(LLVMNM llvm-nm)
find_program_or_warn(LLC llc)
find_program_or_warn(LLI lli)
find_program_or_warn(OPT opt)
find_program_or_warn(LLVMPROFDATA llvm-profdata)
find_program_or_warn(LLD_BINARY lld)
find_program_or_warn(LLDB_BINARY lldb)
find_program_or_warn(LLVMCONFIG_BINARY llvm-config)
find_program_or_warn(LLVMOBJDUMP_BINARY llvm-objdump)
find_program_or_warn(SCANBUILD scan-build)
find_program_or_warn(SCANVIEW scan-view)
find_program_or_warn(SCANBUILDPY scan-build-py)
find_program_or_warn(MLIRTRANSLATE mlir-translate)


option(ENABLE_COMPILER_RT "assume compiler-rt is available" ON)
option(ENABLE_LIBCXX "assume libc++ is available" ON)
option(ENABLE_STATIC_LIBCXX "assume libc++.a is available" ON)
option(ENABLE_LIBUNWIND "assume libunwind is available" ON)

message(STATUS "Checking kernel support for tagged address ABI")
try_run(
    _TEST_RUN_RESULT
    _BUILD_RESULT_UNUSED
    ${CMAKE_BINARY_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/test_tagged_addr_abi_support.c
    )
if(DEFINED _TEST_RUN_RESULT AND _TEST_RUN_RESULT EQUAL 0)
    set(SUPPORT_HWASAN ON)
else()
    message(STATUS "Tagged address ABI disabled, disabling hwasan test(s)")
    set(SUPPORT_HWASAN OFF)
endif()
option(ENABLE_HWASAN
    "The host supports Aarch64 tagged address ABI"
    ${SUPPORT_HWASAN}
    )

configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/tests/lit.site.cfg.in
    ${CMAKE_BINARY_DIR}/tests/lit.site.cfg
    )

add_custom_target(check ${LIT} --show-unsupported --show-xfail -v tests)
