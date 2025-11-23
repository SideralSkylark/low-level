CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11
BUILD = build
SRC = src

all: $(BUILD)/fileinfo

$(BUILD)/fileinfo: $(SRC)/main.o $(SRC)/fileinfo.o
	mkdir -p $(BUILD)
	$(CC) $(CFLAGS) $^ -o $@

$(SRC)/main.o: $(SRC)/main.c $(SRC)/fileinfo.h
	$(CC) $(CFLAGS) -c $< -o $@

$(SRC)/fileinfo.o: $(SRC)/fileinfo.c $(SRC)/fileinfo.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD) $(SRC)/*.o

.PHONY: all clean
