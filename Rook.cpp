#include "Rook.h"

Rook::Rook( short x,  short y, bool colour): Piece(x, y, colour), StraightMove() {
}

Rook::~Rook() {}

const bool Rook::checkLegal( short x,  short y) {
	if (isStraight(this->x, this->y, x, y) == false ) {
		return false;
	}
	return y >= 0 && y <= 7;
}

const string Rook::icon() {
	return colour ? "♜" : "♖";
}