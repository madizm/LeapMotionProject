#pragma once
#include "model.h"
class AS_6DOF_1 :
	public Model
{
public:
	AS_6DOF_1(void);
	~AS_6DOF_1(void);

	virtual void update(VectorXf);

private:
	float l1, l2, l3;
public:
  EIGEN_MAKE_ALIGNED_OPERATOR_NEW
};

