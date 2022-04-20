include(FetchContent)

# setup llvm compatible flags
list(APPEND CMAKE_MODULE_PATH ${LLVM_MAIN_SRC_DIR}/cmake/modules)
include(HandleLLVMOptions)

set(CMAKE_SHARED_LIBRARY_SUFFIX .so)
set(CMAKE_SHARED_MODULE_SUFFIX .so)
# will want to build module by we don't want to build LLVM plugin
# LLVM will set proper CMAKE_MODULE_LINKER_FLAGS
set(CMAKE_SHARED_LINKER_FLAGS ${CMAKE_MODULE_LINKER_FLAGS})

include_directories(${LLVM_INCLUDE_DIRS})
include_directories(${MLIR_INCLUDE_DIRS})
add_subdirectory(MLIR)
