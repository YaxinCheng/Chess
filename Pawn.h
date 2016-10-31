#ifndef PAWN_H
#define PAWN_H
#include "Piece.h"
#include "StraightMove.h"
#include "stdio.h"
#include "stdlib.h"

struct Pawn: Piece, StraightMove {
	Pawn( short x,  short y, bool colour);
	~Pawn();
	const bool checkLegal( short x,  short y);
	const bool checkLegal( short x, short y, Piece* centre, Piece* left, Piece* right);
	const bool promotable();
	const string icon();
};
#endif
