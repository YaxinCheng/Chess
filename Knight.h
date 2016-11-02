#ifndef KNIGHT_H
#define KNIGHT_H
#include "Piece.h"
#include <stdio.h>
#include <stdlib.h>

using namespace chessGame;
namespace chessGame {
	struct Knight: Piece {
		Knight( short x,  short y, bool colour);
		const bool checkLegal( short x,  short y);
		const string icon();
	};
}
#endif