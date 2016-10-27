#include "Pawn.h"

Pawn::Pawn(unsigned short x, unsigned short y, bool colour): Piece(x, y, colour) {
}

vector< tuple<unsigned short, unsigned short> > Pawn::availableMoves() {
	vector< tuple<unsigned short, unsigned short> > moves;
	unsigned short destination_y;
	if (colour == true) {
		destination_y += 1;
	} else {
		destination_y -= 1;
	}
	moves.push_back(make_tuple(x, destination_y));
	if (y == 1) {
		moves.push_back(make_tuple(x, y + 2));
	} else if (y == 6) {
		moves.push_back(make_tuple(x, y - 2));
	}
	return moves;
}
