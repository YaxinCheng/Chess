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

// toString method for printing
// template <class T>
// std::ostream& operator<<(std::ostream &stream, const Board<T> *board) {
// 	string empty = "";
// 	for (int i = 0; i < board.getSize(); i ++) {
// 		for (int j = 0; j < board.getSize(); j ++) {
// 			if (board[i][j] == NULL) {
// 				empty += "-";
// 			} else {
// 				empty += board[i][j]->icon();
// 			}
// 			empty += "\t";
// 		}
// 		empty += "\n";
// 	}
// 	return stream << empty << std::endl;
// }

// Set elements to the board
template <class T>
void Board<T>::setElement(const T element, const int x, const int y) throw(int) {
	if (internalArray[x][y] != NULL) {
		throw -1;
	}
	internalArray[x][y] = element;
}