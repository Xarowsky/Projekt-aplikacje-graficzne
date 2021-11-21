#pragma once
#include "game.h"

game::game()
{
	this->initWindow();
	this->initBackgroud();
	this->playerInit();
	this->loop();
}

void game::initBackgroud()
{
	
}

void game::playerInit() 
{
	textureBank = textures();
	this->gamePlayer = new player(textureBank.getPlayerTexture());
}

void game::initWindow() 
{
	this->window = new sf::RenderWindow(sf::VideoMode(1280, 720), "SFML works!");
	window->setFramerateLimit(60);
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
	this->gamePlayer->render(*window);
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