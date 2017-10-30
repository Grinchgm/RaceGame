#include "Car.h"

Car::Car(GameObjPosition pos)
	: m_carPosition(pos)
{

}

void Car::calcLeft()
{
	if (m_carPosition.getY() - 2 != 2)
	{
		m_screen[m_carTopX - 4][m_carTopY] = ' ';
		m_screen[m_carTopX - 3][m_carTopY + 1] = ' ';
		m_screen[m_carTopX - 2][m_carTopY] = ' ';
		m_screen[m_carTopX - 1][m_carTopY + 1] = ' ';

		m_carTopY--;

		m_screen[m_carTopX - 4][m_carTopY] = 'x';
		m_screen[m_carTopX - 3][m_carTopY - 1] = 'x';
		m_screen[m_carTopX - 2][m_carTopY] = 'x';
		m_screen[m_carTopX - 1][m_carTopY - 1] = 'x';
	}
}

void Car::calcRight()
{
	if (m_carTopY + 2 != 23)
	{
		m_screen[m_carTopX - 4][m_carTopY] = ' ';
		m_screen[m_carTopX - 3][m_carTopY - 1] = ' ';
		m_screen[m_carTopX - 2][m_carTopY] = ' ';
		m_screen[m_carTopX - 1][m_carTopY - 1] = ' ';

		m_carTopY++;

		m_screen[m_carTopX - 4][m_carTopY] = 'x';
		m_screen[m_carTopX - 3][m_carTopY + 1] = 'x';
		m_screen[m_carTopX - 2][m_carTopY] = 'x';
		m_screen[m_carTopX - 1][m_carTopY + 1] = 'x';

	}
}

GameObjPosition Car::getPosition() const
{
	return m_carPosition;
}