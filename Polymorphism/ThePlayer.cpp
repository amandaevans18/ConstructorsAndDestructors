#include "ThePlayer.h"

ThePlayer::ThePlayer()
{
}

ThePlayer::ThePlayer(const std::string & fileName)
{
	mySprite = LoadTexture(fileName.c_str());
}

ThePlayer::~ThePlayer()
{
}

bool ThePlayer::moveTo(const Vector2 & dest)
{
	position.x += speed;
	return false;
}

void ThePlayer::draw()
{
	DrawTexture(mySprite, position.x, position.y, WHITE);
}
