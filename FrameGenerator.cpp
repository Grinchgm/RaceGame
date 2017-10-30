#include "FrameGenerator.h"

FrameGenerator::FrameGenerator()
	: m_timer(TimerInitialValue) 
{
}

bool FrameGenerator::build()
{
	//m_currentFrame.updateGameObjects();
	//m_currentFrame.buildObstacles();
	return m_currentFrame.checkForCollision();
}

void FrameGenerator::waitForNewCycle()
{
	std::this_thread::sleep_for(std::chrono::milliseconds(m_timer.getTimerValue()));
}

void FrameGenerator::fireUserCommand(IUserInputCommand * command)
{
	if (command)
	{
		command->proceed(m_timer);
		m_currentFrame.update(command);
	}
	delete command;
}