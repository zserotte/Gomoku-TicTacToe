#include "TicTacToe.h"
#include "Common.h"
#include <iomanip>

TicTacToe::TicTacToe() {
	boardWidth = 5;
	boardHeight = 5;
	longestString = tictac;
	maxIndex = 3;
	piece1 = "O";
	piece2 = "X";
	moves = 0;
	player1Moves = "Player O: ";
	player2Moves = "Player X: ";
	for (int i = boardHeight; i > 0; i--) {
		for (int j = 0; j < boardWidth; j++) {
			gameBoard[i - 1][j] = " ";
		}
	}
}

// Returns true or false
bool TicTacToe::done()
{
	//return true if 3xs or os are in a row 
	for (int y = 1; y < boardHeight - 1; y++)
	{
		for (int x = 1; x < boardWidth - 1; x++)
		{
			//check rows
			if ((x - 1) > 0 && (x + 1) < boardWidth - 1 
				&& gameBoard[x][y] != " " 
				&& this->gameBoard[x][y] == this->gameBoard[x + 1][y] 
				&& this->gameBoard[x][y] == this->gameBoard[x - 1][y]) 
			{
				return true;
			}
			//check cols
			if (this->gameBoard[x][y] == this->gameBoard[x][y + 1] 
				&& this->gameBoard[x][y] == this->gameBoard[x][y - 1] 
				&& (y - 1) > 0 
				&& (y + 1) < boardHeight - 1 
				&& gameBoard[x][y] != " ") 
			{
				return true;
			}
			//check diag1
			if (this->gameBoard[x][y] == this->gameBoard[x + 1][y + 1] 
				&& this->gameBoard[x][y] == this->gameBoard[x - 1][y - 1] 
				&& (x - 1) > 0 
				&& (x + 1) < (boardWidth - 1) 
				&& (y - 1) > 0 
				&& (y + 1) < (boardHeight - 1) 
				&& gameBoard[x][y] != " ")
			{
				return true;
			}
			//check diag2
			if (this->gameBoard[x][y] == this->gameBoard[x - 1][y + 1] 
				&& this->gameBoard[x][y] == this->gameBoard[x + 1][y - 1] 
				&& (x - 1) > 0 
				&& (x + 1) < (boardWidth - 1) 
				&& (y - 1) > 0 
				&& (y + 1) < (boardHeight - 1) 
				&& gameBoard[x][y] != " ") 
			{
				return true;
			}
		}
	}
	return false;
}

bool TicTacToe::draw()
{

	bool check = done();
	// If the game is done
	if (check)
	{
		return false;
	}
	for (int i = 1; i < boardHeight - 1; i++)
	{
		for (int j = 1; j < boardWidth - 1; j++)
		{
			if (gameBoard[i][j] == " ") // check if all spaces have a piece on them
			{
				return false;
			}
		}
	}
	return true;
}



// Returns success or quitGame
int TicTacToe::turn()
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
			if (gameBoard[pos2][pos1] == " ") {
				// Player X turn
				if (moves % 2 == player1turn) {
					moves = moves + 1;
					gameBoard[pos2][pos1] = piece2;
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
					gameBoard[pos2][pos1] = piece1;
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



void TicTacToe::print() {
	cout << *this;
}


ostream& operator<<(ostream& myOstream, const TicTacToe& myGame)
{
	for (int i = myGame.boardHeight; i > 0; i--) {
		myOstream << setw(myGame.longestString) << i-1;
		for (int j = 0; j < myGame.boardWidth; j++) {
			myOstream << setw(myGame.longestString) << myGame.gameBoard[i - 1][j];
		}
		myOstream << endl;
	}
	myOstream << setw(myGame.longestString) << "X";
	for (int i = 0; i < myGame.boardWidth; i++) {
		myOstream << setw(myGame.longestString) << i;
	}
	myOstream << endl;
	return myOstream;
}
