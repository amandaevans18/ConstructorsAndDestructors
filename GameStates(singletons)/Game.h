#pragma once
#include"GameState.h"
#include "raylib.h"
#include<string>
#include<iostream>
#include"Player.h"
#include"Pickup.h"
#include"Enemy.h"
class Game 
{
public:
	//screen width
	int screenWidth = 800;
	// screen height
	int screenHeight = 450;
	//timer??
	float timer = 0.0f;

	Player player{};
	Enemy enemys[6]{};

	Enemy enemysClone[20]{};

	Pickup pickups[6]{};

	Pickup pickupsClone[20]{};

	void update();
	void collision();
	void draw();

	//help me david
	void mainMenu();
	void inGame();
	void winScreen();
	void loseScreen();
	void go();

	
};