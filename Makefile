CC=gcc

CFLAGS=-Wall -Wextra -pedantic -std=c11

%.o: %.c
	$(CC) $(CFLAGS) -c $<

all: hello test

hello: hello.o
	$(CC) -o hello hello.o

test: hello
	./hello

