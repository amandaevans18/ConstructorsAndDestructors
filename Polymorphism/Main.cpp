
#include "raylib.h"
#include<iostream>
#include<string>
#include"TheBarbarian.h"
#include"ThePlayer.h"
#include"TheWizard.h"

int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = 800;
	int screenHeight = 450;

	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");



	SetTargetFPS(60);
	//--------------------------------------------------------------------------------------

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update
		//----------------------------------------------------------------------------------
		// TODO: Update your variables here
		//----------------------------------------------------------------------------------

		////need to move towards the destination
		//we need to only set these things when we click again so should be in main just saying.
		if (IsMouseButtonDown(0)) 
		{
			run = dest.x - position.x;
			rise = dest.y - position.y;

			targetPostion.x = GetMouseX();
			targetPostion.y = GetMouseY();
		}
		

		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();

		ClearBackground(RAYWHITE);

		DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------   
	CloseWindow();        // Close window and OpenGL context
						  //--------------------------------------------------------------------------------------

	return 0;
}
