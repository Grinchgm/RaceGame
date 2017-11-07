#include "Game.h"

Game::Game()
	: m_frameGenerator(), m_userInputCtrl()
{
}

void Game::start()
{
	while (!m_gameOver)
	{
		m_userInputCtrl.updateUserInput(m_frameGenerator);
		if (m_frameGenerator.build())
		{
			m_gameOver = true;
		}
		m_frameVizualizer.draw(m_frameGenerator.getCurentFrame());
		m_frameGenerator.waitForNewCycle();
	}
}