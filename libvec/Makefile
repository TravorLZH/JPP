CC=gcc
RM=rm
AR=ar

all:	libvec.a

libvec.a:	vector.o
	$(AR) -rc $@ $^

%.o:	%.c
	$(CC) -c $< -o $@

clean:
	$(RM) -f *.a
	$(RM) -f *.o

### Dependencies
vector.o:	vector.c vector.h
