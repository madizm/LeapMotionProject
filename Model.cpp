#include "stdafx.h"
#include "Model.h"


Model::Model(void)
{
}


Model::~Model(void)
{
}

void Model::setSerial(SerialUtil* serial)
{
	this->serial = serial;
}