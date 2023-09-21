#include "GameTimer.h"

//Precondition: None
//Postcondition: None
GameTimer::GameTimer()
{
	roundTimeToSolve = -1;
}

//Precondition: None
//Postcondition: None
int GameTimer::getRoundTimeToSolve() const
{
	return roundTimeToSolve;
}

//Precondition: None
//Postcondition: None
void GameTimer::setRoundTimeToSolve(int newSolveTime)
{
	roundTimeToSolve = newSolveTime;
}

//Precondition: None
//Postcondition: None
void GameTimer::setStartTime()
{
	startTime = std::chrono::high_resolution_clock::now();
}

//Precondition: None
//Postcondition: None
void GameTimer::setEndTime()
{
	endTime = std::chrono::high_resolution_clock::now();
	setRoundTimeToSolve(std::chrono::duration_cast<std::chrono::seconds>((endTime - startTime)).count());
}

GameTimer::~GameTimer()
{

}