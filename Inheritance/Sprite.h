#pragma once
#include "raylib.h"
#include <iostream>
class Sprite : public Vector2
{
public:
	Texture2D * spriteCells = NULL;
	float frameRate = 25.0;
	int cellCount = 0;
	int direction = 1;
	int currentFrame = 0;
	int timePassedBetweenFrames;
	int timeBetweenFrames = 10;

	void Draw();
	void Motion();

	Sprite(const std::string *filename, const  int cellCount, const float _frameRate);
	Sprite();
	~Sprite();
};