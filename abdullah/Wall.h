#pragma once
#include "Dimention.h"
class Wall
{
public:
	Wall(void);
	double tx,ty,tz,rx,ry,rz;
	Dimention dims;
	int lTexture,rTexture,custom;
	int texV,texH;
	bool isWindow,isChair;
	Wall(Dimention dims,int lTexture,int rTexture);
	void setTextureCount(int vertical,int horizontal);
	void translate(double x,double y,double z);
	void rotate(double x,double y,double z);
	void setCustomTexture(int toto);
	void draw();
	static void drawWall(double width,double length,double height,int lTexture,int rTexture,int custom,bool glass,int out,int wood);
	virtual ~Wall(void);
};

