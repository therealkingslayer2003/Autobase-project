#pragma once
#include "Auto.h"
#include "Driver.h"
class Route : 
	public Auto, public Driver
{
private:
	struct date {
		int day;
		int month;
		int year;
		date() {
			day = 0;
			month = 0;
			year = 0;
		}
		date(int dd, int mm, int yyyy) {
			day = dd;
			month = mm;
			year = yyyy;
		}
	};
	date dateofroute;
	string final_destination;
	double km;
	double fuelconsumption;
public:
	Route();
	Route(date, string, int, int, string, string, string, double, double, string, string, double, double);
	friend ostream& operator<<(ostream&, const Route&);
	friend istream& operator>>(istream&, Route&);
	Route& operator=(const Route&);
	double GetFuel();
	void SetKilometers();
	void WriteStringData(string);
	void SetFuelConsumption();
};

