# Asm x86 mini Makefile

AS         := nasm
ASFLAGS    := -f elf64 -g -F dwarf
ASLD       := ld
ASLDFLAGS  := 
EXECUTABLE := a.out
SRC_DIR    := src
BIN_DIR    := bin

SRCS := $(shell find $(SRC_DIR) -name '*.asm')
OBJS := $(patsubst $(SRC_DIR)/%.asm, $(BIN_DIR)/%.o, $(SRCS)) 

all: $(BIN_DIR)/$(EXECUTABLE)

$(BIN_DIR)/$(EXECUTABLE): $(OBJS)
	${ASLD} ${ASLDFLAGS} -o $@ $^	

$(BIN_DIR)/%.o: $(SRC_DIR)/%.asm
	@mkdir -p ${BIN_DIR}
	${AS} ${ASFLAGS} $^ -o $@
		
run: all
	${BIN_DIR}/${EXECUTABLE}

rund: all
	gdb -x auto/gdbinit ${BIN_DIR}/${EXECUTABLE}

clean:
	rm -rf ${BIN_DIR}

.PHONY: run clean
