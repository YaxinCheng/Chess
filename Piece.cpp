#include "Piece.h"

using namespace chessGame;
Piece::Piece( short x,  short y, bool colour) {
	this->x = x;
	this->y = y;
	this->colour = colour;
	stepCounter = 0;
}

Piece::~Piece() {
}

bool Piece::getColour() {
	return this->colour;
}
