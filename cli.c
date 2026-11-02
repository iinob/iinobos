#include "io.h"
#include "kbdriver.h"

#include "cli.h"

void shell() {
	printChar('t', 0, 10);
	char character = readchar();
	printChar('b', 1, 10);
	printChar(character, 2, 10);
}
