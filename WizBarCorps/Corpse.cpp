#include "Corpse.h"

Corpse::Corpse()
{
}

Corpse::Corpse(Wizard deadWiz)
{
	gold = deadWiz.gold;
	position = deadWiz.position;
	name = deadWiz.name;
}

Corpse::Corpse(Barbarian deadBarb)
{
	gold = deadBarb.gold;
	position = deadBarb.position;
	name = deadBarb.name;
}

void Corpse::draw()
{

}
