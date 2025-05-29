#include <stdio.h>

#define VGABUF 0xb8000
#define HEIGHT 80
#define WIDTH 80 // default for qemu. probably shouldn't be hardcoded but it is so suck it. // coming back later and reading the comments I wrote at 3 am is fun
#include "io.cpp"

extern "C" void main() {
	print("kernel loaded!", 0, 0);
	outb (0x70, (NMI_disable_bit << 7) | (0x00)); // set cmos (port 0x70) register to seconds (register 0x00)
	print("Welcome to", 7, 7);
	print("iinob OS!", 7, 9);
	int second = inb (0x71); // read data from port 0x71 (cmos register value)
	print( (unsigned char) second, 10, 10); // cast to char and print probably hopefully
    return;
}
