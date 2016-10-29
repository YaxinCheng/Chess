#ifndef QUEEN_H
#define QUEEN_H
#include "Piece.h"
#include "StraightMove.h"
#include "DiagonalMove.h"

struct Queen: Piece, StraightMove, DiagonalMove {
	Queen( short x,  short y, bool colour);
	const bool checkLegal( short x,  short y);
};
#endif