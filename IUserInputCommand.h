#ifndef IUSER_INPUT_COMAND_H
#define IUSER_INPUT_COMAND_H


class IGameObj;

class IUserInputCommand
{
public:
	virtual void proceed(IGameObj& gameObj) = 0;
};
#endif // !IUSER_INPUT_COMAND_H
