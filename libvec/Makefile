# This Makefile is created for MinGW Make

all:	libvec.a

libvec.a:	vector.o hashset.o
	ar -rc $@ $^

%.o:	%.c
	gcc -c $< -o $@

clean:
	del /f *.a
	del /f *.o

### Dependencies
vector.o:	vector.c vector.h

hashset.o:	hashset.c hashset.h

