#include "Board.h"
#include "Board.cpp"
#include "Cursor.h"
#include <iostream>

int main(void) {
	Board<int> board(5);
	board.setElement(3, 2, 1);
	std::cout << board[2][1];
	try {
		board.setElement(4, 2, 1);
	} catch (int n) {
		std::cout << "Expcetion " << n << std::endl;
	}
	Cursor c;
	char value = c.getch();
	std::cout << "Value is : " << value << std::endl;
	return 0;
}
