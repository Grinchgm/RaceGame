#include "GameObjPosition.h"

GameObjPosition::GameObjPosition(int oX = 0, int oY = 0)
	: x(oX)
	, y(oY)
{
}

int GameObjPosition::getX()
{
	return x;
}

int GameObjPosition::getY()
{
	return y;
}

void GameObjPosition::setX(int oX)
{
	x = oX;
}

void GameObjPosition::setY(int oY)
{
	y = oY;
}
