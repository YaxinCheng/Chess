#include "Chess.h"

Chess::Chess() {
	board = new Board<Piece>(8);
	// Set pawns
	for (short i = 0; i < 16; i ++ ) {
		if (i < 8) {
			board->setElement(new Pawn(i, 6, true));
		} else {
			board->setElement(new Pawn(i - 8, 1, false));
		}
	}
	// Set kings
	board->setElement(new King(3, 0, false));
	board->setElement(new King(3, 7, true));
	// Set queens
	board->setElement(new Queen(4, 0, false));
	board->setElement(new Queen(4, 7, true));
	// Set bishops
	auto bishops = {new Bishop(2, 0, false), new Bishop(5, 0, false), new Bishop(2, 7, true), new Bishop(5, 7, true)};
	for (auto *bishop : bishops) { board-> setElement(bishop); }
	// Set knights
	auto knights = {new Knight(1, 0, false), new Knight(6, 0, false), new Knight(1, 7, true), new Knight(6, 7, true)};
	for (auto *knight : knights) { board-> setElement(knight); }
	// Set rooks
	auto rooks = {new Rook(0, 0, false), new Rook(7, 0, false), new Rook(0, 7, true), new Rook(7, 7, true)};
	for (auto *rook : rooks) { board-> setElement(rook); }
}

Chess* Chess::getInstance() {
	static Chess *instance = new Chess();
	return instance;
}

void Chess::showBoard() {
	string info = "";
	for (int i = 0; i < board->getSize(); i ++) {
		for (int j = 0; j < board->getSize(); j ++) {
			if ((*board)[j][i] == NULL) {
				if (j == cursor.x && i == cursor.y ) {
					info += "[-]";
				} else {
					info += "-";
				}
			} else {
				if (j == cursor.x && i == cursor.y ) {
				 	info += "[" + (*board)[j][i]->icon() + " ]";
				} else {
					info += (*board)[j][i]->icon();
				}
			}
			info += '\t';
		}
		info += '\n';
	}
	cout << '\n' << info << endl;
}

void Chess::start() {
	char input;
	cursor.clearScreen();
	showBoard();
	do {
		input = cursor.getKey();
		switch (input) {
			case 'l': cursor.x -= (cursor.x == 0 ? 0 : 1); break;
			case 'r': cursor.x += (cursor.x == 7 ? 0 : 1); break;
			case 'u': cursor.y -= (cursor.y == 0 ? 0 : 1); break;
			case 'd': cursor.y += (cursor.y == 7 ? 0 : 1); break;
			case 's': break; // Space
			case 'q': cout << "Game Over" << endl; return;
		}
		if (input == 'w') {
			cout << "Wrong key is pressed" << endl;
			continue;
		}
		cursor.clearScreen();
		showBoard();
	} while (input != 'q');
	
}