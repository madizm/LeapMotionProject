#include "stdafx.h"
#include "ModelFactory.h"


ModelFactory::ModelFactory(void)
{
	//chain.addSegment(
	//	Segment(Joint(Joint::RotZ),
	//	Frame(Vector(0.0, 0.0, 80))));
 //   chain.addSegment(
	//	Segment(Joint(Joint::RotX),
	//	Frame(Vector(0.0, 46, 85))));
	//chain.addSegment(
	//	Segment(Joint(Joint::RotX),
	//	Frame(Vector(0.0, 0.0, 88))));
	//chain.addSegment(
	//	Segment(Joint(Joint::RotX),
	//	Frame(Vector(0.0, 0.0, 30))));
	//chain.addSegment(
	//	Segment(Joint(Joint::RotY),
	//	Frame(Vector(0.0, -100, 0.0))));
	//std::cout<<"Model initialization succeed"<<std::endl;
}


ModelFactory::~ModelFactory(void)
{
}

Model* ModelFactory::createModel(ROBOT_TYPE type)
{
	Model* model = NULL;
	switch (type)
	{
	case AS6DOF:
//		model = new AS_6DOF(chain);
	case AS6DOF_1:
		model = new AS_6DOF_1();
	default:
		break;
	}
	return model;
}