#include "Tile.h"

Tile::Tile(std::string imageFilename)
{
	Background = LoadTexture(imageFilename.c_str());
}

Tile::Tile()
{
}

Tile::~Tile()
{
}



