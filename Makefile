include config.mk
BIN    = \
	 diff \
	 doas \
	 m4 \
	 mandoc \
	 md5 \
	 nc \
	 patch \
	 pax \
	 signify

LIB    = lib/libbsd.a
LIBOBJ = \
	 lib/libc/crypt/arc4random.o \
	 lib/libc/crypt/arc4random_uniform.o \
	 lib/libc/crypt/blowfish.o \
	 lib/libc/gen/fts.o \
	 lib/libc/gen/getprogname.o \
	 lib/libc/gen/pwcache.o \
	 lib/libc/gen/readpassphrase.o \
	 lib/libc/gen/setprogname.o \
	 lib/libc/gen/unvis.o \
	 lib/libc/gen/vis.o \
	 lib/libc/gen/vwarnc.o \
	 lib/libc/gen/warnc.o \
	 lib/libc/hash/md5.o \
	 lib/libc/hash/md5hl.o \
	 lib/libc/hash/rmd160.o \
	 lib/libc/hash/rmd160hl.o \
	 lib/libc/hash/sha1.o \
	 lib/libc/hash/sha2.o \
	 lib/libc/hash/sha1hl.o \
	 lib/libc/hash/sha224hl.o \
	 lib/libc/hash/sha256hl.o \
	 lib/libc/hash/sha384hl.o \
	 lib/libc/hash/sha512_256hl.o \
	 lib/libc/hash/sha512hl.o \
	 lib/libc/net/base64.o \
	 lib/libc/stdlib/freezero.o \
	 lib/libc/stdlib/reallocarray.o \
	 lib/libc/stdlib/recallocarray.o \
	 lib/libc/stdlib/strtonum.o \
	 lib/libc/string/strmode.o \
	 lib/libc/string/timingsafe_bcmp.o \
	 lib/libc/string/timingsafe_memcmp.o \
	 lib/libutil/bcrypt_pbkdf.o \
	 lib/libutil/ohash.o \
	 lib/libutil/pidfile.o


MAN = \
	usr.bin/diff/diff.1 \
	usr.bin/doas/doas.1 \
	usr.bin/doas/doas.conf.5 \
	usr.bin/mandoc/apropos.1 \
	usr.bin/mandoc/makewhatis.8 \
	usr.bin/mandoc/man.1 \
	usr.bin/mandoc/man.conf.5 \
	usr.bin/mandoc/mandoc.1 \
	usr.bin/m4/m4.1 \
	usr.bin/nc/nc.1 \
	usr.bin/patch/patch.1 \
	bin/md5/md5.1 \
	bin/md5/cksum.1 \
	bin/pax/cpio.1 \
	bin/pax/pax.1 \
	bin/pax/tar.1 \
	usr.bin/signify/signify.1

.y.c:
	${YACC} -o $@ $<
.c.o:
	${CC} ${CFLAGS} -c -o $@ $<

.o: ${LIB}

all: ${BIN}
${BINOBJ}: ${LIB}

# ------------------------------------------------------------------------------
# diff
DIFFOBJ = \
	  usr.bin/diff/diff.o \
	  usr.bin/diff/diffdir.o \
	  usr.bin/diff/diffreg.o \
	  usr.bin/diff/xmalloc.o
BINOBJ += ${DIFFOBJ}
diff: ${DIFFOBJ} ${LIB}
	${CC} ${LDFLAGS} -o $@ ${DIFFOBJ} ${LIB}

# ------------------------------------------------------------------------------
# doas
DOASOBJ = \
	  usr.bin/doas/parse.o \
	  usr.bin/doas/doas.o \
	  usr.bin/doas/env.o \
	  usr.bin/doas/persist.o

BINOBJ += ${DOASOBJ} parse.c
${DOASOBJ}: usr.bin/doas/parse.tab.h
usr.bin/doas/parse.c usr.bin/doas/parse.tab.h: usr.bin/doas/parse.y
	${YACC} -o usr.bin/doas/parse.c -dH usr.bin/doas/parse.tab.h $<
usr.bin/doas/env.o: usr.bin/doas/env.c
	${CC} ${CFLAGS} -include sys/sys/tree.h -c -o $@ $<
doas: ${DOASOBJ} ${LIB}
	${CC} ${LDFLAGS} -o $@ ${DOASOBJ} ${LIB}


