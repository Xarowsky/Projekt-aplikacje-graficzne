#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
class enemies
{
public:
	void drawEnemies(RenderWindow* window, float radius, int points);
	void updateEnemy();
	sf::Color enemyColor;
	CircleShape enemy;
	float speed;
	enemies();
	enemies(float speed, RenderWindow *window, sf::Color col);
	enemies(float x, float y);
	~enemies();
};

