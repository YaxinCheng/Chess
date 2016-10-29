#include "Board.h"
#include "Board.cpp"
#include "Cursor.h"
#include "Piece.h"
#include "Pawn.h"
#include <iostream>
using namespace std;

int main(void) {
	Cursor c;
	c.getKey();
	Pawn p(0,1, true);
	cout << p.checkLegal(1, 3);
	return 0;
}
