# $Id$

ROOTDIR=../..
include ${ROOTDIR}/Makefile.path

SHLIB=		jives.so
SRCS+=		jives.c
SRCS+=		${PFL_BASE}/fuse.c

#MODULES+=	pfl

include ${PFLMK}
