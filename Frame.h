#ifndef FRAME_H
#define FRAME_H

#include <vector>
#include "IUserInputCommand.h"
#include "IGameObj.h"
#include "Car.h"
#include "Obstacle.h"
#include "Constants.h"



class Frame
{
public:
	Frame();
	
	
	void calculateLeft();	// move car left to 1 pos
	void calculateRight(); // move car right to 1 pos
	void buildObstacles();
	bool checkForCollision() {};
	char getScreenElement(int oX, int oY);
	void setScreenElement(int oX, int oY, char ch);
	void update(IUserInputCommand* command);

private:
	char m_screen[ROW][COLUMN];
	Car m_car;
	std::vector<Obstacle> m_obstacles;
};
#endif // !FRAME_H
