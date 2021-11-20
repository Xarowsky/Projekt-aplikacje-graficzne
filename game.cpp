#pragma once
#include "game.h"

game::game()
{

}

game::game(int scrHeight, int scrWidth, sf::RenderWindow *win)
{
	textureBank = textures();
	gamePlayer = player(textureBank.getPlayerTexture());
	window = win;
	screenHeight = scrHeight;
	screenWidth = scrWidth;
}

void game::loop()
{
	while (window->isOpen())
	{
		gamePlayer.playerControls(screenWidth, screenHeight);
		this->windowCtl();
		this->windowRefresh();
	}
}

void game::windowRefresh()
{
	window->clear(sf::Color::Green);
	window->draw(gamePlayer.objectSprite);
	window->display();
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