#include "Board.h"
#include "Board.cpp"
#include "Cursor.h"
#include "Piece.h"
#include "Pawn.h"
#include <iostream>

int main(void) {
	Cursor c;
	c.getKey();
	Pawn p(0,0, true);
	return 0;
}
