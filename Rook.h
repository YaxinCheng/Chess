#ifndef ROOK_H
#define ROOK_H
#include "Piece.h"
#include "StraightMove.h"

struct Rook: Piece, StraightMove {
	Rook( short x,  short y, bool colour);
	const bool checkLegal( short x,  short y);
	const string icon();
};
#endif