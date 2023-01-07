#include "SideWall.h"
#include "Window.h"
#include "Dimention.h"
#include "Wall.h"
#include <windows.h>		// Header File For Windows
#include <gl\gl.h>			// Header File For The OpenGL32 Library
#include <gl\glu.h>			// Header File For The GLu32 Library
#include <glaux.h>		// Header File For The Glaux Library
#include <texture.h>

SideWall::SideWall(void)
{
}
SideWall::SideWall(Dimention dims,double LNRgab,int lTexture,int rTexture,int curtainTexture){
		this->dims=dims;
		this->n=5;
		this->lg=LNRgab;
		this->rg=LNRgab;
		this->curtainTexture=curtainTexture;
		this->lTexture=lTexture;
		this->rTexture=rTexture;
		reverse=false;
		tx=0;ty=0;tz=0;rx=0;ry=0;rz=0;	
	}
	void SideWall::setNumOfWindows(int n){this->n=n;}

	void SideWall::justReverse(){ ry=180;}
	void SideWall::initialize(){
		double vl=dims.length-lg-rg;
		double bg=(vl - (n* Window::width))/(n-1.0);
		int inside=reverse?lTexture:rTexture;
		int outside=reverse?rTexture:lTexture;
		int counter=0,wall=0,window=0;
		double startingPoint=(-dims.length/2.0+lg)+(Window::width/2.0);
		double endingPoint=(dims.length/2.0-rg);
		for(double z=startingPoint;z<endingPoint;z+=Window::width/2.0 + bg/2.0, counter+=1){
			if(counter%2==0){
				double wallHeight=(dims.height/2.0)-(Window::height/2.0);
				//window
				windows[window]=Window(!reverse,curtainTexture);
				if(!reverse)windows[window++].translate(dims.width/2.0 - Window::thikness/2.0,0,z);
				else windows[window++].translate(-dims.width/2.0 + Window::thikness/2.0,0,z);
				walls[wall]=Wall(Dimention(dims.width,Window::width,wallHeight),inside,outside);
				walls[wall++].translate(0,Window::height/2.0 + wallHeight/2.0,z);
				walls[wall]=Wall(Dimention(dims.width,Window::width,wallHeight),inside,outside);
				walls[wall++].translate(0,-Window::height/2.0 - wallHeight/2.0,z);
			}else {
				walls[wall]=Wall(Dimention(dims.width,bg,dims.height),inside,outside);
				walls[wall++].translate(0,0,z);
			}
		}
		//left n right gabs
		walls[wall]=Wall(Dimention(dims.width,lg,dims.height),inside,outside);
		walls[wall++].translate(0,0,(-dims.length/2.0)+(lg/2.0));
		walls[wall]=Wall(Dimention(dims.width,rg,dims.height),inside,outside);
		walls[wall++].translate(0,0,(dims.length/2.0)-(rg/2.0));
	}
	void SideWall::draw(){
		glPushMatrix();
		if(tx!=0 || ty!=0 || tz!=0)glTranslated(tx,ty,tz);
		if(rx!=0)glRotated(rx,1,0,0);
		if(ry!=0)glRotated(ry,0,1,0);
		if(rz!=0)glRotated(rz,0,0,1);
		for(int i= 0;i<(n*2)+(n-1)+2;i++)
			walls[i].draw();
		glPopMatrix();
	}
	void SideWall::drawWindows(){
		glPushMatrix();
		if(tx!=0 || ty!=0 || tz!=0)glTranslated(tx,ty,tz);
		if(rx!=0)glRotated(rx,1,0,0);
		if(ry!=0)glRotated(ry,0,1,0);
		if(rz!=0)glRotated(rz,0,0,1);
		for(int i=0;i<n;i++)
		windows[i].draw();
		glPopMatrix();
	}
	void SideWall::drawCurtains(){
		glPushMatrix();
		if(tx!=0 || ty!=0 || tz!=0)glTranslated(tx,ty,tz);
		if(rx!=0)glRotated(rx,1,0,0);
		if(ry!=0)glRotated(ry,0,1,0);
		if(rz!=0)glRotated(rz,0,0,1);
		for(int i=0;i<n;i++)
		windows[i].drawCurtain();
		glPopMatrix();
	}
	void SideWall::openWindows(){		
		for(int i=0;i<n;i++)
		windows[i].openCurtain();
	}
	void SideWall::closeWindows(){
		for(int i=0;i<n;i++)
		windows[i].closeCurtain();
	}
	void SideWall::rotate(double x,double y,double z){
		rx+=x;ry+=y;rz+=z;
	}
	void SideWall::translate(double x,double y, double z){
		tx+=x;ty+=y;tz+=z;	
		/*for(int i=0;i<n;i++)
		windows[i].translate(tx,ty,tz);*/
	}
	


SideWall::~SideWall(void)
{
}
