CC=gcc
CFLAGS=-std=c99 -Wall -pedantic -g3

all: turing

myDeque.o: myDeque.c

turing.o: turing.c 

turing: turing.o myDeque.o
	$(CC) $(CFLAGS) -o $@ $^	


clean:
	$(RM) turing *.o