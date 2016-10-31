#include "King.h"

King::King(short x, short y, bool colour): Piece(x, y, colour), StraightMove() {
}

King::~King() {}

const bool King::checkLegal(short x, short y) {
	if (isStraight(this->x, this->y, x, y) == false ) {
		return false;
	}
	return abs(x - this->x) + abs(y - this->y) == 1;
}

const string King::icon() {
	return colour ? "♚" : "♔" ;
}
