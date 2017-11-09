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

void DashBoard::calcDown()
{
	m_odometr++;
}

void DashBoard::calcForward()
{
	if (m_speed < constants::MAX_CAR_SPEED)
	{
		m_speed += constants::CAR_SPEED_INCREASE;
	}
}

void DashBoard::calcBack()
{
	if (m_speed > constants::MIN_CAR_SPEED)
	{
		m_speed -= constants::CAR_SPEED_INCREASE;
	}
}
