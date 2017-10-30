#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "GameObjPosition.h"
#include "IGameObj.h"
#include <iostream>

class Obstacle : public IGameObj
{
public:
	Obstacle(GameObjPosition pos);
		
	virtual void calcLeft() {};
	virtual void calcRight() {};
	virtual void calcDown(); // TODO: move down for each frame
	virtual void calcForward() {};
	virtual void calcBack() {};

	GameObjPosition getPosition() const;
	
private:
	GameObjPosition m_obstaclePosition;
};
#endif OBSTACLE_H