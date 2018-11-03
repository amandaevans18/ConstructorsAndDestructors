#pragma once
#include"raylib.h"
#include<string>
#include"Game.h"
using namespace std;

class Pickup
{
public:
	//amt of starting pickups
	int pickupAmt = 6;
	//amt of pickup clones aka double of og pickups
	int pickupCloneAmt = 20;
	//Keeping tract of which clone to spawn PU == pickups
	int nextCloneToSpawnPU = 0;
	//location
	Vector2 pos;
	float radius;
	//speed
	float speed;
	int value;
	//type of movement
	// 1 == move up
	//2 == move down
	//3 == move right
	// 4 == move left
	int preSetMovement;
	// is it there?
	bool enabled;
	//direction of image
	string direction;

	Pickup();
	Pickup(Player _player, Pickup * _enemys, Pickup * _enemysClone);
	void pickupUpdate(float deltaTime, float screenX, float screenY);
	void pickupCollision(Player _player,Pickup* _pickups,Pickup *_pickupClones);
	void pickupCloneCollision(Player _player, Pickup *_pickupClones);
	void pickupDraw();
};