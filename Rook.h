#ifndef ROOK_H
#define ROOK_H
#include "Piece.h"
#include "StraightMove.h"

using namespace chessGame;
namespace chessGame {
	struct Rook: Piece, StraightMove {
		Rook( short x,  short y, bool colour);
		~Rook();
		const bool checkLegal( short x,  short y);
		const string icon();
	};
}
#endif
