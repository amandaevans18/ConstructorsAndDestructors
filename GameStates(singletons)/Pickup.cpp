#include "Pickup.h"

Pickup::Pickup()
{
	pos = { (float)GetRandomValue(100, 750), (float)GetRandomValue(100, 400) };
	radius = GetRandomValue(10, 20);
	speed = GetRandomValue(1.0f, 5.0f);
	value = GetRandomValue(1, 5);
	preSetMovement = GetRandomValue(1, 4);
	enabled = true;
}

Pickup::Pickup(Player _player, Pickup * _pickups, Pickup * _pickupsClone)
{
	//pickups not on player
	for (int i = 0; i < pickupAmt; i++)
	{
		while (CheckCollisionCircles(_player.pos, _player.radius, _pickups[i].pos, _pickups[i].radius))
		{
			_pickups[i].pos = { (float)GetRandomValue(100, 750), (float)GetRandomValue(100, 400) };
		}
	}
	for (int i = 0; i < pickupCloneAmt; i++)
	{
		while (CheckCollisionCircles(_player.pos, _player.radius, _pickupsClone[i].pos, _pickupsClone[i].radius))
		{
			_pickupsClone[i].pos = { (float)GetRandomValue(100, 750), (float)GetRandomValue(100, 400) };
		}
	}

	for (int i = 0; i < pickupCloneAmt; i++)
	{
		_pickupsClone[i].enabled = false;
	}
}

//The pickups movement(differs by 4 diff types)
void Pickup::pickupUpdate(float deltaTime, float screenX, float screenY)
{

	//moves up
	if (preSetMovement == 1)
	{
		pos.y -= speed;

		if (pos.y < radius * -1)
		{
			pos.y = screenY + radius;
		}
	}
	//moves down
	else if (preSetMovement == 2)
	{
		pos.y += speed;

		if (pos.y > screenY + radius)
		{
			pos.y = radius * -1;
		}
	}
	//moves right
	else if (preSetMovement == 3)
	{
		pos.x -= speed;

		if (pos.x < radius * -1)
		{
			pos.x = screenX + radius;
		}
	}
	//moves left
	else if (preSetMovement == 4)
	{
		pos.x += speed;

		if (pos.x > screenX + radius)
		{
			pos.x = radius * -1;
		}
	}
}


void Pickup::pickupCollision(Player _player,Pickup* _pickups, Pickup* _pickupClones)
{
	//pick up collision (and spawn of clones)
	for (int i = 0; i < pickupAmt; ++i)
	{
		if (CheckCollisionCircles(_player.pos, _player.radius, _pickups[i].pos, _pickups[i].radius) && _pickups[i].enabled == true)
		{
			_pickups[i].enabled = false;
			_player.fatness += _pickups[i].value;
			_pickupClones[0 + nextCloneToSpawnPU].enabled = true;
			if (nextCloneToSpawnPU < pickupCloneAmt)
			{
				nextCloneToSpawnPU++;
			}
		}
	}
}

void Pickup::pickupCloneCollision(Player _player, Pickup * _pickupClones)
{
	//pick up clone collision (and respawn)
	for (int i = 0; i < pickupCloneAmt; ++i)
	{
		if (CheckCollisionCircles(_player.pos, _player.radius, _pickupClones[i].pos, _pickupClones[i].radius) && _pickupClones[i].enabled == true)
		{
			_pickupClones[i].enabled = false;
			_player.fatness += _pickupClones[i].value;
			_pickupClones[0 + nextCloneToSpawnPU].enabled = true;
			if (nextCloneToSpawnPU < pickupCloneAmt)
			{
				nextCloneToSpawnPU++;
			}
		}
	}
}

//if enabled draw the pickup
void Pickup::pickupDraw()
{
	if (enabled)
	{
		DrawCircleGradient(pos.x, pos.y, radius, LIGHTGRAY, DARKBROWN);
	}
}