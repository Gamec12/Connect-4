

#include <iostream>
#include <string>
#include <algorithm>
#include "Stack.h";

using namespace std;

class Board {
public:
	Stack board[7];
	Board() {};
	void printBoard() {
		char** temp = toArray();

		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 7; j++) {
				cout << temp[i][j] << " ";
			}
			cout << endl;
		}

	}
	void addPiece(int column, char piece) {
		board[column].push(piece);
	}
	bool isFull(int column) {
		return board[column].getSize() == 6;
	}
	bool isWin() {
		char** temp = toArray();
		// check horizontal
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 4; j++) {
				if (temp[i][j] != '_' && temp[i][j] == temp[i][j + 1] && temp[i][j] == temp[i][j + 2] && temp[i][j] == temp[i][j + 3]) {
					return true;
				}
			}
		}
		// check vertical
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 7; j++) {
				if (temp[i][j] != '_' && temp[i][j] == temp[i + 1][j] && temp[i][j] == temp[i + 2][j] && temp[i][j] == temp[i + 3][j]) {
					return true;
				}
			}
		}
		// check diagonal
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 4; j++) {
				if (temp[i][j] != '_' && temp[i][j] == temp[i + 1][j + 1] && temp[i][j] == temp[i + 2][j + 2] && temp[i][j] == temp[i + 3][j + 3]) {
					return true;
				}
			}
		}
		// check diagonal
		for (int i = 0; i < 3; i++) {
			for (int j = 3; j < 7; j++) {
				if (temp[i][j] != '_' && temp[i][j] == temp[i + 1][j - 1] && temp[i][j] == temp[i + 2][j - 2] && temp[i][j] == temp[i + 3][j - 3]) {
					return true;
				}
			}
		}
		return false;
	}
	char** toArray() {
		char** temp = new char* [6];
		for (int i = 0; i < 6; i++) {
			temp[i] = new char[7];
		}
		for (int i = 0; i < 7; i++) {
			Stack tempStack;
			for (int j = 0; j < board[i].getSize(); j++) {
				tempStack.push(board[i][j]);
			}
			for (int j = 5; j >= 0; j--) {
				if (board[i].hasPosition(j)) {
					temp[5 - j][i] = tempStack[j];
				}
				else {
					temp[5 - j][i] = '_';
				}
			}
		}
		return temp;
	}

};

int pickAPlace(char token)
{
	int pos;
	cout << endl << "<" << token << "> Choose a column for your token - ";
	cin >> pos;
	if (pos < 1 || pos > 7)
	{
		cout << "Invalid column. Try again." << endl;
		return pickAPlace(token);
	}
	return pos - 1;
}

int main()
{
	Board board;
	char token = 'X';
	while (true) {
		board.printBoard();
		int pos = pickAPlace(token);
		if (board.isFull(pos)) {
			cout << "That column is full. Please choose another column." << endl;
			continue;
		}
		else {
			board.addPiece(pos, token);
			if (board.isWin()) {
				board.printBoard();
				cout << "Player " << token << " wins!" << endl;
				break;
			}
		}

		token = (token == 'X') ? 'O' : 'X';
	}
}