#include "Meep.h"


meep::meep()
{
	texture = LoadTexture("AmandasCreatation.png");
	dTexture = new Texture2D(texture);
	if (dTexture == nullptr)
	{
		std::cout << "Error: out of memory." << std::endl;
		exit(1);
	}
}

meep::meep(bool _enabled)
{
	enabled = _enabled;
}

meep::~meep()
{
	UnloadTexture(*dTexture);
	delete dTexture;
}

void meep::refresh()
{
	if (enabled)
	{
		DrawTexture(texture, 100, 100, WHITE);
	}
}
