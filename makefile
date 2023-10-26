### Awesome Makefile ### ~ eylon & oriya


### SETTINGS ###

# Name of main directories
SRC_DIR := src
BIN_DIR := bin
INCLUDE_DIR := $(SRC_DIR)/include

SRCS := $(shell find $(SRC_DIR) -name '*.c')
OBJS := $(patsubst $(SRC_DIR)/%.c, $(BIN_DIR)/%.o, $(SRCS))

# The name of the executable program
EXECUTABLE := $(BIN_DIR)/shell_todo.elf

# Compiler settings
CC     := gcc
CFLAGS := -I$(INCLUDE_DIR) -Wall -Wextra -g 


### COMPILE ###
all: $(EXECUTABLE)

# Compile the objects
$(BIN_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p ${shell dirname $@}
	${CC} ${CFLAGS} -c -o $@ $<

# Link objects into an executable
$(EXECUTABLE): $(OBJS)
	${CC} ${CFLAGS} -o $@ $^

### UTILS ###
run:
	$(EXECUTABLE)

clean:
	rm -rf $(BIN_DIR)

.PHONY: clean run
