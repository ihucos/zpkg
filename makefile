PLASH_LIB=../plash/opt/plash/lib/c
CC=musl-gcc
CFLAGS=-static -I$(PLASH_LIB)

all: run

run: run.c
	$(CC) $(CFLAGS) -o run run.c $(PLASH_LIB)/plash.c

clean:
	rm run
