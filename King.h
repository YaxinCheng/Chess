#ifndef KING_H
#define KING_H
#include "Piece.h"
#include "StraightMove.h"
#include "DiagonalMove.h"
#include <stdio.h>
#include <stdlib.h>

using namespace chessGame;
namespace chessGame {
	struct King: Piece, StraightMove, DiagonalMove {
		King(short x, short y, bool colour);
		~King();
		const bool checkLegal(short x, short y);
		const string icon();
	};
}
#endif
