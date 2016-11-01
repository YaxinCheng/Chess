#include "Board.h"
#include <iostream>

// Constructor
template<class T>
Board<T>::Board(const int size) {
	this->size = size;
	this->selectedElement = NULL;
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
		for (int j = 0; j < this->size; j ++) {
			if (internalArray[i][j] != NULL) {
				delete internalArray[i][j];
			}
		}
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
void Board<T>::setElement(T* element, const short x, const short y) throw(int) {
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
	if (internalArray[Y][X] != NULL && element != NULL ) {
		if (internalArray[Y][X]->getColour() != element->getColour()) {
			if (dynamic_cast<King*>(internalArray[Y][X]) != NULL) {
				observer->win(!internalArray[Y][X]->getColour());
			}
			delete internalArray[Y][X];
			internalArray[Y][X] = element;
		} else {
			throw -1;
		}
	}
	internalArray[Y][X] = element;
}

// Move elements
template <class T>
void Board<T>::moveElement(T* element, const short x, const short y) throw (int) {
	short X, Y;
	if (dynamic_cast<Pawn*>(element) != NULL) {// Pawn specific
		short nextY = element->getColour() ? element->y - 1 : element->y + 1;
		Piece* centre = internalArray[nextY][element->x];
		Piece* left = element->x == 0 ? NULL : internalArray[nextY][element->x - 1];
		Piece* right = element->x == 7 ? NULL : internalArray[nextY][element->x + 1];
		if (dynamic_cast<Pawn*>(element)->checkLegal(x, y, centre, left, right) && !existObstacle(element, x, y)) {
			X = x;
			Y = y;
			if ((element->getColour() && Y == 0) || (!element->getColour() && Y == 7)) {
				Queen* queen = new Queen(element->x, element->y, element->getColour());
				delete element;
				element = queen;
			}
		} else {
			throw -2;
		}
	} else { // Generic
		if (element->checkLegal(x, y) && !existObstacle(element, x, y)) {
			X = x;
			Y = y;
		} else {
			throw -2;
		}
	}	
	setElement(NULL, element->x, element->y);
	element->x = X;
	element->y = Y;
	setElement(element);
	selectedElement = NULL;
	observer->moved();
}

template <class T>
bool Board<T>::existObstacle(T* element, short destinationX, short destinationY) {
	// Check obstacles
	if (dynamic_cast<StraightMove*>(element) != NULL) {
		if ((dynamic_cast<StraightMove*>(element))->isStraight(element->x, element->y, destinationX, destinationY)) {
			if (element->x == destinationX) { // Move vertically
				short beginning = destinationY > element->y ? element->y : destinationY;
				short ending = destinationY > element->y ? destinationY : element->y;
				for (short i = beginning; i < ending; i ++) {
					if (internalArray[i][element->x] != NULL && i != element->y && i != destinationY) {
						return true;
					}
				}
			} else if (element->y == destinationY) { // Move horizontally
				short beginning = destinationX > element->x ? element->x : destinationX;
				short ending = destinationX > element->x ? destinationX : element->x;
				for (short i = beginning; i < ending; i ++) {
					if (internalArray[element->y][i] != NULL && i != element->x && i != destinationX) {
						return true;
					}
				}
			}
		}
	}	
	if (dynamic_cast<DiagonalMove*>(element) != NULL) {
		if ((dynamic_cast<DiagonalMove*>(element))->isDiagonal(element->x, element->y, destinationX, destinationY)) {
			if (destinationX > element->x) { // Move right diagonal
				short deviation = abs(destinationX - element->x);
				for (short i = 1; i < deviation; i ++) {
					if (destinationY < element->y) {// Right up
						if (internalArray[element->y - i][element->x + i] != NULL) {
							return true;
						}
					} else if (destinationY > element->y) {// Right down
						if (internalArray[element->y + i][element->x + i] != NULL) {
							return true;
						}
					}
				}
			} else if (destinationX < element->x) {// Move left diagonal
				short deviation = abs(destinationX - element->x);
				for (short i = 1; i < deviation; i ++) { 
					if (destinationY > element->y) {// Left down
						if (internalArray[element->y + i][element->x - i] != NULL) {
							return true;
						}
					} else if (destinationY < element->y) { // Left up
						if (internalArray[element->y - i][element->x - i] != NULL) {
							return true;
						}
					}
				}
			} 
		}
	}
	T* destination = internalArray[destinationY][destinationX];
	return destination != NULL && destination->getColour() == element->getColour();
}

template <class T>
void Board<T>::setObserver(GameProcessObserver* observer) {
	this->observer = observer;
}