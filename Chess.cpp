#include "Chess.h"

Chess::Chess() {
	board = new Board<Piece>(8);
}

Chess* Chess::getInstance() {
	static Chess *instance = new Chess();
	return instance;
}

void Chess::showBoard() {
	string info = "";
	for (int i = 0; i < board->getSize(); i ++) {
		for (int j = 0; j < board->getSize(); j ++) {
			if ((*board)[i][j] == NULL) {
				info += "-";
			} else {
				info += (*board)[i][j]->icon();
			}
			info += '\t';
		}
		info += '\n';
	}
	cout << '\n' << info << endl;
}