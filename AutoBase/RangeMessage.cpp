#include "RangeMessage.h"
RangeMessage::RangeMessage(int value) :ErrorMessage(value) {}
void RangeMessage::printmessage() {
	cout << "�������� �� ����� �������� �� ���� - " << index << endl;
}