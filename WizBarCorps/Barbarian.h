//Barbarian.h
#pragma once
#include <iostream>
#include "raylib.h"
class Barbarian
{
public:
	Barbarian();           // sets default values
	Barbarian(std::string _name, std::string _attributes);

	std::string name;
	Vector2 position;
	//attributes
	std::string attributes;
	int stamina;
	int maxStamina = 50;
	int headButt = 30;
	int punch = 20;
	int bodySlam = 10;
	//stats
	int gold;
	int health;
	int maxHealth = 100;

	void takeDamage();
	void useAtribute();
	void update();
	void draw();        // call this in your draw loop to render the wizard
};