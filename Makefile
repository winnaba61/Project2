OBJ = main.c
CC = gcc
EXEC = main

all: $(OBJ)
	$(CC) -o $(EXEC) $^

clean:
	rm -rf $(EXEC)
