#include "Wizard.h"

Wizard::Wizard()
{
}

Wizard::Wizard(std::string _name, std::string _abilitys[], Vector2 _position, std::string _spriteName)
{
	name = _name;
	for (int i =0; i<5; i++) 
	{
		abilitys[i] = _abilitys[i];
	}
	position = _position;
	sprite = LoadTexture(_spriteName.c_str());

}

void Wizard::takeDamage(int damageToTake)
{
	health -= damageToTake;
}

attributesForAbilitys Wizard::theAttributeUsed()
{
	//should really be adding an array of strings that is the ability names but ITS FINE
	attributesForAbilitys dmgAndName;
	int rng = GetRandomValue(0, 3);
	switch(rng)
	{
	case 0:
		dmgAndName.dmg = burn;
		dmgAndName.abilityName = "burn";
		break;
	case 1:
		dmgAndName.dmg = freeze;
		dmgAndName.abilityName = "freeze";
		break;
	case 2:
		health += heal;
		dmgAndName.dmg = 0;
		dmgAndName.abilityName = "heal";
		break;
	case 3:
		dmgAndName.dmg = shower;
		dmgAndName.abilityName = "Shower";
		break;
	};
	return dmgAndName;
}



void Wizard::update(float deltaTime, float screenX, float screenY)
{
	position.x -= speed;

	if (position.x < width * -1)
	{
		position.x = screenX + width;
	}
}

void Wizard::draw()
{
	DrawTexture(sprite, position.x, position.y, WHITE);
}
