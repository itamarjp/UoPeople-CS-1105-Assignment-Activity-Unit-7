# Makefile for CS-1105 Unit 7 Assignment
# Compiles the array operations program

CC = gcc
CFLAGS = -Wall -Wextra -std=c99
TARGET = array_operations
SOURCE = array_operations.c

all: $(TARGET)

$(TARGET): $(SOURCE)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCE)

clean:
	rm -f $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run
