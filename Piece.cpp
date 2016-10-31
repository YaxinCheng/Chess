#include "Piece.h"

Piece::Piece( short x,  short y, bool colour) {
	this->x = x;
	this->y = y;
	this->colour = colour;
}

Piece::~Piece() {
}

bool Piece::getColour() {
	return this->colour;
}
