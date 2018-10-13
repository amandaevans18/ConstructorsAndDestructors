//Wizard.h
#pragma once
#include <iostream>
#include "raylib.h"
struct attributesForAbilitys
{
	int dmg;
	std::string abilityName;
};

class Wizard
{
public:
	Wizard();           // sets default values
	Wizard(std::string _name,std::string _abilitys[],Vector2 _position, std::string _spriteName);

	std::string name;
	Vector2 position;
	//attributes
	std::string abilitys[5];
	int mana;
	int maxMana = 50;
	int burn = 30;
	int freeze = 20;//has the farest range 
	int heal = 10;
	int shower = 40;
	//stats
	int gold;
	int health;
	int maxHealth = 100;
	float speed;
	//sprite 
	int width;
	int height;
	Texture2D sprite;

	//FUNCTIONS
	void takeDamage(int damageToTake);
	attributesForAbilitys theAttributeUsed();
	void update(float deltaTime, float screenX, float screenY);
	void draw();        // call this in your draw loop to render the wizard
};