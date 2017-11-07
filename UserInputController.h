#ifndef USER_INPUT_CONTROLLER_H
#define USER_INPUT_CONTROLLER_H

#include "FrameGenerator.h"
#include "UserInputEvent.h"
#include <conio.h>

class UserInputController
{
public:
	UserInputController() {}

	void updateUserInput(FrameGenerator& generator)
	{
		int userInput = 0;
		if (_kbhit())
		{
			userInput = _getch();
		}
		IUserInputCommand* currentCommand = generateUserInputEvent(userInput);
		generator.fireUserCommand(currentCommand);
		delete currentCommand;
	}

private:
	enum InputType
	{
		UpCmd = 72,
		DownCmd = 80,
		LeftCmd = 75,
		RightCmd = 77
	};

	IUserInputCommand* generateUserInputEvent(int userInput)
	{
		switch (userInput)
		{
		case UpCmd:
			return new Forward();
			break;
		case DownCmd:
			return new Back();
			break;
		case LeftCmd:
			return new Left();
			break;
		case RightCmd:
			return new Right();
			break;
		default:
			return new NoInput();
			break;
		}
	}
};
#endif //USER_INPUT_CONTROLLER_H
