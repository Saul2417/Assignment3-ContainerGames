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
	slowestRoundTime = -1;
	pegToPop = ' ';
}

//Precondition:
//Postcondition: return the value of the numDisks object
int TowerOfHanoi::getNumDisks() const
{
	return numDisks;
}

//Precondition:
//Postcondition: return the value of the moveCount object
int TowerOfHanoi::getMoveCount() const
{
	return moveCount;
}

//Precondition:
//Postcondition: return the value of the holdNum object
int TowerOfHanoi::getHoldNum() const
{
	return holdNum;
}

//Precondition:
//Postcondition: return the value of the roundTimeToSolve object
int TowerOfHanoi::getRoundTimeToSolve() const
{
	return roundTimeToSolve;
}

//Precondition:
//Postcondition: return the value of the fastestRoundTime object
int TowerOfHanoi::getFastestRoundTime() const
{
	return fastestRoundTime;
}

//Precondition:
//Postcondition: return one of the stack objects
stack<int> TowerOfHanoi::getStack(char stackLetter) const
{
	switch (stackLetter)
	{
	case 'A': return stackA; break;
	case 'B': return stackB; break;
	case 'C': return stackC; break;
	}
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
	if (slowestRoundTime == -1 || roundTimeToSolve > slowestRoundTime)
	{
		slowestRoundTime = roundTimeToSolve;
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

	std::cout << "Tower of Hanoi: " << setw(40) << right << "Minumum Moves To Solve: " << (pow(2, numDisks) - 1) << left << endl << endl;

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
	case 'A': 
		if (!stackA.empty())
		{
			holdNum = stackA.top();
			pegToPop = 'A';
			break;
		}
		else
		{
			std::cout << "Peg is empty, cannot pop. Please try again.";
		}
	case 'B': 
		if (!stackB.empty())
		{
			holdNum = stackB.top();
			pegToPop = 'B';
			break;
		}
		else
		{
			std::cout << "Peg is empty, cannot pop. Please try again.";
		}
	case 'C': 
		if (!stackC.empty())
		{
			holdNum = stackC.top(); 
			pegToPop = 'C';  
			break;
		}
		else
		{
			std::cout << "Peg is empty, cannot pop. Please try again.";
		}
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
			std::cout << "Cannot make the move. Top disk(" << holdNum << ") of Peg-" << pegToPop << " is larger than top disk(" << stackB.top() << ") of Peg-B" << endl;
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
			std::cout << "Cannot make the move. Top disk(" << holdNum << ") of Peg-" << pegToPop << " is larger than top disk(" << stackC.top() << ") of Peg-C" << endl;
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
	
	std::cout << "Top Peg From Peg-" << pegToPop << " Has Moved to Peg-" << towerOption << endl;
	moveCount++;
}

//Precondition: None
//Postcondition: Returns true or false depending on if each disk has been properly moved to the third stack
bool TowerOfHanoi::hasWon() const
{
	
	if (stackC.size() != numDisks)
	{
		return false;
	}

	stack<int> verifyStackC(stackC);

	for (int index = 0; index < numDisks; index++)
	{
		if (verifyStackC.top() != (index + 1)) 
		{
			return false;
		}
		verifyStackC.pop();
	}
	return true;
}

void displayHanoiRules();
void towerOfHanoiRound(TowerOfHanoi hanoiGame);
char towerOfHanoiRoundPopOption(TowerOfHanoi hanoiGame);
char towerOfHanoiRoundPushOption();
void displayFinalStatistics(TowerOfHanoi hanoiGame);
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
			displayFinalStatistics(hanoiGame);
			return;
		}
	} while (true);	
}

//Precondition:
//Postcondition: None
void towerOfHanoiRound(TowerOfHanoi hanoiGame)
{
	chrono::steady_clock::time_point start = chrono::high_resolution_clock::now();
	do
	{
		hanoiGame.displayTowers();
		switch (towerOfHanoiRoundPopOption(hanoiGame))
		{
		case 'Q': return; break;
		case 'A': hanoiGame.hanoiTowerPop('A'); break;		
		case 'B': hanoiGame.hanoiTowerPop('B'); break;
		case 'C': hanoiGame.hanoiTowerPop('C'); break;
		default: std::cout << "\t\tERROR - Invalid option. Please re-enter."; break;
		}

		switch (towerOfHanoiRoundPushOption())
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
			hanoiGame.setRoundTimeToSolve(chrono::duration_cast<chrono::seconds>((end - start)).count());
			cout << "Congrats! You Solved The Game In " << hanoiGame.getMoveCount() << " Turn(s)." << endl
			     << "Time Taken: " << hanoiGame.getRoundTimeToSolve() << " Seconds. " << endl << endl;
			return;
		};
		system("pause");
	} while (true);
}

//Precondition:
//Postcondition: Return a char character to represent user choice that has has been verified to match a stack that is not empty
char towerOfHanoiRoundPopOption(TowerOfHanoi hanoiGame)
{
	char option;
	do
	{
		option = (toupper(inputChar("Select the top disk from the start peg (A, B, C, or Q-quit): ", "ABCQ")));
		if (option == 'Q')
		{
			break;
		}
		if (hanoiGame.getStack(option).empty())
		{
			cout << "Error: Peg-" << option << " is empty, cannot pop. Please enter a peg that is not empty." << endl;
		}
	}while (hanoiGame.getStack(option).empty());

	return option;
}

//Precondition: None
//Postcondition: None
char towerOfHanoiRoundPushOption()
{
	char option = (toupper(inputChar("Select the end peg (A, B, C or Q-quit) to move the selected disk: ", "ABCQ")));
	return option;
}

void displayFinalStatistics(TowerOfHanoi hanoiGame)
{
	
}

//Precondition: None
//Postcondition: None
void displayHanoiRules()
{
	std::cout << "The Tower of Hanoi also called the Tower of Brahma or Lucas' Tower is a mathematical game. " << endl
		<< "It consists of three pegs and a number of rings of different sizes, which can slide onto " << endl
		<< "any peg. The game starts with the rings in a neat stack in ascending order of size on one " << endl
		<< "peg, the smallest at the top, thus making a conical shape." << endl;

	std::cout << "The objective of the game is to move the entire stack from the starting peg - A to ending peg - B, " << endl
		<< "obeying the following simple rules : " << endl << endl;

	std::cout << "1. Only one disk can be moved at a time. " << endl
		<< "2. Each move consists of taking the upper disk from one of the stacks and "
		<< "placing it on top of another stack or on an empty peg. " << endl
		<< "3. No larger disk may be placed on top of a smaller disk. " << endl;
}