#pragma once
#include "Gamebase.h"

class GomokuGame:public GameBase {
public:
	string gameBoard[19][19];
	GomokuGame();
	friend ostream& operator<<(ostream& myOstream, const GomokuGame& myGame);
	virtual bool done();
	virtual bool draw();
	virtual int turn();
	virtual void print();
};

ostream& operator<<(ostream& myOstream, const GomokuGame& myGame);
