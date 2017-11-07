#ifndef FRAME_GENERATOR_H
#define FRAME_GENERATOR_H

#include <thread>
#include <chrono>

#include "IUserInputCommand.h"
#include "IGameObj.h"
#include "Frame.h"
#include "Timer.h"

class FrameGenerator
{
public:
	FrameGenerator();
	
	bool build();
	void waitForNewCycle();
	void fireUserCommand(IUserInputCommand* command); //TODO change speed!!!
	Frame& getCurentFrame();
private:
	Timer m_timer;
	Frame m_currentFrame;
};

inline Frame& FrameGenerator::getCurentFrame()
{
	return m_currentFrame;
}
#endif //!FRAME_GENERATOR_H