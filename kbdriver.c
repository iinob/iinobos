#include "io.h"

#include "kbdriver.h"

static char keymap[] = {
	0, 0, '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=', 0,
	'\t', 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']',
	'\n', 0, 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'', '`',
	0, '\\', 'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/', 0,
	'*', 0, ' ', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '7', '8', '9',
	'-', '4', '5', '6', '+', '1', '2', '3', '0', '.'
};

static inline void ps2WaitIn(void) {
    while (inb(0x64) & 0x02) {}
}

static inline void ps2WaitOut(void) {
    while (!(inb(0x64) & 0x01)) {}
}

void kb_enable() {

}

char kb_readchar() {
    ps2WaitIn();
    outb(0x64, 0xAE);

    ps2WaitIn();
    outb(0x60, 0xF4);

    while (1) {
        ps2WaitOut();
	unsigned char charBuffer = inb(0x60); // wait for buffer to fill and then take data
// TODO: invent a way to print hex and show the charBuffer
        //if (charBuffer & 0x80)
        //    continue;

        char character = keymap[charBuffer];
        if (character)
            return character;
    }
}

