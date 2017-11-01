#ifndef TIMER_H
#define TIMER_H

#include "IGameObj.h"

class Timer : public IGameObj
{
public:
	Timer();
	Timer(int timerValue);

	virtual void calcLeft() {};
	virtual void calcRight() {};
	virtual void calcDown() {};
	virtual void calcForward();
	virtual void calcBack();
	int getTimerValue() const;
	
private:
	int m_timer;
};

inline int Timer::getTimerValue() const
{
	return m_timer;
};
#endif // !TIMER_H

