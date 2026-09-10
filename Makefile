# Project settings
TARGET    := CHANGE_ME
CC        := gcc
SRC_DIR   := src
INC_DIR   := include
BUILD_DIR := build
BIN_DIR   := bin

# Compiler/linker flags
CFLAGS  := -Wall -Wextra -std=c99 -I$(INC_DIR) -MMD -MP
LDFLAGS :=
LDLIBS  :=

# Source discovery (recursive, handles subdirectories under src/)
SRCS := $(shell find $(SRC_DIR) -name '*.c')
OBJS := $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

.PHONY: all clean run debug release

all: release

# Build modes
debug: CFLAGS += -g -O0 -DDEBUG
debug: $(BIN_DIR)/$(TARGET)

release: CFLAGS += -O2 -DNDEBUG
release: $(BIN_DIR)/$(TARGET)

# Link
$(BIN_DIR)/$(TARGET): $(OBJS) | $(BIN_DIR)
	$(CC) $(OBJS) -o $@ $(LDFLAGS) $(LDLIBS)

# Compile
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Ensure output dirs exist
$(BIN_DIR):
	@mkdir -p $(BIN_DIR)

run: all
	./$(BIN_DIR)/$(TARGET)

clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)

-include $(DEPS)