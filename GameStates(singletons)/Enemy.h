#pragma once
#include"raylib.h"
#include<string>
#include"Game.h"
using namespace std;

class Enemy
{
public:
	//location
	Vector2 pos;
	float radius;
	//speed
	float speed;
	//value
	int value;
	//type of movement
	// 1 == move up
	//2 == move down
	//3 == move right
	// 4 == move left
	// 5 == random
	int preSetMovement;
	// is it there?
	bool enabled;
	string direction;
	//amt of starting enemys
	int enemyAmt = 6;
	//amt of enemy clones
	int enemyCloneAmt = 20;
	//Keeping tract of which clone to spawn EM == enemys
	int nextCloneToSpawnEM = 0;

	Enemy();
	Enemy(Player _player, Enemy * _enemys, Enemy * _enemysClone);
	void enemyUpdate(float deltaTime, float screenX, float screenY);
	void enemyCollision(Player _player, Enemy* _enemy, Enemy *_enemyClones);
	void enemyCloneCollision(Player _player,  Enemy *_enemyClones);

	void enemyDraw();

};