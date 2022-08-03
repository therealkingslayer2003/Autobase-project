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
	number = "АХ 5667 ВК";
	model = "КамАЗ-5320";
	type_of_transport = "бортовий великотоннажний вантажний автомобіль";
	capacity = 15;
	normalfuelrate = 34.5;
	registration = "Харків";
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
	output << "=====Повна інформація про автомобіль=====" << endl;
	output << "Державний номер авто: " << object.number << endl;
	output << "Модель: " << object.model << endl;
	output << "Тип: " << object.type_of_transport << endl;
	output << "Вантажопідйомність(тонн): " << object.capacity << endl;
	output << "Норма витрат пального(л/100км): " << object.normalfuelrate << endl;
	output << "Місце приписки: " << object.registration << endl;
	return output;
}
istream& operator>>(istream& input, Auto& object) {
	cout << "=====Введіть інформацію про авто=====" << endl;
	cout << "Державний номер автомобіля: ";
	input >> object.number;
	cout << "Модель: ";
	input >> object.model;
	cout << "Tип: ";
	input >> object.type_of_transport;
	cout << "Вантажопідйомність: ";
	input >> object.capacity;
	cout << "Норма витрат пального: ";
	input >> object.normalfuelrate;
	cout << "Місце приписки: ";
	input >> object.registration;
	cout << "Інформація успішно введена!" << endl;
	return input;
}
