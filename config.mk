PREFIX  = /usr/local
BINDIR  = ${PREFIX}/bin
MANPREFIX = ${PREFIX}/share/man

AR      ?= ar
CC      ?= cc
RANLIB  ?= ranlib
RM      ?= rm -f
YACC    ?= yacc


# You can uncomment the latter if you aren't using libtls-bearssl. If you
# aren't linking statically, '-ltls' should be suffice.
TLSLIB = -ltls -lbearssl
#TLSLIB    = `pkgconf --static --libs libtls`

# You can replace the following to 'lib/libz/libz.a' in order to build with the
# in-source zlib.
ZLIB      = -lz

# If fts is available on your system, we need to disable building it here.
# Change with 1 if you are using musl-fts, 2 if you are using glibc.
FTS=0

CFLAGS  += -Wall -Wno-pointer-sign -Wno-maybe-uninitialized \
	  -Wno-attributes -I${PWD}/includedir \
	  -D 'DEF_WEAK(n)=_Static_assert(1, "")' \
	  -idirafter ${PWD}/include \
	  -idirafter ${PWD}/sys \
	  -idirafter ${PWD}/lib/libutil \
	  -idirafter ${PWD}/lib/libcrypto

# If you are using a less implementation with tags support, uncomment
# the following.
# CFLAGS += -DHAVE_LESS_T
