#include "Manager.h"
ostream& operator<<(ostream& output, const Manager& object) {
	output << "����������� ������!, ������� ��� " << object.login << endl;
	return output;
}
istream& operator>>(istream& input, Manager& object) {
	cout << "������ ����: "; input >> object.login;
	return input;
}