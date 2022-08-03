#pragma once
#include "Container.h"
#include "Driver.h"
class Drivers : public Container<Driver>
{
public:
	Drivers();
	Drivers(int);
};

