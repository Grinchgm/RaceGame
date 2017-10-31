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
	inline int getTimerValue() const { return m_timer; };
	
private:
	int m_timer;
};
#endif // !TIMER_H

