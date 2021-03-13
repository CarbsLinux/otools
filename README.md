otools
======

Some OpenBSD-6.8 userland utilities meant to be included in Carbs Linux base.

Currently includes the following software:
- diff
- doas
- m4
- mandoc
- md5
- nc
- patch
- pax
- signify

You can build software individually by calling `make <program>`, and the
program will be built to the root directory of the source. The build system is
configured through `config.mk`


requirements
------------

In order to build `mandoc`, you need to either have zlib installed, or edit
`config.mk` to use the in-source `zlib`.

In order to build `nc`, you need to have a `libtls` implementation. Carbs Linux
uses `libtls-bearssl` by default.


patch directory
---------------

The patch directory doesn't serve any function but to keep track of the applied
patches under revision control. The sources here are already patched.

