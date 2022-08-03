#include "Driver.h"
Driver::Driver() {
	fullname = " ";
	tabelnumber = 0;
	salary = 0;
}
Driver::Driver(string fio, int tabel, int zp) : fullname(fio), tabelnumber(tabel), salary(zp) {}
Driver& Driver::operator=(const Driver& object) {
	fullname = object.fullname;
	tabelnumber = object.tabelnumber;
	salary = object.salary;
	return *this;
}
int Driver::operator() (int value) {
	salary += value;
	return salary;
}
ostream& operator<<(ostream& output, const Driver& object) {
	output << "=====Інформація про водія=====" << endl;
	output << "Прізвище та ініціали: " << object.fullname << endl;
	output << "Табельний номер: " << object.tabelnumber << endl;
	output << "Зарплата: " << object.salary << endl;
	return output;
}
istream& operator>>(istream& input, Driver& object) {
	cout << "=====Введіть дані про водія=====" << endl;
	cout << "Прізвище та ініціали: ";
	input >> object.fullname;
	cout << "Табельний номер: ";
	input >> object.tabelnumber; bool flag = false;
	while (flag != true) {
		try {
			cout << "Зарплата(мінімальна 6000): ";
			input >> object.salary;
			if (object.salary < 6000) { flag = false; throw object.salary; }
			else { flag = true; break; }
		}
		catch (const int ex) { cout << ex << " це менше мінімальної зарплати,введіть інше значення"; }
	}
	cout << "Інфрмація успішно введена!"<< endl;
	return input;
}