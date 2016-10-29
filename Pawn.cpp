#include "Pawn.h"

Pawn::Pawn( short x,  short y, bool colour): Piece(x, y, colour), StraightMove() {
}

const bool Pawn::checkLegal( short x,  short y) {
	if (isStraight(this->x, this->y, x, y) == false ) {
		return false;
	}
	if (colour == true && y - this->y == 1) {
		return true;
	}
	if (colour == true && this->y == 1 && y - this->y == 2) {
		return true;
	}
	if (colour == false && y - this->y == -1) {
		return true;
	}
	if (colour == false && this->y == 6 && y - this->y == -2) {
		return true;
	}
	return false;
}

const bool Pawn::promotable() {
	if (colour == true) {
		return y == 7;
	} else {
		return y == 0;
	}
}

const string Pawn::icon() {
	return colour ? "♙" : "♟";
}