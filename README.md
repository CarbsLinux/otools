otools
======

Some OpenBSD-6.8 userland utilities meant to be included in Carbs Linux base.

Currently includes the following software:
- diff
- doas
- ed
- grep
- m4
- mandoc
- md5
- nc
- patch
- pax
- signify

The build system is configured by running the `configure` script at the root of
the directory. You can build software individually by calling `make <program>`,
and the program will be built to the root directory of the source.


requirements
------------

In order to build `nc`, you need to have a `libtls` implementation. Carbs Linux
uses `libressl` by default.

