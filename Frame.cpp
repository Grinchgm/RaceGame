#include "Frame.h"
#include<iostream>



Frame::Frame()
	: m_car(GameObjPosition(ROW - 4, CAR_INIT_POSITION)) // todo: initial position
	//, m_obstacles()
{
	for (int i = 0; i < ROW; i++)
		for (int j = 0; j < COLUMN; j++)
			m_screen[i][j] = ' ';
	/*
	// прорисовка дороги
	

	m_screen[ROW - 1][COLUMN / 2 - 1] = m_screen[ROW - 1][COLUMN / 2] =
		m_screen[ROW - 1][COLUMN / 2 + 1] = 'x';
	m_screen[ROW - 2][COLUMN / 2] = 'x';
	m_screen[ROW - 3][COLUMN / 2 - 1] = m_screen[ROW - 3][COLUMN / 2]
		= m_screen[ROW - 3][COLUMN / 2 + 1] = 'x';
	m_screen[ROW - 4][COLUMN / 2] = 'x';
	*/
}

void Frame::updateFrame()
{
	buildCar();
	buildRoad();
}

/*
void Frame::setScreenElement(int oX, int oY, char ch)
{
	m_screen[oX][oY] = ch;
}
*/

void Frame::update(IUserInputCommand * command)
{
	if (command)
	{
		command->proceed(m_car);
		/*
		for (auto obstacle : m_obstacles)
		{
			command->proceed(obstacle);
		}
		*/
	}
}

void Frame::buildCar()
{
	if (m_car.isMovedLeft())
	{
		m_screen[m_car.getPosition().getX()][m_car.getPosition().getY() + 1] = ' ';
		m_screen[m_car.getPosition().getX() + 1][m_car.getPosition().getY() + 2] = ' ';
		m_screen[m_car.getPosition().getX() + 2][m_car.getPosition().getY() + 1] = ' ';
		m_screen[m_car.getPosition().getX() + 3][m_car.getPosition().getY() + 2] = ' ';

		m_screen[m_car.getPosition().getX()][m_car.getPosition().getY()] = 'x';
		m_screen[m_car.getPosition().getX() + 1][m_car.getPosition().getY() - 1] = 'x';
		m_screen[m_car.getPosition().getX() + 2][m_car.getPosition().getY()] = 'x';
		m_screen[m_car.getPosition().getX() + 3][m_car.getPosition().getY() - 1] = 'x';

		m_car.resetMove();
	}
	else if (m_car.isMovedRight())
	{
		m_screen[m_car.getPosition().getX()][m_car.getPosition().getY() - 1] = ' ';
		m_screen[m_car.getPosition().getX() + 1][m_car.getPosition().getY() - 2] = ' ';
		m_screen[m_car.getPosition().getX() + 2][m_car.getPosition().getY() - 1] = ' ';
		m_screen[m_car.getPosition().getX() + 3][m_car.getPosition().getY() - 2] = ' ';

		m_screen[m_car.getPosition().getX()][m_car.getPosition().getY()] = 'x';
		m_screen[m_car.getPosition().getX() + 1][m_car.getPosition().getY() + 1] = 'x';
		m_screen[m_car.getPosition().getX() + 2][m_car.getPosition().getY()] = 'x';
		m_screen[m_car.getPosition().getX() + 3][m_car.getPosition().getY() + 1] = 'x';

		m_car.resetMove();
	}
	else
	{
		m_screen[m_car.getPosition().getX()][m_car.getPosition().getY()] = 'x';

		m_screen[m_car.getPosition().getX() + 1][m_car.getPosition().getY() - 1]
			= m_screen[m_car.getPosition().getX() + 1][m_car.getPosition().getY()] 
			= m_screen[m_car.getPosition().getX() + 1][m_car.getPosition().getY() + 1] = 'x';

		m_screen[m_car.getPosition().getX() + 2][m_car.getPosition().getY()] = 'x';

		m_screen[m_car.getPosition().getX() + 3][m_car.getPosition().getY() - 1]
			= m_screen[m_car.getPosition().getX() + 3][m_car.getPosition().getY()]
			= m_screen[m_car.getPosition().getX() + 3][m_car.getPosition().getY() + 1] = 'x';
	}
}

void Frame::buildRoad()
{
	for (int i = 1; i < ROW; i++)
	{
		if (i % 3 == 0)
		{
			m_screen[i][0] = '#';
			m_screen[i][COLUMN - 1] = '#';
		}
		m_screen[i][1] = '#';
		m_screen[i][COLUMN - 2] = '#';
	}
}
