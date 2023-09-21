#include "GameTimer.h"
GameTimer::GameTimer()
{
	roundTimeToSolve = -1;
}
int GameTimer::getRoundTimeToSolve() const
{
	return roundTimeToSolve;
}

void GameTimer::setRoundTimeToSolve(int newSolveTime)
{
	roundTimeToSolve = newSolveTime;
}

void GameTimer::setStartTime()
{
	startTime = std::chrono::high_resolution_clock::now();
}

void GameTimer::setEndTime()
{
	endTime = std::chrono::high_resolution_clock::now();
	setRoundTimeToSolve(std::chrono::duration_cast<std::chrono::seconds>((endTime - startTime)).count());
}

GameTimer::~GameTimer()
{

}