#include "Wall.h"
#include "Dimention.h"
#include <windows.h>		// Header File For Windows
#include <gl\gl.h>			// Header File For The OpenGL32 Library
#include <gl\glu.h>			// Header File For The GLu32 Library
#include <glaux.h>		// Header File For The Glaux Library
#include "ProjectTextures.h"


Wall::Wall(void)
{
}

Wall::Wall(Dimention dims,int lTexture,int rTexture){
	this->custom=-232;
	this->dims=dims;
	this->rTexture=rTexture;
	this->lTexture=lTexture;
	this->texV=(int)(this->dims.height)/2;
	this->texH=(int)(this->dims.width)/2;
	this->isWindow=false;
	this->isChair=false;
	if(texV==0)texV=1;
	if(texH==0)texH=1;
	tx=0;ty=0;tz=0;rx=0;ry=0;rz=0;	
}
void Wall::setTextureCount(int vertical,int horizontal){
	this->texH=horizontal;
	this->texV=vertical;
}
void Wall::translate(double x,double y,double z){
	tx+=x;
	ty+=y;
	tz+=z;
}
void Wall::rotate(double x,double y,double z){
	rx+=x;
	ry+=y;
	rz+=z;
}
void Wall::setCustomTexture(int toto){custom=toto;}
void Wall::draw(){
	if(isChair)glDisable(GL_LIGHT2);

	double hw=this->dims.width/2.0,hl=this->dims.length/2.0,hh=this->dims.height/2.0;
	if(!isWindow){
		glColor3d(1,1,1);
		glEnable(GL_CULL_FACE);
	}
	glPushMatrix();
	if(tx!=0 || ty!=0 || tz!=0)glTranslated(tx,ty,tz);
	if(rx!=0)glRotated(rx,1,0,0);
	if(ry!=0)glRotated(ry,0,1,0);
	if(rz!=0)glRotated(rz,0,0,1);
	//front face
	glCullFace(GL_BACK);
	glBindTexture(GL_TEXTURE_2D,custom<0?ProjectTextures::out:custom);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3d(-hw,-hh,hl);
	glTexCoord2d(texH,0);
	glVertex3d(hw,-hh,hl);
	glTexCoord2d(texH,texV);
    glVertex3d(hw,hh,hl);
	glTexCoord2d(0,texV);
	glVertex3d(-hw,hh,hl);
	glEnd();
	//back face
	glCullFace(GL_FRONT);
	glBindTexture(GL_TEXTURE_2D,custom<0?ProjectTextures::out:custom);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3d(-hw,-hh,-hl);
	glTexCoord2d(texH,0);
	glVertex3d(hw,-hh,-hl);
	glTexCoord2d(texH,texV);
    glVertex3d(hw,hh,-hl);
	glTexCoord2d(0,texV);
	glVertex3d(-hw,hh,-hl);
	glEnd();
	glCullFace(GL_BACK);

	//left face
	if(!isChair) glDisable(GL_LIGHT2);
	glBindTexture(GL_TEXTURE_2D,lTexture);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3d(-hw,-hh,-hl);
	glTexCoord2d(texH,0);
	glVertex3d(-hw,-hh,hl);
	glTexCoord2d(texH,texV);
    glVertex3d(-hw,hh,hl);
	glTexCoord2d(0,texV);
	glVertex3d(-hw,hh,-hl);
	glEnd();
	if(!isChair)glEnable(GL_LIGHT2);

	//right face
	
	glBindTexture(GL_TEXTURE_2D,rTexture);
	glBegin(GL_QUADS);
	glNormal3d(0,1,0);
	glTexCoord2d(0,0);
	glVertex3d(hw,-hh,hl);
	glTexCoord2d(texH,0);
	glVertex3d(hw,-hh,-hl);
	glTexCoord2d(texH,texV);
    glVertex3d(hw,hh,-hl);
	glTexCoord2d(0,texV);
	glVertex3d(hw,hh,hl);
	glEnd();		

	//
	glBindTexture(GL_TEXTURE_2D,custom<0?ProjectTextures::out:custom);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3d(-hw,hh,hl);
	glTexCoord2d(texH,0);
	glVertex3d(hw,hh,hl);
	glTexCoord2d(texH,texV);
	glVertex3d(hw,hh,-hl);
	glTexCoord2d(0,texV);
	glVertex3d(-hw,hh,-hl);
	glEnd();
	//

	glCullFace(GL_FRONT);
	glBindTexture(GL_TEXTURE_2D,custom<0?ProjectTextures::out:custom);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3d(-hw,-hh,hl);
	glTexCoord2d(texH,0);
	glVertex3d(hw,-hh,hl);
	glTexCoord2d(texH,texV);
	glVertex3d(hw,-hh,-hl);
	glTexCoord2d(0,texV);
	glVertex3d(-hw,-hh,-hl);
	glEnd();
	glFlush();
	glPopMatrix();
	if(!isWindow){
		glDisable(GL_CULL_FACE);
	}
	if(isChair)glEnable(GL_LIGHT2);
	}
