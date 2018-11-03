#include "Enemy.h"

Enemy::Enemy()
{
	pos = { (float)GetRandomValue(100, 750), (float)GetRandomValue(100, 400) };
	radius = GetRandomValue(10.0f, 20.0f);
	speed = GetRandomValue(1.0f, 5.0f);
	value = GetRandomValue(1, 5);
	preSetMovement = GetRandomValue(1, 4);
	enabled = true;
}

Enemy::Enemy(Player _player, Enemy * _enemys, Enemy * _enemysClone)
{
	for (int i = 0; i < enemyAmt; i++)
	{
		while (CheckCollisionCircles(_player.pos, _player.radius, _enemys[i].pos, _enemys[i].radius))
		{
			_enemys[i].pos = { (float)GetRandomValue(100, 750), (float)GetRandomValue(100, 400) };
		}
	}
	for (int i = 0; i < enemyCloneAmt; i++)
	{
		while (CheckCollisionCircles(_player.pos, _player.radius, _enemysClone[i].pos, _enemysClone[i].radius))
		{
			_enemysClone[i].pos = { (float)GetRandomValue(100, 750), (float)GetRandomValue(100, 400) };
		}
	}
	for (int i = 0; i < enemyCloneAmt; i++)
	{
		_enemysClone[i].enabled = false;
	}
}

void Enemy::enemyUpdate(float deltaTime, float screenX, float screenY)
{

	if (preSetMovement == 1)
	{
		pos.y -= speed;

		if (pos.y < radius * -1)
		{
			pos.y = screenY + radius;
		}
	}
	else if (preSetMovement == 2)
	{
		pos.y += speed;

		if (pos.y > screenY + radius)
		{
			pos.y = radius * -1;
		}
	}
	else if (preSetMovement == 3)
	{
		pos.x -= speed;

		if (pos.x < radius * -1)
		{
			pos.x = screenX + radius;
		}
	}
	else if (preSetMovement == 4)
	{
		pos.x += speed;

		if (pos.x > screenX + radius)
		{
			pos.x = radius * -1;
		}
	}

}

void Enemy::enemyCollision(Player _player, Enemy * _enemys, Enemy *_enemysClone)
{
	//enemy collision
	for (int i = 0; i < enemyAmt; ++i)
	{
		if (CheckCollisionCircles(_player.pos, _player.radius, _enemys[i].pos, _enemys[i].radius) && _enemys[i].enabled == true)
		{
			_enemys[i].enabled = false;
			_player.fatness -= _enemys[i].value;
			_enemysClone[0 + nextCloneToSpawnEM].enabled = true;
			if (nextCloneToSpawnEM < enemyCloneAmt)
			{
				nextCloneToSpawnEM++;
			}
		}
	}

}

void Enemy::enemyCloneCollision(Player _player, Enemy * _enemysClone)
{
	//enemy clone collision and respawn
	for (int i = 0; i < enemyCloneAmt; ++i)
	{
		if (CheckCollisionCircles(_player.pos, _player.radius, _enemysClone[i].pos, _enemysClone[i].radius) && _enemysClone[i].enabled == true)
		{
			_enemysClone[i].enabled = false;
			_player.fatness -= _enemysClone[i].value;
			_enemysClone[0 + nextCloneToSpawnEM].enabled = true;
			if (nextCloneToSpawnEM < enemyCloneAmt)
			{
				nextCloneToSpawnEM++;
			}
		}
	}
}

void Enemy::enemyDraw()
{
	//should be a load image stuff! need to add a check for direction facing
	if (enabled)
	{
		DrawCircleGradient(pos.x, pos.y, radius, BLACK, RED);
	}
}