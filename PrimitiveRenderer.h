#pragma once
#include <SFML/Graphics.hpp>
#include "Point2D.h"
#include "LineSegment.h"

class PrimitiveRenderer
{
public:
	void drawPoint(sf::RenderWindow *window, Point2D *point);
	void drawLine(sf::RenderWindow *window, LineSegment *line);
private:
	
};

