#ifndef IO_H
#define IO_H

void printChar(char character, unsigned int posX, unsigned int posY);

void print(const char string[], unsigned int posX, unsigned int posY);

void printSquare(unsigned int posX, unsigned int posY, unsigned int sqwidth, unsigned int sqheight);

void printNum(int number, int posX, int posY);

unsigned char inb (unsigned short int __port);

void outb (unsigned char __value, unsigned short int __port);

//int getSecond();

#endif
