nasm -f bin boot.asm -o ./bin/boot.bin
nasm -f bin zero.asm -o ./bin/zero.bin
nasm -f elf32 kernelEntry.asm -o ./bin/kernelEntry.o