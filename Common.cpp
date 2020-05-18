#include "Common.h"
using namespace std;

int usageMessage()
{
	cout << "In order for the program to work you must pass in 'TicTacToe' or 'Gomoku' as the command line argument." << endl;
	return wrongArgument;
}

int argsError()
{
	cout << "You must enter exactly one command line argument for the program to work." << endl;
	return numberOfArguments;
}
