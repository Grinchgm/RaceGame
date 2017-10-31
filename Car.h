#ifndef CAR_H
#define CAR_H

#include "GameObjPosition.h"
#include "IGameObj.h"
#include "Constants.h"

class Car : public IGameObj
{
public:
	Car(GameObjPosition pos);
	
	virtual void calcLeft() override; // TODO:
	virtual void calcRight() override; // TODO:
	virtual void calcDown() override  {};
	virtual void calcForward() override {};
	virtual void calcBack() override  {};
	bool isMovedLeft();
	bool isMovedRight();
	void resetMove();
	GameObjPosition getPosition() const { return m_carPosition; };
private:
	bool m_movedLeft;
	bool m_movedRight;
	GameObjPosition m_carPosition;
};
#endif // !CAR_H
