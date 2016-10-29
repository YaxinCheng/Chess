#ifndef PAWN_H
#define PAWN_H
#include "Piece.h"
#include "StraightMove.h"

struct Pawn: Piece, StraightMove {
	Pawn( short x,  short y, bool colour);
	const bool checkLegal( short x,  short y);
};
#endif
