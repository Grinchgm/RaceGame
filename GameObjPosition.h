#ifndef GAME_ODJ_POSITION_H
#define GAME_ODJ_POSITION_H

class GameObjPosition
{
public:
	GameObjPosition();
	GameObjPosition(int x, int y);
	inline int getX() const { return x; };
	inline int getY() const { return y; }
	void setX(int oX);
	void setY(int oY);
		
private:
	int x;
	int y;
};
#endif // !GAME_ODJ_POSITION_H