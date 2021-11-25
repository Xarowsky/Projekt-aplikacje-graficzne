#pragma once
#include <SFML/Graphics.hpp>
#include "Point2D.h"
#include "LineSegment.h"

class PrimitiveRenderer
{
public:
	//Custom entities
	void drawPoint(sf::RenderWindow *window, Point2D *point);
	void drawLine(sf::RenderWindow *window, LineSegment *line);

	//Primitive shapes
	void drawCircle(RenderWindow * window, float radius, Color circle_color, float outline, Color out_color, Vector2f pos);
	void drawRectangle(RenderWindow* window, Vector2f dimensions, Color rect_color, Vector2f pos);
	void drawPolygons(RenderWindow* window, float radius, int points, Color poly_color, Vector2f pos);
	PrimitiveRenderer();
private:
	
};