# ------------------------------------------------------------------------------
# m4
M4OBJ = \
	usr.bin/m4/eval.o \
	usr.bin/m4/expr.o \
	usr.bin/m4/look.o \
	usr.bin/m4/main.o \
	usr.bin/m4/misc.o \
	usr.bin/m4/gnum4.o \
	usr.bin/m4/trace.o \
	usr.bin/m4/tokenizer.o \
	usr.bin/m4/parser.o
BINOBJ += ${M4OBJ} parser.c

usr.bin/m4/parser.c usr.bin/m4/parser.tab.h: usr.bin/m4/parser.y
	${YACC} -o usr.bin/m4/parser.c -dH usr.bin/m4/parser.tab.h $<
usr.bin/m4/tokenizer.o: usr.bin/m4/tokenizer.c usr.bin/m4/parser.tab.h
	${CC} ${CFLAGS} -I${PWD}/usr.bin/m4 -include usr.bin/m4/parser.tab.h \
		-c -o $@ usr.bin/m4/tokenizer.c

m4: ${M4OBJ} ${LIB}
	${CC} ${LDFLAGS} -o $@ ${M4OBJ} ${LIB}

# ------------------------------------------------------------------------------
# mandoc
MANDOCLINK = makewhatis whatis apropos man
MANDOCOBJ = \
	    usr.bin/mandoc/arch.o \
	    usr.bin/mandoc/att.o \
	    usr.bin/mandoc/chars.o \
	    usr.bin/mandoc/dba.o \
	    usr.bin/mandoc/dba_array.o \
	    usr.bin/mandoc/dba_read.o \
	    usr.bin/mandoc/dba_write.o \
	    usr.bin/mandoc/dbm.o \
	    usr.bin/mandoc/dbm_map.o \
	    usr.bin/mandoc/eqn.o \
	    usr.bin/mandoc/eqn_html.o \
	    usr.bin/mandoc/eqn_term.o \
	    usr.bin/mandoc/html.o \
	    usr.bin/mandoc/main.o \
	    usr.bin/mandoc/man.o \
	    usr.bin/mandoc/man_html.o \
	    usr.bin/mandoc/man_macro.o \
	    usr.bin/mandoc/man_term.o \
	    usr.bin/mandoc/man_validate.o \
	    usr.bin/mandoc/mandoc.o \
	    usr.bin/mandoc/mandoc_aux.o \
	    usr.bin/mandoc/mandoc_msg.o \
	    usr.bin/mandoc/mandoc_ohash.o \
	    usr.bin/mandoc/mandoc_xr.o \
	    usr.bin/mandoc/mandocdb.o \
	    usr.bin/mandoc/manpath.o \
	    usr.bin/mandoc/mansearch.o \
	    usr.bin/mandoc/mdoc.o \
	    usr.bin/mandoc/mdoc_argv.o \
	    usr.bin/mandoc/mdoc_html.o \
	    usr.bin/mandoc/mdoc_macro.o \
	    usr.bin/mandoc/mdoc_man.o \
	    usr.bin/mandoc/mdoc_markdown.o \
	    usr.bin/mandoc/mdoc_state.o \
	    usr.bin/mandoc/mdoc_term.o \
	    usr.bin/mandoc/mdoc_validate.o \
	    usr.bin/mandoc/msec.o \
	    usr.bin/mandoc/out.o \
	    usr.bin/mandoc/preconv.o \
	    usr.bin/mandoc/read.o \
	    usr.bin/mandoc/roff.o \
	    usr.bin/mandoc/roff_html.o \
	    usr.bin/mandoc/roff_term.o \
	    usr.bin/mandoc/roff_validate.o \
	    usr.bin/mandoc/st.o \
	    usr.bin/mandoc/tag.o \
	    usr.bin/mandoc/tbl.o \
	    usr.bin/mandoc/tbl_data.o \
	    usr.bin/mandoc/tbl_html.o \
	    usr.bin/mandoc/tbl_layout.o \
	    usr.bin/mandoc/tbl_opts.o \
	    usr.bin/mandoc/tbl_term.o \
	    usr.bin/mandoc/term.o \
	    usr.bin/mandoc/term_ascii.o \
	    usr.bin/mandoc/term_ps.o \
	    usr.bin/mandoc/term_tab.o \
	    usr.bin/mandoc/term_tag.o \
	    usr.bin/mandoc/tree.o
