#pragma once
#include <stack>
#include <chrono>
using namespace std;

class TowerOfHanoi
{
private:
	int numDisks;
	int moveCount;
	int holdNum;
	int roundTimeToSolve;
	int fastestRoundTime;
	char pegToPop;
	stack <int> stackA;
	stack <int> stackB;
	stack <int> stackC;

public:
	TowerOfHanoi();
	int getNumDisks() const; 
	int getMoveCount() const;
	int getHoldNum() const;
	stack<int> getStack(char stackLetter) const;
	int getRoundTimeToSolve() const;
	int getFastestRoundTime() const;
	char getPegToPop() const;
	void setNumDisks(int newNumDisks);
	void setMoveCount(int newMoveCount);
	void setHoldNum(int newHoldNum);
	void setRoundTimeToSolve(int newSolveTime);
	void initializeRound();
	void displayTowers() const;
	void hanoiTowerPop(char towerOption);
	void hanoiTowerPush(char towerOption);
	bool hasWon() const;
};

