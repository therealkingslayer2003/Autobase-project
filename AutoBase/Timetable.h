#pragma once
#include "Route.h"
#include "Header.h"
#include "Container.h"
class Timetable: public Container<Route>
{
private:
	double fuelvalue;
public:
	Timetable();
	Timetable(int);
	double allfuel();
};

