#include "SimpleSprite.h"

void SimpleSprite::translate(Vector2 delta)
{
	pos = delta;
}

void SimpleSprite::draw()
{
	DrawTexturePro(texture, r1, r2, { 0,0 }, rot, WHITE);
}

SimpleSprite::SimpleSprite()
{
}

SimpleSprite::SimpleSprite(const std::string & filename, const std::string _sprType, float scale)
{
	 texture = LoadTexture(filename.c_str());
	 sprType = _sprType;

}

SimpleSprite::~SimpleSprite()
{
}
