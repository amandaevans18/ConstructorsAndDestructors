#pragma once
#include <iostream>
#include "raylib.h"

template <typename T>
class gameObject
{
public:
	bool enabled;   // is this gameObject enabled?
	T  object;     // pointer to underlying instance of type T

	gameObject() {};
	gameObject(T  _object)
	{
		object = _object;
	}

	void update(float delta)
	{
		if (enabled)
		{
			(*object).update();
			std::cout << "updating" << std::endl;
		}
	}

	void render()
	{
		if (enabled)
		{
			(*object).draw();
		}
		std::cout << "rendering" << std::endl;
	}

	// todo: What else would you need to include in this class declaration?
};