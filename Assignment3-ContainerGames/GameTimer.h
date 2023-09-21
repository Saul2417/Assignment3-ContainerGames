#pragma once
#include <chrono>
class GameTimer
{
private:
	int roundTimeToSolve;
	std::chrono::steady_clock::time_point startTime;
	std::chrono::steady_clock::time_point endTime;

public:
	GameTimer();
	int getRoundTimeToSolve() const;
	void setRoundTimeToSolve(int newSolveTime);
	void setStartTime();
	void setEndTime();
	~GameTimer();
};

