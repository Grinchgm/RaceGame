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
	inline char getScreenElement(int oX, int oY) {	return m_screen[oX][oY]; };
	void update(IUserInputCommand* command);

private:
	char m_screen[ROW][COLUMN];
	Car m_car;
	Road m_road;
	void buildCar();
	void buildRoad();
	//std::vector<Obstacle> m_obstacles;
};
#endif // !FRAME_H
