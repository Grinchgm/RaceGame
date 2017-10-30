#include "Game.h"

Game::Game()
	: m_frameGenerator(), m_userInputCtrl()
{
}

void Game::start()
{
	while (true)
	{
		m_userInputCtrl.updateUserInput(m_frameGenerator);
		if (!m_frameGenerator.build())
		{
			// TODO: GAME OVER
			break;
		}
		m_frameVizualizer.draw(m_frameGenerator.getCurentFrame());
		m_frameGenerator.waitForNewCycle();
	}
}