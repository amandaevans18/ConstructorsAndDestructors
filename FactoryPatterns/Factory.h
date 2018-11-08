//Factory.h
#pragma once
#include <iostream>
#include "IBox.h"
#include "RedBox.h"
#include "BlueBox.h"
#include "IFactory.h"

class Factory : public IFactory
{
public:
	IBox * Create(std::string type);
};
