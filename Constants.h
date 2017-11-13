#ifndef CONSTANTS_H
#define CONSTANTS_H

namespace constants
{
	static const int ROW = 26;
	static const int COLUMN = 25;
	static const int OBSTACLES_COUNT = 5;
	static const int CAR_INIT_POSITION = COLUMN / 2;
	static const int ROAD_LEFT_BORDER = 1;
	static const int ROAD_RIGHT_BORDER = 23;
	static const int TOP_OF_SCREEN = 0;
	static const int BOTTOM_OF_SCREEN = 25;
	static const int TIMER_INITIAL_VALUE = 50;
	static const int TIMER_MIN_VALUE = -10;
	static const int MIN_CAR_SPEED = 10;
	static const int MAX_CAR_SPEED = 300;
	static const int CAR_SPEED_INCREASE = 5;
} //constants

#endif //!CONSTANTS_H