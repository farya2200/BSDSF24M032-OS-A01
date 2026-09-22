CC = gcc
CFLAGS = -Wall -Wextra

TARGET = bin/client
OBJECTS = src/main.o src/mystrfunctions.o src/myfilefunctions.o

.PHONY: all build clean

all: build

build:
	$(MAKE) -C src
	$(CC) $(CFLAGS) $(OBJECTS) -o $(TARGET)

clean:
	$(MAKE) -C src clean
	rm -f $(TARGET)
