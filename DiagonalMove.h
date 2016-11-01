#ifndef DIAGONALMOVE_H
#define DIAGONALMOVE_H
#include <stdio.h>
#include <stdlib.h>

struct DiagonalMove {// Super class for piece move diagonally
	const bool isDiagonal(short x, short y, short destinationX, short destinationY);// Check if it is a diagonally move from x y to destinationX destinationY. true for diagonal, false otherwise
};
#endif
