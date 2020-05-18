#pragma once
#include <string>
#include <iostream>
using namespace std;

enum relevantIndices { firstArg, secondArg, desiredArgsLength };
enum outcome { success, numberOfArguments, wrongArgument, quitGame, tie, error };
enum strings {sameString, tictac , gomoku};
enum extra {player1turn , invalidString = 2};
enum start_game {firstMove};

int usageMessage();
int argsError();
