#ifndef GAME_PROCESS_OBSERVER
#define GAME_PROCESS_OBSERVER
#include "Piece.h"

struct GameProcessObserver {
	virtual void moved(Piece *piece) = 0;
	virtual void win(bool colour) = 0;
};
#endif