#ifndef CURSOR_H
#define CURSOR_H
#include <termios.h>
#include <stdio.h>

class Cursor {
	private:
		termios oldTerm;
		termios newTerm;
		void initTermios(int echo);
		void resetTermios();
	public:
		Cursor();
		~Cursor();
		char getch(int echo = 0);
		char getKey();
};
#endif