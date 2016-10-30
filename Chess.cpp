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
				info += "-";
			} else {
				info += (*board)[j][i]->icon();
			}
			info += '\t';
		}
		info += '\n';
	}
	cout << '\n' << info << endl;
}