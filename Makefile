CC = gcc
CFLAGS  = -Wall -Werror

.PHONY: clean

default: bin/chessvizual 

test: bin/test
	bin/test

bin/chessvizual: build/main.o build/board.o build/board_print_plain.o bin
	$(CC) $(CFLAGS) build/main.o build/board_print_plain.o build/board.o -o bin/chessvizual

bin/test: build/maintest.o build/board.o
	$(CC) $(CFLAGS) build/maintest.o build/board.o bin/test

build/main.o: src/main.c src/board.h src/board_print_plain.h build
	$(CC) $(CFLAGS) -c src/main.c -o build/main.o

build/board.o: src/board.c src/board.h build
	$(CC) $(CFLAGS) -c src/board.c -o build/board.o

build/board_print_plain.o: src/board_print_plain.c src/board_print_plain.h build
	$(CC) $(CFLAGS) -c src/board_print_plain.c -o build/board_print_plain.o

build/maintest.o: test/maintest.c
	$(CC) -I thirdparty -I src -c test/maintest.c -o build/maintest.o

build:
	mkdir build

bin:
	mkdir bin

clean:
	rm -rf build bin
