#pragma once
#include "PassengersCar.h"
#include "CargoCar.h"
#include "BedRoomCar.h"
#include "KitchenCar.h"
#include "DrivingCar.h"

class Train
{	
public:
	static PassengersCar pCar1,pCar2,pCar3,pCar4;
	static CargoCar cCar1,cCar2;
	static BedRoomCar bCar1,bCar2;
	static KitchenCar kCar1,kCar2;
	static DrivingCar drivingCar;
	static double tx,ty,tz;
	static void initialize();
	static void draw();
	static void translate(int x,int y,int z);
	static void interact(bool keys[]);
	static bool canCameraGoTo(double x,double y,double z);
	
	
	

	Train(void);
	~Train(void);
};

