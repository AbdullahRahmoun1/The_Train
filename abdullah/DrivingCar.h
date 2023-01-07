#pragma once
#include <windows.h>		// Header File For Windows
#include <gl\gl.h>			// Header File For The OpenGL32 Library
#include <gl\glu.h>			// Header File For The GLu32 Library
#include <glaux.h>		// Header File For The Glaux Library
#include <texture.h>
#include <math.h>	
#include "TrainCar.h"
class DrivingCar : public TrainCar
{
public:
	DrivingCar(void);
	DrivingCar(int t);
	double wheelsAngle;
	void draw();
	~DrivingCar(void);
	
};

