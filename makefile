CC = gcc
CFLAGS = -g -Wall
OBJECTS = main.o poli.o operations.o

all: main

main: $(OBJECTS) poli.h
	$(CC) $(CFLAGS) $(OBJECTS) -o main

main.o: poli.h operations.h

poli.o: poli.h operations.h

operations.o: poli.h operations.h

clean:
	rm -f main main.o poli.o operations.o