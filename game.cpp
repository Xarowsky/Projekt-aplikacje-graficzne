#pragma once
#include "game.h"
#include "LineSegment.h"
#include "PrimitiveRenderer.h"


game::game()
{
	textureBank = textures();
	this->initWindow();
	this->initBackgroud();
	this->initSound();
	//this->initBullets();
	this->playerInit();
	this->initGUI();
	this->loop();
}


void game::initBackgroud()
{
	background = new gameObject(textureBank.getBackgroundTexture());
}


void game::playerInit() 
{
	this->gamePlayer = new player(textureBank.getPlayerTexture(), window);
}

//void game::initBullets()
//{
//	projectile* newProjectile = new projectile(textureBank.getPlayerProjectile(), window);
//	this->gameObjectBank.push_back(newProjectile);
//}

void game::initGUI()
{
	if (!this->font.loadFromFile("assets/impact.ttf"))
		std::cout << "ERROR:Failed to load font" << "\n";

	this->pointText.setPosition(10.f, 10.f);
	this->pointText.setFont(this->font);
	this->pointText.setCharacterSize(20);
	this->pointText.setFillColor(sf::Color::White);

	this->hpText.setPosition(this->window->getSize().x / 1.2, 10.f);
	this->hpText.setFont(this->font);
	this->hpText.setCharacterSize(20);
	this->hpText.setFillColor(sf::Color::White);

	std::stringstream point_stream, hp_stream;
	this->points = 0;

	point_stream << "Points: " << this->points;

	this->pointText.setString(point_stream.str());

	hp_stream << "HP:";

	this->hpText.setString(hp_stream.str());
}


void game::renderGUI()
{
	PrimitiveRenderer renderer;
	this->window->draw(this->pointText);
	this->window->draw(this->hpText);
	LineSegment line1(sf::Vector2f(1110.f, 10.f), sf::Vector2f(1260.f, 10.f), sf::Color::Red);
	LineSegment line2(sf::Vector2f(1110.f, 40.f), sf::Vector2f(1260.f, 40.f), sf::Color::Red);
	LineSegment line3(sf::Vector2f(1110.f, 10.f), sf::Vector2f(1110.f, 40.f), sf::Color::Red);
	LineSegment line4(sf::Vector2f(1260.f, 10.f), sf::Vector2f(1260.f, 40.f), sf::Color::Red);
	renderer.drawLine(window, &line1);
	renderer.drawLine(window, &line2);
	renderer.drawLine(window, &line3);
	renderer.drawLine(window, &line4);
}

void game::initSound()
{
	if (!buffer.loadFromFile("assets/hit.wav"))
		exit(0);
	sound.setBuffer(buffer);
}


void game::initWindow() 
{
	this->window = new sf::RenderWindow(sf::VideoMode(1280, 720), "Kapitan Bomba",  sf::Style::Close);
	window->setFramerateLimit(60);
	window->setVerticalSyncEnabled(true);
}


void game::updateControls()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		this->gamePlayer->playerMove(-1.f, 0.f, this->window);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		this->gamePlayer->playerMove(1.f, 0.f, this->window);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		this->gamePlayer->playerMove(0.f, -1.f, this->window);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		this->gamePlayer->playerMove(0.f, 1.f, this->window);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		if (timer > delay) {
			this->shoot();
			timer = 0;
		}
	}
}


void game::loop()
{
	Clock clock;
	Clock clock2;
	while (window->isOpen())
	{
		time = clock.getElapsedTime().asSeconds();
		time2 = clock2.getElapsedTime().asSeconds();
		clock.restart();
		clock2.restart();
		timer += time;
		timer2 += time2;
		this->updateControls();
		this->windowCtl();
		this->windowRefresh();
	}
}


void game::windowRefresh()
{
	this->window->clear();
	this->background->render(*window);
	this->updateObjects();
	this->renderObjects();
	this->updateEnemies();
	this->renderEnemies();
	if (timer2 > delay2)
	{
		this->spawnEnemies();
		timer2 = 0;
	}
	this->gamePlayer->render(*window);
	this->renderGUI();
	this->window->display();
}


void game::windowCtl()
{
	sf::Event event;
	while (window->pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			window->close();
			break;
		case sf::Event::KeyPressed:
			if (event.key.code == sf::Keyboard::Escape)
				window->close();
			break;
		}

	}
}

bool game::isColliding(Sprite s1, CircleShape s2)
{
	return s1.getGlobalBounds().intersects(s2.getGlobalBounds());
}


void game::updateObjects()
{
;	std::vector<gameObject*>::iterator it = gameObjectBank.begin();
	for (it; it != gameObjectBank.end(); it++)
	{
		if ((*it)->type == "projectile")
			((projectile*)(*it))->update();
		if (isColliding((*it)->objectSprite, enemy->enemy))
			sound.play();
	}
}

void game::shoot()
{
	projectile* newProjectile = new projectile(textureBank.getPlayerProjectile(), window, gamePlayer->objectSprite.getPosition().x, gamePlayer->objectSprite.getPosition().y);
	this->gameObjectBank.push_back(newProjectile);
}

void game::renderObjects()
{
	std::vector<gameObject*>::iterator it = gameObjectBank.begin();
	for (it; it != gameObjectBank.end(); it++)
	{
		(*it)->render(*window);
	}
}

void game::spawnEnemies()
{
	enemy->enemy.setPosition(window->getSize().x, rand() % window->getSize().y);
	this->enemies_list.push_back(enemy);
}

void game::updateEnemies()
{
	std::vector<enemies*>::iterator it = enemies_list.begin();
	float speed = -5.f;
	for (it; it < enemies_list.end(); it++)
	{
		(*it)->updateEnemy(speed);
	}
}

void game::renderEnemies()
{
	std::vector<enemies *>::iterator it = enemies_list.begin();
	for (it; it != enemies_list.end(); it++)
	{
		(*it)->drawEnemies(window, 20.f, 8, Color::Red);
	}
}