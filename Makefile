# This Makefile is used by MinGW Make in Windows, UNIX Makefiles haven't been
# created yet.

SHELL=cmd.exe
CC=gcc
LDFLAGS+=libvec/libvec.a
CPPFLAGS+=-I. -Ilibvec
C_SOURCES=$(wildcard *.c)
OBJ=$(C_SOURCES:.c=.o)

.PHONY:	all libvec/libvec.a clean clean-subdirs html

all:	jpp.exe

libvec/libvec.a:
	$(MAKE) -C libvec libvec.a

# JPP - Java PreProcessor
jpp.exe:	libvec/libvec.a $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

clean:	clean-subdirs
	del /f *.o
	del /f *.exe

clean-subdirs:
	$(MAKE) -C libvec clean

# Doxygen documentation generation
html:
	doxygen .

# Test the preprocessor
test:
	test.bat
