#include"FrameVizualizer.h"
#include <iostream>

void FrameVizualizer::draw(Frame& frame) const
{
	system("cls");
	for (int i = 0; i < constants::ROW; i++)
	{
		for (int j = 0; j < constants::COLUMN; j++)
		{
			std::cout << frame.getScreenElement(i, j);
		}
		std::cout << std::endl;
	}
}
