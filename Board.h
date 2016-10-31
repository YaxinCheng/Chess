#ifndef BOARD_H
#define BOARD_H
#include "Piece.h"
#include "StraightMove.h"
#include "DiagonalMove.h"

template <class T>
struct Board {
	private:
		static_assert((std::is_base_of<Piece, T>::value), "T is not a piece class");
		T*** internalArray;
		bool existObstacle(T* element, short destinationX, short destinationY);
		int size;
	public:
		T* selectedElement;
		Board(const int size);
		~Board();
		const int getSize() const;
		T** operator[] (int index) const;
		void setElement(T* element, const short x = -7, const short y = -7) throw (int);
		void moveElement(T* element, const short x, const short y) throw (int);
};
#endif
