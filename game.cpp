#pragma once
#include "game.h"


game::game()
{
	textureBank = textures();
	this->initWindow();
	this->initBackgroud();
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

	this->hpText.setPosition(this->window->getSize().x / 1.1, 10.f);
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
	this->window->draw(this->pointText);
	this->window->draw(this->hpText);
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
		this->shoot();
}


void game::loop()
{
	while (window->isOpen())
	{
		this->updateControls();
		this->windowCtl();
		this->windowRefresh();
	}
}


void game::windowRefresh()
{
	this->window->clear();
	this->background->render(*window);
	//this->newProjectile->render(*window);
	this->updateObjects();
	this->renderObjects();
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


void game::updateObjects()
{
	std::list<gameObject*>::iterator it = gameObjectBank.begin();
	for (it; it != gameObjectBank.end(); it++)
	{
		if ((*it)->type == "projectile")
			((projectile*)(*it))->update();
	}
}


void game::shoot()
{
	projectile* newProjectile = new projectile(textureBank.getPlayerProjectile(), window, gamePlayer->objectSprite.getPosition().x, gamePlayer->objectSprite.getPosition().y);
	this->gameObjectBank.push_back(newProjectile);
}


void game::renderObjects()
{
	std::list<gameObject*>::iterator it = gameObjectBank.begin();
	for (it; it != gameObjectBank.end(); it++)
	{
		(*it)->render(*window);
	}
}