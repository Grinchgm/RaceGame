#ifndef GAME_ODJ_POSITION_H
#define GAME_ODJ_POSITION_H

class GameObjPosition
{
public:
	GameObjPosition();
	GameObjPosition(int x, int y);
	int getX() const;
	int getY() const;
	void setX(int oX);
	void setY(int oY);
		
private:
	int x;
	int y;
};

inline int GameObjPosition::getX() const { return x; }
inline int GameObjPosition::getY() const { return y; }
#endif // !GAME_ODJ_POSITION_H