#pragma once
#include<iostream>
#include"Factory.h"
class IFactory 
{

	IFactory* f = NULL;
	
	void Create();
};