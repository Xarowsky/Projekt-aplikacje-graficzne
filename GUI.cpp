#include "GUI.h"


GUI::GUI()
{

}


void GUI::initGUI(sf::RenderWindow *window)
{
	points = 0;
	hp = 150.f;
	if (!this->font.loadFromFile("assets/impact.ttf"))
		std::cout << "ERROR:Failed to load font" << "\n";

	if (!this->game_over_font.loadFromFile("assets/impact.ttf"))
		std::cout << "ERROR:Failed to load font" << "\n";

	this->game_over_text.setPosition((window->getSize().x / 2)-125, (window->getSize().y / 2)-80);
	this->game_over_text.setFont(this->game_over_font);
	this->game_over_text.setCharacterSize(40);
	this->game_over_text.setFillColor(sf::Color::Red);

	this->pointText.setPosition(10.f, 10.f);
	this->pointText.setFont(this->font);
	this->pointText.setCharacterSize(20);
	this->pointText.setFillColor(sf::Color::White);

	this->hpText.setPosition(window->getSize().x / 1.2, 10.f);
	this->hpText.setFont(this->font);
	this->hpText.setCharacterSize(20);
	this->hpText.setFillColor(sf::Color::White);
	std::stringstream hp_stream;
	std::stringstream initial_score;
	initial_score << "Points: ";
	this->pointText.setString(initial_score.str());

	hp_stream << "HP:";
	this->hpText.setString(hp_stream.str());
}

void GUI::updateGUI()
{
	this->points += 10;
	std::stringstream point_stream;
	point_stream << "Points: " << this->points;
	this->pointText.setString(point_stream.str());
}

void GUI::hit(float damage)
{
	hp -= damage;
}

float GUI::getHp()
{
	return hp;
}

void GUI::renderGUI(RenderWindow *window)
{
	PrimitiveRenderer renderer;
	window->draw(pointText);
	window->draw(hpText);
	LineSegment line1(sf::Vector2f(1110.f, 10.f), sf::Vector2f(1260.f, 10.f), sf::Color::Red);
	LineSegment line2(sf::Vector2f(1110.f, 40.f), sf::Vector2f(1260.f, 40.f), sf::Color::Red);
	LineSegment line3(sf::Vector2f(1110.f, 10.f), sf::Vector2f(1110.f, 40.f), sf::Color::Red);
	LineSegment line4(sf::Vector2f(1260.f, 10.f), sf::Vector2f(1260.f, 40.f), sf::Color::Red);
	renderer.drawLine(window, &line1);
	renderer.drawLine(window, &line2);
	renderer.drawLine(window, &line3);
	renderer.drawLine(window, &line4);
	renderer.drawRectangle(window, Vector2f(hp, 27.f), Color::Green, Vector2f(1110.f, 10.f));
	std::stringstream game_over_stream;
	if(hp <= 0)
	{
		game_over_stream << "EARTH IS DOOMED";
		this->game_over_text.setString(game_over_stream.str());
		window->draw(game_over_text);
	}
}