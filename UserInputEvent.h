#ifndef USER_INPUT_EVENT_H
#define USER_INPUT_EVENT_H

#include "IGameObj.h"

class NoInput : public IUserInputCommand
{
public:
	virtual void proceed(IGameObj& gameObj)
	{
		gameObj.calcDown();
	}
};

class Left : public IUserInputCommand
{
public:
	virtual void proceed(IGameObj& gameObj)
	{
		gameObj.calcLeft();
	}
};

class Right : public IUserInputCommand
{
public:
	virtual void proceed(IGameObj& gameObj)
	{
		gameObj.calcRight();
	}
};

class Forward : public IUserInputCommand
{
public:
	virtual void proceed(IGameObj& gameObj)
	{
		gameObj.calcForward();
	}
};

class Back : public IUserInputCommand
{
public:
	virtual void proceed(IGameObj& gameObj)
	{
		gameObj.calcBack();
	}
};

#endif //USER_INPUT_EVENT_H