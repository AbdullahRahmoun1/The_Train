#pragma once
#include "Wall.h"
class MainDoor
{
public:
	int state;
	static double width,height,thikness;
	double forwordSpeed,LNRSpeed;
	double tx,ty,tz,rx,ry,rz;
	Wall leftDoor,rightDoor;
	MainDoor(void);
	MainDoor(int left,int right);
	void draw();
	void manageDoors();
	void manage();
	void setState(int t);
	void open();
	void close();
	void translate(double x,double y,double z);
	void rotate(double x,double y,double z);
	virtual ~MainDoor(void);
};

