#pragma once
#include "Header.h"
#include "Route.h"
#include "Timetable.h"
class Order
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
	int ordernumber;
	string companyname;
	string cargotype;
	int routeamount;
	double alltonns;
	double allfuel;
	date contractdate;
public:
	Order();
	friend ostream& operator<<(ostream&, const Order&);
	friend istream& operator>>(istream&, Order&);
	void SetAllFuel(Timetable&);
	double GetAllFuel();
	void SetNumber(int);
	void SetRouteAmount(Auto&);
	int GetRouteAmount();
};

