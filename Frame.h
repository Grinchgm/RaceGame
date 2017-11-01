#ifndef FRAME_H
#define FRAME_H

#include <vector>
#include "IUserInputCommand.h"
#include "IGameObj.h"
#include "Car.h"
#include "Road.h"
#include "Obstacle.h"
#include "Constants.h"



class Frame
{
public:
	Frame();
	void updateFrame();
	bool checkForCollision() { return true; };
	char getScreenElement(int oX, int oY) const;
	void update(IUserInputCommand* command);

private:
	char m_screen[ROW][COLUMN];
	Car m_car;
	Road m_road;
	Obstacle m_obstacles;

	void buildCar();
	void buildRoad();
	void buildObstacles();
};

inline char Frame::getScreenElement(int oX, int oY) const 
{
	return m_screen[oX][oY]; 
};

#endif // !FRAME_H
