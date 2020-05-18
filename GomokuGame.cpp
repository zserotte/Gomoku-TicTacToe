#include "GomokuGame.h"
#include "Common.h"
#include <iomanip>

GomokuGame::GomokuGame() {
	boardWidth = 19;
	boardHeight = 19;
	longestString = gomoku;
	maxIndex = 19;
	piece1 = "W";
	piece2 = "B";
	moves = 0;
	player1Moves = "White player: ";
	player2Moves = "Black player: ";
	for (int i = boardHeight; i > 0; i--) {
		for (int j = 0; j < boardWidth; j++) {
			GomokuGame::gameBoard[i - 1][j] = " ";
		}
	}
}

bool GomokuGame::done()
{
	//return true if 3xs or os are in a row 
	for (int y = 0; y < boardHeight; y++)
	{
		for (int x = 0; x < boardWidth; x++)
		{
			if ((x - 2) >= 0 && (x + 2) <= boardWidth //check rows
				&& gameBoard[x][y] != " " 
				&& this->gameBoard[x][y] == this->gameBoard[x + 1][y]
				&& this->gameBoard[x][y] == this->gameBoard[x + 2][y]
				&& this->gameBoard[x][y] == this->gameBoard[x - 1][y]
				&& this->gameBoard[x][y] == this->gameBoard[x - 2][y])
				 
			{
				return true;
			}
			if  ((y - 2) >= 0 && (y + 2) <= boardHeight //check cols
				&& gameBoard[x][y] != " " 
				&& this->gameBoard[x][y] == this->gameBoard[x][y + 1]
				&& this->gameBoard[x][y] == this->gameBoard[x][y + 2]
				&& this->gameBoard[x][y] == this->gameBoard[x][y - 1]
				&& this->gameBoard[x][y] == this->gameBoard[x][y - 2] )
				
			{
				return true;
			}
			if ((x - 2) >= 0 && (x + 2) <= (boardWidth) //check diag1
				&& (y - 2) >= 0 && (y + 2) <= (boardHeight)
				&& gameBoard[x][y] != " " 
				&& this->gameBoard[x][y] == this->gameBoard[x + 1][y + 1]
				&& this->gameBoard[x][y] == this->gameBoard[x + 2][y + 2]
				&& this->gameBoard[x][y] == this->gameBoard[x - 1][y - 1]
				&& this->gameBoard[x][y] == this->gameBoard[x - 2][y - 2] )
				
			{
				return true;
			}
			if ((x - 2) >= 0 && (x + 2) <= (boardWidth) //check diag2
				&& (y - 2) >= 0 && (y + 2) <= (boardHeight)
				&& gameBoard[x][y] != " " 
				&& this->gameBoard[x][y] == this->gameBoard[x - 1][y + 1]
				&& this->gameBoard[x][y] == this->gameBoard[x - 2][y + 2]
				&& this->gameBoard[x][y] == this->gameBoard[x + 1][y - 1]
				&& this->gameBoard[x][y] == this->gameBoard[x + 2][y - 2] )
			{
				return true;
			}
		}
	}
	//otherwise return false
	return false;
}

bool GomokuGame::draw()
{
	bool check = done();
	// If the game is done
	if (check)
	{
		return false;
	}
	for (int i = 0; i < boardHeight; i++)
	{
		for (int j = 0; j < boardWidth; j++)
		{
			if (gameBoard[i][j] == " ") // Check if there is a piece on each spot on the board
			{
				return false;
			}
		}
	}
	return true;
}

int GomokuGame::turn()
{
	unsigned int pos1;
	unsigned int pos2;

	while (1) {
		// The user quit the game
		if (prompt(pos1, pos2) == quitGame) {
			return  quitGame;
		}
		// The user gave us valid coordinates
		else {
			// The place that the user wants to put the piece is empty
			if (gameBoard[pos2-1][pos1-1] == " ") {
				// Player X turn
				if (moves % 2 == player1turn) {
					moves = moves + 1;
					// We subtract 1 from the coordinates they entered because or 2-d array ranges from 0-18, whereas the spots on the board range from 1-19
					gameBoard[pos2-1][pos1-1] = piece2;
					cout << *this << endl;
					string pos1String = to_string(pos1);
					string pos2String = to_string(pos2);
					player2Moves = player2Moves + pos1String + ", " + pos2String + "; ";
					cout << player2Moves << endl;
					return success;
				}
				// Player O turn
				else {
					moves = moves + 1;
					gameBoard[pos2-1][pos1-1] = piece1;
					cout << *this << endl;
					string pos1String = to_string(pos1);
					string pos2String = to_string(pos2);
					player1Moves = player1Moves + pos1String + ", " + pos2String + "; ";
					cout << player1Moves << endl;
					return success;
				}
			}
			// The place that the user wants to put the piece is not empty
			cout << "The position where the user wants to put their piece is full. Please pick another position" << endl;
		}
	}
}

void GomokuGame::print(){
	cout << *this;
}

ostream& operator<<(ostream& myOstream, const GomokuGame& myGame)
{
	for (int i = myGame.boardHeight; i > 0; i--) {
		myOstream << setw(myGame.longestString) << i;
		for (int j = 0; j < myGame.boardWidth; j++) {
			myOstream << setw(myGame.longestString) << myGame.gameBoard[i - 1][j] << "|";
		}
		myOstream << endl;
	}
	myOstream << setw(myGame.longestString) << "X";
	for (int i = 1; i <= myGame.boardWidth; i++) {
		myOstream << setw(myGame.longestString) << i;
		cout << " ";
	}
	myOstream << endl;
	return myOstream;
}
