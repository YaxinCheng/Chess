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

class Chess: GameProcessObserver {// Chess game main program
private:
	Board<Piece> *board;// Chess board
	Cursor cursor;// Game controller
	void showBoard();// Show chess board
	Chess();// Constructor, but the chess should be a singleton
	long stepCounter;// Coun steps, to decide who's turn this is and tie condition
	bool goingOn;// Game status is on going or not
public:
	static Chess* getInstance();// Get instance of the chess
	~Chess();
	void start();// Game start
	void moved(Piece* piece);// Observer function: Chess is moved
	void win(bool colour);// Observer function: Player wins
	void tie();// Tie condition
};
#endif