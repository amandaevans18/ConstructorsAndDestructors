#include "TheWizard.h"

TheWizard::TheWizard():ThePlayer()
{

}

TheWizard::~TheWizard()
{
}

bool TheWizard::moveTo(Vector2 & dest)
{
	//set position to click position
	if (position.x == dest.x && position.y == dest.y)
	{
		return true;
	}
	else
	{
		position.x = dest.x;
		position.y = dest.y;
		return false;
	}
}
