CC = gcc
CFLAGS = -Wall -Wextra -Iinclude

TARGET = program

all: $(TARGET)

$(TARGET): main.o concept.o
	$(CC) $^ -o $@

main.o: main.c include/concept.h
	$(CC) $(CFLAGS) -c main.c -o main.o

concept.o: src/concept.c include/concept.h
	$(CC) $(CFLAGS) -c src/concept.c -o concept.o

clean:
	rm -f $(TARGET) *.o

.PHONY: all clean