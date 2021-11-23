#include "PrimitiveRenderer.h"

void PrimitiveRenderer::drawPoint(sf::RenderWindow *window, Point2D* point)
{
	point->draw(*window, RenderStates::Default);
}

void PrimitiveRenderer::drawLine(sf::RenderWindow* window, LineSegment* line)
{
	line->draw(*window, sf::RenderStates::Default);
}
