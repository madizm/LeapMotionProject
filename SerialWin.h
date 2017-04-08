#pragma once
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include "SerialUtil.h"
class SerialWin : public SerialUtil
{
public:
	SerialWin(const char *portName);
	~SerialWin(void);
	int ReadData(char *buffer, unsigned int nbChar);
	int WriteData(const char *buffer, unsigned int nbChar);
	bool IsConnected();
private:
	HANDLE hSerial;
	bool connected;
	COMSTAT status;
	DWORD errors;
};

