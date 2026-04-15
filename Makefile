# DccX 编译器 Makefile

CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -O2
LDFLAGS = 
TARGET = dccx
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

SRCS = $(SRC_DIR)/main.c $(SRC_DIR)/lexer.c $(SRC_DIR)/ai_assistant.c
OBJS = $(OBJ_DIR)/main.o $(OBJ_DIR)/lexer.o $(OBJ_DIR)/ai_assistant.o

all: $(TARGET)

$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(BIN_DIR)/$(TARGET)

$(OBJ_DIR)/main.o: $(SRC_DIR)/main.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $(SRC_DIR)/main.c -o $(OBJ_DIR)/main.o

$(OBJ_DIR)/lexer.o: $(SRC_DIR)/lexer.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $(SRC_DIR)/lexer.c -o $(OBJ_DIR)/lexer.o

$(OBJ_DIR)/ai_assistant.o: $(SRC_DIR)/ai_assistant.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $(SRC_DIR)/ai_assistant.c -o $(OBJ_DIR)/ai_assistant.o

test:
	$(BIN_DIR)/$(TARGET) test/test_lexer.dvx
	$(BIN_DIR)/$(TARGET) test/test_ai.dvx

ai:
	$(BIN_DIR)/$(TARGET) -ai test/test_ai.dvx

lexer-test:
	$(BIN_DIR)/$(TARGET) lexer.c

install:
	cp $(BIN_DIR)/$(TARGET) /usr/local/bin/

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

clean-all:
	rm -rf $(OBJ_DIR) $(BIN_DIR) *.o $(TARGET)

distclean:
	rm -rf $(OBJ_DIR) $(BIN_DIR) $(TARGET) *.o *.log *.cache

.PHONY: all test ai lexer-test install clean clean-all distclean