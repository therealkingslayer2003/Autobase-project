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
	cout << "����� ���������� " << ordernumber << endl;
}
void Order::SetRouteAmount(Auto& object)
{
	routeamount = ceil(alltonns / object.GetCapacity());
	cout << "!ʳ������ ����� ��� ����������: " << routeamount << endl;
}
int Order::GetRouteAmount()
{
	return routeamount;
}
ostream& operator<<(ostream& output, const Order& object) {
	output << "=====���������� ��� ����������=====" << endl;
	output << "����� ����������: " << object.ordernumber << endl;
	output << "����� ������-��������� : " << object.companyname << endl;
	output << "��� �������: " << object.cargotype << endl;
	output << "ʳ������ �������(� ������): " << object.alltonns << endl;
	output << "ʳ������ �����: " << object.routeamount << endl;
	output << "������� ������� ��������: " << object.allfuel << endl;
	output << "<���� ��������� ��������� � ���������>" << endl;
	output << "����: " << object.contractdate.day << endl;
	output << "̳����: " << object.contractdate.month << endl;
	output << "г�: " << object.contractdate.year << endl;
	return output;
}
istream& operator>>(istream& input, Order& object) {
	cout << "=====ϳ�������� ��������� � ��������� 'Express'=====" << endl;
	cout << "����� ������: "; input >> object.companyname; cout << endl;
	cout << "��� �������: "; input >> object.cargotype; cout << endl;
	cout << "ʳ������ �������(� ������): "; input >> object.alltonns; cout << endl;
	cout << "<���� ��������� ���������>" << endl; 
	cout << "����: "; input >> object.contractdate.day; cout << endl;
	cout << "̳����: "; input >> object.contractdate.month; cout << endl;
	cout << "г�: "; input >> object.contractdate.year; cout << endl;
	cout << "�������� ���������!" << endl;
	return input;
}