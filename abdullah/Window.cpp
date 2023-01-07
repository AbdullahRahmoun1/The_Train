#include "Window.h"
#include "Wall.h"
#include <windows.h>		// Header File For Windows
#include <gl\gl.h>			// Header File For The OpenGL32 Library
#include <gl\glu.h>			// Header File For The GLu32 Library
#include <glaux.h>		// Header File For The Glaux Library
#include <texture.h>
#include <math.h>
#include "TrainCar.h"

double Window::width=0.47;
double Window::height=0.3;
double Window::thikness=0.03;

Window::Window(void)
{
}
Window::Window(bool right,int curtainTexture){

		this->right=right;
		this->curtainTexture=curtainTexture;
		distanceBetweenGlassAndCurtain=0.05;
		curtainHeight=0.1;
		curtainState=2;
		curtain_monvingSpeed=0.1;
		alpha=0.3;
		tx=0;
		ty=0;
		tz=0;
		rx=0;
		ry=0;
		rz=0;
	}
	void Window::draw(){
		glPushMatrix();
		if(tx!=0 || ty!=0 || tz!=0)glTranslated(tx,ty,tz);
		if(rx!=0)glRotated(rx,1,0,0);
		if(ry!=0)glRotated(ry,0,1,0);
		if(rz!=0)glRotated(rz,0,0,1);
		//curtain
		glPushMatrix();
		glColor4d(1,1,1,1);
		glTranslated(right?-distanceBetweenGlassAndCurtain:distanceBetweenGlassAndCurtain,(height/2.0)-(curtainHeight*height/2.0),0);
		Wall(Dimention(0.01,width,curtainHeight*height),curtainTexture,curtainTexture).draw();
		glPopMatrix();
		//glass
		glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	    glEnable(GL_BLEND);
		glColor4d(1,1,1,alpha);	
		Wall wall=Wall(Dimention(thikness,width,height),33,33);
		wall.isWindow=true;
		wall.draw();
		glDisable(GL_BLEND);
		glPopMatrix();
	}
	void Window::drawCurtain(){
		manageMovment();
		glPushMatrix();
		if(tx!=0 || ty!=0 || tz!=0)glTranslated(tx,ty,tz);
		if(rx!=0)glRotated(rx,1,0,0);
		if(ry!=0)glRotated(ry,0,1,0);
		if(rz!=0)glRotated(rz,0,0,1);
		glPushMatrix();
		glColor4d(1,1,1,1);
		glTranslated(right?-distanceBetweenGlassAndCurtain:distanceBetweenGlassAndCurtain,(height/2.0)-(curtainHeight*height/2.0),0);
		Wall(Dimention(0.01,width,curtainHeight*height),curtainTexture,curtainTexture).draw();
		glPopMatrix();
		
		glPopMatrix();
	}
	void Window::translate(double x,double y,double z){
		tx+=x;
		ty+=y;
		tz+=z;
	}
	void Window::rotate(double x,double y,double z){
		rx+=x;
		ry+=y;
		rz+=z;
	}
	void Window::closeCurtain(){
		if(curtainState!=2)return;
		curtain_monvingSpeed=abs(curtain_monvingSpeed);
		curtainState=1;
	}
	void Window::openCurtain(){
		if(curtainState!=0)return;
		curtain_monvingSpeed=-abs(curtain_monvingSpeed);
		curtainState=1;
	}
	void Window::manageMovment(){
		if(curtainState!=1)return;
		curtainHeight+=curtain_monvingSpeed;
		if(curtainHeight>=1){
			curtainState=0;
			curtainHeight=1;
		}
		if(curtainHeight<=0.1){
			curtainState=2;
			curtainHeight=0.1;
		}
	}


Window::~Window(void)
{
}
