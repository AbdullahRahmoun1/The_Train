#pragma once
#include "TrainCar.h"
class kitchen : public TrainCar
{
public:
	bool canCameraGoTo(float x,float y,float z) ;
	virtual ~kitchen(void);
protected: 
	void drawDecore();
	void initializeDecore();
	
};

