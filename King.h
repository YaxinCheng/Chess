#ifndef KING_H
#define KING_H
#include "Piece.h"
#include "StraightMove.h"
#include <stdio.h>
#include <stdlib.h>

struct King: Piece, StraightMove {
	King(short x, short y, bool colour);
	~King();
	const bool checkLegal(short x, short y);
	const string icon();
};
#endif
