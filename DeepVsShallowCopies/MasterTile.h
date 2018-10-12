#pragma once
#include <string>
#include <iostream>
#include "raylib.h"
#include"Tile.h"

class MasterTile 
{
public:

	Tile types[3];
	int ** grid;
	int rows;
	int colums;

	MasterTile();
	MasterTile(Tile _types,int _grid[5][4],int _rows,int _colums);
	void draw();
};