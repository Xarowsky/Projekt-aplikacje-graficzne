#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
class enemies
{
public:
	void drawEnemies(RenderWindow* window, float radius, int points, Color poly_color);
	void updateEnemy(float speed);
	CircleShape enemy;
	float speed;
	enemies();
};

