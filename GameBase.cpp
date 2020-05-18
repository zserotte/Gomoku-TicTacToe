#include "Gamebase.h"
#include "Common.h"
#include "TicTacToe.h"
#include "GomokuGame.h"


// Returns success or quitGame
int GameBase::prompt(unsigned int& cord1, unsigned int& cord2)
{
	if (moves == firstMove) {
		string rulesMessage = "Rules of the game are as follows: ";
		string quitMessage = "If you want to quit the game at any point, type 'quit'";
		string pieceMessage = "If you want to put a piece on the board, type two comma separated integers that correspond to a valid position on the board";
		cout << rulesMessage << endl << quitMessage << endl << pieceMessage << endl;
	}
	// Prompt player X
	if (moves % 2 == player1turn) {
		cout << "It is player 1's turn. Please make a move" << endl;
	}
	// Prompt player O
	else {
		cout << "It is player 2's turn. Please make a move" << endl;
	}

	string userString = "";
	cin >> userString;

	
	int rePrompt = 0;
	while (1) {
		rePrompt = rePrompt + 1;
		// If they did not enter a valid string
		if (rePrompt == invalidString) {
			rePrompt = 1;
			cout << "You did not enter a valid string" << endl;
			cout << "Please enter 'quit' or valid game board coordinate" << endl;
			cin >> userString;
		}
		// The user entered an invalid string. We need this if statement because if its not here, the program will throw an error
		// On line 51
		if (userString.length() < 3) {
			// Do nothing
		}
		else {
			string quit = "quit";
			// If they entered 'quit'
			if (userString.compare(quit) == sameString) {
				return quitGame;
			}
			// If the first coordinate they entered was a single digit coordinate
			else if (userString.at(1) == ',') {
				userString.replace(1, 1, " ");
				istringstream stringStream(userString);
				// if we can successfully extract integers and they are in valid coordinates on the board
				if (stringStream >> cord1 && stringStream >> cord2 && cord1 > 0 && cord1 <= maxIndex && cord2 > 0 && cord2 <= maxIndex) {
					return success;
				}
				// We could not extract the values 
			}
			// The first coordinate that the user entered was 2 digits long 
			else if (userString.at(2) == ',') {
				userString.replace(2, 1, " ");
				istringstream stringStream(userString);
				// if we can successfully extract integers and they are in valid coordinates on the board
				if (stringStream >> cord1 && stringStream >> cord2 && cord1 > 0 && cord1 <= maxIndex && cord2 > 0 && cord2 <= maxIndex) {
					return success;
				}
				// We could not extract the user values
			}
			// If we reach this point the string was not formatted correctly
		}
	}
}

int GameBase::play()
{
	print();

	unsigned int result1 = 0;
	bool result2 = false;
	bool result3 = false;
	// While the game is not a tie, neither play won, and the user does not want to quit
	while (result1 != quitGame && result2 == false && result3 == false) {
		result1 = turn();
		result2 = done();
		result3 = draw();
	}
	// Somebody quit the game
	if (result1 == quitGame) {
		if (moves % 2 == player1turn) {
			cout << "There were a total of " << moves << " turns and no winner, but player 1 quit the game" << endl;
		}
		else {
			cout << "There were a total of " << moves << " turns and no winner, but player 2 quit the game" << endl;
		}
		return quitGame;
	}
	// There was a tie
	else if (result3 == true) {
		cout << "Draw! There were a total of " << moves << " turns, but we have no winner and there is no winning moves left" << endl;
		return tie;
	}
	// Somebody won
	else if (result2 == true) {
		// Player X wins
		if (moves % 2 == player1turn) {
			cout << "Player 2 won the game!" << endl;
		}
		// Player O wins
		else {
			cout << "Player 1 won the game!" << endl;
		}
		return success;
	}
	// Unspecified error
	else {
		cout << "There was an unspecified error" << endl;
		return error;
	}
}

GameBase* GameBase::getObject(int myInt, char* myArray[])
{
	// If the user entered the correct number of command line arguments
	if (myInt == relevantIndices::desiredArgsLength) {
		if (strcmp(myArray[1], "TicTacToe") == sameString) {
			TicTacToe* myGame = new TicTacToe();
			return myGame;
		}
		else if (strcmp(myArray[1], "Gomoku") == sameString) {
			GomokuGame* myGame = new GomokuGame();
			return myGame;
		}
		// The user did not enter a valid command line argument
		else {
			GameBase* nothing = 0;
			return nothing;
		}
	}
	// If the user did not enter the correct number of command line arguments
	else {
		GameBase* nothing = 0;
		return nothing;
	}
}
