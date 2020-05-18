#include "Gamebase.h"
#include "Common.h"
#include "TicTacToe.h"

int main(int argc, char* argv[]) {
	try {
		shared_ptr<GameBase> newerObj(GameBase::getObject(argc, argv));

		if (argc == desiredArgsLength) {
			//If getObject() returned singular pointer
			if (newerObj == 0) {
				return usageMessage();
			}
			int outcome = newerObj->play();
			return outcome;
		}
		else {
			return argsError();
		}
	}
	catch (bad_alloc& ba)
	{
		// Catch error where we try to allocated memory that the compiler could not give us
		cerr << "bad_alloc caught: " << ba.what() << '\n';
	}
}
