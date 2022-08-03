#pragma once
template <typename T,typename Tvalue> // � - ��� ��'����,�� ������ ��������, �value - ��� ��������
class CustomIter // ������������ ������� ��������� STL::iterator
{
private:
	T& data;	//���������
	int beginposition;	//��������� �������
	int endposition;	//������ �������
	int width; //������ ����
	int widthregion; //������ ������
	int now; //������ �������
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

