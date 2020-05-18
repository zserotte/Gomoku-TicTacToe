#pragma once
#include "Gamebase.h"

class TicTacToe : public GameBase {
public:
	TicTacToe();
	friend ostream& operator<<(ostream& myOstream, const TicTacToe& myGame);
	string gameBoard[5][5];
	virtual bool done();
	virtual bool draw();
	virtual int turn();
	virtual void print();
};

ostream& operator<<(ostream& myOstream, const TicTacToe& myGame);
