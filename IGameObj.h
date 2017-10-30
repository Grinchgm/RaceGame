#ifndef IGAME_OBJ_H
#define IGAME_OBJ_H

class IGameObj
{
public:
	virtual void calcLeft() = 0;
	virtual void calcRight() = 0;
	virtual void calcDown() = 0;
	virtual void calcForward() = 0;
	virtual void calcBack() = 0;
};
#endif // !IGAME_OBJ_H