#include "LineChain.h"

void LineChain::drawLineChain(sf::RenderWindow *window, std::vector<LineSegment> lines_vector, LineSegment *line)
{
	std::vector<LineSegment>::iterator it;
	lines_vector.push_back(*line);
	for (it = lines_vector.begin(); it < lines_vector.end(); it++)
	{
		(*it).draw(*window, sf::RenderStates::Default);
	}
}
