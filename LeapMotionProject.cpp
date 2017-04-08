// LeapMotionProject.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "FrameListener.h"
#include "ModelFactory.h"
#include "SerialWin.h"
int _tmain(int argc, _TCHAR* argv[])
{
	SerialUtil* serial = new SerialWin("\\\\.\\COM3");
	if(serial->IsConnected()) cout<<"Serial Opened.."<<endl;

	Controller controller;
	FrameListener listener;

	ModelFactory factory;
	Model* as6dof = factory.createModel(ModelFactory::AS6DOF_1);
	as6dof->setSerial(serial);
	listener.addObserverModel(as6dof);

	listener.onFrame(controller);

	
	delete as6dof;
	delete serial;

	return 0;
}

