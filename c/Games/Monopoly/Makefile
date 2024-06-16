# Awesome Makefile for C and GAS programs # ~ eylon

# Define main directories
SRC_DIR := src
BIN_DIR := bin
INC_DIR := include

# Find C and GAS sources and object files
SRCS := $(shell find $(SRC_DIR) -name '*.c' -or -name '*.S')
OBJS := $(patsubst $(SRC_DIR)/%, $(BIN_DIR)/%.o, $(SRCS))

# Define compiler setting
CC      := gcc
CFLAGS  := -I$(INC_DIR) -g -Wall -Wextra
BIN_OUT := $(BIN_DIR)/Program.elf


_all: $(BIN_OUT)

# Compile source files to objects
$(BIN_DIR)/%.o: $(SRC_DIR)/%
	mkdir -p ${shell dirname $@}
	gcc ${CFLAGS} -c -o $@ $<

# Link objects to create final image
$(BIN_OUT): $(OBJS)
	gcc ${CFLAGS} -o $@ $^


# Clean binary
clean:
	rm -rf $(BIN_DIR)

# Execute program
run: $(BIN_OUT)
	$< ${ARGS}

# Recompile program
re: clean $(BIN_OUT)

# Recompile program and execute
rer: clean run

# Recompile program and execute via a debugger
rerd: clean rund

# Execute program via a debugger
rund: $(BIN_OUT)
	gdb -ex 'layout src' ${GDBF} --args $< ${ARGS}

.PHONY: _all clean run re rer rerd  rund