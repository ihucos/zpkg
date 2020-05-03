PLASH_LIB=../plash/lib
CC=musl-gcc
CFLAGS=-static -I$(PLASH_LIB)

all: run

run: src/run.c
	$(CC) $(CFLAGS) -o src/run src/run.c $(PLASH_LIB)/plash.c

clean:
	rm src/run
