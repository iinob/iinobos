#define VGABUF 0xb8000
#define HEIGHT 80
#define WIDTH 80 // default for qemu. probably shouldn't be hardcoded but it is so suck it.

#define LINE_HORIZONTAL 0xCD
#define LINE_VERTICAL 0xBA
#define CORNER_DR 0xC9 // down right
#define CORNER_DL 0xBB // down left
#define CORNER_UR 0xC8 // up right
#define CORNER_UL 0xBC // up left

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

void printSquare(unsigned int posX, unsigned int posY, unsigned int sqwidth, unsigned int sqheight) { // width is almost double equivalent height, for qemu at least
    printChar(CORNER_DR, posX, posY);
    printChar(CORNER_DL, posX + sqwidth, posY);
    printChar(CORNER_UR, posX, posY + sqheight);
    printChar(CORNER_UL, posX + sqwidth, posY + sqheight); // define corners

    for (int i = posX + 1; i < posX + sqwidth; i++) { // horizontal
        printChar(LINE_HORIZONTAL, i, posY); // top line
        printChar(LINE_HORIZONTAL, i, posY + sqheight); // bottom line
    }
    for (int i = posY + 1; i < posY + sqheight; i++) { // vertical
        printChar(LINE_VERTICAL, posX, i); // left
        printChar(LINE_VERTICAL, posX + sqwidth, i); // right
    }

}

void printNum(int number, int posX, int posY) { // only works with 1-2 digit numbers
	if (number >= 10) {
		printChar((number / 10) + '0', posX, posY);
		printChar((number % 10) + '0', posX + 1, posY);
	} else {
		printChar('0', posX, posY);
		printChar(number + '0', posX + 1, posY);
	}
}

static __inline unsigned char inb (unsigned short int __port) { // functions to read and write from system ports
  unsigned char _v;

  __asm__ __volatile__ ("inb %w1,%0":"=a" (_v):"Nd" (__port));
  return _v;
}

static __inline void outb (unsigned char __value, unsigned short int __port){
  __asm__ __volatile__ ("outb %b0,%w1": :"a" (__value), "Nd" (__port));
}
