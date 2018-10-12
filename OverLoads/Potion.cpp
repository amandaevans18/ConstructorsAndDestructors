#include "Potion.h"

Potion::Potion()
{
}

Potion::Potion(string _name, int _hpModifier, string _quality, int _usedByDate)
{
	name = _name;
	hpModifier = _hpModifier;
	quality = _quality;
	usedByDate = _usedByDate;
}

Potion::~Potion()
{
}
