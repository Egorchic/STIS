CC = gcc
CFLAGS = -Wall -Wextra -Iinclude

TARGET = program

all: $(TARGET)

$(TARGET): main.o concept.o instance.o possible_world.o
	$(CC) $^ -o $@

main.o: main.c include/possible_world.h include/instance.h include/concept.h
	$(CC) $(CFLAGS) -c main.c -o main.o

concept.o: src/concept.c include/concept.h
	$(CC) $(CFLAGS) -c src/concept.c -o concept.o

instance.o: src/instance.c include/instance.h include/concept.h
	$(CC) $(CFLAGS) -c src/instance.c -o instance.o

possible_world.o: src/possible_world.c include/possible_world.h include/instance.h include/concept.h
	$(CC) $(CFLAGS) -c src/possible_world.c -o possible_world.o

clean:
	rm -f $(TARGET) *.o

.PHONY: all clean