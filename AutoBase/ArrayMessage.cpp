#include "ArrayMessage.h"
ArrayMessage::ArrayMessage(int size):ErrorMessage(size) {}
void ArrayMessage::printmessage() {
	cout << "Масив більше ніж на 10 елементів створювати заборонено" << endl;
}