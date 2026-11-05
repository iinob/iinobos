#define VGABUF 0xb8000
#define HEIGHT 80
#define WIDTH 80 // default for qemu. probably shouldn't be hardcoded but it is so suck it. // coming back later and reading the comments I wrote at 3 am is fun
#define NMI_disable_bit 1

#include "io.h"
#include "shell.h"

int initTime;
int prevTime;
int uptime = 0;

void main() {
	initTime = getSecond();
	prevTime = initTime;

	print("kernel loaded!", 0, 0);
	//shout("testicle");
	//outb (0x70, (NMI_disable_bit << 7) | (0x00)); // set cmos (port 0x70) register to seconds (register 0x00)
	printSquare(6,6,11,4);
	print("Welcome to", 7, 7);
	print("iinob OS!", 7, 9);
	//unsigned char rawSecond = inb(0x71); // read data from port 0x71 (cmos register value)
	//unsigned int second = ((rawSecond >> 4) * 10) + (rawSecond & 0x0F);
	/*while (1) {
		if (getSecond() != prevTime) {
			uptime += 1;
			prevTime = getSecond();
		}
		if (uptime > 5) {
			clear();
			break;
		}
		//printNum(getSecond(), 0, 2); // cast to char and print probably hopefully
	}*/
	clear();
	while (1) {
		shout("love the balls!");
	}
	return;
}
