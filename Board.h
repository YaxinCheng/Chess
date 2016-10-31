#ifndef BOARD_H
#define BOARD_H
#include "Piece.h"
template <class T>
struct Board {
	private:
		static_assert((std::is_base_of<Piece, T>::value), "T is not a piece class");
		T*** internalArray;
		bool existObstacle(T* element, short destinationX, short destinationY);
		int size;
	public:
		Board(const int size);
		~Board();
		const int getSize() const;
		T** operator[] (int index) const;
		void setElement(T* element, const int x = -7, const int y = -7) throw (int);
};
#endif
