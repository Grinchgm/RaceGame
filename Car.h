#ifndef CAR_H
#define CAR_H

#include "GameObjPosition.h"
#include "IGameObj.h"

class Car : public IGameObj
{
public:
	Car(GameObjPosition pos);
		
	virtual void calcLeft(); // TODO:
	virtual void calcRight(); // TODO:
	virtual void calcDown() {};
	virtual void calcForward() {};
	virtual void calcBack() {};
	GameObjPosition getPosition() const;
	
private:
	GameObjPosition m_carPosition;
};
#endif // !CAR_H
