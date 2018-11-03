#include "Game.h"

void Game::update()
{
	//MOVEMENT
	player.update(GetFrameTime(), screenWidth, screenHeight);
	//locks enemy and pick up movement until player moves
	if (player.hasMoved)
	{

		//for pick ups and there clones to move
		for (int i = 0; i < pickups[i].pickupAmt; ++i)
		{
			pickups[i].pickupUpdate(GetFrameTime(), screenWidth, screenHeight);
		}
		for (int i = 0; i < pickupsClone[i].pickupCloneAmt; ++i)
		{
			pickupsClone[i].pickupUpdate(GetFrameTime(), screenWidth, screenHeight);
		}

		//for enemys and there clones to move
		for (int i = 0; i < enemys[i].enemyAmt; ++i)
		{
			enemys[i].enemyUpdate(GetFrameTime(), screenWidth, screenHeight);
		}
		for (int i = 0; i < enemysClone[i].enemyCloneAmt; ++i)
		{
			enemysClone[i].enemyUpdate(GetFrameTime(), screenWidth, screenHeight);
		}
	}
}

void Game::collision()
{

	//for pick ups and there clones to move
	for (int i = 0; i < pickups[i].pickupAmt; ++i)
	{
		pickups[i].pickupCollision(player, pickups, pickupsClone);
	}
	for (int i = 0; i < pickupsClone[i].pickupCloneAmt; ++i)
	{
		pickupsClone[i].pickupCloneCollision(player, pickupsClone);
	}

	//for enemys and there clones to move
	for (int i = 0; i < enemys[i].enemyAmt; ++i)
	{
		enemys[i].enemyCollision(player, enemys, enemysClone);
	}
	for (int i = 0; i < enemysClone[i].enemyCloneAmt; ++i)
	{
		enemysClone[i].enemyCloneCollision(player, enemysClone);
	}
}

void Game::draw()
{
	player.playerDraw();

	for (int i = 0; i < pickups[i].pickupAmt; i++)
	{
		pickups[i].pickupDraw();
		pickupsClone[i].pickupDraw();
	}
	for (int i = 0; i < enemys[i].enemyAmt; i++)
	{
		enemys[i].enemyDraw();
		enemysClone[i].enemyDraw();
	}
}

void Game::mainMenu()
{
	ClearBackground(BLACK);

	DrawText("This is a game", 10, 10, 20, WHITE);

	DrawText("Press [ space ] to start", 10, 40, 50, WHITE);

}

void Game::winScreen()
{
	bool notDone = true;
	while (notDone)
	{
		timer += GetFrameTime();
		player.update(GetFrameTime(), screenWidth, screenHeight);

		BeginDrawing();
		ClearBackground(WHITE);
		DrawText("You won... press space to exit", 25, 100, 50, GREEN);
		player.playerDraw();
		EndDrawing();
		if (IsKeyPressed(KEY_SPACE))
		{
			notDone = false;
			continue;
		}
	}
}

void Game::loseScreen()
{
	bool notDone = true;
	while (notDone)
	{
		BeginDrawing();
		ClearBackground(BLACK);
		DrawText("You're dead... press SPACE to exit", 50, 100, 30, RED);
		EndDrawing();
		if (IsKeyPressed(KEY_SPACE))
		{
			notDone = false;
			continue;
		}
	}
	
}

void Game::inGame()
{
	timer += GetFrameTime();
	ClearBackground(BLUE);

	//wo9w you can draw text 
	//DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
	DrawText(("Thiccness: " + (std::to_string(player.fatness))).c_str(), 25, 25, 20, BLACK);
	update();
	collision();
	draw();
	if (player.fatness < 0)
	{
		//go to lose screen
		GameState::GetInstance().setState(LoseScreen);
	}
	if (player.fatness >= 25)
	{
		//go to win screen
		GameState::GetInstance().setState(WinScreen);
	}
}

void Game::go()
{
	switch (GameState::GetInstance().getState()) {

	case(MainMenu):
		mainMenu();
		break;
	case(InGame):
		inGame();
		break;
	case(LoseScreen):
		loseScreen();
		break;
	case(WinScreen):
		winScreen();
		break;
	default:
		mainMenu();
	}
}