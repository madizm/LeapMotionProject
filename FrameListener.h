#pragma once
#include <iostream>
#include <cstring>
#include "Leap.h"
#include "Model.h"
#include "AS_6DOF.h"
//#include <vector>
#include <Windows.h>
using namespace Leap;
class FrameListener
{
public:
	FrameListener(void);
	~FrameListener(void);

    void onFrame(const Controller&);

	void notify(VectorXf info);
	void addObserverModel(Model*);

//	void setSerial(SerialUtil* serial);
private:
//	SerialUtil* serial;
	int numOberver;
	const static int MAXOBSERVER = 5;
	Model** observes;
//	VectorXd	info;//(R,P,Y,x,y,z)Rad
};

