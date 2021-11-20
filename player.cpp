#include "player.h"

player::player()
{

}

player::player(sf::Texture *objectTexture)
{
    this->objTexture = sf::Texture(*objectTexture);
    this->objectSprite = sf::Sprite();
    this->objectSprite.setTexture(objTexture, true);
}

void player::playerControls(int screenWidth, int screenHeight)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        this->objectSprite.move(-PLAYER_SPEED, 0.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        this->objectSprite.move(PLAYER_SPEED, 0.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        this->objectSprite.move(0.f, -PLAYER_SPEED);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        this->objectSprite.move(0.f, PLAYER_SPEED);
    
 //   if ((xAxisCorrection = this->borderXAxisCollision(screenHeight)) != 0)
 //   {
//        this->objectSprite.move(0.f, xAxisCorrection);
//    }
//    if((yAxisCorrection = this->borderYAxisCollision(screenWidth)) != 0)
//    {
//        this->objectSprite.move(yAxisCorrection, 0.f);
//    }
}
