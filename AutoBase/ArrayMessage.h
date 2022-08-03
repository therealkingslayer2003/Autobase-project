#pragma once
#include "ErrorMessage.h"
class ArrayMessage :
    public ErrorMessage
{
public:
    ArrayMessage(int);
    void printmessage()override;
};

