#pragma once
#include "SpriteForButton.h"
class Button :
	public ButtonSprite
{
public:
	void Draw();// This Draw function will override the base classes Draw.
	bool CheckForClick();

	Button(const std::string *filename, const Vector2 & position, const  int cellCount = 1);
	Button();
	~Button();
};