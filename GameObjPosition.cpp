#include "GameObjPosition.h"

GameObjPosition::GameObjPosition()
	: x(0)
	, y(0)
{
}

GameObjPosition::GameObjPosition(int oX = 0, int oY = 0)
	: x(oX)
	, y(oY)
{
}

void GameObjPosition::setX(int oX)
{
	x = oX;
}

void GameObjPosition::setY(int oY)
{
	y = oY;
}
