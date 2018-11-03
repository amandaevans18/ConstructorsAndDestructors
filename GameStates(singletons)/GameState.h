//GameState.h with Enum
#pragma once
#include "raylib.h"
#include<string>
#include<iostream>
#include"Player.h"
#include"Pickup.h"
#include"Enemy.h"


enum GStates
{
	MainMenu = 0,
	InGame,
	WinScreen,
	LoseScreen
};

class GameState
{
private:
	GStates cState = MainMenu;
	GameState() {};
	GameState(GameState const&) {};  // pprevents external use
	void operator=(GameState const&) {}; // prevents external use

									  // note that the getState and setState function have changed to return and
									  // accept enum values instead of integers
public:
	GStates getState();
	void setState(GStates newState);
	static GameState& GetInstance();
	~GameState();
};