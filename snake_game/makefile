# Directories
SRC_DIR := src
OBJ_DIR := obj
INCLUDE := include

# Source files and object files
SRCS = $(shell find $(SRC_DIR) -name '*.c')
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

# Binary
EXECUTABLE := $(OBJ_DIR)/snake_game

# Compiler settings
CC = gcc
CFLAGS = -I$(INCLUDE) -Wall -Werror -g
# Add -lncurses to link with the ncurses library
LIBS = -lncurses

# Targets
all: $(EXECUTABLE)

# Link
$(EXECUTABLE): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)  # Include $(LIBS) to link with ncurses

# Compile objects
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(shell dirname $@)
	${CC} ${CFLAGS} -c -o $@ $<

run:
	$(EXECUTABLE)

clean:
	rm -rf ${OBJ_DIR}

.PHONY: clean run
