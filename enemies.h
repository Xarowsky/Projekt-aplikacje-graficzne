#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
/**@brief
*Klasa przeciwnikow
*/
class enemies
{
public:
	/**@brief
	*Metoda rysujaca przeciwnikow
	*/
	void drawEnemies(RenderWindow* window, float radius, int points);
	/**@brief
	*Metoda logiki przeciwnikow
	*/
	void updateEnemy();

	sf::Color enemyColor;
	CircleShape enemy;
	float speed;
	enemies();
	enemies(float speed, RenderWindow *window, sf::Color col);
	enemies(float x, float y);
	~enemies();
};

