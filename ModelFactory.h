#pragma once
#include "Model.h"
#include "AS_6DOF.h"
#include "AS_6DOF_1.h"
#include <string>
#include "kdl/chainiksolverpos_lma.hpp"
using namespace KDL;
using namespace std;
class ModelFactory
{
public:
	typedef enum MyEnum
	{
		AS6DOF,
		AS6DOF_1
	}ROBOT_TYPE;

	ModelFactory(void);
	~ModelFactory(void);
	Model* createModel(ROBOT_TYPE type);
private:
	Chain chain;
};

