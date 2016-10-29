#include "Bishop.h"

Bishop::Bishop( short x,  short y, bool colour): Piece(x, y, colour), DiagonalMove() {
}

const bool Bishop::checkLegal( short x,  short y) {
	if (isDiagonal(this->x, this->y, x, y) == false ) {
		return false;
	}
	return x >= 0 && x <= 7 && y >= 0 && y <= 7;
}

const string Bishop::icon() {
	return colour ? "♗" : "♝";
}
