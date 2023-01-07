#pragma once
#include <windows.h>		// Header File For Windows
#include <gl\gl.h>			// Header File For The OpenGL32 Library
#include <gl\glu.h>			// Header File For The GLu32 Library
#include <glaux.h>		// Header File For The Glaux Library
#include <texture.h>
#include <iostream>
#include <math.h>
#include "Point2.h"
#include "Dimention.h"
#include "Wall.h"
#include "Door.h"
#include "Window.h"
#include "SideWall.h"
#include "MainDoor.h"
#include "Chair.h"
#include "ProjectTextures.h"
#include <vector>
 class TrainCar
{
public:
	static double width,length,height,wallThikness,cLength,enginsThikness,enginsWidth,scale,scaledWidth,scaledHeight,scaledLength,scaledWallThikness,heightTranslation;
	SideWall leftSideWall,lRightSideWall,rRightSideWall;
	MainDoor mainDoor;
	Wall aboveDoor,lConnecterGlass,rConnecterGlass,engins,carpet;
	double wheelsAngle;
	bool hasMainDoor,hasConnecter,hasLight;
	double roofR,horizontalBox;
	double tx,ty,tz;
	static int wheelsListId,CarListId,roofListId
		,wallWithDoorId,hasDoorId,noDoorId,lastWithDoorId,lastNoDoorId;
	TrainCar();
	TrainCar(bool hasMainDoor,bool hasConnecter,double collisionDistance);
	void interactLight();
	bool inRange();
	static void initializeLists();
	void translate(double x,double y,double z);
	void initalizeDrawing();
	void openFrontDoor();
	void closeFrontDoor();
	void openBackDoor();
	void closeBackDoor();
	void closeDoors();
	void openDoors();
	virtual void draw();
	virtual void drawLast();
	void manageAnimations();
	void closeWindows();
	void openWindows();
	void interactDoors();
	void interactWindows();
	double getGoodLength();
	virtual bool canCameraGoTo(double x,double y,double z);
	virtual ~TrainCar(void);
private:
	bool visible;
	Door frontDoor;
	Door backDoor;
	Wall ground;
	void WallWithDoor(bool front);
	void drawRoofSide(bool left);
	void drawRoof();
	void drawConnecter();
	
protected:
	void drawWheels();
	void drawWheel(double z);
	static void WheelsBuild(double WheelRadius,double WheelThikness,double WheelDepth,double CylinderLength,double CylinderRadius);
	static void WheelBuild(double radius,double thikness,double depth);
	void CylinderBuild(double length,double radius);
	virtual void drawDecore();
	virtual void initializeDecore();
	bool canInteract(double x , double z ,double width);
	
};

