#include "Board.h"
#include <iostream>

// Constructor
template<class T>
Board<T>::Board(const int size) {
	this->size = size;
	internalArray = new T*[size * size];
	for (int i = 0; i < size; i ++) {
		internalArray[i] = new T[size];
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
const int Board<T>::getSize() {
	return this->size;
}

// Get operator of brackets
template<class T>
T* Board<T>::operator[] (int index ) {
	return internalArray[index];
}

// toString method for printing
template <class T>
std::ostream& operator<<(std::ostream &stream, const Board<T> &board) {
	return stream << board[0][0] << " " << board[0][1] << "\n" << board[1][0] << " " << board[1][1] << std::endl;
}

// Set elements to the board
template <class T>
void Board<T>::setElement(const T element, const int x, const int y) throw(int) {
	if (internalArray[x][y] != NULL) {
		throw -1;
	}
	internalArray[x][y] = element;
}