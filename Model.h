#pragma once
#include <Eigen/Dense>
#define _USE_MATH_DEFINES
#include <math.h>
#include <Windows.h>
#include "SerialUtil.h"
#include <string>
#include <iostream>
#include <sstream>  
#include "Leap.h"

using namespace Eigen;
class Model
{
public:
	Model();
	virtual ~Model(void);
	void setSerial(SerialUtil* serial);
	virtual void update(VectorXf) = 0;
	
protected:
	SerialUtil* serial;
};

