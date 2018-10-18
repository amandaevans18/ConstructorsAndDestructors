#pragma once
#include "raylib.h"
#include <iostream>
class ButtonSprite : public Vector2
{
public:
	Texture2D * spriteCells = NULL;
	float frameRate = 25.0;
	int cellCount = 0;
	int direction = 1;

	void draw();

	ButtonSprite(const std::string *filename, const  int _cellCount = 1, const float _frameRate = 25.0);
	ButtonSprite();
	~ButtonSprite();
};