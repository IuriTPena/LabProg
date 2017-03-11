CC = gcc
CFLAGS = -g -Wall
OBJECTS = man.o poli.o

all: man

man: $(OBJECTS) poli.h
	$(CC) $(CFLAGS) $(OBJECTS) -o man

man.o: poli.h

poli.o: poli.h

clean:
	rm -f man man.o poli.o