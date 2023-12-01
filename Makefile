CC = gcc
CFLAGS = -Wall -std=c99 -pedantic
TARGET = tree
SOURCES = tree.c
OBJECTS = $(SOURCES:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(TARGET) $(OBJECTS)

.PHONY: all clean