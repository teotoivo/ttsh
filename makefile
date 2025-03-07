PROJECT_DIR := .
BUILD_DIR   := build

# Default target
all: build run

build:
	@mkdir -p $(BUILD_DIR)
	@cmake -S $(PROJECT_DIR) -B $(BUILD_DIR)
	@cmake --build $(BUILD_DIR)
	@if [ -f $(BUILD_DIR)/compile_commands.json ]; then \
		cp $(BUILD_DIR)/compile_commands.json $(PROJECT_DIR)/compile_commands.json; \
		echo "Copied compile_commands.json to project root."; \
	else \
		echo "compile_commands.json not found in build directory."; \
	fi

run:
	@clear
	@$(PROJECT_DIR)/bin/ttsh

clean:
	@rm -rf $(BUILD_DIR)
	@rm -rf $(PROJECT_DIR)/bin
	@rm -f $(PROJECT_DIR)/compile_commands.json

.PHONY: all build run clean