void Wall::drawWall(double width,double length,double height,int lTexture,int rTexture,int custom,bool glass,int out,int wood){
	double hw=width/2.0,hl=length/2.0,hh=height/2.0;
	int texV=(int)(height);
	int texH=(int)(width);
	if(!glass)glColor3d(1,1,1);
	//front face
	glBindTexture(GL_TEXTURE_2D,custom<0?out:custom);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3d(-hw,-hh,hl);
	glTexCoord2d(texH,0);
	glVertex3d(hw,-hh,hl);
	glTexCoord2d(texH,texV);
    glVertex3d(hw,hh,hl);
	glTexCoord2d(0,texV);
	glVertex3d(-hw,hh,hl);
	glEnd();
	//back face
	glBindTexture(GL_TEXTURE_2D,custom<0?out:custom);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3d(-hw,-hh,-hl);
	glTexCoord2d(texH,0);
	glVertex3d(hw,-hh,-hl);
	glTexCoord2d(texH,texV);
    glVertex3d(hw,hh,-hl);
	glTexCoord2d(0,texV);
	glVertex3d(-hw,hh,-hl);
	glEnd();
	//left face
	glBindTexture(GL_TEXTURE_2D,lTexture);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3d(-hw,-hh,-hl);
	glTexCoord2d(texH,0);
	glVertex3d(-hw,-hh,hl);
	glTexCoord2d(texH,texV);
    glVertex3d(-hw,hh,hl);
	glTexCoord2d(0,texV);
	glVertex3d(-hw,hh,-hl);
	glEnd();
	//right face
	glBindTexture(GL_TEXTURE_2D,rTexture);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3d(hw,-hh,hl);
	glTexCoord2d(texH,0);
	glVertex3d(hw,-hh,-hl);
	glTexCoord2d(texH,texV);
    glVertex3d(hw,hh,-hl);
	glTexCoord2d(0,texV);
	glVertex3d(hw,hh,hl);
	glEnd();		
	//
	glBindTexture(GL_TEXTURE_2D,custom<0?out:custom);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3d(-hw,hh,hl);
	glTexCoord2d(texH,0);
	glVertex3d(hw,hh,hl);
	glTexCoord2d(texH,texV);
	glVertex3d(hw,hh,-hl);
	glTexCoord2d(0,texV);
	glVertex3d(-hw,hh,-hl);
	glEnd();
	//
	glBindTexture(GL_TEXTURE_2D,custom<0?out:custom);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3d(-hw,-hh,hl);
	glTexCoord2d(texH,0);
	glVertex3d(hw,-hh,hl);
	glTexCoord2d(texH,texV);
	glVertex3d(hw,-hh,-hl);
	glTexCoord2d(0,texV);
	glVertex3d(-hw,-hh,-hl);
	glEnd();
	glFlush();
		
}

Wall::~Wall(void)
{
}
