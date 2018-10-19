#pragma once
#include "raylib.h"
#include <iostream>
#include"ThePlayer.h"

class TheBarbarian : public ThePlayer
{
public:
	TheBarbarian();           // sets default values
	~TheBarbarian();

	bool moveTo(Vector2 & dest);
};