#pragma once
#include "Header.h"
class Auto
{
protected:							
	string number;
	string model;
	string type_of_transport;
	double capacity;
	double normalfuelrate;
	string registration;
public:
	Auto();
	Auto(string, string, string, double, double, string);
	Auto(const Auto&);
	friend ostream& operator<<(ostream&, const Auto&);
	friend istream& operator>>(istream&, Auto&);
	Auto& operator=(const Auto&);
	double GetNormalFuelRate();
	double GetCapacity();
	string GetModel();
	void SetAllatributes();
};

