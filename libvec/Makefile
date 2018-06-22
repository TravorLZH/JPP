# This Makefile is created for MinGW Make

all:	libvec.a

libvec.a:	vector.o
	ar -rc $@ $^

%.o:	%.c
	gcc -c $< -o $@

clean:
	del /f *.a
	del /f *.o

### Dependencies
vector.o:	vector.c vector.h
