#include "Chair.h"
#include <windows.h>		// Header File For Windows
#include <gl\gl.h>			// Header File For The OpenGL32 Library
#include <gl\glu.h>			// Header File For The GLu32 Library
#include <glaux.h>		// Header File For The Glaux Library
#include <texture.h>
#include "Wall.h"
#include "ProjectTextures.h"
#include "Point2.h"
#include <math.h>

double Chair::width=0.27;
double Chair::height=0.32;
double Chair::thikness=0.04;
double Chair::curvR=Chair::height/12.0;
int Chair::listId=0;
Chair::Chair(void)
{
}
void Chair::draw(double tx,double ty,double tz,int seatTex,int seatBackTex){
		glPushMatrix();
		if(tx!=0 || ty!=0 || tz!=0)glTranslated(tx,ty,tz);
		glCallList(listId);
		glPopMatrix();
	}

void Chair::drawCurv(){
		double r=curvR;
		double stopAngle=-0.2;
		double clarity=0.4;
		double margin=0.375*width;
		Point2 center(-width/2.0,r,-r);
		glColor3d(0.45, 0.46, 0.45);
		glPushMatrix();
		glTranslated(0,r,-r);
		glBegin(GL_QUAD_STRIP);
		for(double angle=-1.57;angle<=stopAngle;angle+=clarity){
			glVertex3d(center.x+margin,r*sin(angle),r*cos(angle));
			glVertex3d(center.x+width-margin,r*sin(angle),r*cos(angle));
		}
		glEnd();
		r+=thikness;
		glBegin(GL_QUAD_STRIP);
		for(double angle=-1.57;angle<=stopAngle;angle+=clarity){
			glVertex3d(center.x+margin,r*sin(angle),r*cos(angle));
			glVertex3d(center.x+width-margin,r*sin(angle),r*cos(angle));
		}
		glEnd();
		glBegin(GL_QUAD_STRIP);
		for(double angle=-1.57;angle<=stopAngle;angle+=clarity){
			glVertex3d(center.x+margin,r*sin(angle),r*cos(angle));
			glVertex3d(center.x+margin,(r-thikness)*sin(angle),(r-thikness)*cos(angle));
		}
		glEnd();
		glEnd();
		glBegin(GL_QUAD_STRIP);
		for(double angle=-1.57;angle<=stopAngle;angle+=clarity){
			glVertex3d(center.x+width-margin,r*sin(angle),r*cos(angle));
			glVertex3d(center.x+width-margin,(r-thikness)*sin(angle),(r-thikness)*cos(angle));
		}
		glEnd();
		glPopMatrix();
	}
void Chair::initializeList(){
	listId=glGenLists(1);
	glNewList(listId,GL_COMPILE);
	glPushMatrix();
		Wall seat(Dimention(width,width,thikness),ProjectTextures::seatTex,ProjectTextures::seatTex);
		seat.isChair=true;
		seat.translate(0,-thikness/2.0,-width/2.0-curvR);
		seat.setCustomTexture(ProjectTextures::seatTex);
		seat.draw();
		//draw curv
		drawCurv();
		//
		Wall seatBack(Dimention(width,thikness,height-curvR),ProjectTextures::seatBackTex,ProjectTextures::seatBackTex);
		seatBack.isChair=true;
		seatBack.translate(0,curvR+(height-curvR)/2.0 - thikness*0.6,thikness*1.5);
		seatBack.setCustomTexture(ProjectTextures::seatBackTex);
		seatBack.rotate(9,0,0);
		seatBack.draw();
	glPopMatrix();
	glEndList();
}
Chair::~Chair(void)
{
}
