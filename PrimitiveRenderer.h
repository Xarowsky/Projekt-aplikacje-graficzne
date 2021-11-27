#pragma once
#include <SFML/Graphics.hpp>
#include "Point2D.h"
#include "LineSegment.h"
/**@brief
*Klasa zawierajaca metody pozwalajace rysowac prymitywy
* 
***/
class PrimitiveRenderer
{
public:
	/**@brief
	*narysowanie punktu
	*/
	void drawPoint(sf::RenderWindow *window, Point2D *point);
	/**@brief
	*narysowanie lini
	*/
	void drawLine(sf::RenderWindow *window, LineSegment *line);

	/**@brief
	*narysowanie kola
	*/
	void drawCircle(RenderWindow * window, float radius, Color circle_color, float outline, Color out_color, Vector2f pos);
	/**@brief
	*narysownie prostokatu
	*/
	void drawRectangle(RenderWindow* window, Vector2f dimensions, Color rect_color, Vector2f pos);
	/**@brief
	*narysowanie poligonow
	*/
	void drawPolygons(RenderWindow* window, float radius, int points, Color poly_color, Vector2f pos);
	PrimitiveRenderer();
private:
	
};

