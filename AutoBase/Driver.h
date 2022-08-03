#pragma once
#include "Header.h"
class Driver
{
protected:
	string fullname;
	int tabelnumber;
	int salary;
public:
	Driver();
	Driver(string, int, int);
	friend ostream& operator<<(ostream&, const Driver&);
	friend istream& operator>>(istream&, Driver&);
	Driver& operator=(const Driver&);
	int operator() (int);
};

