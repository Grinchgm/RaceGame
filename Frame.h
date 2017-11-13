#ifndef FRAME_H
#define FRAME_H

#include "IUserInputCommand.h"
#include "IGameObj.h"
#include "Car.h"
#include "DashBoard.h"
#include "Road.h"
#include "Obstacle.h"
#include "Constants.h"

class Frame
{
public:
	Frame();
	void updateFrame();
	bool checkForCollision();
	char getScreenElement(int oX, int oY) const;
	void update(IUserInputCommand* command);

public:
	char m_screen[constants::ROW][constants::COLUMN];
	Car m_car;
	DashBoard m_dashboard;
	Road m_road;
	Obstacle m_obstacles;

	void buildCar();
	void buildDashBoard();
	void buildObstacles();
	void buildRoad();
};

inline char Frame::getScreenElement(int oX, int oY) const 
{
	return m_screen[oX][oY]; 
};

#endif // !FRAME_H
