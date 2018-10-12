#pragma once
#include <string>
#include <iostream>
#include "raylib.h"
#include"Tile.h"

class MasterTile 
{
public:

	Tile * types;
	int * grid;
	int rows = 100;
	int colums = 100;

	MasterTile();
};