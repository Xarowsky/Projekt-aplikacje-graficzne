#include "LineSegment.h"

void LineSegment::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_vertices, states);
}

LineSegment::LineSegment(Vector2f point1, Vector2f point2, Color point_color)
{
	float m;
	int delta_x = abs(point1.x - point2.x);
	int delta_y = abs(point1.y - point2.y);
	m = delta_y / delta_x;
	for (int i = 0 ; i <= point2.x; i++)
	{
		for (int j = 0; j <= point2.y; j++)
		{

		}
	}
}
