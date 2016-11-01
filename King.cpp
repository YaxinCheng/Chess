#include "King.h"

King::King(short x, short y, bool colour): Piece(x, y, colour), StraightMove(), DiagonalMove() {
}

King::~King() {}

const bool King::checkLegal(short x, short y) {
	if (isStraight(this->x, this->y, x, y)) {
		return abs(x - this->x) + abs(y - this->y) == 1;
	} else if (isDiagonal(this->x, this->y, x, y)) {
		return abs(x - this->x) + abs(y - this->y) == 2;
	}
	return false;
}

const string King::icon() {
	return colour ? "♚" : "♔" ;
}
