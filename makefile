CC = gcc
CFLAGS = -g -Wall
OBJECTS = main.o poli.o

all: main

main: $(OBJECTS) poli.h
	$(CC) $(CFLAGS) $(OBJECTS) -o main

main.o: poli.h

poli.o: poli.h

clean:
	rm -f main main.o poli.o