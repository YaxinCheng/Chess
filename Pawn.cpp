#include "Pawn.h"
#include <iostream>

Pawn::Pawn( short x,  short y, bool colour): Piece(x, y, colour), StraightMove() {
}

Pawn::~Pawn() {
}

const bool Pawn::checkLegal( short x,  short y) {// Deprecated function
	return false;
}

const bool Pawn::checkLegal( short x, short y, Piece* centre, Piece* left, Piece* right) {
	if ((left != NULL || right != NULL) && abs(this->x - x) == 1 && abs(this->y - y) == 1) {// If left or right has some piece, and distance to those pieces are only 1
			return true;// Allow to move
	}
	if (isStraight(this->x, this->y, x, y) == false ) {// If not move straight, don't allow
		return false;
	}
	if ( colour == false && y - this->y == 1) {// For white pawn, can only move down
		return centre == NULL;
	}
	if ( colour == true && y - this->y == -1) {// For black pawn, can only move up
		return centre == NULL;
	}
	if (colour == true && this->y == 6 && y - this->y == -2) {// For black unmoved pawn, can move steps at once
		return true;
	}
	if (colour == false && this->y == 1 && y - this->y == 2) {// For white unmoved pawn, can move steps at once
		return true;
	}
	return false;// Other conditions are not allowed
}

const string Pawn::icon() {
	return colour ? "♟" : "♙";
}
