#ifndef GAME_H
#define GAME_H

#include "FrameGenerator.h"
#include "FrameVizualizer.h"
#include "UserInputController.h"

class Game
{
public:
	Game();
	void start();
private:
	UserInputController m_userInputCtrl;
	FrameGenerator m_frameGenerator;
	FrameVizualizer m_frameVizualizer;
};
#endif // !GAME_H