BINOBJ += ${MANDOCOBJ}
mandoc: ${MANDOCOBJ} ${LIB}
	${CC} ${LDFLAGS} -o $@ ${MANDOCOBJ} ${LIB} ${ZLIB}

# ------------------------------------------------------------------------------
#  md5
MD5LINK = sha1 sha224 sha256 sha384 sha512 rmd160 cksum
MD5MAN  = sha1.1 sha224.1 sha256.1 sha384.1 sha512.1 rmd160.1
MD5OBJ = \
	 bin/md5/crc.o \
	 bin/md5/md5.o
BINOBJ += ${MD5OBJ}
md5: ${MD5OBJ} ${LIB}
	${CC} ${LDFLAGS} -o $@ ${MD5OBJ} ${LIB}

# ------------------------------------------------------------------------------
#  nc
NCOBJ = \
	usr.bin/nc/atomicio.o \
	usr.bin/nc/netcat.o \
	usr.bin/nc/socks.o
BINOBJ += ${NCOBJ}
usr.bin/nc/netcat.o: usr.bin/nc/netcat.c
	${CC} ${CFLAGS} -include /usr/include/tls.h -c -o $@ $<
nc: ${NCOBJ} ${LIB}
	${CC} ${LDFLAGS} -o $@ ${NCOBJ} ${LIB} ${TLSLIB}

# ------------------------------------------------------------------------------
#  pax
PAXOBJ = \
	 bin/pax/ar_io.o \
	 bin/pax/ar_subs.o \
	 bin/pax/buf_subs.o \
	 bin/pax/cpio.o \
	 bin/pax/file_subs.o \
	 bin/pax/ftree.o \
	 bin/pax/gen_subs.o \
	 bin/pax/getoldopt.o \
	 bin/pax/options.o \
	 bin/pax/pat_rep.o \
	 bin/pax/pax.o \
	 bin/pax/sel_subs.o \
	 bin/pax/tables.o \
	 bin/pax/tar.o \
	 bin/pax/tty_subs.o
BINOBJ += ${PAXOBJ}
pax: ${PAXOBJ} ${LIB}
	${CC} ${LDFLAGS} -o $@ ${PAXOBJ} ${LIB}

# ------------------------------------------------------------------------------
# patch
PATCHOBJ = \
	   usr.bin/patch/patch.o \
	   usr.bin/patch/pch.o \
	   usr.bin/patch/inp.o \
	   usr.bin/patch/util.o \
	   usr.bin/patch/backupfile.o \
	   usr.bin/patch/mkpath.o \
	   usr.bin/patch/ed.o
BINOBJ += ${PATCHOBJ}
patch: ${PATCHOBJ} ${LIB}
	${CC} ${LDFLAGS} -o $@ ${PATCHOBJ} ${LIB}

# -----------------------------------------------------------------------------
#  signify
SIGNIFYOBJ = \
	     usr.bin/signify/signify.o \
	     usr.bin/signify/zsig.o \
	     usr.bin/signify/fe25519.o \
	     usr.bin/signify/sc25519.o \
	     usr.bin/signify/mod_ed25519.o \
	     usr.bin/signify/mod_ge25519.o \
	     usr.bin/signify/crypto_api.o
BINOBJ += ${SIGNIFYOBJ}
signify: ${SIGNIFYOBJ} ${LIB}
	${CC} ${LDFLAGS} -o $@ ${SIGNIFYOBJ} ${LIB}

# ------------------------------------------------------------------------------
#  hash helpers
HELPER  = lib/libc/hash/helper.c
HASHOBJ = \
	  lib/libc/hash/md5hl.c \
	  lib/libc/hash/rmd160hl.c \
	  lib/libc/hash/sha1hl.c \
	  lib/libc/hash/sha224hl.c \
	  lib/libc/hash/sha256hl.c \
	  lib/libc/hash/sha384hl.c \
	  lib/libc/hash/sha512hl.c \
	  lib/libc/hash/sha512_256hl.c
