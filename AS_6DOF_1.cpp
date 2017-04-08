#include "stdafx.h"
#include "AS_6DOF_1.h"


AS_6DOF_1::AS_6DOF_1(void)
{
	l1 = 97.0;
	//l2 = 120.0;
	//l3 = 5.0;
	l2 = 92.0;
	l3 = 30.0;
}


AS_6DOF_1::~AS_6DOF_1(void)
{
}

void AS_6DOF_1::update(VectorXf info)
{	
	float R = info(0);
	float P = info(1);
	float Y = info(2); 
	float x = info(3);
	float y = info(4);
	float z = info(5);
	float strength = info(6);
	std::cout<<"RPYxyz: "<<R*Leap::RAD_TO_DEG<<" "<<P*Leap::RAD_TO_DEG<<" "<<Y*Leap::RAD_TO_DEG<<" "<<x<<" "<<y<<" "<<z<<" "<<strength<<std::endl;
	Matrix3f projM ;
	projM<<cos(Y), 0, sin(Y),
		0, 1, 0,
		-sin(Y), 0, cos(Y);
	Vector3f v3 = projM*Vector3f(x, y, z);
	float A = v3(1) - l3*cos(P);
	float B = v3(2) - l3*sin(P);

	float t = (A*A+B*B-l1*l1-l2*l2)/(2*l1*l2);
	if(t>1){
		std::cout<<"Can Not Reach!!"<<std::endl;
		return;
	}
	float theta2 = acos(t);
	
	float p = l1+l2*cos(theta2);
	float q = l2*sin(theta2);
	t = (p*A-q*B)/(p*p+q*q);
	if(t>1){
		std::cout<<"Can Not Reach!!"<<std::endl;
		return;
	}
	float theta1 = asin(t);

	std::cout<<Y*Leap::RAD_TO_DEG<<" "<<theta1*Leap::RAD_TO_DEG<<" "<<theta2*Leap::RAD_TO_DEG<<" "<<P*Leap::RAD_TO_DEG<<" "<<R*Leap::RAD_TO_DEG<<std::endl;
//	P = P+theta1+theta2-M_PI_2;
	P = P+theta1+theta2-M_PI_2;
	int q0 = 1500 - 10*Y*Leap::RAD_TO_DEG;
	int q1 = 1720 - 10*(theta1*Leap::RAD_TO_DEG - 60);
	int q2 = 1850 - 10*(theta2*Leap::RAD_TO_DEG - 30);
	int q3 = 1550 + 10*P*Leap::RAD_TO_DEG;
	int q4 = 1500 - 10*R*Leap::RAD_TO_DEG;
	int q5 = 500 + (1260-500)*strength;

	std::ostringstream ostr;
	ostr<<q0<<" "<<q1<<" "<<q2<<" "<<q3<<" "<<q4<<" "<<q5<<'e';
	std::string s = ostr.str();
	std::cout<<s<<std::endl;

	
	std::cout<<serial->WriteData(s.c_str(),s.length())<<std::endl;

	Sleep(500);
}