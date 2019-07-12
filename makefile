BCHROOT_LIB=../bchroot/lib
CC=musl-gcc
CFLAGS=-static -I$(BCHROOT_LIB)

all: run

run: run.c
	$(CC) $(CFLAGS) -o run run.c $(BCHROOT_LIB)/brtlib.c

clean:
	rm run
