#ifndef PIECE_H
#define PIECE_H
#include <vector>
#include <tuple>
#include <string>
using namespace std;

struct Piece {
protected:
	short x, y;
	bool colour; // True for White, False for black
public:
 	Piece( short x,  short y, bool colour) ;
	virtual const bool checkLegal( short x,  short y) = 0 ;
	virtual const string icon() = 0;
};
#endif