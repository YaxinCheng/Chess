#ifndef BOARD_H
#define BOARD_H
#include "Piece.h"
#include "Pawn.h"
#include "Queen.h"
#include "King.h"
#include "Rook.h"
#include "StraightMove.h"
#include "DiagonalMove.h"
#include "GameProcessObserver.h"

using namespace chessGame;

template <class T>
struct Board {
	private:
		static_assert((std::is_base_of<Piece, T>::value), "T is not a piece class");// Board can only accepts Piece values
		T*** internalArray;// Internal array for all the pieces, 2D stores pointers
		bool existObstacle(T* element, short destinationX, short destinationY);// Detects obstacles from x y of element to destinationX and destinationY
		GameProcessObserver* observer;// Observer class, send game processing information to the observer
		int size;// Board size
		void movePawn(T** element, const short x, const short y, short &X, short &Y) throw(int);// Pawn is special, so this function is for moving pawn
		void moveKing(T* element, const short x, const short y, short &X, short &Y) throw(int);// Castling for king and rook
	public:
		T* selectedElement;// Selected element on the board
		Board(const int size);//Constructor with a size
		~Board();//Destructor
		const int getSize() const;// Returns the size of the board
		T** operator[] (int index) const;// [] operator makes the board easily access
		void setElement(T* element, const short x = -7, const short y = -7) throw (int);// Set element on the board, default x y = -7 means take the x y from element
		void moveElement(T* element, const short x, const short y, bool countStep = true) throw (int);// Move element from its original location to x y 
		void setObserver(GameProcessObserver* observer);// Set observer class
};
#endif
