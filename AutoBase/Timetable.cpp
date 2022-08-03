#include "Timetable.h"
Timetable::Timetable() : Container<Route>() {
	fuelvalue = 0;
}
Timetable::Timetable(int size) : Container<Route>::Container(size){
	fuelvalue = 0;
}
double Timetable::allfuel()
{
	for (int i = 0; i < size; i++) {
		fuelvalue += info[i].GetFuel();
	}
	return fuelvalue;
}


