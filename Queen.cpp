#include "Queen.h"

Queen::Queen( short x,  short y, bool colour): Piece(x, y, colour), StraightMove(), DiagonalMove() {
}

const bool Queen::checkLegal( short x,  short y) {
	if (isStraight(this->x, this->y, x, y) == false && isDiagonal(this->x, this->y, x, y) == false ) {
		return false;
	}
	return x >= 0 && x <= 7 && y >= 0 && y <= 7;
}

const string Queen::icon() {
	return colour ? "♛" : "♕" ;
}