#ifndef BISHOP_H
#define BISHOP_H
#include "Piece.h"
#include "DiagonalMove.h"

using namespace chessGame;
namespace chessGame {
	struct Bishop: Piece, DiagonalMove {
		Bishop( short x,  short y, bool colour);
		~Bishop();
		const bool checkLegal( short x,  short y);
		const string icon();
	};
}
#endif