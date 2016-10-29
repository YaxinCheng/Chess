#include "Board.h"
#include "Board.cpp"
#include "Cursor.h"
#include "Piece.h"
#include "Pawn.h"
#include "Knight.h"
#include <iostream>
using namespace std;

int main(void) {
	Knight k(0, 1, true);
	cout << k.icon();
	return 0;
}
