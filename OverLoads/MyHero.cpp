#include "MyHero.h"

MyHero::MyHero()
{

	texture = LoadTexture("ouch1.png");
	dTexture = new Texture2D(texture);
	if (dTexture == nullptr)
	{
		std::cout << "Error: out of memory." << std::endl;
		exit(1);
	}
}

MyHero::MyHero(string _name, string _specialText, int _age, int _hitPoints, int _wealth)
{
	cout << "A hero with the name of " << _name << " has spawned" << endl;
	name = _name;
	specialText = _specialText;
	age = _age;
	hitPoints = _hitPoints;
	wealth = _wealth;
}

MyHero::~MyHero()
{
}

MyHero MyHero::operator+=(const Potion & rhs)
{
	MyHero newHero;

	newHero.hitPoints += rhs.hpModifier;

	return newHero;
}

void MyHero::update()
{
	if (hitPoints != 0)
	{
		cout << "Healt left = "<< hitPoints << endl;
		if (hitPoints <= maxHitPoints && hitPoints > 80)
		{
			texture = LoadTexture("ouch1.png");
		}
		else if (hitPoints < 80 && hitPoints > 60)
		{
			texture = LoadTexture("ouch2.png");
		}
		else if (hitPoints < 60 && hitPoints > 40)
		{
			texture = LoadTexture("ouch3.png");
		}
		else if (hitPoints < 40 && hitPoints > 20)
		{
			texture = LoadTexture("ouch4.png");
		}
		else if (hitPoints < 20 && hitPoints > 0)
		{
			texture = LoadTexture("ouch5.png");
		}
	}
	else 
	{
		cout << "You're Dead!" << endl;
	}
}

void MyHero::renderer()
{
	DrawTextureEx(texture, Vector2{200,100}, 100, 100, WHITE);
}
