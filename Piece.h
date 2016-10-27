#ifndef PIECE_H
#define PIECE_H
#include <vector>
#include <tuple>
using namespace std;

struct Piece {
protected:
	unsigned short x, y;
	bool colour; // True for White, False for black
public:
 	Piece(unsigned short x, unsigned short y, bool colour) ;
	virtual vector< tuple<unsigned short, unsigned short> > availableMoves() = 0 ;
};
#endif
