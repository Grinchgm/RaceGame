#include<iostream>
#include"Game.h"

int main(int argc, char* argv[])
{
	system("mode con cols=25 lines=27");
	system("title Dead Racer");
	system("color 0A");
	
	Game game;
	while (true)
	{
		game.start();
	}

	return 0;
}
