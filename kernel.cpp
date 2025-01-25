#define VGABUF 0xb8000
#define HEIGHT 80
#define WIDTH 80 // default for qemu. probably shouldn't be hardcoded but it is so suck it. // coming back later and reading the comments I wrote at 3 am is fun
#include "io.cpp"

extern "C" void main() {
	print("kernel loaded!", 0, 0);
	printSquare(5, 5, 14, 7);
	print("Welcome to", 7, 7);
	print("iinob OS!", 7, 9);
    return;
}
