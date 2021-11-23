#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Point2D : public sf::Shape
{
private:
	sf::VertexArray m_vertices;
public:
	Point2D(Vector2f point_vector, Color point_color);
	virtual std::size_t getPointCount() const override;
	virtual Vector2f getPoint(std::size_t index) const override;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

