#include "Sprite.h"

void Sprite::Draw()
{
	//going to draw the sprite
	
	timePassedBetweenFrames += GetFrameTime();

	DrawTextureEx(spriteCells[currentFrame], Vector2{ x,y }, 0.0f, 1, WHITE);

	if (timePassedBetweenFrames >= timeBetweenFrames)
	{
		timePassedBetweenFrames = 0;

		currentFrame++;
		if (currentFrame >= cellCount)
		{
			currentFrame = 0;
		}
	}
	
}

void Sprite::Motion()
{
	if (IsKeyDown(KEY_D)) 
	{

		x++;
	}
}

Sprite::Sprite(const std::string * filename, const int _cellCount, const float _frameRate)
{
	//setting cell count
	cellCount = _cellCount;
	//setting frameRate to frameRate
	frameRate = _frameRate;
	//allocating memory for sprite cells 
	spriteCells = new Texture2D[_cellCount];
	//Gets all the textures from the fileNames given
	for (size_t i = 0; i < _cellCount; i++)
	{
		spriteCells[i] = LoadTexture(filename[i].c_str());
	}
	x = 90;
	y = 50;

}

Sprite::Sprite()
{
}

Sprite::~Sprite()
{
	delete spriteCells;
}
