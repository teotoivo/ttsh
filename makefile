# Compiler and flags
CC      := clang
CFLAGS  := -g -Wall -Wextra -pedantic -D_GNU_SOURCE -std=c23 -Iinclude -Wno-gnu-zero-variadic-macro-arguments
LDFLAGS :=

# Directories and target name
SRC_DIR := src
OBJ_DIR := obj
BIN_DIR := bin
TARGET  := ttsh

# libraries
LIB_DIR := libs
LIB_SRC   := $(shell find $(LIB_DIR) -type f -name '*.c')
LIB_OBJ   := $(patsubst $(LIB_DIR)/%.c, $(OBJ_DIR)/$(LIB_DIR)/%.o, $(LIB_SRC))
CFLAGS += -Ilibs/linenoise


# Source and object files
SRC := $(shell find $(SRC_DIR) -type f -name '*.c')
OBJ := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

# Default target: build and run
.PHONY: all
all: $(BIN_DIR)/$(TARGET)
	./$(BIN_DIR)/$(TARGET) $(ARGS)

# Build target (compiles without running)
.PHONY: build
build: $(BIN_DIR)/$(TARGET)

# Link: combine object files into the final executable
$(BIN_DIR)/$(TARGET): $(OBJ) $(LIB_OBJ)
	@mkdir -p $(BIN_DIR)
	$(CC) $(LDFLAGS) -o $@ $^

# Compile: create object files from source files and generate dependencies
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c -o $@ $< -MMD -MP

# Compile library source files from LIB_DIR
$(OBJ_DIR)/$(LIB_DIR)/%.o: $(LIB_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c -o $@ $< -MMD -MP

# Include automatically generated dependency files
-include $(OBJ:.o=.d)
-include $(LIB_OBJ:.o=.d)

# Run: execute the built target
.PHONY: run
run: $(BIN_DIR)/$(TARGET)
	./$(BIN_DIR)/$(TARGET) $(ARGS)

# Install: copy the executable to DESTDIR/bin (use DESTDIR when needed)
.PHONY: install
install: $(BIN_DIR)/$(TARGET)
	install -d $(DESTDIR)/bin
	install $(BIN_DIR)/$(TARGET) $(DESTDIR)/bin

# Clean: remove build artifacts
.PHONY: clean
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

