#include "StraightMove.h"
const bool StraightMove::isStraight( short x,  short y,  short destinationX,  short destinationY) {
	return x == destinationX || y == destinationY;
}