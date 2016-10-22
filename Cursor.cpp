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