/*******************************************************************************************
*
*   raylib [core] example - basic window
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2013-2016 Ramon Santamaria (@raysan5)
*
********************************************************************************************/
#include"GameState.h"
int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	//screen width
	int screenWidth = 800;
	// screen height
	int screenHeight = 450;
	

	//Controls the window size / makes the window
	InitWindow(screenWidth, screenHeight, "Platformed");

	SetTargetFPS(60);
	//--------------------------------------------------------------------------------------
	Game myGame;
	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{

		BeginDrawing();
		myGame.go();
		EndDrawing();
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------   
	CloseWindow();        // Close window and OpenGL context
						  //--------------------------------------------------------------------------------------
	return 0;
}