CC = gcc
CFLAGS = -I./head `sdl2-config --cflags` -lm
LDFLAGS = `sdl2-config --libs`
SRC = $(wildcard src/*.c)
OBJ = $(SRC:.c=.o)
BIN = bin/game

all: $(BIN)

$(BIN): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(BIN) $(LDFLAGS)

clean:
	rm -f $(BIN)

