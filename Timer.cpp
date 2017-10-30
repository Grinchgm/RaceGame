#include "Timer.h"

Timer::Timer()
{
}

Timer::Timer(int timerValue)
	: m_timer(timerValue)
{

}

void Timer::calcForward()
{
	m_timer--;
}

void Timer::calcBack()
{
	m_timer++;
}

int Timer::getTimerValue() const
{
	return m_timer;
};