#include "Chess.h"
#include <iostream>
using namespace std;

int main(void) {
	auto game = Chess::getInstance();
	game->showBoard();
	return 0;
}
