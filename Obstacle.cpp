#include "Obstacle.h"

Obstacle::Obstacle(GameObjPosition pos)
	: m_obstaclePosition(pos)
{

}

void Obstacle::calcDown()
{
	/*
	int randColumn = rand() % (COLUMN - 2) + 2;
	for (int i = 1;; i++)
	{
		if (rand() % 10 == 1)
			m_screen[i][49] = '¤';
	}
	*/
}

GameObjPosition Obstacle::getPosition() const
{
	return m_obstaclePosition;
}
