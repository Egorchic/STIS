CC = gcc
CFLAGS = -Wall -Wextra -Iinclude

TARGET = program

all: $(TARGET)

$(TARGET): main.o concept.o instance.o
	$(CC) $^ -o $@

main.o: main.c include/instance.h include/concept.h
	$(CC) $(CFLAGS) -c main.c -o main.o

concept.o: src/concept.c include/concept.h
	$(CC) $(CFLAGS) -c src/concept.c -o concept.o

instance.o: src/instance.c include/instance.h include/concept.h
	$(CC) $(CFLAGS) -c src/instance.c -o instance.o

clean:
	rm -f $(TARGET) *.o

.PHONY: all clean