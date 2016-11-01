#include "Chess.h"

Chess::Chess() {
	stepCounter = 0;
	goingOn = true;
	board = new Board<Piece>(8);// Initialize an 8 x 8 board
	board->setObserver(this);// Set observer
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

Chess::~Chess() {
	delete board;// Delete board
}

Chess* Chess::getInstance() {
	static Chess *instance = new Chess();
	return instance;
}

void Chess::showBoard() {
	string info = "";
	for (int i = 0; i < board->getSize(); i ++) {
		for (int j = 0; j < board->getSize(); j ++) {// Loop through the board
			if ((*board)[i][j] == NULL) {// If no piece is at the position
				if (j == cursor.x && i == cursor.y ) {// If the cursor is on the position
					info += board->selectedElement == NULL ? "[-]" : "(+)";// Print empty with the cursor with different mode
				} else {// If cursor not on
					info += "-";
				}
			} else {// Piece exists
				if (j == cursor.x && i == cursor.y ) {// If cursor is on the position
				 	info += board->selectedElement == NULL ? "[" + (*board)[i][j]->icon() + " ]" : "(" + (*board)[i][j]->icon() + " )";// Print piece with cursor
				} else {// Cursor not on
					info += board->selectedElement == (*board)[i][j] ? "[" + (*board)[i][j]->icon() + " ]" : (*board)[i][j]->icon();
				}
			}
			info += '\t';
		}
		info += '\n';
	}
	cout << '\n' << info << endl;
}

void Chess::start() {// Starts game
	char input;// Input from keyboard
	cursor.clearScreen();// Clear screen
	showBoard();// Show chess board
	cout << "White\'s turn" << endl;// White goes first
	do {
		input = cursor.getKey();// Get one key from the keyboard
		switch (input) {
			case 'l': cursor.x -= (cursor.x == 0 ? 0 : 1); break;// Go left
			case 'r': cursor.x += (cursor.x == 7 ? 0 : 1); break;// Go right
			case 'u': cursor.y -= (cursor.y == 0 ? 0 : 1); break;// Go up
			case 'd': cursor.y += (cursor.y == 7 ? 0 : 1); break;// Go down
			case 'q': cout << "Game Over" << endl; return;// Quit game
		}
		if (input == 'w') {// Wrong input
			cout << "Wrong key is pressed" << endl;// Show information
			continue;// Keep looping to skip clearing of screen
		}
		if (input == 's') { // Space bar
			if (board->selectedElement == NULL) {// If no piece is selected
				if ((*board)[cursor.y][cursor.x]->getColour() == (stepCounter % 2 != 0)) {// Can only select piece with one colour at each turn
					board->selectedElement = (*board)[cursor.y][cursor.x];// Set pointer
				}
			} else if (cursor.x != board->selectedElement->x || cursor.y != board->selectedElement->y) {// Cursor is not on the selected piece
				try {
					board->moveElement(board->selectedElement, cursor.x, cursor.y);// Move piece
				} catch (int e) {// Catch exceptions
					cout << e;
				}
			} else {// If cursor is on the selected piece
				board->selectedElement = NULL;// Cacel selection
			}
		}
		if (goingOn) {// If game is ongoing
			cursor.clearScreen();// Clear screen
			showBoard();// show refreshed chess board
			cout << (stepCounter % 2 != 0 ? "Black" : "White") << "\'s turn" << endl;// Show information about who's round
		}	
	} while (goingOn);// If game is not ongoing
}

void Chess::moved(Piece* piece) {
	piece->stepCounter += 1;
	stepCounter += 1;// Add move counter
	if (stepCounter >= 2000) {// When there are more than 2000 moves, count as a tie
		tie();
	}
}

void Chess::win(bool colour) {
	string winner = colour ? "Black" : "White";
	cout << winner << " wins!" << endl;// Show winning information
	goingOn = false;// End the game
}

void Chess::tie() {
	cout << "Game is tie!" << endl;// Show tie information
	goingOn = false;// End the game
}