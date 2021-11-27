#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <sstream>
#include <iostream>
#include "PrimitiveRenderer.h"
/**@brief
*Klasa zawierajaca elementy interfejsu oraz powiazane metody
* 
*******************************************************************************/
class GUI
{
private:
	sf::Font menu_font;
	sf::Font game_over_font;
	sf::Text game_over_text;
	sf::Text pointText;
	sf::Text hpText;
	float hp;
	int points;

public:

	GUI();

	/**@brief
	*inicjalizacja interfejsu
	*/	
	void initGUI(sf::RenderWindow* window);
	/**@brief
	*renderowanie ekranu
	*/
	void renderGUI(sf::RenderWindow *win);
	/**@brief
	*odswiezenie stanu interfejsu
	*/
	void updateGUI();
	/**@brief
	*zmiana statusu zdrowia
	*/
	void hit(float damage);
	/**@brief
	*getter zdrowia
	*/
	float getHp();
	/**@brief
	*getter punktow
	*/
	float getPoints();
};