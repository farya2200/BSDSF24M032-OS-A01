CC = gcc
CFLAGS = -Wall -Wextra -Iinclude

TARGET = bin/client_static
LIB = lib/libmyutils.a

LIB_OBJECTS = obj/mystrfunctions.o obj/myfilefunctions.o
MAIN_OBJECT = obj/main.o

.PHONY: all build library clean

all: build

build: $(TARGET)

library: $(LIB)

$(LIB): $(LIB_OBJECTS)
	ar rcs $(LIB) $(LIB_OBJECTS)

$(TARGET): $(MAIN_OBJECT) $(LIB)
	$(CC) $(CFLAGS) $(MAIN_OBJECT) -Llib -lmyutils -o $(TARGET)

obj/main.o: src/main.c
	$(CC) $(CFLAGS) -c src/main.c -o obj/main.o

obj/mystrfunctions.o: src/mystrfunctions.c
	$(CC) $(CFLAGS) -c src/mystrfunctions.c -o obj/mystrfunctions.o

obj/myfilefunctions.o: src/myfilefunctions.c
	$(CC) $(CFLAGS) -c src/myfilefunctions.c -o obj/myfilefunctions.o

clean:
	rm -f obj/*.o
	rm -f $(LIB)
	rm -f $(TARGET)
