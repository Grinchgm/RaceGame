#ifndef ROAD_H
#define ROAD_H

#include "GameObjPosition.h"
#include "Constants.h"

class Road
{
public:
	Road();
	~Road();
private:
	GameObjPosition m_leftBorder;
	GameObjPosition m_rightBorder;
};

#endif // !ROAD_H