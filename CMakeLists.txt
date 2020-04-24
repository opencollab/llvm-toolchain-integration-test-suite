cmake_minimum_required(VERSION 3.4.3)
project(LLVMToolchainIntegrationTestSuite VERSION 1.0 LANGUAGES NONE)

message(STATUS "Checking for lit")
find_program(LIT lit)
if(NOT LIT)
    message(ERROR "lit program not found")
endif()

macro(find_program_or_warn OUT_VAR name)
    message(STATUS "Checking for ${name}")
    find_program(${OUT_VAR} ${name})
    if (NOT ${OUT_VAR})
        message(WARN "Disabling tests related to ${name}")
    endif()
endmacro()

find_program_or_warn(CLANGXX_BINARY clang++)
find_program_or_warn(CLANG_BINARY clang)
find_program_or_warn(LLD lld)
find_program_or_warn(LLDB lldb)

configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/tests/lit.site.cfg.in
    ${CMAKE_BINARY_DIR}/tests/lit.site.cfg
    )

add_custom_target(check ${LIT} tests)
