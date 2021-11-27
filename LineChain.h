#pragma once
#include <vector>
#include "LineSegment.h"

/**@brief
*Metoda rysujaca serie lini
* 
***************************************************/


class LineChain
{
	void drawLineChain(sf::RenderWindow* window, std::vector<LineSegment>, LineSegment *line);
};

