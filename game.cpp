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
	this->playerInit();
	gamegui.initGUI(window);
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


void game::initSound()
{
	if (!buffer.loadFromFile("assets/hit.wav"))
		exit(-1);
	sound.setBuffer(buffer);
	if (!death_buffer.loadFromFile("assets/death.wav"))
		exit(-1);
	death_sound.setBuffer(death_buffer);
	if (!oof.loadFromFile("assets/oof.wav"))
		exit(-1);
	gotHit.setBuffer(oof);
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
		if(!gameover)
			this->updateControls();
		this->windowCtl();
		this->windowRefresh();
		if (gamegui.getHp() <= 0) gameover = true;
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
	if(!gameover)
	{
		this->gamePlayer->render(*window);
		death_sound.play();
	}
	gamegui.renderGUI(window);
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
	std::vector<gameObject*>::iterator itPro = gameObjectBank.begin();
	std::vector<enemies*>::iterator itEne = enemies_list.begin();

	for (itPro; itPro != gameObjectBank.end(); itPro++)
	{
		if ((*itPro)->type == "projectile")
		{
			((projectile*)(*itPro))->update();
			for (itEne = enemies_list.begin(); itEne != enemies_list.end(); itEne++)
			{
				if (isColliding((*itPro)->objectSprite,(*itEne)->enemy))
				{
					sound.play();
					(*itEne)->~enemies();
					(*itPro)->~gameObject();
					itEne = enemies_list.erase(itEne);
					itPro = gameObjectBank.erase(itPro);
					gamegui.updateGUI();
					return;
				}
			}
		}
	}
	if (!gameover)
	{
		for (itEne = enemies_list.begin(); itEne != enemies_list.end(); itEne++)
		{
			if (isColliding(gamePlayer->objectSprite, (*itEne)->enemy))
			{
				gotHit.play();
				(*itEne)->~enemies();
				gamegui.hit(30.f);
				itEne = enemies_list.erase(itEne);
				return;
			}
		}
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
	int amount = rand() % 4 + 2;
	for (int i = 0; i < amount; ++i)
	{
		this->enemies_list.push_back(new enemies(-5.f, window, ColArr[rand() % 5]));
	}	
}

void game::updateEnemies()
{
	std::vector<enemies*>::iterator it = enemies_list.begin();

	for (it; it < enemies_list.end(); it++)
	{
		(*it)->updateEnemy();
	}
}

void game::renderEnemies()
{
	std::vector<enemies *>::iterator it = enemies_list.begin();
	for (it; it != enemies_list.end(); it++)
	{
		(*it)->drawEnemies(window, 20.f, 8);
	}
}