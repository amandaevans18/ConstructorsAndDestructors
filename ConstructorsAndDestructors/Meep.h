#pragma once
#include "raylib.h"
#include <iostream>

class meep
{
public:

	//Vars
	bool enabled = true;
	Texture2D texture;
	Texture2D* dTexture;

	// Constructors & Destructors
	meep();
	meep(bool _enabled);
	~meep();

	// Misc Functions
	void refresh();

private:
};