#pragma once

class Chair
{
public:
	static double width,height,length,thikness,curvR;
	static int listId;
	Chair(void);
	static void draw(double tx,double ty,double tz,int seatTex,int seatBackTex);
	static void drawCurv();
	static void initializeList();
	virtual ~Chair(void);
};

