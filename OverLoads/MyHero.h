#pragma once
#include"raylib.h"
#include<iostream>
#include<string>
#include"Potion.h"

using std::string;
using std::cout;
using std::endl;
using std::cin;


class MyHero
{
public:
//constructors
	MyHero();
	MyHero(string _name, string _specialText, int _age, int _hitPoints, int _wealth);
	~MyHero();

//varibles
	string name;
	string specialText;
	int age;
	int hitPoints;
	int maxHitPoints = 100;
	int wealth;

	Texture2D texture;
	Texture2D* dTexture;


//functions
	MyHero operator+=(const Potion &rhs);
	void update();
	void renderer();

};
