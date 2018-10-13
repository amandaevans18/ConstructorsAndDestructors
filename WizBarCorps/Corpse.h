//Corpse.h
#pragma once
#include <iostream>
#include "raylib.h"
#include"Barbarian.h"
#include"Wizard.h"

class Corpse
{
public:
	Corpse();           // sets default values
	//Wiz conversion
	Corpse(Wizard deadWiz);
	//Barb conversion
	Corpse(Barbarian deadBarb);

	std::string name;
	int gold;

	Vector2 position;

	void draw();        // call this in your draw loop to render the CORPSE
};