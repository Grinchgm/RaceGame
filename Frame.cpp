#include "Frame.h"
#include<iostream>



Frame::Frame()
	: m_car(GameObjPosition(constants::ROW - 4, constants::CAR_INIT_POSITION))
	, m_obstacles(GameObjPosition(constants::TOP_OF_SCREEN,
		std::rand() % (constants::ROAD_RIGHT_BORDER - constants::ROAD_LEFT_BORDER) + constants::ROAD_LEFT_BORDER))
{
	for (int i = 0; i < constants::ROW; i++)
		for (int j = 0; j < constants::COLUMN; j++)
			m_screen[i][j] = ' ';
}

void Frame::updateFrame()
{
	buildCar();
	buildRoad();
	buildObstacles();
}

bool Frame::checkForCollision()
{
	if (m_car.getPosition().getX() == m_obstacles.getPosition().getX() &&
		m_car.getPosition().getY() == m_obstacles.getPosition().getY())
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Frame::update(IUserInputCommand * command)
{
	if (command)
	{
		command->proceed(m_car);
		//for (auto obstacle : m_obstacles)
		command->proceed(m_obstacles);
	}
}

void Frame::buildCar()
{
	if (m_car.isMovedLeft())
	{
		m_screen[m_car.getPosition().getX() + 0][m_car.getPosition().getY() + 1] = ' ';
		m_screen[m_car.getPosition().getX() + 1][m_car.getPosition().getY() + 2] = ' ';
		m_screen[m_car.getPosition().getX() + 2][m_car.getPosition().getY() + 1] = ' ';
		m_screen[m_car.getPosition().getX() + 3][m_car.getPosition().getY() + 2] = ' ';

		m_screen[m_car.getPosition().getX() + 0][m_car.getPosition().getY() + 0] = 'x';
		m_screen[m_car.getPosition().getX() + 1][m_car.getPosition().getY() - 1] = 'x';
		m_screen[m_car.getPosition().getX() + 2][m_car.getPosition().getY() + 0] = 'x';
		m_screen[m_car.getPosition().getX() + 3][m_car.getPosition().getY() - 1] = 'x';

		m_car.resetMove();
	}
	else if (m_car.isMovedRight())
	{
		m_screen[m_car.getPosition().getX() + 0][m_car.getPosition().getY() - 1] = ' ';
		m_screen[m_car.getPosition().getX() + 1][m_car.getPosition().getY() - 2] = ' ';
		m_screen[m_car.getPosition().getX() + 2][m_car.getPosition().getY() - 1] = ' ';
		m_screen[m_car.getPosition().getX() + 3][m_car.getPosition().getY() - 2] = ' ';

		m_screen[m_car.getPosition().getX() + 0][m_car.getPosition().getY() + 0] = 'x';
		m_screen[m_car.getPosition().getX() + 1][m_car.getPosition().getY() + 1] = 'x';
		m_screen[m_car.getPosition().getX() + 2][m_car.getPosition().getY() + 0] = 'x';
		m_screen[m_car.getPosition().getX() + 3][m_car.getPosition().getY() + 1] = 'x';

		m_car.resetMove();
	}
	else
	{
		if (m_car.getPosition().getX() < 25)
		{
			m_screen[m_car.getPosition().getX()][m_car.getPosition().getY()] = 'x';

			m_screen[m_car.getPosition().getX() + 1][m_car.getPosition().getY() - 1] = 'x';
			m_screen[m_car.getPosition().getX() + 1][m_car.getPosition().getY() + 0] = 'x';
			m_screen[m_car.getPosition().getX() + 1][m_car.getPosition().getY() + 1] = 'x';

			m_screen[m_car.getPosition().getX() + 2][m_car.getPosition().getY() + 0] = 'x';

			m_screen[m_car.getPosition().getX() + 3][m_car.getPosition().getY() - 1] = 'x';
			m_screen[m_car.getPosition().getX() + 3][m_car.getPosition().getY() + 0] = 'x';
			m_screen[m_car.getPosition().getX() + 3][m_car.getPosition().getY() + 1] = 'x';
			m_car.resetMove();
		}
	}
}

void Frame::buildRoad()
{
	for (int i = 1; i < constants::ROW; i++)
	{
		if (i % 3 == 0)
		{
			m_screen[i][constants::ROAD_LEFT_BORDER - 1] = '#';
			m_screen[i][constants::ROAD_RIGHT_BORDER + 1] = '#';
		}
		m_screen[i][constants::ROAD_LEFT_BORDER] = '#';
		m_screen[i][constants::ROAD_RIGHT_BORDER] = '#';
	}
}

void Frame::buildObstacles()
{
	m_screen[m_obstacles.getPosition().getX()][m_obstacles.getPosition().getY()] = '@';
	if (m_obstacles.getPosition().getX() > constants::TOP_OF_SCREEN)
	{
		m_screen[m_obstacles.getPosition().getX() - 1][m_obstacles.getPosition().getY() + 0] = ' ';
		m_screen[m_obstacles.getPosition().getX() + 0][m_obstacles.getPosition().getY() + 0] = '@';
	}
	if (m_obstacles.getPosition().getX() == 25)
	{
		m_screen[m_obstacles.getPosition().getX()][m_obstacles.getPosition().getY()] = ' ';
		m_obstacles.setPosition(constants::TOP_OF_SCREEN, std::rand() %
			(constants::ROAD_RIGHT_BORDER - constants::ROAD_LEFT_BORDER) + constants::ROAD_LEFT_BORDER);
	}
}