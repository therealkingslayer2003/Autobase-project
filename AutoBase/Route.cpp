#include "Route.h"
Route::Route() : Driver(),Auto(){
	dateofroute.day = 0;
	dateofroute.month = 0;
	dateofroute.year = 0;
	final_destination = " ";
	km = 0;
	fuelconsumption = 0;
}
Route::Route(date dateroute, string name,int number, int zp, string number1, string model1, string type, double capacity1, double normalfuelrate1, string registr, string finaldest, double kilom,double fuelconsum) :dateofroute(dateroute),Driver(name,number,zp),Auto(number1,model1,type,capacity1, normalfuelrate1,registr),final_destination(finaldest), km(kilom),fuelconsumption(fuelconsum) {}
ostream& operator<<(ostream& output, const Route& object) {
	output << "=====���������� ��� ����: ����� - " << object.final_destination <<"=====" << endl;
	output << "���� �����: " << object.dateofroute.day << "." << object.dateofroute.month << "." << object.dateofroute.year << endl;
	output << "=====���������� ��� ����=====" << endl;
	output << "������� �� �������: " << object.fullname << endl;
	output << "��������� �����: " << object.tabelnumber << endl;
	output << "��������: " << object.salary << endl;
	output << "=====����� ���������� ��� ���������=====" << endl;
	output << "��������� ����� ����: " << object.number << endl;
	output << "������: " << object.model << endl;
	output << "���: " << object.type_of_transport << endl;
	output << "����������������(����): " << object.capacity << endl;
	output << "����� ������ ��������(�/100��): " << object.normalfuelrate << endl;
	output << "̳��� ��������: " << object.registration << endl;
	output << "ʳ��������: " << object.km << endl;
	output << "������ �������� �� ����: " << object.fuelconsumption << endl;
	output << "==========================================================" << endl;
	return output;
}
istream& operator>>(istream& input, Route& object) {
	cout << "=====������ ���������� ��� ����=====" << endl;
	cout << "���� �����: "; input >> object.dateofroute.day; cout << "."; input >> object.dateofroute.month; cout << "."; input >> object.dateofroute.year; cout << endl;
	cout << "��������� ���� �� ��� ���� , ������ ������� �� ��'� ��� ������ ����� ������ "; input >> object.fullname; cout << endl;
	cout << "��������� �����: "; input >> object.tabelnumber; cout << endl;
	bool flag = false;
	while (flag != true) {
		try {
			cout << "��������(�������� 6000): ";
			input >> object.salary;
			if (object.salary < 6000) { flag = false; throw object.salary; }
			else { flag = true; }
		}
		catch (const int ex) { cout << ex << " �� ����� �������� ��������,������ ���� ��������" <<endl; }
	}
	object.SetAllatributes();
	cout << "ʳ������ ����� �����(������� ���� �� ����� ������� ����� - ���, ��������, ����, ������, ������) ";
	while (object.final_destination != "���" or object.final_destination != "��������" or object.final_destination != "����" or object.final_destination != "������" or object.final_destination != "������") {
		try {
			cout << "������ ���� ��������: "; input >> object.final_destination;
			if (object.final_destination == "���" or object.final_destination == "��������" or object.final_destination == "����" or object.final_destination == "������" or object.final_destination == "������") {
				break;
			}
			else {
				throw object.final_destination;
			}
		}
		catch (const string str) {
			cout << str << " �� ���������� ����!" << endl;
		}
	};
	object.SetKilometers();
	object.SetFuelConsumption();
	cout << "=====================================\n���������� ������ �������!" << endl;

	return input;

}

Route& Route::operator=(const Route& object) {
	dateofroute.day = object.dateofroute.day;
	dateofroute.month = object.dateofroute.month;
	dateofroute.year = object.dateofroute.year;
	fullname = object.fullname;
	tabelnumber = object.tabelnumber;
	salary = object.salary;
	number = object.number;
	model = object.model;
	type_of_transport = object.type_of_transport;
	capacity = object.capacity;
	normalfuelrate = object.normalfuelrate;
	registration = object.registration;
	final_destination = object.final_destination;
	km = object.km;
	fuelconsumption = object.fuelconsumption;
	return *this;
}

double Route::GetFuel()
{
	return fuelconsumption;
}

void Route::SetKilometers()
{
	if (final_destination == "���") {
		km = 480.4;
	}
	if (final_destination == "����") {
		km = 183.8;
	}
	if (final_destination == "������") {
		km = 148.6;
	}
	if (final_destination == "��������") {
		km = 297.4;
	}
	if (final_destination == "������") {
		km = 540.3;
	}
}

void Route::WriteStringData(string FILE)
{
	string str;
	ifstream fin;
	try
	{
		fin.open(FILE);
	}
	catch (const exception&) {}
	if (fin.peek() == ifstream::traits_type::eof())
	{
		str = "\n���� ����� " + to_string(dateofroute.day) + "." + to_string(dateofroute.month) + "." + to_string(dateofroute.year) + "\n����: "+ fullname+ " ��������� ����� : " + to_string(tabelnumber) + "\n���� : " + number + " ������ : " + model + " ��� : "+ type_of_transport + " ���������������� : " + to_string(capacity) + " ������� �������� : " + to_string(normalfuelrate) + "\nʳ������ ����� ����� : " + final_destination + "\n������ �������� : " + to_string(km) + "\n������� �������� �� ���� : " + to_string(fuelconsumption);
	}
	else
	{
		str ="\n\n���� ����� " + to_string(dateofroute.day) + "." + to_string(dateofroute.month) + "." + to_string(dateofroute.year) + "\n����: " + fullname + " ��������� ����� : " + to_string(tabelnumber) + "\n���� : " + number + " ������ : " + model + " ��� : " + type_of_transport + " ���������������� : " + to_string(capacity) + " ������� �������� : " + to_string(normalfuelrate) + "\nʳ������ ����� ����� : " + final_destination + "\n������ �������� : " + to_string(km) + "\n������� �������� �� ����: " + to_string(fuelconsumption);
	}
	fin.close();
	ofstream fout;
	try {
		fout.open(FILE, ofstream::app);
		fout << str;
	}
	catch (const exception&) {}
	
}

void Route::SetFuelConsumption()
{
	const double fuelrate = 34.5;
	fuelconsumption = ((km / 100) * fuelrate) * 2;
}
