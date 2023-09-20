#include "TowerOfHanoi.h"
#include "input.h"
#include <cmath>
#include <iomanip>

//Precondition:
//Postcondition:
TowerOfHanoi::TowerOfHanoi()
{
	numDisks = 0;
	moveCount = 0;
	holdNum = 0;
	roundTimeToSolve = -1;
	fastestRoundTime = -1;
	pegToPop = ' ';
}

//Precondition:
//Postcondition:
int TowerOfHanoi::getNumDisks() const
{
	return numDisks;
}

//Precondition:
//Postcondition:
int TowerOfHanoi::getMoveCount() const
{
	return moveCount;
}

//Precondition:
//Postcondition:
int TowerOfHanoi::getHoldNum() const
{
	return holdNum;
}

//Precondition:
//Postcondition:
int TowerOfHanoi::getRoundTimeToSolve() const
{
	return roundTimeToSolve;
}

//Precondition:
//Postcondition:
int TowerOfHanoi::getFastestRoundTime() const
{
	return fastestRoundTime;
}

//Precondition:
//Postcondition:
char TowerOfHanoi::getPegToPop() const
{
	return pegToPop;
}

//Precondition:
//Postcondition:
void TowerOfHanoi::setNumDisks(int newNumDisks)
{
	numDisks = newNumDisks;
}

//Precondition:
//Postcondition:
void TowerOfHanoi::setMoveCount(int newMoveCount)
{
	moveCount = newMoveCount;
}

//Precondition:
//Postcondition:
void TowerOfHanoi::setHoldNum(int newHoldNum)
{
	holdNum = newHoldNum;
}

//Precondition:
//Postcondition:
void TowerOfHanoi::setRoundTimeToSolve(int newSolveTime)
{
	roundTimeToSolve = newSolveTime;
	if (fastestRoundTime == -1 || roundTimeToSolve < fastestRoundTime)
	{
		fastestRoundTime = roundTimeToSolve;
	}
}

//Precondition:
//Postcondition:
void TowerOfHanoi::initializeRound()
{
	while (!stackA.empty())
	{
		stackA.pop();
	}
	while (!stackB.empty())
	{
		stackB.pop();
	}
	while (!stackC.empty())
	{
		stackC.pop();
	}
	numDisks = inputInteger("Enter Enter the number of rings (1..64) to begin: ", 1, 64);
	moveCount = 0;

	// Push every disk on to stack A
	for (int index = 0; index < numDisks; index++)
	{
		stackA.push(numDisks - index);
	}	
}

//Precondition:
//Postcondition:
void TowerOfHanoi::displayTowers() const
{
	// use temporary stacks to display the stacks to the user
	stack<int> displayStackA(stackA);
	stack<int> displayStackB(stackB);
	stack<int> displayStackC(stackC);

	std::cout << "Tower of Hanoi: " << right << "Minumum Moves To Solve: " << (pow(2, numDisks) - 1) << left << endl << endl;

	for (int index = 0; index < numDisks; index++)
	{
		std::cout << setw(7) << ' ' << setw(10);
		if (displayStackA.size() == (numDisks - index))
		{
			std::cout << displayStackA.top();
			displayStackA.pop();
		}
		else
		{
			std::cout << char(186);
		}
		std::cout << setw(10);
		if (displayStackB.size() == (numDisks - index))
		{
			std::cout << displayStackB.top();
			displayStackB.pop();
		}
		else
		{
			std::cout << char(186);
		}
		std::cout << setw(10);;
		if (displayStackC.size() == (numDisks - index))
		{
			std::cout << displayStackC.top();
			displayStackC.pop();
		}
		else
		{
			std::cout << char(186);
		}
		std::cout << endl;
	}
	std::cout << setw(5) << ' ' << char(205) << char(205) << char(205) << char(205) << char(205)
			  << setw(5) << ' ' << char(205) << char(205) << char(205) << char(205) << char(205)
			  << setw(5) << ' ' << char(205) << char(205) << char(205) << char(205) << char(205)  << endl;
	std::cout << setw(7) << ' ' << setw(10) << 'A' << setw(10) << 'B' << setw(10) << 'C' << endl << endl;

	// Display Move Number
	std::cout << "Move #" << (moveCount + 1) << endl << endl;

}

//Precondition:
//Postcondition:
void TowerOfHanoi::hanoiTowerPop(char towerOption)
{
	switch (towerOption)
	{
	case 'A': holdNum = stackA.top(); pegToPop = 'A';  break;
	case 'B': holdNum = stackB.top(); pegToPop = 'B';  break;
	case 'C': holdNum = stackC.top(); pegToPop = 'C';  break;
	default: std::cout << "\t\tERROR - Invalid option."; return;
	}
}

//Precondition:
//Postcondition:
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
			std::cout << "Cannot make the move. Top disk(" << holdNum << ") of Peg-" << pegToPop << " is larger than top disk(" << stackA.top() << ") of Peg-A" << endl;
			return;
		}
		break;
	
	case 'B': 
		if (stackB.empty() || holdNum < stackB.top())
		{
			stackB.push(holdNum);
		}
		else
		{
			std::cout << "Cannot make the move. Top disk(" << holdNum << ") of Peg-" << pegToPop << " is larger than top disk(" << stackA.top() << ") of Peg-B" << endl;
			return;
		}
		break;
	case 'C': 
		if (stackC.empty() || holdNum < stackC.top())
		{
			stackC.push(holdNum);
		}
		else
		{
			std::cout << "Cannot make the move. Top disk(" << holdNum << ") of Peg-" << pegToPop << " is larger than top disk(" << stackA.top() << ") of Peg-C" << endl;
			return;
		}
		break;
	default: cout << "\t\tERROR - Invalid option."; return;
	}
	if (pegToPop == 'A')
	{
		stackA.pop();
	}
	else if (pegToPop == 'B')
	{
		stackB.pop();
	}
	else if (pegToPop == 'C')
	{
		stackC.pop();
	}
	
	std::cout << "Top Peg From Peg " << pegToPop << " Has Moved to Peg- " << towerOption << endl;
	moveCount++;
}

//Precondition:
//Postcondition:
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

//Precondition: None
//Postcondition: None
void playTowerOfHanoi()
{
	TowerOfHanoi hanoiGame;
	displayHanoiRules();

	do
	{
		hanoiGame.initializeRound();
		towerOfHanoiRound(hanoiGame);
		
		if (toupper(inputChar("Play again? (Y-yes or N-no) ", "YN")) == 'N')
		{
			return;
		}
	} while (true);	
}

//Precondition:
//Postcondition:
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

//Precondition:
//Postcondition: Return a char character to represent user choice
char towerOfHanoiRoundMenuOption(string optionText)
{	
	char option = toupper(inputChar(optionText, "ABC"));
	return option;
}

//Precondition: None
//Postcondition: None
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