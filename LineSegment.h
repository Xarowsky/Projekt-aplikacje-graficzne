#pragma once
#include <SFML/Graphics.hpp>
#include "Point2D.h"
using namespace sf;

class LineSegment : public Shape 
{
private:
	VertexArray m_vertices;
	Vector2f begin;
	Vector2f end;
	Color line_colour;

	virtual std::size_t getPointCount() const override;
	virtual Vector2f getPoint(std::size_t index) const override;
public:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	LineSegment(Vector2f point1, Vector2f point2, Color point_color);
	void calculatePoints();
	Vector2f getPointBegin();
	Vector2f getPointEnd();
	void changePoints(Vector2f Begin, Vector2f End);
};

