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
	this->menuOff = false;
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
	if (!mainBuffer.loadFromFile("assets/louda.wav"))
		exit(-1);
	mainSound.setBuffer(mainBuffer);
	gotHit.setBuffer(oof);
	gotHit.setPitch(2);
	mainSound.play();
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
		this->cleanupObjects();
	}
}


void game::windowRefresh()
{
	this->window->clear();
	gameMenu.draw(*window);
	gameMenu.updateVolume(mainSound.getVolume());
	if (gameMenu.GetPressedItem() == 0 && isPressed == true)
	{
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
		if (!gameover)
		{
			this->gamePlayer->render(*window);
			death_sound.play();
		}
		gamegui.renderGUI(window);
		gameMenu.inGameVolume(mainSound.getVolume(), window);
	}
	if (gameMenu.GetPressedItem() == 1 && isPressed == true )
	{
		exit(0);
	}
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
			if (event.key.code == sf::Keyboard::Up)
			{
				if(!isPressed)
					gameMenu.MoveUp();
			}
			if (event.key.code == sf::Keyboard::Down)
			{
				if(!isPressed)
					gameMenu.MoveDown();
			}
			if (event.key.code == sf::Keyboard::Enter)
			{
				isPressed = true;
				menuOff = true;
			}
			if (event.key.code == sf::Keyboard::Left) {
				if(mainSound.getVolume() >= 0)
					mainSound.setVolume(mainSound.getVolume() - 1);
			}
			if (event.key.code == sf::Keyboard::Right) {
				if (mainSound.getVolume() <= 100)
					mainSound.setVolume(mainSound.getVolume() + 1);
			}
			break;
		}
	}
}

bool game::isColliding(Sprite s1, CircleShape s2)
{
	return s1.getGlobalBounds().intersects(s2.getGlobalBounds());
}


void game::cleanupObjects()
{
	std::vector<gameObject*>::iterator itPro = ProjectileBank.begin();
	std::vector<enemies*>::iterator itEne = enemies_list.begin();

	while (itPro != ProjectileBank.end() && itEne != enemies_list.end())
	{
		for (itPro; itPro != ProjectileBank.end(); itPro++)
		{
			if ((*itPro)->objectSprite.getPosition().x > window->getSize().x)
			{
				delete (*itPro);
				itPro = ProjectileBank.erase(itPro);
				break;
			}
		}

		for (itEne = enemies_list.begin(); itEne != enemies_list.end(); itEne++)
		{
			if ((*itEne)->enemy.getPosition().x < 0)
			{
				delete (*itEne);
				itEne = enemies_list.erase(itEne);
				break;
			}
		}
	}
}


void game::updateObjects()
{
	std::vector<gameObject*>::iterator itPro = ProjectileBank.begin();
	std::vector<enemies*>::iterator itEne = enemies_list.begin();

	for (itPro; itPro != ProjectileBank.end(); itPro++)
	{
		if ((*itPro)->type == "projectile")
		{
			((projectile*)(*itPro))->update();
			for (itEne = enemies_list.begin(); itEne != enemies_list.end(); itEne++)
			{
				if (isColliding((*itPro)->objectSprite,(*itEne)->enemy))
				{
					sound.play();
					delete (*itEne);
					delete (*itPro);
					itEne = enemies_list.erase(itEne);
					itPro = ProjectileBank.erase(itPro);
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
				delete (*itEne);
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
	this->ProjectileBank.push_back(newProjectile);
}

void game::renderObjects()
{
	std::vector<gameObject*>::iterator it = ProjectileBank.begin();
	for (it; it != ProjectileBank.end(); it++)
	{
		(*it)->render(*window);
	}
}

void game::spawnEnemies()
{
	int amount = rand() % (8 + difficulty);
	if (gamegui.getPoints() > 250) {
		difficulty += 4;
		delay2 = 2;
	}
	if (gamegui.getPoints() > 500) {
		difficulty += 4;
		delay2 = 2;
	}
	if (gamegui.getPoints() > 1000) {
		delay2 = 1;
	}
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