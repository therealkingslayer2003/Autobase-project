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
	output << "=====Інформація про рейс: Харків - " << object.final_destination <<"=====" << endl;
	output << "Дата рейсу: " << object.dateofroute.day << "." << object.dateofroute.month << "." << object.dateofroute.year << endl;
	output << "=====Інформація про водія=====" << endl;
	output << "Прізвище та ініціали: " << object.fullname << endl;
	output << "Табельний номер: " << object.tabelnumber << endl;
	output << "Зарплата: " << object.salary << endl;
	output << "=====Повна інформація про автомобіль=====" << endl;
	output << "Державний номер авто: " << object.number << endl;
	output << "Модель: " << object.model << endl;
	output << "Тип: " << object.type_of_transport << endl;
	output << "Вантажопідйомність(тонн): " << object.capacity << endl;
	output << "Норма витрат пального(л/100км): " << object.normalfuelrate << endl;
	output << "Місце приписки: " << object.registration << endl;
	output << "Кілометраж: " << object.km << endl;
	output << "Розхід пального за рейс: " << object.fuelconsumption << endl;
	output << "==========================================================" << endl;
	return output;
}
istream& operator>>(istream& input, Route& object) {
	cout << "=====Введіть інформацію про рейс=====" << endl;
	cout << "Дата рейсу: "; input >> object.dateofroute.day; cout << "."; input >> object.dateofroute.month; cout << "."; input >> object.dateofroute.year; cout << endl;
	cout << "Призначте водія на цей рейс , введіть прізвище та ім'я без пробілів через крапки "; input >> object.fullname; cout << endl;
	cout << "Табельний номер: "; input >> object.tabelnumber; cout << endl;
	bool flag = false;
	while (flag != true) {
		try {
			cout << "Зарплата(мінімальна 6000): ";
			input >> object.salary;
			if (object.salary < 6000) { flag = false; throw object.salary; }
			else { flag = true; }
		}
		catch (const int ex) { cout << ex << " це менше мінімальної зарплати,введіть інше значення" <<endl; }
	}
	object.SetAllatributes();
	cout << "Кінцевий пункт рейсу(Доступні міста на період воєнного стану - Київ, Запоріжжя, Суми, Чернігів, Лозова) ";
	while (object.final_destination != "Київ" or object.final_destination != "Запоріжжя" or object.final_destination != "Суми" or object.final_destination != "Чернігів" or object.final_destination != "Лозова") {
		try {
			cout << "укажіть місто доставки: "; input >> object.final_destination;
			if (object.final_destination == "Київ" or object.final_destination == "Запоріжжя" or object.final_destination == "Суми" or object.final_destination == "Чернігів" or object.final_destination == "Лозова") {
				break;
			}
			else {
				throw object.final_destination;
			}
		}
		catch (const string str) {
			cout << str << " це недоступне місто!" << endl;
		}
	};
	object.SetKilometers();
	object.SetFuelConsumption();
	cout << "=====================================\nІнформація успішно введена!" << endl;

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
	if (final_destination == "Київ") {
		km = 480.4;
	}
	if (final_destination == "Суми") {
		km = 183.8;
	}
	if (final_destination == "Лозова") {
		km = 148.6;
	}
	if (final_destination == "Запоріжжя") {
		km = 297.4;
	}
	if (final_destination == "Чернігів") {
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
		str = "\nДата рейсу " + to_string(dateofroute.day) + "." + to_string(dateofroute.month) + "." + to_string(dateofroute.year) + "\nВодій: "+ fullname+ " табельний номер : " + to_string(tabelnumber) + "\nАвто : " + number + " модель : " + model + " тип : "+ type_of_transport + " вантажопідйомність : " + to_string(capacity) + " витрати пального : " + to_string(normalfuelrate) + "\nКінцевий пункт рейсу : " + final_destination + "\nВсього кілометрів : " + to_string(km) + "\nВитрати пального за рейс : " + to_string(fuelconsumption);
	}
	else
	{
		str ="\n\nДата рейсу " + to_string(dateofroute.day) + "." + to_string(dateofroute.month) + "." + to_string(dateofroute.year) + "\nВодій: " + fullname + " табельний номер : " + to_string(tabelnumber) + "\nАвто : " + number + " модель : " + model + " тип : " + type_of_transport + " вантажопідйомність : " + to_string(capacity) + " витрати пального : " + to_string(normalfuelrate) + "\nКінцевий пункт рейсу : " + final_destination + "\nВсього кілометрів : " + to_string(km) + "\nВитрати пального за рейс: " + to_string(fuelconsumption);
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
