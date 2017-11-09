#ifndef DASH_BOARD_H
#define DASH_BOARD_H

#include "GameObjPosition.h"
#include "Constants.h"
#include "IGameObj.h"
#include <chrono>
#include <thread>

class DashBoard : public IGameObj
{
public:
	DashBoard();
	DashBoard(GameObjPosition pos);
	~DashBoard();
	virtual void calcLeft() override {};
	virtual void calcRight() override {};
	virtual void calcDown() override;
	virtual void calcForward() override;
	virtual void calcBack() override;
	int getSpeed() const;
	int getOdometr() const;
private:
	GameObjPosition m_dashBoardPosition;
	int m_speed;
	int m_odometr;
};

inline int DashBoard::getSpeed() const { return m_speed; }
inline int DashBoard::getOdometr() const { return m_odometr; }

#endif DASH_BOARD_H