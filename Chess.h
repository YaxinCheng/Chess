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
#include "GameProcessObserver.h"
using namespace std;

class Chess: GameProcessObserver {
private:
	Board<Piece> *board;
	Cursor cursor;
	void showBoard();
	static void resetBoard();
	Chess();
	long stepCounter;
	bool goingOn;
public:
	static Chess* getInstance();
	void start();
	void moved();
	void win(bool colour);
	void tie();
};
#endif