#include "raylib.h"
#include "Tile.h"
#include"MasterTile.h"
int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = 800;
	int screenHeight = 450;

	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

	SetTargetFPS(60);
	std::string tileOne = "mappack\\png\\mapTile_019.png";
	std::string tileTwo = "mappack\\png\\mapTile_024.png";
	std::string tileThree = "mappack\\png\\mapTile_027.png";

	Tile tiles[3] = {tileOne, tileTwo, tileThree };
	int grid[5][4] =
	{
	 0,1,0,0,0
	,0,0,0,0,0
	,0,0,0,0,0
	,0,0,0,0,0
	};
	MasterTile gameBoard(tiles[3],grid,5,4);
	//--------------------------------------------------------------------------------------

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update
		//----------------------------------------------------------------------------------
		// TODO: Update your variables here


		//----------------------------------------------------------------------------------
		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();

		ClearBackground(RAYWHITE);
		gameBoard.draw();
		//DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------   
	CloseWindow();        // Close window and OpenGL context
						  //--------------------------------------------------------------------------------------

	return 0;
}
