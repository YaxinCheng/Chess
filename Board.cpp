#include "Board.h"
#include <iostream>

// Constructor
template<class T>
Board<T>::Board(const int size) {
	this->size = size;// Get size
	this->selectedElement = NULL;// no piece should be selected at the begining
	internalArray = new T**[size * size];// Initialize an array with size * size which stores T* arrays
	for (int i = 0; i < size; i ++) {// Initialize size number of T* arrays
		T** temp = new T*[size];
		for (int j = 0; j < size; j ++) {// For each place of the array, fill NULL
			temp[j] = NULL;
		}
		internalArray[i] = temp;// add the arrays to the 2D array
	}
}

// Destructor
template<class T>
Board<T>::~Board() {
	for (int i = 0; i < this->size; i ++) {
		for (int j = 0; j < this->size; j ++) {
			if (internalArray[i][j] != NULL) {// Loop through all the elements, and delete them
				delete internalArray[i][j];
			}
		}
		delete internalArray[i];// Delete the array
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
	if (x == -7 && y == -7) {// Default value, means getting the x y from element
		X = element->x;
		Y = element->y;
	} else {// If not default, accepts the x and y
		X = x;
		Y = y;
	}
	if (X < 0 || Y < 0) {// X Y should be in range of the board
		throw -2;// -2 : Illegal location
	}
	if (internalArray[Y][X] != NULL && element != NULL ) {// If X Y coordinate exists a piece and we are not cleaning that by NULL 
		if (internalArray[Y][X]->getColour() != element->getColour()) {// If the colour differs, it's one piece capturing another piece
			if (dynamic_cast<King*>(internalArray[Y][X]) != NULL) {// If a king is captured
				observer->win(!internalArray[Y][X]->getColour());// Tell observer game wins
			}
			delete internalArray[Y][X];// Delete this piece
		} else { // If colour is the same, unable to move
			throw -1;// -1: Unable to move
		}
	}
 	internalArray[Y][X] = element;//Set element to the location
}

template <class T>
void Board<T>::movePawn(T** element, const short x, const short y, short& X, short& Y) throw (int) {
	short nextY = (*element)->getColour() ? (*element)->y - 1 : (*element)->y + 1;// Check the y for next step
	Piece* centre = internalArray[nextY][(*element)->x];// Centre piece of the next y
	Piece* left = (*element)->x == 0 ? NULL : internalArray[nextY][(*element)->x - 1];// Left piece for the next y
	Piece* right = (*element)->x == 7 ? NULL : internalArray[nextY][(*element)->x + 1];// Right piece for the next y
	if (dynamic_cast<Pawn*>(*element)->checkLegal(x, y, centre, left, right) && !existObstacle((*element), x, y)) {// Check legal and no obstacle
		X = x;
		Y = y;
		if (((*element)->getColour() && Y == 0) || (!(*element)->getColour() && Y == 7)) {// Reaches the bottom of the board
			Queen* queen = new Queen((*element)->x, (*element)->y, (*element)->getColour());// Promotion
			delete (*element);// delete the original pawn
			*element = queen;// pointer points to the new queen
		}
	} else {
		throw -2;// Illeal move
	}
}

template <class T>
void Board<T>::moveKing(T* element, const short x, const short y, short &X, short &Y) throw (int) {
	short kingY = element->y;
	Piece* leftRook = internalArray[kingY][0];// Get two rooks
	Piece* rightRook = internalArray[kingY][7];
	Piece* targetRook = x == 1 ? leftRook : rightRook;// Get the rook that doing castling
	if (targetRook->stepCounter > 0 || existObstacle(element, targetRook->x == 0 ? 2 : 5, targetRook->y)) {
		// Rook must be unmoved and there should be no piece in between the rook and the king
		throw -2;
	}
	X = x;// Move king
	Y = y;
	moveElement(targetRook, targetRook->x == 0 ? 2 : 5, targetRook->y, false);// Move rook
}

// Move elements
template <class T>
void Board<T>::moveElement(T* element, const short x, const short y, bool countStep) throw (int) {
	short X, Y;
	cout << x << " " << y << endl;
	if (dynamic_cast<Pawn*>(element) != NULL) {// Pawn specific
		movePawn(&element, x, y, X, Y);
	} else if (dynamic_cast<King*>(element) != NULL && element->stepCounter == 0 && (x == 1 || x == 6)) {
		moveKing(element, x, y, X, Y);
	} else { // Generic
		if (element->checkLegal(x, y) && !existObstacle(element, x, y)) {// If legal and no obstacle
			X = x;
			Y = y;
		} else {
			throw -2;// Illegal moves
		}
	}	
	setElement(NULL, element->x, element->y);// Clear the spot on the board of x y
	element->x = X;// Set new coordinates to the piece
	element->y = Y;
	setElement(element);// Add the new piece to the board
	selectedElement = NULL;// One move finished, the cancel the selection mode
	if (countStep) {
		observer->moved(element);// Tell observer, a piece is moved
	}
}

template <class T>
bool Board<T>::existObstacle(T* element, short destinationX, short destinationY) {
	// Check obstacles
	if (dynamic_cast<StraightMove*>(element) != NULL) {// If the piece is a StraightMove piece
		if ((dynamic_cast<StraightMove*>(element))->isStraight(element->x, element->y, destinationX, destinationY)) {// Check if it did straight move
			if (element->x == destinationX) { // Move vertically
				short beginning = destinationY > element->y ? element->y : destinationY;// Begining is the smaller one
				short ending = destinationY > element->y ? destinationY : element->y;// Ending is the greater one
				for (short i = beginning; i < ending; i ++) {
					if (internalArray[i][element->x] != NULL && i != element->y && i != destinationY) {// If there's a piece exits between the begining and destination, then found obstacle
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
	T* destination = internalArray[destinationY][destinationX];// Destination piece if exists
	return destination != NULL && destination->getColour() == element->getColour();// Allows movement if the destination is empty or having a different colour  
}

template <class T>
void Board<T>::setObserver(GameProcessObserver* observer) {
	this->observer = observer;
}
