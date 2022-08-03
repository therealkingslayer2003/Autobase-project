#include "Auto.h"
Auto::Auto() {
	number = " ";
	model = " ";
	type_of_transport = " ";
	capacity = 0;
	normalfuelrate = 0;
	registration = " ";
}
Auto::Auto(string number1, string model1, string type, double capacity1, double normalfuelrate1, string registr) : number(number1), model(model1), type_of_transport(type), capacity(capacity1), normalfuelrate(normalfuelrate1), registration(registr) {}
Auto::Auto(const Auto& object) {
	number = object.number;
	model = object.model;
	type_of_transport = object.type_of_transport;
	capacity = object.capacity;
	normalfuelrate = object.normalfuelrate;
	registration = object.registration;
}
void Auto::SetAllatributes() {
	number = "�� 5667 ��";
	model = "�����-5320";
	type_of_transport = "�������� ��������������� ��������� ���������";
	capacity = 15;
	normalfuelrate = 34.5;
	registration = "�����";
}
double Auto::GetCapacity() {
	return capacity;
}
string Auto::GetModel()
{
	return model;
}
double Auto::GetNormalFuelRate() {
	return normalfuelrate;
}
Auto& Auto::operator=(const Auto& object) {
	number = object.number;
	model = object.model;
	type_of_transport = object.type_of_transport;
	capacity = object.capacity;
	normalfuelrate = object.normalfuelrate;
	registration = object.registration;
	return *this;
}
ostream& operator<<(ostream& output, const Auto& object) {
	output << "=====����� ���������� ��� ���������=====" << endl;
	output << "��������� ����� ����: " << object.number << endl;
	output << "������: " << object.model << endl;
	output << "���: " << object.type_of_transport << endl;
	output << "����������������(����): " << object.capacity << endl;
	output << "����� ������ ��������(�/100��): " << object.normalfuelrate << endl;
	output << "̳��� ��������: " << object.registration << endl;
	return output;
}
istream& operator>>(istream& input, Auto& object) {
	cout << "=====������ ���������� ��� ����=====" << endl;
	cout << "��������� ����� ���������: ";
	input >> object.number;
	cout << "������: ";
	input >> object.model;
	cout << "T��: ";
	input >> object.type_of_transport;
	cout << "����������������: ";
	input >> object.capacity;
	cout << "����� ������ ��������: ";
	input >> object.normalfuelrate;
	cout << "̳��� ��������: ";
	input >> object.registration;
	cout << "���������� ������ �������!" << endl;
	return input;
}
