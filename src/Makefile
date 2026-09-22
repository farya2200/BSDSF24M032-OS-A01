CC = gcc
CFLAGS = -Wall -Wextra -I../include

SRC = main.c mystrfunctions.c myfilefunctions.c
OBJ = $(SRC:.c=.o)

all: $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
