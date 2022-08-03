#pragma once
template <typename T,typename Tvalue> // Т - тип об'єкту,що містить елементи, Тvalue - тип елементів
class CustomIter // Успадкування прямого ітератора STL::iterator
{
private:
	T& data;	//контейнер
	int beginposition;	//початкова позиція
	int endposition;	//кінцева позиція
	int width; //ширина поля
	int widthregion; //ширина регіона
	int now; //нинішня позиція
public:
	CustomIter(T& data1, int posbeg, int posend, int widthpos, int widthresionpos, int nowpos = 0) :data(data1), beginposition(posbeg), endposition(posend), width(widthpos), widthregion(widthresionpos), now(nowpos) {}
	Tvalue& operator* () {
		return data[beginposition + (now % widthregion) + (now / widthregion) * width];
	}
	CustomIter<T, Tvalue>& operator++() {
		++now; return *this;
	}
	CustomIter<T, Tvalue>& operator++(int a) {
		++now; return *this;
	}
};

