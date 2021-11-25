#include "enemies.h"

void enemies::drawEnemies(RenderWindow* window, float radius, int points, Color poly_color)
{
	enemy.setRadius(radius);
	enemy.setPointCount(points);
	enemy.setFillColor(poly_color);
	window->draw(enemy);
}

void enemies::updateEnemy(float speed)
{
	enemy.move(speed, 0.f);
}

enemies::enemies()
{
}
