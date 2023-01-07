#include "MainDoor.h"
#include <windows.h>		// Header File For Windows
#include <gl\gl.h>			// Header File For The OpenGL32 Library
#include <gl\glu.h>			// Header File For The GLu32 Library
#include <glaux.h>		// Header File For The Glaux Library
#include <texture.h>
#include <math.h>
double MainDoor::width=0.6;//0.6
double MainDoor::height=0.7;
double MainDoor::thikness=0.05;
MainDoor::MainDoor(){};
MainDoor::MainDoor(int mainDoorLeft,int mainDoorRight){
		state=0;
		leftDoor=Wall(Dimention(this->thikness,this->width/2.0,this->height),mainDoorLeft,mainDoorRight);
		leftDoor.translate(0,0,-this->width/4.0);
		leftDoor.setTextureCount(1,1);
		rightDoor=Wall(Dimention(this->thikness,this->width/2.0,this->height),mainDoorRight,mainDoorLeft);
		rightDoor.translate(0,0,this->width/4.0);
		rightDoor.setTextureCount(1,1);
		forwordSpeed=0.03;
		LNRSpeed=0.03;
		tx=0;
		ty=0;
		tz=0;
		rx=0;
		ry=0;
		rz=0;
	}
	void MainDoor::draw(){
		glColor3d(state/10.0,1,1);
		manageDoors();
		glPushMatrix();
		//-----------------
		if(tx!=0 || ty!=0 || tz!=0)glTranslated(tx,ty,tz);
		if(rx!=0)glRotated(rx,1,0,0);
		if(ry!=0)glRotated(ry,0,1,0);
		if(rz!=0)glRotated(rz,0,0,1);
		leftDoor.draw();
		rightDoor.draw();
		//----------------
		glPopMatrix();
	}

	void MainDoor::manageDoors(){
	if(this->state!=1 && this->state!=2)return;
	double forwordLimit=thikness+0.01;
	double LNRLimit=width-width/4.0;
	if(this->state==1){
		
		leftDoor.translate(forwordSpeed,0,0);
		rightDoor.translate(forwordSpeed,0,0);
		if(leftDoor.tx>= forwordLimit){
			this->state=2;
			leftDoor.tx=forwordLimit;
			rightDoor.tx=forwordLimit;
		}
		if(leftDoor.tx<=0){
			this->state=0;
			leftDoor.tx=0;
			rightDoor.tx=0;
		}
	}else {
		leftDoor.translate(0,0,-LNRSpeed);
		rightDoor.translate(0,0,LNRSpeed);
		if(rightDoor.tz>=LNRLimit){
			this->state=3;
			leftDoor.tz=-LNRLimit;
			rightDoor.tz=LNRLimit;
		}
		if(rightDoor.tz<=width/4.0){
		    this->state=1;
			leftDoor.tz=-width/4.0;
			rightDoor.tz=width/4.0;
		}
	}

	}
	void MainDoor::manage(){
		leftDoor.translate(forwordSpeed,0,0);
		rightDoor.translate(forwordSpeed,0,0);
	}
	void MainDoor::setState(int t){state=t;}
	void MainDoor::open(){
	if(state!=0)return;
	state=1;
	forwordSpeed=abs(forwordSpeed);
	LNRSpeed=abs(LNRSpeed);
	}
	void MainDoor::close(){
	if(state!=3)return;
	state=2;
	forwordSpeed=-abs(forwordSpeed);
	LNRSpeed=-abs(LNRSpeed);
	}
	void MainDoor::translate(double x,double y,double z){
		tx+=x;
		ty+=y;
		tz+=z;
	}
	void MainDoor::rotate(double x,double y,double z){
		rx+=x;
		ry+=y;
		rz+=z;
	}

MainDoor::~MainDoor(void)
{
}
