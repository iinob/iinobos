/usr/local/i386elfgcc/bin/i386-elf-gcc -ffreestanding -m32 -g -c "kernel.cpp" -o "./bin/kernel.o"
/usr/local/i386elfgcc/bin/i386-elf-ld -o "./bin/kernel.bin" -Ttext 0x1000 "./bin/kernelEntry.o" "./bin/kernel.o" --oformat binary
cat "./bin/boot.bin" "./bin/kernel.bin" > ./bin/osMin.bin
cat "./bin/osMin.bin" "./bin/zero.bin" > ./bin/os.bin
qemu-system-x86_64 -drive format=raw,file=./bin/os.bin
