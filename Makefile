CC   = /usr/local/i386elfgcc/bin/i386-elf-gcc
LD   = /usr/local/i386elfgcc/bin/i386-elf-ld
NASM = nasm

CFLAGS  = -ffreestanding -m32 -g -Wall -Wextra -c
LDFLAGS = -Ttext 0x1000 --oformat binary --entry main

C_OBJS   = bin/kernel.o bin/io.o
ASM_OBJS = bin/kernelEntry.o

KERNEL_BIN = bin/kernel.bin
OS_BIN     = bin/os.bin

all: run

bin:
	mkdir -p bin

bin/%.o: %.c | bin
	$(CC) $(CFLAGS) $< -o $@

bin/%.o: %.asm | bin
	$(NASM) -f elf32 $< -o $@

bin/%.bin: %.asm | bin
	$(NASM) -f bin $< -o $@

$(KERNEL_BIN): $(ASM_OBJS) $(C_OBJS)
	$(LD) -o $@ $^ $(LDFLAGS)

$(OS_BIN): bin/boot.bin $(KERNEL_BIN) bin/zero.bin
	cat $^ > $@

run: $(OS_BIN)
	qemu-system-x86_64 -drive format=raw,file=$(OS_BIN)

clean:
	rm -f bin/*.o bin/*.bin

