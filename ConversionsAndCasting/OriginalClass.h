#pragma once
#include<iostream>
#include"raylib.h"
#include<string>
#include"NewerClass.h"

class OriginalClass
{
public:
	int myVal = 10;
	OriginalClass(NewerClass b);

	OriginalClass();
	~OriginalClass();
};