#pragma once
#include <iostream>
#include "raylib.h"
#include<string>
class Ninja
{
public:
	Vector2 position;
	float speed;
	Texture2D sprite;

	Ninja(std::string fileName, float _speed, Vector2 _position);

	Ninja();
	~Ninja();


	void update(float delta);
	void render();
};