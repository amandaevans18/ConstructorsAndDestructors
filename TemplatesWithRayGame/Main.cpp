#include <iostream>
#include "raylib.h"
#include"GameObject.h"
#include"Ninja.h"
#include"Soldier.h"

int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = 800;
	int screenHeight = 450;

	InitWindow(screenWidth, screenHeight, " window");
	Ninja myNinja("alienYellow_stand.png", 5.0f, { 100,100 });

	gameObject<Ninja> myNinjaGO(myNinja);

	SetTargetFPS(60);
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
		std::string text = "The x pos = " + std::to_string(myNinja.position.x) + "The y pos = " + std::to_string(myNinja.position.y);
		DrawText(text.c_str(), 190, 200, 20, LIGHTGRAY);

		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------   
	CloseWindow();        // Close window and OpenGL context
						  //--------------------------------------------------------------------------------------

	return 0;
}
