#pragma once
#include "Header.h"
class ErrorMessage
{
protected:
	int index;
public:
	ErrorMessage(int);
	virtual void printmessage() = 0;
};

