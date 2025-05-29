#define VGABUF 0xb8000
#define HEIGHT 80
#define WIDTH 80 // default for qemu. probably shouldn't be hardcoded but it is so suck it. // coming back later and reading the comments I wrote at 3 am is fun
#define NMI_disable_bit 1

#include "io.cpp"

extern "C" void main() {
while (true) {
	print("kernel loaded!", 0, 0);
	//outb (0x70, (NMI_disable_bit << 7) | (0x00)); // set cmos (port 0x70) register to seconds (register 0x00)
	printSquare(6,6,11,4);
	print("Welcome to", 7, 7);
	print("iinob OS!", 7, 9);
	//unsigned char rawSecond = inb(0x71); // read data from port 0x71 (cmos register value)
	//unsigned int second = ((rawSecond >> 4) * 10) + (rawSecond & 0x0F);
	printNum(getSecond(), 0, 2); // cast to char and print probably hopefully
}
	return;
}
