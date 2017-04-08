#include "stdafx.h"
#include "FrameListener.h"


FrameListener::FrameListener(void)
{
	numOberver = 0;
	observes = new Model*[MAXOBSERVER];
	//info = Eigen::VectorXd(6);
	//info<<0.0, 0.0, 0.0, 0.0, 0.0, 0.0;
}


FrameListener::~FrameListener(void)
{
}


void FrameListener::onFrame(const Controller& con){
	do
	{
		const Leap::Frame fr = con.frame();
		const Hand hand = fr.hands()[0];
		if(fr.hands().isEmpty())
		{
//			info<<0.0, 0.0, 0.0, 0.0, 0.0, 0.0;
			continue;
		}
		const Leap::Vector position = hand.palmPosition();
		const Leap::Vector normal = hand.palmNormal();
		const Leap::Vector direction = hand.direction();

		const float R = normal.roll();
		const float P = direction.pitch();
		const float Y = direction.yaw();
		const float x = position.x;
		const float y = position.y;
		const float z = position.z;
		const float s = hand.grabStrength();
		VectorXf vec = Eigen::VectorXf(7);
		vec<<R, P, Y, x, y, z, s;
		//if(oldInfo(0)==0.0&&oldInfo(1)==0.0&&oldInfo(2)==0.0&&oldInfo(3)==0.0&&oldInfo(4)==0.0&&oldInfo(5)==0.0)
		//{
		//	oldInfo<<R, P, Y, x, y, z;
		//	continue;
		//}
		//oldInfo<<R, P, Y, x, y, z;
//		std::cout<<vec<<std::endl;
		notify(vec);
		Sleep(500);
	} while (true);
}

void FrameListener::notify(VectorXf info)
{
	int i;
	for(i = 0; i<numOberver; i++)
	{
		observes[i]->update(info);
	}
//	as->update(dInfo);
}

void FrameListener::addObserverModel(Model* m)
{
	numOberver++;
	if(numOberver>=MAXOBSERVER)
	{
		std::cout<<"Can not Add more Obverser"<<std::endl;
		return;
	}
	observes[numOberver-1] = m;
}


//void FrameListener::onInit(const Controller& controller) {
//  std::cout << "Initialized" << std::endl;
//}
//
//void FrameListener::onConnect(const Controller& controller) {
//  std::cout << "Connected" << std::endl;
//  controller.enableGesture(Gesture::TYPE_CIRCLE);
//  controller.enableGesture(Gesture::TYPE_KEY_TAP);
//  controller.enableGesture(Gesture::TYPE_SCREEN_TAP);
//  controller.enableGesture(Gesture::TYPE_SWIPE);
//}
//
//void FrameListener::onFocusGained(const Controller& controller) {
//  std::cout << "Focus Gained" << std::endl;
//}
//
//void FrameListener::onFocusLost(const Controller& controller) {
//  std::cout << "Focus Lost" << std::endl;
//}