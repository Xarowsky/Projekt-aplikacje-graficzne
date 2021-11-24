#include "PrimitiveRenderer.h"

void PrimitiveRenderer::drawPoint(sf::RenderWindow *window, Point2D* point)
{
	point->draw(*window, RenderStates::Default);
}

void PrimitiveRenderer::drawLine(sf::RenderWindow* window, LineSegment* line)
{
	line->draw(*window, sf::RenderStates::Default);
}

void PrimitiveRenderer::drawCircle(RenderWindow* window, float radius, Color circle_color, float outline, Color out_color, Vector2f pos)
{
	sf::CircleShape circle(radius);
	circle.setFillColor(circle_color);
	circle.setOutlineThickness(outline);
	circle.setOutlineColor(out_color);
	circle.setPosition(pos);
	window->draw(circle);
}

void PrimitiveRenderer::drawRectangle(RenderWindow* window, Vector2f dimensions, Color rect_color, Vector2f pos)
{
	sf::RectangleShape rect(dimensions);
	rect.setFillColor(rect_color);
	rect.setPosition(pos);
	window->draw(rect);
}

void PrimitiveRenderer::drawPolygons(RenderWindow* window, float radius, int points, Color poly_color, Vector2f pos)
{
	sf::CircleShape polygon(radius, points);
	polygon.setFillColor(poly_color);
	polygon.setPosition(pos);
	window->draw(polygon);
}
