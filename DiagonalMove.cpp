#include "DiagonalMove.h"
const bool DiagonalMove::isDiagonal(short x, short y, short destinationX, short destinationY) {
	return abs(destinationX - x) / abs(destinationY - y) == 1;
}
