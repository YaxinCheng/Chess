#ifndef GAME_PROCESS_OBSERVER
#define GAME_PROCESS_OBSERVER
struct GameProcessObserver {
	virtual void moved() = 0;
	virtual void win(bool colour) = 0;
};
#endif