#pragma once
#include "Window.h"
#include "Dimention.h"
#include "Wall.h"
class SideWall
{
public:
	Dimention dims;
	Window windows[5];//number of Windowes
	Wall walls[16];// num of windows *2 + num of windows-1
	int n,lTexture,rTexture,curtainTexture;
	double lg,rg,bg;
	bool reverse;
	double tx,ty,tz,rx,ry,rz;
	SideWall(void);
	SideWall(Dimention dims,double LNRgab,int lTexture,int rTexture,int curtainTexture);
	void setNumOfWindows(int n);
	void justReverse();
	void initialize();
	void draw();
	void drawWindows();
	void drawCurtains();
	void openWindows();
	void closeWindows();
	void rotate(double x,double y,double z);
	void translate(double x,double y, double z);
	virtual ~SideWall(void);
};

