#include "Chess.h"
#include <iostream>
using namespace std;

int main(void) {
	auto game = Chess::getInstance();
	game->start();
	return 0;
}
