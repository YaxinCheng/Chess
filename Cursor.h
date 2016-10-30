#ifndef CURSOR_H
#define CURSOR_H
#include <termios.h>
#include <stdio.h>
#include <iostream>
#include <string>

class Cursor {
	private:
		termios oldTerm;
		termios newTerm;
		void initTermios(int echo);
		void resetTermios();
	public:
		short x;
		short y;
		Cursor();
		~Cursor();
		char getch(int echo = 0);
		char getKey();
		void clearScreen();
};
#endif