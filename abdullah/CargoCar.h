#pragma once
#include "TrainCar.h"

class CargoCar : public TrainCar
{
public:
	static int cargoId;
	CargoCar();
	CargoCar(int nothing);
	void draw();

	~CargoCar();
};

