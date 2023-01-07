#pragma once
class Window
{
public:
	static double width,height,thikness;
	double tx,ty,tz,rx,ry,rz;
	double curtainHeight;
	double distanceBetweenGlassAndCurtain;
	int curtainState,curtainTexture;
	double curtain_monvingSpeed;
	double alpha;
	bool right;
	double i;
	Window(void);
	Window(bool right,int);
	void draw();
	void drawCurtain();
	void translate(double x,double y,double z);
	void rotate(double x,double y,double z);
	void closeCurtain();
	void openCurtain();
	void manageMovment();

	virtual ~Window(void);
};

