#ifndef STRAIGHT_MOVE_H
#define STRAIGHT_MOVE_H
struct StraightMove {// Super class for pieces only move on straight lines
	const bool isStraight( short x,  short y,  short destinationX,  short destinationY);// Check if it is straight from x y to destinationX destinationY. True for straight, false otherwise
};
#endif
