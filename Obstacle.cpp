#include "Obstacle.h"

Obstacle::Obstacle()
{
}

Obstacle::Obstacle(GameObjPosition pos)
	: m_obstaclePosition(pos)
{

}

void Obstacle::calcDown()
{
	/*if (m_obstaclePosition.getX() < constants::ROW)
	{
		m_obstaclePosition.setX(m_obstaclePosition.getX() + 1);
	}*/
}