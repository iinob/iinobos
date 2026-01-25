# Tools
CC   = /usr/local/i386elfgcc/bin/i386-elf-gcc
LD   = /usr/local/i386elfgcc/bin/i386-elf-ld
NASM = nasm

# Flags
CFLAGS  = -ffreestanding -m32 -g -Wall -Wextra -c
LDFLAGS = -Ttext 0x1000 --oformat binary --entry main

# Objects
C_OBJS   = bin/kernel.o bin/io.o
ASM_OBJS = bin/kernelEntry.o

# Final files
KERNEL_BIN = bin/kernel.bin
OS_BIN     = bin/os.bin

# Default target
all: run

# Ensure bin exists
bin:
	mkdir -p bin

# C compilation
bin/%.o: %.c | bin
	$(CC) $(CFLAGS) $< -o $@

# ASM → object (ELF)
bin/%.o: %.asm | bin
	$(NASM) -f elf32 $< -o $@

# ASM → raw binary (boot + padding)
bin/%.bin: %.asm | bin
	$(NASM) -f bin $< -o $@

# Link kernel
$(KERNEL_BIN): $(ASM_OBJS) $(C_OBJS)
	$(LD) -o $@ $^ $(LDFLAGS)

# Build OS image
$(OS_BIN): bin/boot.bin $(KERNEL_BIN) bin/zero.bin
	cat $^ > $@

# Run in QEMU
run: $(OS_BIN)
	qemu-system-x86_64 -drive format=raw,file=$(OS_BIN)

# Clean
clean:
	rm -f bin/*.o bin/*.bin

