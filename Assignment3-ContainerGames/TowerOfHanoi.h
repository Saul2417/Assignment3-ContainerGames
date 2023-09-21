#pragma once
#include <stack>
#include "GameTimer.h"
using namespace std;

class TowerOfHanoi: public GameTimer
{
private:
	int numDisks;
	int moveCount;
	int holdNum;
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
	char getPegToPop() const;
	void setNumDisks(int newNumDisks);
	void setMoveCount(int newMoveCount);
	void setHoldNum(int newHoldNum);
	void initializeRound();
	void displayTowers() const;
	void hanoiTowerPop(char towerOption);
	void hanoiTowerPush(char towerOption);
	bool hasWon() const;

	friend bool operator <(const TowerOfHanoi& obj1, const TowerOfHanoi& obj2)
	{
		if (obj1.numDisks < obj2.numDisks)
			return true;
		else
			return false;
	}
};

