#pragma once
#include "ErrorMessage.h"
class RangeMessage:public ErrorMessage
{
public:
	RangeMessage(int);
	void printmessage()override;
};

