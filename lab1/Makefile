CC = gcc
CFLAGS = -Wall -Wextra -Iinclude

TARGET = program

all: $(TARGET)

$(TARGET): main.o concept.o instance.o possible_world.o kripke_scale.o frame.o
	$(CC) $^ -o $@

main.o: main.c include/frame.h include/kripke_scale.h include/possible_world.h include/instance.h include/concept.h
	$(CC) $(CFLAGS) -c main.c -o main.o

concept.o: src/concept.c include/concept.h
	$(CC) $(CFLAGS) -c src/concept.c -o concept.o

instance.o: src/instance.c include/instance.h include/concept.h
	$(CC) $(CFLAGS) -c src/instance.c -o instance.o

possible_world.o: src/possible_world.c include/possible_world.h include/instance.h include/concept.h
	$(CC) $(CFLAGS) -c src/possible_world.c -o possible_world.o

kripke_scale.o: src/kripke_scale.c include/kripke_scale.h include/possible_world.h include/instance.h include/concept.h
	$(CC) $(CFLAGS) -c src/kripke_scale.c -o kripke_scale.o

frame.o: src/frame.c include/frame.h include/concept.h
	$(CC) $(CFLAGS) -c src/frame.c -o frame.o

clean:
	rm -f $(TARGET) *.o

.PHONY: all clean