#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "GameObjPosition.h"
#include "IGameObj.h"
#include "Constants.h"
#include <iostream>

class Obstacle : public IGameObj
{
public:
	Obstacle();
	Obstacle(GameObjPosition pos);
		
	virtual void calcLeft() {};
	virtual void calcRight() {};
	virtual void calcDown(); // TODO: move down for each frame
	virtual void calcForward() {};
	virtual void calcBack() {};

	GameObjPosition getPosition() const;
	void setPosition(int oX, int oY);
	
private:
	GameObjPosition m_obstaclePosition;
};

inline GameObjPosition Obstacle::getPosition() const
{
	return m_obstaclePosition;
}

inline void Obstacle::setPosition(int oX, int oY)
{
	m_obstaclePosition.setX(oX);
	m_obstaclePosition.setY(oY);
}

#endif OBSTACLE_H