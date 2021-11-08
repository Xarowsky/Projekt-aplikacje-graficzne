#include"gameObject.h"


bool gameObject::detectCollision(gameObject obj1, gameObject obj2)
{
	if (obj1.objectSprite.getGlobalBounds().intersects(obj2.objectSprite.getGlobalBounds()))
		return true;
	else
		return false;
}

float gameObject::borderYAxisCollision(float screenHeight)
{
	if (OBJECTY > 0.f && OBJECTY < screenHeight)
		return 0.f;
	else
		return -(OBJECTY - screenHeight);
}

float gameObject::borderXAxisCollision(float screenWidth)
{
	if (OBJECTX > 0.f && OBJECTX < screenWidth)
		return 0.f;
	else
		return -(OBJECTX - screenWidth);
}

void gameObject::moveObject(float x, float y)
{
	this->objectSprite.move(x, y);
}