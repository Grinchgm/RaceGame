#ifndef CAR_H
#define CAR_H

#include "GameObjPosition.h"
#include "IGameObj.h"

class Car : public IGameObj
{
public:
	Car(GameObjPosition pos);
		
	virtual void calcLeft() override; // TODO:
	virtual void calcRight() override; // TODO:
	virtual void calcDown() override  {};
	virtual void calcForward() override {};
	virtual void calcBack() override  {};
	GameObjPosition getPosition() const;
	
private:
	GameObjPosition m_carPosition;
};
#endif // !CAR_H
