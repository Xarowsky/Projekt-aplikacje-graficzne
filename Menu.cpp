#include "Menu.h"

Menu::Menu()
{
	if (!menu_font.loadFromFile("assets/impact.ttf"))
	{
		exit(-1);
	}

	if (!menuTexture.loadFromFile("assets/menu.jpg"))
		exit(0);

	menuSprite.setTexture(menuTexture);

	menu[0].setFont(menu_font);
	menu[0].setColor(sf::Color::Red);
	menu[0].setString("Play");
	menu[0].setPosition(sf::Vector2f(1280 / 2 - 50, 720 / (MAX_NUMBER_OF_ITEMS + 1) * 1));

	menu[1].setFont(menu_font);
	menu[1].setColor(sf::Color::White);
	menu[1].setString("Exit");
	menu[1].setPosition(sf::Vector2f(1280 / 2 - 45, 720 / (MAX_NUMBER_OF_ITEMS + 1) * 2 - 120));

	volumeLevel.setFont(menu_font);
	volumeLevel.setColor(sf::Color::White);
	volumeLevel.setPosition(sf::Vector2f(1280 / 2 - 90, 720 / (MAX_NUMBER_OF_ITEMS + 1) * 2));

	selectedItemIndex = 0;
}

void Menu::draw(sf::RenderWindow& window)
{
	window.draw(menuSprite);
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(menu[i]);
	}
	window.draw(volumeLevel);
}

void Menu::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setColor(sf::Color::Red);
	}
}

void Menu::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		menu[selectedItemIndex].setColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setColor(sf::Color::Red);
	}
}

//float Menu::MoveLeft(float currentVolume)
//{
//	return currentVolume -= 10;
//}
//
//float Menu::MoveRight(float currentVolume)
//{
//	return currentVolume += 10;
//}

void Menu::updateVolume(int currentVolume)
{
	std::stringstream vol_stream;
	vol_stream << "Volume: " << currentVolume;
	this->volumeLevel.setString(vol_stream.str());
}

void Menu::inGameVolume(int currentVolume, sf::RenderWindow *window)
{
	volumeLevel.setFont(menu_font);
	volumeLevel.setColor(sf::Color::White);
	volumeLevel.setPosition(sf::Vector2f(1120, 720 - 40));
	std::stringstream vol_stream;
	vol_stream << "Volume: " << currentVolume;
	this->volumeLevel.setString(vol_stream.str());
	window->draw(volumeLevel);
}
