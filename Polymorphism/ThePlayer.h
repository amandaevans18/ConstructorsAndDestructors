//Player.h
#pragma once
#include "raylib.h"
#include <iostream>

class ThePlayer
{
public:
	ThePlayer();
	ThePlayer(const std::string &fileName);    // loads a texture from the given path
	~ThePlayer();                              // unloads the texture

	Vector2 position = { 100,100 };         // current location
	Vector2 targetPostion = {};
	int rise = 0;
	int run = 0;
	float speed = 10;                        // units per second to move
	Texture2D mySprite;                     // texture used to draw the player

	virtual bool moveTo(const Vector2 &dest);       // moves the Player towards the given location
											// (returns true if the destination is reached)

	void draw();                            // draws player to the screen
};
