#include "Frame.h"
#include<iostream>



Frame::Frame()
	: m_car(GameObjPosition(constants::ROW - 4, constants::CAR_INIT_POSITION))
	, m_obstacles(GameObjPosition(constants::TOP_OF_SCREEN,
		std::rand() % (constants::ROAD_RIGHT_BORDER - constants::ROAD_LEFT_BORDER) 
		+ constants::ROAD_LEFT_BORDER))
	, m_dashboard(GameObjPosition(constants::TOP_OF_SCREEN, constants::TOP_OF_SCREEN))
{
	for (int i = 0; i < constants::ROW; i++)
		for (int j = 0; j < constants::COLUMN; j++)
			m_screen[i][j] = ' ';
}

void Frame::updateFrame()
{
	buildCar();
	buildDashBoard();
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
		command->proceed(m_dashboard);
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

void Frame::buildDashBoard()
{
	m_screen[constants::TOP_OF_SCREEN][4] = 'K';
	m_screen[constants::TOP_OF_SCREEN][5] = 'm';
	m_screen[constants::TOP_OF_SCREEN][6] = '/';
	m_screen[constants::TOP_OF_SCREEN][7] = 'H';

	int speed = m_dashboard.getSpeed();
	for (int i = constants::TOP_OF_SCREEN + 2; speed != 0; i--)
	{
		m_screen[constants::TOP_OF_SCREEN][constants::TOP_OF_SCREEN] = ' ';
		m_screen[constants::TOP_OF_SCREEN][i] = static_cast<char>(speed % 10) + '0';
		speed /= 10;
	}

	m_screen[constants::TOP_OF_SCREEN][constants::COLUMN - 2] = 'm';
	int odometr = m_dashboard.getOdometr();
	for (int i = constants::COLUMN - 4; odometr != 0; i--)
	{
		m_screen[constants::TOP_OF_SCREEN][i] = static_cast<char>(odometr % 10) + '0';
		odometr /= 10;
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
			(constants::ROAD_RIGHT_BORDER - constants::ROAD_LEFT_BORDER - 1) 
			+ constants::ROAD_LEFT_BORDER + 1);
	}
}