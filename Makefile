CC=gcc
RM=rm
INSTALL=install
DEST=/usr/local
LDFLAGS+=libvec/libvec.a
CPPFLAGS+=-I. -Ilibvec
C_SOURCES=$(wildcard *.c)
OBJ=$(C_SOURCES:.c=.o)

.PHONY:	all libvec/libvec.a install clean clean-subdirs html

all:	jpp

libvec/libvec.a:
	$(MAKE) -C libvec libvec.a

jpp:	libvec/libvec.a $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

install:
	$(INSTALL) jpp $(DEST)/bin

clean:	clean-subdirs
	$(RM) -f *.o
	$(RM) -f *.exe

clean-subdirs:
	$(MAKE) -C libvec clean

# Doxygen documentation generation
html:
	doxygen .

# Test the preprocessor
test:
	sh test.sh
