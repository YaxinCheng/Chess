#ifndef CHESS_H
#define CHESS_H
#include "Board.h"
#include "Board.cpp"
#include "Piece.h"
#include "Cursor.h"
#include "Bishop.h"
#include "King.h"
#include "Pawn.h"
#include "Knight.h"
#include "Queen.h"
#include "Rook.h"
using namespace std;

class Chess {
private:
	Board<Piece> *board;
	Cursor cursor;
	Chess();
public:
	static Chess* getInstance();
	void showBoard();
	void start();
};
#endif