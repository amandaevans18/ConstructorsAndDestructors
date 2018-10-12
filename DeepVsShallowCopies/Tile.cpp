#include "Tile.h"

Tile::Tile(std::string imageFilename)
{
	Background = LoadTexture(imageFilename.c_str());
}

void Tile::draw()
{
	tint = {GetRandomValue(1,255),GetRandomValue(1,255),GetRandomValue(1,255)};
	DrawTexture(Background, 100, 100, tint);
}
