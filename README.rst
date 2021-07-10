LLVM Toolchain Integration Test Suite
#####################################

An agglomeration of integration tests for the `LLVM Toolchain <https://llvm.org/>`_.
Unlike the various existing llvm testing suites, this is meant to be used in an installed
environment to detect packaging issues.

This is an initiative started by Debian/Ubuntu and Fedora maintainers to agregate the testing effort.
Hopefully, this project will be also a forcing function to bring more consistency in the LLVM
toolchain packaging.

Requirements
------------

The `lit <https://pypi.org/project/lit/>`_ tool is used to run the tests and
`cmake <https://cmake.org/>`_ is used for the configuration step.

Usage
-----

From source directory:

.. code-block:: sh

    > mkdir _build && cd _build
    > cmake ..
    > make check

Sensible configuration variables
--------------------------------

- ``LIT``: path to the lit program

- ``CLANG_BINARY``: path to the clang binary to check
- ``CLANGXX_BINARY``: path to the clang++ binary to check
- ``CLANG_TIDY_BINARY``: path to the clang tidy binary to check
- ``LLD_BINARY``: path to the lld binary to check
- ``LLDB_BINARY``: path to the lldb binary to check

- ``ENABLE_COMPILER_RT``: ON (the default) if we assume compiler-rt is available
- ``ENABLE_LIBCXX``: ON (the default) if we assume libc++ is available

Writing new tests
-----------------

Just drop a new file under ``tests/``, using the lit format. Please use the following substitutions and requirements:

Lit substitutions
+++++++++++++++++

    - ``%clang``
    - ``%clangxx``
    - ``%clang-tidy``
    - ``%lldb``
    - ``%lld``
    - ``%scan-build``
    - ``%scan-view``
    - ``%scan-build-py``

requirements
++++++++++++

    - clang
    - clangxx
    - clang-tidy
    - lldb
    - lld
    - scanbuild
    - scanbuild-py
    - scanview

License
-------

See LICENSE.txt
