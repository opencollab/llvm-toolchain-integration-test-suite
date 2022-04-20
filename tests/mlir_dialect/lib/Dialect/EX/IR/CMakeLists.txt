add_mlir_dialect_library(MLIREX
        EXDialect.cpp
        EXOps.cpp

        ADDITIONAL_HEADER_DIRS
        ${PROJECT_SOURCE_DIR}/csrc/include

        DEPENDS
        MLIREXOpsIncGen

	LINK_LIBS PUBLIC
	MLIRIR
	)
