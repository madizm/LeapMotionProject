#pragma once
#define ARDUINO_WAIT_TIME 2000
class SerialUtil
{
public:
	SerialUtil();
	//SerialUtil(const char *portName);
	~SerialUtil(void);
	virtual int ReadData(char *buffer, unsigned int nbChar)=0;
	virtual int WriteData(const char *buffer, unsigned int nbChar)=0;
	virtual bool IsConnected()=0;
private:
};

