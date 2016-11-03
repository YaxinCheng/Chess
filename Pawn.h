#ifndef PAWN_H
#define PAWN_H
#include "Piece.h"
#include "StraightMove.h"
#include "stdio.h"
#include "stdlib.h"

using namespace chessGame;
namespace chessGame {
	struct Pawn: Piece, StraightMove {
		Pawn( short x,  short y, bool colour);
		~Pawn();
		const bool checkLegal( short x,  short y);// Deprecated function. Exists only from super class
		// x y are destination coordinates
		// centre, left, right stand for piece or NULL in front of, on the left front of, and on the right front of
		const bool checkLegal( short x, short y, Piece* centre, Piece* leftFront, Piece* rightFront, Piece* left, Piece* right) throw (int);// Really in use checkLegal function for pawn
		const string icon();
	};
}
#endif
