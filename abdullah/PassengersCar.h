#pragma once
#include "TrainCar.h"
class PassengersCar : public TrainCar
{
public:
	static int passengersId;
	PassengersCar(void);
	PassengersCar(int t);
	void draw();
	virtual ~PassengersCar(void);
protected: 
	std::vector<Wall>decoreWalls;
	void initializeDecore();
};

