#include "RangeMessage.h"
RangeMessage::RangeMessage(int value) :ErrorMessage(value) {}
void RangeMessage::printmessage() {
	cout << "Елементу за даним індексом не існує - " << index << endl;
}