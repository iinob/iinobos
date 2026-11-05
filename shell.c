#define HEIGHT 80

#include "shell.h"
#include "io.h"

int currentLine = 0;

void shout(const char string[]) {
	print(string, 0, currentLine);
	if (currentLine < HEIGHT) {
		currentLine++;
	} else {
		currentLine = 0;
	}
}
