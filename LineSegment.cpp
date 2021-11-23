#include "LineSegment.h"

std::size_t LineSegment::getPointCount() const
{
    return 1;
}

Vector2f LineSegment::getPoint(std::size_t index) const
{
    return m_vertices[index].position;
}

void LineSegment::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_vertices, states);
}

LineSegment::LineSegment(Vector2f point1, Vector2f point2, Color point_color)
{
	begin = point1;
	end = point2;
	this->line_colour = point_color;
    this->calculatePoints();
}

void LineSegment::calculatePoints()
{
	m_vertices.clear();
	m_vertices.resize(0);

    int deltaY = abs(end.y - begin.y);
    int deltaX = abs(end.x - begin.x);

    float increaseM;
    int numberOfPoints;
    Vector2f* discretePoinstCoords;
    float x, y;

    /// 
    /// If the line is horizontal long
    /// 
    if (deltaX > deltaY) {
        increaseM = (float)deltaY / (float)deltaX;
        numberOfPoints = deltaX + 1;

        discretePoinstCoords = new Vector2f[numberOfPoints];

        if (begin.x < end.x) {
            y = begin.y;
            x = begin.x;
            discretePoinstCoords[0] = begin;
            discretePoinstCoords[numberOfPoints - 1] = end;
        }
        else {
            y = end.y;
            x = end.x;
            discretePoinstCoords[0] = end;
            discretePoinstCoords[numberOfPoints - 1] = begin;
        }

        for (int i = 0; i < numberOfPoints; i++) {
            discretePoinstCoords[i] = Vector2f(x, y);
            x++;
            y += increaseM;

            m_vertices.append(
                Vector2f(
                    round(discretePoinstCoords[i].x),
                    round(discretePoinstCoords[i].y)
                )
            );
            m_vertices[i].color = line_colour;
        }
    }
    /// 
    /// if the line is vertical long
    /// 
    else {
        increaseM = (float)deltaX / (float)deltaY;
        numberOfPoints = deltaY + 1;

        discretePoinstCoords = new Vector2f[numberOfPoints];

        if (begin.y < end.y) {
            y = begin.y;
            x = begin.x;
            discretePoinstCoords[0] = begin;
            discretePoinstCoords[numberOfPoints - 1] = end;
        }
        else {
            y = end.y;
            x = end.x;
            discretePoinstCoords[0] = end;
            discretePoinstCoords[numberOfPoints - 1] = begin;
        }

        for (int i = 0; i < numberOfPoints; i++) {
            discretePoinstCoords[i] = Vector2f(x, y);
            y++;
            x += increaseM;

            m_vertices.append(
                Vector2f(
                    round(discretePoinstCoords[i].x),
                    round(discretePoinstCoords[i].y)
                )
            );
            m_vertices[i].color = line_colour;
        }

    }
}

Vector2f LineSegment::getPointBegin()
{
    return begin;
}

Vector2f LineSegment::getPointEnd()
{
    return end;
}

void LineSegment::changePoints(Vector2f Begin, Vector2f End)
{
    this->begin = Begin;
    this->end = End;

    this->calculatePoints();
}
