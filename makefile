# Makefile

PROJECT_DIR := .
BUILD_DIR   := build

# Default target
all: build run

build:
	@mkdir -p $(BUILD_DIR)
	@cmake -S $(PROJECT_DIR) -B $(BUILD_DIR)
	@cmake --build $(BUILD_DIR)

run:
	@clear
	@$(PROJECT_DIR)/bin/ttsh

clean:
	@rm -rf $(BUILD_DIR)
	@rm -rf $(PROJECT_DIR)/bin

.PHONY: all build run clean

