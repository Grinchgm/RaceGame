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
	if (m_timer > constants::TIMER_MIN_VALUE)
	{
		m_timer--;
	}
}

void Timer::calcBack()
{
	if (m_timer < constants::TIMER_INITIAL_VALUE)
	{
		m_timer++;
	}
}
