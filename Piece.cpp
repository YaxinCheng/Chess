#include "Piece.h"

Piece::Piece( short x,  short y, bool colour) {
	this->x = x;
	this->y = y;
	this->colour = colour;
}

bool Piece::getColour() {
	return this->colour;
}