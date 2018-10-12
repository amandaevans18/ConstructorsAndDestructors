#include "MasterTile.h"

MasterTile::MasterTile()
{
}

MasterTile::MasterTile(Tile  _types, int _grid[5][4], int _rows, int _colums)
{
	types[3] = {_types};
	for (int c = 0; c < colums; c++)
	{
		for (int r = 0; r < rows; r++)
		{

		}
	}
	rows = _rows;
	colums = _colums;
}


void MasterTile::draw()
{
	int placementX = 0;
	int placementY = 0;
	for (int c = 0; c < colums; c++)
	{
		for (int r = 0; r<rows;r++) 
		{
			if (grid[c][r] == 0)
			{
				DrawTexture(types[0].Background, placementX, placementY, WHITE);
			}
			if (grid[c][r] == 1)
			{
				DrawTexture(types[1].Background, placementX, placementY, WHITE);
			}
			if (grid[c][r] == 2)
			{
				DrawTexture(types[2].Background, placementX, placementY, WHITE);
			}
			placementX += 64;
			if (placementX <= placementX * rows)
			{
				placementY = 64;
				placementX = 0;
			}
		}
	}
}