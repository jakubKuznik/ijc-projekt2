CC = gcc
LD = gcc

CFLAGS = -g -std=c11 -pedantic -Wall -Wextra -lm -O2 
all: tail


tail: tail.o
	gcc $(CFLAGS) tail.o -o tail
tail.o: tail.c tail.h
	gcc $(CFLAGS) -c tail.c -o tail.o

# primes primes-i
##########################################################################
#COPILE WITH MACROS 
#primes: primes.o error.o eratosthenes.o
#	gcc $(CFLAGS) primes.o error.o eratosthenes.o -o primes
#
#primes.o: primes.c primes.h bitset.h
#	gcc $(CFLAGS) -c primes.c -o primes.o
#eratosthenes.o: eratosthenes.c primes.h bitset.h 
#	gcc $(CFLAGS) -c eratosthenes.c -o eratosthenes.o
#
#error.o: error.h error.c
#	gcc $(CFLAGS) -c error.c -o error.o


clean:
	rm *.o main

run: tail 
	./tail

