#include "Knight.h"

Knight::Knight( short x,  short y, bool colour): Piece(x, y, colour) {
}

const bool Knight::checkLegal( short x,  short y) {
	if (x < 0 || x > 7 || y < 0 || y > 7) {
		return false;
	}
	short x_difference = abs(x - this->x);
	short y_difference = abs(y - this->y);
	if (x_difference == 0 || y_difference == 0) {
		return false;
	}
	float ratio = (float)x_difference / (float)y_difference;
	return ratio == 0.5 || ratio == 2;
}

const string Knight::icon() {
	return colour ? "♞" : "♘";
}