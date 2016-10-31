#include "DiagonalMove.h"
const bool DiagonalMove::isDiagonal(short x, short y, short destinationX, short destinationY) {
	if (destinationY == y || destinationX == x) {
		return false;
	}
	return abs(destinationX - x) / abs(destinationY - y) == 1;
}
