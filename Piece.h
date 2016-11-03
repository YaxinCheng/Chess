#ifndef PIECE_H
#define PIECE_H
#include <string>
using namespace std;

namespace chessGame {
	struct Piece {
	protected:
		bool colour; // False for White, True for black
	public:
		int stepCounter;
		short x, y;// X Y coordinates of the piece
	 	Piece( short x,  short y, bool colour) ;// Constructor accepting x, y, and a colour
	 	virtual ~Piece();// Destructor
		virtual const bool checkLegal( short x,  short y) = 0 ;// Check if the move from current x y coordinates to x y is legal. True for legal, false for illegal
		virtual const string icon() = 0;// Returns a non-ASCII icon of the piece
		bool getColour();// Return piece colour
	};
}
#endif
