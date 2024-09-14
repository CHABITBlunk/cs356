CC = gcc
CFLAGS = -Wall -Wextra -O2

SRC = main.c

EXEC = cipher

all: $(EXEC)

$(EXEC): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(EXEC)

clean:
	rm -rf $(EXEC)
