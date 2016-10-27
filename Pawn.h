#ifndef PAWN_H
#define PAWN_H
#include "Piece.h"

struct Pawn: Piece {
	Pawn(unsigned short x, unsigned short y, bool colour);
	vector< tuple<unsigned short, unsigned short> > availableMoves();
};
#endif
