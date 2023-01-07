#include "Door.h"
#include <windows.h>		// Header File For Windows
#include <gl\gl.h>			// Header File For The OpenGL32 Library
#include <gl\glu.h>			// Header File For The GLu32 Library
#include <glaux.h>		// Header File For The Glaux Library
#include <texture.h>
#include <math.h>
#include "Wall.h"


Door::Door(void)
{
}
Door::Door(bool PZ,int door,int rdoor){
		status=0;
		angle=0;
		openingSpeed=5;
		this->PZ=PZ;
		this->door=door;
		this->rdoor=rdoor;
		if(!PZ)openingSpeed*=-1;

	}
	void Door::draw(){
		manageMovment();
		glPushMatrix();
		glTranslated(0,0,-(width/2.0));
		glRotatef(angle,0,1,0);
		glTranslated(0,0,(width/2.0));
		if(PZ)glRotated(-180,0,1,0);
		if(PZ){
			if(pzListId<0){
			pzListId= glGenLists(1);
			glNewList(pzListId,GL_COMPILE);
			Wall(Dimention(thikness,width,height),rdoor,door).draw();
			glEndList();
			}
			glCallList(pzListId);
		}else{
			if(nzListId<0){
			nzListId= glGenLists(1);
			glNewList(nzListId,GL_COMPILE);
			Wall(Dimention(thikness,width,height),door,rdoor).draw();
			glEndList();
			}
			glCallList(nzListId);
		}
			
		
		
		glPopMatrix();
	}
	void Door::open(){
		if(status!=0)return;
		openingSpeed*=-1;
		status=1;
	}
	void Door::close(){
		if(status!=2)return;
		openingSpeed*=-1;
		status=1;
	}
	void Door::manageMovment(){
		if(status==1)
		angle+=openingSpeed;
		if(abs(angle)>=90){
			angle=PZ?-90:90;
			status=2;
		}
		if(abs(angle)<=0){
			angle=0;
			status=0;
		}

	}


Door::~Door(void)
{
}
int Door::pzListId=-100000;
int Door::nzListId=-100000;
double Door::width=0.3;
double Door::height=0.6;
double Door::thikness=0.04;
