#pragma once
#include "Header.h"
class Manager
{
private:
	string login;
public:
	friend ostream& operator<<(ostream&, const Manager&);
	friend istream& operator>>(istream&, Manager&);
};

