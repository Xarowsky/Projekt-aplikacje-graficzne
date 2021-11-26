#include "enemies.h"

void enemies::drawEnemies(RenderWindow* window, float radius, int points)
{
	enemy.setRadius(radius);
	enemy.setPointCount(points);
	enemy.setFillColor(enemyColor);
	window->draw(enemy);
}

void enemies::updateEnemy()
{
	enemy.move(speed, 0.f);
}

enemies::enemies()
{
	speed = -5.f;
}

enemies::enemies(float speed, RenderWindow *window, sf::Color col)
{
	this->speed = speed;
	this->enemy.setPosition(window->getSize().x, (rand() % (window->getSize().y - 50)) + 25);
	enemyColor = col;
}

enemies::enemies(float x, float y)
{
	this->speed = 0.f;
	this->enemy.setPosition(x,y);
}

enemies::~enemies()
{
	enemy.~CircleShape();
}

