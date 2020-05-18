#pragma once
using namespace std;
#include <string>
#include <iostream>
#include <sstream>

class GameBase {
protected:
	int boardWidth;
	int boardHeight;
	string piece1;
	string piece2;
	int moves;
	string player1Moves;
	string player2Moves;
	int longestString;
	unsigned int maxIndex;
public:
	virtual void print() = 0;
	virtual bool done() = 0;
	virtual bool draw() = 0;
	int prompt(unsigned int& a, unsigned int& b);
	virtual int turn() = 0;
	int play();
	static GameBase* getObject(int myInt, char* myArray[]);
};
