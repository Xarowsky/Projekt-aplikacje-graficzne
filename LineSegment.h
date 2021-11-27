#pragma once
#include <SFML/Graphics.hpp>
#include "Point2D.h"
using namespace sf;
/**@brief
*Prymityw - linia
*
**********************/
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
	/**@brief
	*metoda rysujaca obiekt
	*/
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	/**@brief
	*Konstruktor obiektu
	*/
	LineSegment(Vector2f point1, Vector2f point2, Color point_color);
	/**@brief
	*metoda obliczajac punkty lini
	*/
	void calculatePoints();
	/**@brief
	*getter punktu poczatkowego odcinka
	*/
	Vector2f getPointBegin();
	/**@brief
	*getter punktu konczacego odcinek
	*/
	Vector2f getPointEnd();
	/**@brief
	*metoda zmiany punktow poczatkowe oraz koncowego odcinka
	*/
	void changePoints(Vector2f Begin, Vector2f End);
};

