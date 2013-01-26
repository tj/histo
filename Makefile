
SRC = $(wildcard src/*.c)
SRC += $(wildcard deps/*.c)
OBJ = $(SRC:.c=.o)
PREFIX=/usr/local
BIN=histo

histo: $(SRC)
	$(CC) $^ -std=c99 -lm -I deps -o $@

install: $(BIN)
	install $(BIN) $(PREFIX)/bin

uninstall:
	rm $(PREFIX)/bin/$(BIN)

clean:
	rm -f $(BIN) $(OBJ)

.PHONY: clean install uninstall
