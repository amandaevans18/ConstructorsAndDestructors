#include "SpriteForButton.h"

void ButtonSprite::draw()
{
}

ButtonSprite::ButtonSprite(const std::string * filename, const int _cellCount, const float _frameRate)
{
	for (size_t i = 0; i < _cellCount; i++)
	{
		spriteCells[i] = LoadTexture(filename[i].c_str());
	}
}

ButtonSprite::ButtonSprite()
{
}

ButtonSprite::~ButtonSprite()
{
}
