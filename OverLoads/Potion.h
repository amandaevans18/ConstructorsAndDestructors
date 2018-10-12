#pragma once
#include"raylib.h"
#include<iostream>
#include<string>

using std::string;
using std::cout;
using std::endl;
using std::cin;


class Potion
{
public:
//constructs and destructs
	Potion();
	Potion(string _name,int _hpModifier,string _quality, int _usedByDate);
	~Potion();

//varibles
	string name;
	int hpModifier;
	string quality;
	int usedByDate;

};
