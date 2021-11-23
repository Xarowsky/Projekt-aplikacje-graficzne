#include "Point2D.h"

void Point2D::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_vertices, states);
}

Point2D::Point2D(Vector2f point_vector, Color point_color)
{
	m_vertices.append(Vertex(point_vector, point_color));
}

std::size_t Point2D::getPointCount() const
{
	return 1;
}

Vector2f Point2D::getPoint(std::size_t index) const
{
	return m_vertices[index].position;
}
