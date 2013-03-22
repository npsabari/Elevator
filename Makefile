# Makefile
#Author: npsabari

SH = bash
CFLAGS = -g
LDFLAGS = -lm 
CC = gcc

all: main 

main: main.o elevator.o floor.o person.o 
	$(CC) $(LDFLAGS) $^ -o $@
main.o: ./src/main.c ./headers/elevator.h ./headers/floor.h ./headers/person.h
	$(CC) -c $(CFLAGS) $< -o $@

elevator.o: ./src/elevator.c ./headers/person.h ./headers/elevator.h
	$(CC) -c $(CFLAGS) $< -o $@

floor.o: ./src/floor.c ./headers/person.h ./headers/floor.h
	$(CC) -c $(CFLAGS) $< -o $@

person.o: ./src/person.c ./headers/person.h
	$(CC) -c $(CFLAGS) $< -o $@

.PHONY: clean lint test

clean:
	rm -rf *.o
	rm -rf main 

lint:
	for f in *.c; do echo $$f; splint -standard $$f; done;


