#include "Frame.h"
#include<iostream>



Frame::Frame()
	: m_car(GameObjPosition(ROW - 4, COLUMN / 2)) // todo: initial position
	, m_obstacles()
{
	for (int i = 0; i < ROW; i++)
		for (int j = 0; j < COLUMN; j++)
			m_screen[i][j] = ' ';

	// прорисовка дороги
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

	m_screen[ROW - 1][COLUMN / 2 - 1] = m_screen[ROW - 1][COLUMN / 2] =
		m_screen[ROW - 1][COLUMN / 2 + 1] = 'x';
	m_screen[ROW - 2][COLUMN / 2] = 'x';
	m_screen[ROW - 3][COLUMN / 2 - 1] = m_screen[ROW - 3][COLUMN / 2]
		= m_screen[ROW - 3][COLUMN / 2 + 1] = 'x';
	m_screen[ROW - 4][COLUMN / 2] = 'x';
}


void Frame::calculateLeft()
{
	// если не левая обочина, сместить влево
	
}

void Frame::calculateRight()
{
	
}

void Frame::buildObstacles() //TODO
{
	
}

char Frame::getScreenElement(int i, int j)
{
	return m_screen[i][j];
}

void Frame::setScreenElement(int oX, int oY, char ch)
{
	m_screen[oX][oY] = ch;
}

void Frame::update(IUserInputCommand * command)
{
	if (command)
	{
		command->proceed(m_car);
		for (auto obstacle : m_obstacles)
		{
			command->proceed(obstacle);
		}
	}
}