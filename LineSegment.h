#pragma once
#include <SFML/Graphics.hpp>
#include "Point2D.h"
using namespace sf;

class LineSegment : public Shape 
{
private:
	VertexArray m_vertices;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
public:
	LineSegment(Vector2f point1, Vector2f point2, Color point_color);
};

