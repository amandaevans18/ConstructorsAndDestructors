#pragma once
#include <iostream>
#include "raylib.h"
#include<string>
class Soldier
{
public:
	Vector2 position{};
	float speed;
	Texture2D sprite;

	Soldier(std::string fileName, float _speed , Vector2 _position);

	Soldier();
	~Soldier();


	void update(float delta);
	void render();
};
