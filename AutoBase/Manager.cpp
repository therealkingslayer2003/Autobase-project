#include "Manager.h"
ostream& operator<<(ostream& output, const Manager& object) {
	output << "јвторизац≥€ усп≥шна!, доброго дн€ " << object.login << endl;
	return output;
}
istream& operator>>(istream& input, Manager& object) {
	cout << "¬вед≥ть лог≥н: "; input >> object.login;
	return input;
}