#pragma once
#include "raylib.h"
#include<string>
using namespace std;

class Player
{
public:
	//The different sprite images Visuals
	//an array of ints that stand for the sprites for the fattness of squid
	//aim for three fatnesses
	//size
	float radius;

	//position
	Vector2 pos;

	//speed
	float speed;

	//player height is the pos.y
	bool hasMoved = false;

	//aka health (amount of fish collected by player)
	int fatness = 0;

	//functions

	void update(float deltaTime, float screenX, float screenY);
	void playerDraw();

};