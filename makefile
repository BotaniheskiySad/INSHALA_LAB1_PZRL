CC = gcc
CFLAGS = -O3 -g
TARGET = main
SOURCES = main.c func.c
OBJECTS = $(SOURCES:.c=.o)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

main.o: main.c
	gcc -c main.c
calc.o: func.c
	gcc -c func.c
clean:
	rm -f $(OBJECTS) $(TARGET)

run: $(TARGET)
	./$(TARGET) 41 + 33 111 - 8 22 '*' 5 221 % 111 100 + 13 -k 2

.PHONY: clean run

