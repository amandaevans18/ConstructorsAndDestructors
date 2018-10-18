#include<iostream>
#include"raylib.h"
#include"Sprite.h"

int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = 800;
	int screenHeight = 450;

	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

	SetTargetFPS(60);

	std::string files[3] = {"PNG/Female/Poses/female_cheer1.png","PNG/Female/Poses/female.duck.png","PNG/Female/Poses/female_hold2,png"};

	Sprite boi(files,3,GetFrameTime());
	//--------------------------------------------------------------------------------------

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update
		//----------------------------------------------------------------------------------
		// TODO: Update your variables here
		//----------------------------------------------------------------------------------
		boi.Motion();
		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();


		ClearBackground(RAYWHITE);
	
		boi.Draw();
		
		
		


		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------   
	CloseWindow();        // Close window and OpenGL context
						  //--------------------------------------------------------------------------------------

	return 0;
}
