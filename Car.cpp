#include "Car.h"

Car::Car(GameObjPosition pos)
	: m_carPosition(pos)
	, m_movedLeft(false)
	, m_movedRight(false)
{
}

void Car::calcLeft()
{
	if (m_carPosition.getY() - 2 != constants::ROAD_LEFT_BORDER)
	{
		m_carPosition.setY(m_carPosition.getY() - 1);
		m_movedLeft = true;
	}
}

void Car::calcRight()
{
	if (m_carPosition.getY() + 2 != constants::ROAD_RIGHT_BORDER)
	{
		m_carPosition.setY(m_carPosition.getY() + 1);
		m_movedRight = true;
	}
}

bool Car::isMovedLeft()
{
	return m_movedLeft;
}

bool Car::isMovedRight()
{
	return m_movedRight;
}

void Car::resetMove()
{
	m_movedLeft = false;
	m_movedRight = false;
}