BINOBJ += ${HASHOBJ}
${HASHOBJ}: ${HELPER}
lib/libc/hash/md5hl.c:
	sed 's|HASH|MD5|g;s|hashinc|md5.h|' < ${HELPER} > $@
lib/libc/hash/rmd160hl.c:
	sed 's|HASH|RMD160|g;s|hashinc|rmd160.h|' < ${HELPER} > $@
lib/libc/hash/sha1hl.c:
	sed 's|HASH|SHA1|g;s|hashinc|sha1.h|' < ${HELPER} > $@
lib/libc/hash/sha224hl.c:
	sed 's|HASH|SHA224|g;s|hashinc|sha2.h|' < ${HELPER} | sed 's,SHA224_CTX,SHA2_CTX,g' > $@
lib/libc/hash/sha256hl.c:
	sed 's|HASH|SHA256|g;s|hashinc|sha2.h|' < ${HELPER} | sed 's,SHA256_CTX,SHA2_CTX,g' > $@
lib/libc/hash/sha384hl.c:
	sed 's|HASH|SHA384|g;s|hashinc|sha2.h|' < ${HELPER} | sed 's,SHA384_CTX,SHA2_CTX,g' > $@
lib/libc/hash/sha512hl.c:
	sed 's|HASH|SHA512|g;s|hashinc|sha2.h|' < ${HELPER} | sed 's,SHA512_CTX,SHA2_CTX,g' > $@
lib/libc/hash/sha512_256hl.c:
	sed 's|HASH|SHA512_256|g;s|hashinc|sha2.h|' < ${HELPER} | sed 's,SHA512_256_CTX,SHA2_CTX,g' > $@

# ------------------------------------------------------------------------------
#  libz
LIBZOBJ = \
	  lib/libz/adler32.o \
	  lib/libz/compress.o \
	  lib/libz/crc32.o \
	  lib/libz/deflate.o \
	  lib/libz/gzio.o \
	  lib/libz/infback.o \
	  lib/libz/inffast.o \
	  lib/libz/inflate.o \
	  lib/libz/inftrees.o \
	  lib/libz/trees.o \
	  lib/libz/uncompr.o \
	  lib/libz/zutil.o
BINOBJ += ${LIBZOBJ}
lib/libz/libz.a: ${LIBZOBJ}
	${AR} rc $@ $?
	${RANLIB} $@

# ------------------------------------------------------------------------------
#  libbsd

lib/libc/crypt/arc4random.o: lib/libc/crypt/arc4random.c lib/libcrypto/arc4random/arc4random_linux.h
	mkdir -p arc4random
	cp lib/libc/crypt/arc4random.c arc4random
	cp lib/libcrypto/arc4random/arc4random_linux.h arc4random/arc4random.h
	cp lib/libc/crypt/chacha_private.h arc4random
	${CC} ${CFLAGS} -c -o $@ arc4random/arc4random.c
	${RM} -r -- arc4random

lib/libbsd.a: ${LIBOBJ}
	${AR} rc $@ $?
	${RANLIB} $@


getobj:
	@printf '%s\n' ${LIBOBJ}

install:
	mkdir -p ${DESTDIR}${BINDIR}
	for bin in ${BIN}; do \
		cp $${bin} ${DESTDIR}${BINDIR}; \
		chmod 755 ${DESTDIR}${BINDIR}/$${bin##*/}; done
	chmod u+s ${DESTDIR}${BINDIR}/doas
	for bin in ${MANDOCLINK}; do \
		ln -s mandoc ${DESTDIR}${BINDIR}/$${bin}; done
	for bin in ${MD5LINK}; do \
		ln -s md5    ${DESTDIR}${BINDIR}/$${bin}; done
	for man in ${MAN}; do \
		mkdir -p ${DESTDIR}${MANPREFIX}/man$${man##*.}; \
		cp $${man} ${DESTDIR}${MANPREFIX}/man$${man##*.}; \
		chmod 644 ${DESTDIR}${MANPREFIX}/man$${man##*.}/$${man##*/}; done
	for man in ${MD5MAN}; do \
		ln -s md5.1 ${DESTDIR}${MANPREFIX}/man1/$${man}; done

clean:
	${RM} ${LIBOBJ} ${LIB} ${BIN} ${BINOBJ} lib/libz/libz.a

.PHONY: all clean
