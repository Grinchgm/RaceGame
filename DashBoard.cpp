#include "DashBoard.h"



DashBoard::DashBoard()
{
}

DashBoard::DashBoard(GameObjPosition pos)
	: m_dashBoardPosition(pos)
	, m_speed(5)
	, m_odometr(0)
{
}


DashBoard::~DashBoard()
{
}

void DashBoard::calcForward()
{
	if (m_speed < 300)
	{
		m_speed += 5;
	}
}

void DashBoard::calcBack()
{
	if (m_speed > 10)
	{
		m_speed -= 5;
	}
}
