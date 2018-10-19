#include "TheBarbarian.h"

TheBarbarian::TheBarbarian() : ThePlayer()
{
}

TheBarbarian::~TheBarbarian()
{
}

bool TheBarbarian::moveTo(Vector2 & dest)
{
	if (position.x == dest.x && position.y == dest.y)
	{
		return true;
	}
	else
	{
		position.x += run / speed;
		position.y += rise / speed;
		return false;
	}
}
