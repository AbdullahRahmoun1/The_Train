#include "Train.h"
#include "PassengersCar.h"
#include "CargoCar.h"
#include "BedRoomCar.h"
#include "KitchenCar.h"


PassengersCar Train::pCar1=PassengersCar(3);
PassengersCar Train::pCar2=PassengersCar(3);
PassengersCar Train::pCar3=PassengersCar(3);
PassengersCar Train::pCar4=PassengersCar(3);
CargoCar Train::cCar1=CargoCar(3);
CargoCar Train::cCar2=CargoCar(3);
BedRoomCar Train::bCar1=BedRoomCar(3);
BedRoomCar Train::bCar2=BedRoomCar(3);
KitchenCar Train::kCar1=KitchenCar(3);
KitchenCar Train::kCar2=KitchenCar(3);
DrivingCar Train::drivingCar=DrivingCar(3);

Train::Train(void)
{
}
void Train::initialize(){
	Chair::initializeList();
	TrainCar::initializeLists();
	KitchenCar::initializeList();
	pCar1=PassengersCar();
	pCar2=PassengersCar();
	pCar3=PassengersCar();
	pCar4=PassengersCar();
	cCar1=CargoCar();
	cCar2=CargoCar();
	bCar1=BedRoomCar();
	bCar2=BedRoomCar();
	kCar1=KitchenCar();
	kCar2=KitchenCar();
	drivingCar=DrivingCar();
	cCar1.frontDoorLocked=true;
	double z=0;
	z-=cCar1.getGoodLength();
	kCar1.translate(0,0,z);
	z-=kCar1.getGoodLength();
	pCar1.translate(0,0,z);
	z-=pCar1.getGoodLength();
	pCar2.translate(0,0,z);
	z-=pCar2.getGoodLength();
	kCar2.translate(0,0,z);
	z-=kCar2.getGoodLength();
	// pass 
	pCar3.translate(0,0,z);
	z-=pCar3.getGoodLength();
	pCar4.translate(0,0,z);
	z-=pCar4.getGoodLength();
	// pass
	bCar1.translate(0,0,z);
	z-=bCar1.getGoodLength();
	bCar2.translate(0,0,z);
	z-=bCar2.getGoodLength();
	cCar2.translate(0,0,z);
	z-=cCar2.getGoodLength();
	drivingCar.translate(0,0,z-0.5);
}
void Train::draw(){
	double z=0;
	cCar1.draw();
	cCar2.draw();
	pCar1.draw();
	pCar2.draw();
	pCar3.draw();
	pCar4.draw();
	bCar1.draw();
	bCar2.draw();
	kCar1.draw();
	kCar2.draw();
	drivingCar.draw();
	//windows 
	cCar1.drawLast();
	cCar2.drawLast();
	pCar1.drawLast();
	pCar2.drawLast();
	pCar3.drawLast();
	pCar4.drawLast();
	bCar1.drawLast();
	bCar2.drawLast();
	kCar1.drawLast();
	kCar2.drawLast();
}
void Train::translate(int x,int y,int z){


}
void Train::interact(bool Keys[]){
	if(Keys['E']){
		cCar1.interactDoors();
		cCar2.interactDoors();
		pCar1.interactDoors();
		pCar2.interactDoors();
		pCar3.interactDoors();
		pCar4.interactDoors();
		bCar1.interactDoors();
		bCar2.interactDoors();
		kCar1.interactDoors();
		kCar2.interactDoors();
		bCar1.interactCloast();
		bCar2.interactCloast();
	}
	if(Keys['Q']){
		cCar1.interactWindows();
		cCar2.interactWindows();
		pCar1.interactWindows();
		pCar2.interactWindows();
		pCar3.interactWindows();
		pCar4.interactWindows();
		bCar1.interactWindows();
		bCar2.interactWindows();
		kCar1.interactWindows();
		kCar2.interactWindows();
	}
	if(Keys['1']){
		cCar1.interactLight();
		cCar2.interactLight();
		pCar1.interactLight();
		pCar2.interactLight();
		pCar3.interactLight();
		pCar4.interactLight();
		bCar1.interactLight();
		bCar2.interactLight();
		kCar1.interactLight();
		kCar2.interactLight();
	}
}
bool Train::canCameraGoTo(double x,double y,double z){
	return pCar1.canCameraGoTo(x,y,z) &&
		pCar2.canCameraGoTo(x,y,z) &&
		pCar3.canCameraGoTo(x,y,z) &&
		pCar4.canCameraGoTo(x,y,z) &&
		cCar1.canCameraGoTo(x,y,z) &&
		cCar2.canCameraGoTo(x,y,z) &&
		kCar1.canCameraGoTo(x,y,z) &&
		kCar2.canCameraGoTo(x,y,z) &&
		bCar1.canCameraGoTo(x,y,z) &&
		bCar2.canCameraGoTo(x,y,z) &&
		drivingCar.canCameraGoTo(x,y,z);
}
Train::~Train(void)
{
}
