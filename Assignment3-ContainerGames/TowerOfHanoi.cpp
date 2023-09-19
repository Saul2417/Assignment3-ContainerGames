#include "TowerOfHanoi.h"
#include "input.h"
#include <cmath>
#include <iomanip>

TowerOfHanoi::TowerOfHanoi()
{
	numDisks = 0;
	moveCount = 0;
	holdNum = 0;
	roundTimeToSolve = -1;
	fastestRoundTime = -1;
	pegToPop = ' ';
}

int TowerOfHanoi::getNumDisks() const
{
	return numDisks;
}

int TowerOfHanoi::getMoveCount() const
{
	return moveCount;
}

int TowerOfHanoi::getHoldNum() const
{
	return holdNum;
}

int TowerOfHanoi::getRoundTimeToSolve() const
{
	return roundTimeToSolve;
}

int TowerOfHanoi::getFastestRoundTime() const
{
	return fastestRoundTime;
}

char TowerOfHanoi::getPegToPop() const
{
	return pegToPop;
}

void TowerOfHanoi::setNumDisks(int newNumDisks)
{
	numDisks = newNumDisks;
}

void TowerOfHanoi::setMoveCount(int newMoveCount)
{
	moveCount = newMoveCount;
}

void TowerOfHanoi::setHoldNum(int newHoldNum)
{
	holdNum = newHoldNum;
}

void TowerOfHanoi::setRoundTimeToSolve(int newSolveTime)
{
	roundTimeToSolve = newSolveTime;
	if (fastestRoundTime == -1 || roundTimeToSolve < fastestRoundTime)
	{
		fastestRoundTime = roundTimeToSolve;
	}
}

void TowerOfHanoi::initializeRound()
{
	numDisks = inputInteger("Enter Enter the number of rings (1..64) to begin: ", 1, 64);
	moveCount = 0;

	// Push every disk on to stack A
	for (int index = 0; index < numDisks; index++)
	{
		stackA.push(numDisks - index);
	}	
}

void TowerOfHanoi::displayTowers() const
{
	std::cout << "Tower of Hanoi: " << right << "Minumum Moves To Solve: " << (pow(2, numDisks) - 1) << left << endl;

	// Code to display towers go here
	std::cout << "Move #" << (moveCount + 1) << endl;

}

void TowerOfHanoi::hanoiTowerPop(char towerOption)
{
	switch (towerOption)
	{
	case 'A': holdNum = stackA.top(); break;
	case 'B': holdNum = stackB.top(); break;
	case 'C': holdNum = stackC.top(); break;
	default: std::cout << "\t\tERROR - Invalid option."; return;
	}
}

void TowerOfHanoi::hanoiTowerPush(char towerOption)
{
	if (towerOption == pegToPop)
	{
		std::cout << "Cannot make the move. The selected end peg cannot be the same as the selected start peg." << endl
			<< "Please choose again." << endl;
		return;
	}

	switch (towerOption)
	{
	case 'A': 
		if (stackA.empty() || holdNum < stackA.top())
		{ 
			stackA.push(holdNum);
		}
		else
		{
			// std::cout << "Cannot make the move. Top disk( stack" 
		}
		break;
	
	case 'B': 
		if (stackB.empty() || holdNum < stackB.top())
		{
			stackB.push(holdNum);
		}
		else
		{

		}
		break;
	case 'C': 
		if (stackC.empty() || holdNum < stackC.top())
		{
			stackC.push(holdNum);
		}
		else
		{

		}
		break;
	default: cout << "\t\tERROR - Invalid option."; return;
	}

	std::cout << "Top Peg From Peg " << towerOption << " Has Moved to Peg " << towerOption << endl;
	moveCount++;
}

bool TowerOfHanoi::hasWon() const
{
	if (stackC.size() != numDisks)
	{
		return false;
	}

	for (int index = 0; index < numDisks; index++)
	{
		if (stackC.top() != (index + 1))
		{
			return false;
		}
	}
	return true;
}

void displayHanoiRules();
void towerOfHanoiRound(TowerOfHanoi hanoiGame);
char towerOfHanoiRoundMenuOption(string optionText);
void displayHanoiRules();

void playTowerOfHanoi()
{
	TowerOfHanoi hanoiGame;
	displayHanoiRules();

	do
	{
		hanoiGame.initializeRound();
		towerOfHanoiRound(hanoiGame);
		
		if (toupper(inputChar("Play again? (Y-yes or N-no) ", "YN") == 'N'))
		{
			return;
		}
	} while (true);	
}

void towerOfHanoiRound(TowerOfHanoi hanoiGame)
{
	chrono::steady_clock::time_point start = chrono::high_resolution_clock::now();
	do
	{
		hanoiGame.displayTowers();
		switch (towerOfHanoiRoundMenuOption("Select the top disk from the start peg (A, B, C, or Q-quit): "))
		{
		case 'Q': return; break;
		case 'A': hanoiGame.hanoiTowerPop('A'); break;
		case 'B': hanoiGame.hanoiTowerPop('B'); break;
		case 'C': hanoiGame.hanoiTowerPop('C'); break;
		default: std::cout << "\t\tERROR - Invalid option. Please re-enter."; break;
		}

		switch (towerOfHanoiRoundMenuOption("Select the end peg (A, B, C or Q-quit) to move the selected disk: "))
		{
		case 'Q': return; break;
		case 'A': hanoiGame.hanoiTowerPush('A'); break;
		case 'B': hanoiGame.hanoiTowerPush('B'); break;
		case 'C': hanoiGame.hanoiTowerPush('C'); break;
		default: std::cout << "\t\tERROR - Invalid option. Please re-enter."; break;
		}

		if (hanoiGame.hasWon())
		{
			chrono::steady_clock::time_point end = chrono::high_resolution_clock::now();
			hanoiGame.setRoundTimeToSolve(chrono::duration_cast<chrono::seconds>(end - start).count());
			return;
		};
		system("pause");
	} while (true);
}

char towerOfHanoiRoundMenuOption(string optionText)
{	
	char option = toupper(inputChar(optionText));
	return option;
}

void displayHanoiRules()
{
	std::cout << "The Tower of Hanoi also called the Tower of Brahma or Lucas' Tower is a mathematical game. " << endl
		<< "It consists of three pegs and a number of rings of different sizes, which can slide onto " << endl
		<< "any peg. The game starts with the rings in a neat stack in ascending order of size on one" << endl
		<< "peg, the smallest at the top, thus making a conical shape." << endl;

	std::cout << "The objective of the game is to move the entire stack from the starting peg - A to ending peg - B," << endl
		<< "obeying the following simple rules :" << endl << endl;

	std::cout << "1. Only one disk can be moved at a time." << endl
		<< "2. Each move consists of taking the upper disk from one of the stacks and "
		<< "placing it on top of another stack or on an empty peg." << endl
		<< "3. No larger disk may be placed on top of a smaller disk." << endl;
}