LLVM Toolchain Integration Test Suite
#####################################

An agglomeration of integration tests for the `LLVM Toolchain <https://llvm.org/>`_.
Unlike the various existing llvm testing suites, this is meant to be used in an installed
environment to detect packaging issues.

Requirements
------------

The `lit <https://pypi.org/project/lit/>`_ tool is used ro tun the tests and
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
- ``CLANGXX_BINARY``: clang binary to checkth to the clang++ binary to check
- ``LLD_BINARY``: path to the lld binary to check
- ``LLDB_BINARY``: path to the lldb binary to check

Writing new tests
-----------------

Just drop a new file under ``tests/``, using the lit format. Please use the following substitutions and requirements:

Lit substitutions
+++++++++++++++++

    - ``%clang``
    - ``%clangxx``
    - ``%lldb``
    - ``%lld``
    - ``%scan-build``
    - ``%scan-view``

requirements
++++++++++++

    - clang
    - clangxx
    - lldb
    - lld
    - scanbuild
    - scanview

License
-------

See LICENSE.txt
