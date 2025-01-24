#define VGABUF 0xb8000
#define HEIGHT 80
#define WIDTH 80 // default for qemu. probably shouldn't be hardcoded but it is so suck it.

void printChar(char character, unsigned int posX, unsigned int posY) {
	unsigned int offset = (posY * WIDTH + posX) * 2;
    unsigned char* vga = (unsigned char*)VGABUF;
    vga[offset] = character;
    vga[offset + 1] = 0x07;
}

void print(const char string[], unsigned int posX, unsigned int posY) {
	int i = 0;
	while (string[i] != '\0') {
		printChar(string[i], posX + i, posY);
		i++;
	}
}

extern "C" void main() {
	print("kernel loaded!", 0, 0);
    return;
}
