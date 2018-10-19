#pragma once
#include "raylib.h"
#include <iostream>
#include"ThePlayer.h"

class TheWizard : public ThePlayer
{
public:
	TheWizard();           // sets default values
	~TheWizard();

	bool moveTo(Vector2 & dest);
};