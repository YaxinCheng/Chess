#include "Board.h"
#include <iostream>

// Constructor
template<class T>
Board<T>::Board(const int size) {
	this->size = size;
	internalArray = new T**[size * size];
	for (int i = 0; i < size; i ++) {
		T** temp = new T*[size];
		for (int j = 0; j < size; j ++) {
			temp[j] = NULL;
		}
		internalArray[i] = temp;
	}
}

// Destructor
template<class T>
Board<T>::~Board() {
	for (int i = 0; i < this->size; i ++) {
		delete internalArray[i];
	}
	delete internalArray;
}

// Get the board size
template<class T>
const int Board<T>::getSize() const {
	return this->size;
}

// Get operator of brackets
template<class T>
T** Board<T>::operator[] (int index ) const {
	return internalArray[index];
}

// Set elements to the board
template <class T>
void Board<T>::setElement(T* element, const int x, const int y) throw(int) {
	int X, Y;
	if (x == -7 && y == -7) {
		X = element->x;
		Y = element->y;
	} else {
		X = x;
		Y = y;
	}
	if (X < 0 || Y < 0) {
		throw -2;
	}
	if (internalArray[X][Y] != NULL ) {
		throw -1;
	}
	internalArray[X][Y] = element;
}