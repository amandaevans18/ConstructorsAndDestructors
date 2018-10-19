#include "Soldier.h"

Soldier::Soldier(std::string fileName, float _speed, Vector2 _position)
{
	sprite = LoadTexture(fileName.c_str());
	speed = _speed;
	position = _position;
}

Soldier::Soldier()
{

}

Soldier::~Soldier()
{
}

void Soldier::update(float delta)
{
	if (IsKeyDown(KEY_W))
	{
		position.y -= speed * GetFrameTime();
	}
	if (IsKeyDown(KEY_S))
	{
		position.y += speed * GetFrameTime();
	}
	if (IsKeyDown(KEY_A))
	{
		position.x -= speed * GetFrameTime();
	}
	if (IsKeyDown(KEY_D))
	{
		position.x += speed * GetFrameTime();
	}
}

void Soldier::render()
{
	DrawTexture(sprite, position.x, position.y, WHITE);
}
