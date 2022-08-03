#include "Order.h"
Order::Order() {
	ordernumber = 0;
	companyname = " ";
	cargotype = " ";
	routeamount = 0;
	alltonns = 0;
	allfuel = 0;
	contractdate.day = 0;
	contractdate.month = 0;
	contractdate.year = 0;
}
void Order::SetAllFuel(Timetable & object)
{
	allfuel = object.allfuel();
}
double Order::GetAllFuel()
{
	return allfuel;
}
void Order::SetNumber(int number)
{
	ordernumber = number;
	cout << "Номер замовлення " << ordernumber << endl;
}
void Order::SetRouteAmount(Auto& object)
{
	routeamount = ceil(alltonns / object.GetCapacity());
	cout << "!Кількість рейсів для замовлення: " << routeamount << endl;
}
int Order::GetRouteAmount()
{
	return routeamount;
}
ostream& operator<<(ostream& output, const Order& object) {
	output << "=====Інформація про замовлення=====" << endl;
	output << "Номер замовлення: " << object.ordernumber << endl;
	output << "Назва компанії-замовника : " << object.companyname << endl;
	output << "Вид вантажу: " << object.cargotype << endl;
	output << "Кількість вантажу(у тоннах): " << object.alltonns << endl;
	output << "Кількість рейсів: " << object.routeamount << endl;
	output << "Загальні витрати пального: " << object.allfuel << endl;
	output << "<Дата підписання контракту з автобазою>" << endl;
	output << "День: " << object.contractdate.day << endl;
	output << "Місяць: " << object.contractdate.month << endl;
	output << "Рік: " << object.contractdate.year << endl;
	return output;
}
istream& operator>>(istream& input, Order& object) {
	cout << "=====Підписання контракту з автобазою 'Express'=====" << endl;
	cout << "Назва компанії: "; input >> object.companyname; cout << endl;
	cout << "Вид вантажу: "; input >> object.cargotype; cout << endl;
	cout << "Кількість вантажу(у тоннах): "; input >> object.alltonns; cout << endl;
	cout << "<Дата підписання контракту>" << endl; 
	cout << "День: "; input >> object.contractdate.day; cout << endl;
	cout << "Місяць: "; input >> object.contractdate.month; cout << endl;
	cout << "Рік: "; input >> object.contractdate.year; cout << endl;
	cout << "Контракт підписаний!" << endl;
	return input;
}