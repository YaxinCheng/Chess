#include "Cursor.h"

void Cursor::initTermios(int echo) {
	tcgetattr(0, &oldTerm);
	newTerm = oldTerm;
	newTerm.c_lflag &= ~ICANON;
	newTerm.c_lflag &= echo ? ECHO : ~ECHO;
	tcsetattr(0, TCSANOW, &newTerm);
}

void Cursor::resetTermios() {
	tcsetattr(0, TCSANOW, &oldTerm);
}

Cursor::Cursor() {
	x = 0;
	y = 0;
}

Cursor::~Cursor() {
}

char Cursor::getch(int echo) {
	char ch;
	initTermios(echo);
	ch = getchar();
	resetTermios();
	return ch;
}

char Cursor::getKey() {
	// Left key: 27 91 68
	// Right key: 27 91 67
	// Up key: 27 91 65
	// Down key: 27 91 66
	int firstKey = getch();
	if (firstKey == 'q') {
		return 'q';// Q stands for quit
	} else if (firstKey == 32) {
		return 's';// S stands for space
	}
	else if (firstKey == 27) {
		getch();
		int thirdKey = getch();
		switch (thirdKey) {
			case 68: return 'l'; // L stands for left
			case 67: return 'r'; // R stands for right
			case 65: return 'u'; // U stands for up
			case 66: return 'd'; // D stands for down
			default: return 'w'; // W stands for wrong
		}
	}
	return 'w';// W stands for wrong
	
}

void Cursor::clearScreen() {
	std::cout << std::string(100, '\n');
}