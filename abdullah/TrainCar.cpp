#include "TrainCar.h"
#include <windows.h>		// Header File For Windows
#include <gl\gl.h>			// Header File For The OpenGL32 Library
#include <gl\glu.h>			// Header File For The GLu32 Library
#include <glaux.h>		// Header File For The Glaux Library
#include <texture.h>
#include <iostream>
#include <math.h>
#include "Point2.h"
#include "Dimention.h"
#include "Wall.h"
#include "Door.h"
#include "Window.h"
#include "SideWall.h"
#include "MainDoor.h"
#include "Chair.h"
#include "ProjectTextures.h"
#include "UltimateCamera.h"
#pragma comment(lib, "Winmm.lib" )

double TrainCar::scale=4;
double TrainCar::width = 1.5;
double TrainCar::length = 5.0;
double TrainCar::height = 1.0;
double TrainCar::scaledWidth=width*scale;
double TrainCar::scaledHeight=height*scale;
double TrainCar::scaledLength=length*scale;
double TrainCar::wallThikness=0.1;
double TrainCar::scaledWallThikness=wallThikness*scale;
double TrainCar::cLength=length*0.33;
double TrainCar::enginsWidth=(width+2*wallThikness)*0.93;
double TrainCar::enginsThikness=height*0.2;
int TrainCar::wheelsListId=0;
int TrainCar::CarListId=-10000;
int TrainCar::roofListId=-10000;
int TrainCar::wallWithDoorId=-10000;
int TrainCar::hasDoorId=-10000;
int TrainCar::noDoorId=-10000;
int TrainCar::lastNoDoorId=-10000;
int TrainCar::lastWithDoorId=-10000;
// this is for you omran 
double TrainCar::heightTranslation=0.9;
TrainCar::TrainCar()
{
	
}
TrainCar::TrainCar(bool hasMainDoor,bool hasConnecter,double collisionDistance){
		this->horizontalBox=collisionDistance;
		this->hasMainDoor=hasMainDoor;
		this->hasConnecter=hasConnecter;
		tx=0;ty=0.85+scaledHeight/2.0+enginsThikness*scale;tz=0;
		visible=true;
		hasLight=false;
		frontDoorLocked=false;
		roofR=0.1;
		wheelsAngle=0;
		frontDoor=Door(true,ProjectTextures::door,ProjectTextures::rdoor);
		backDoor=Door(false,ProjectTextures::door,ProjectTextures::rdoor);
		double sidesGab=length*0.1;
		double fragmentSideGab=length*0.1;
		
		//
		double fragmentWidth=(length-MainDoor::width)/2.0;
		lRightSideWall=SideWall(Dimention(wallThikness,hasMainDoor?fragmentWidth:length,height),hasMainDoor?											  
		fragmentSideGab:sidesGab,ProjectTextures::out,ProjectTextures::wood,ProjectTextures::curtainTexture);
		lRightSideWall.setNumOfWindows(hasMainDoor?2:5);
		if(hasMainDoor)lRightSideWall.rg=fragmentSideGab*0.75;
		lRightSideWall.initialize();
		if(hasMainDoor){
			lRightSideWall.translate((wallThikness/2.0)+(width/2.0),0,-length/2.0+ fragmentWidth/2.0);
		}
		else lRightSideWall.translate(width/2.0+wallThikness/2.0,0,0);
		
		
		//
		rRightSideWall=SideWall(Dimention(wallThikness,fragmentWidth,height),fragmentSideGab,ProjectTextures::out,ProjectTextures::wood,ProjectTextures::curtainTexture);
		rRightSideWall.setNumOfWindows(2);
		rRightSideWall.lg=fragmentSideGab*0.75;
		rRightSideWall.initialize();
		rRightSideWall.translate((wallThikness/2.0)+(width/2.0),0,length/2.0 - fragmentWidth/2.0);
		//
		mainDoor= MainDoor(ProjectTextures::mainDoorLeft,ProjectTextures::mainDoorRight);
		mainDoor.translate(width/2.0 + MainDoor::thikness/2.0,-height/2.0 + MainDoor::height/2.0,0);
		//
		double soso=height-MainDoor::height;
		aboveDoor=Wall(Dimention(wallThikness,MainDoor::width,soso),ProjectTextures::wood,ProjectTextures::out);
		aboveDoor.translate(width/2.0 + wallThikness/2.0,height/2.0 -soso/2.0,0);

		leftSideWall=SideWall(Dimention(wallThikness,length,height),sidesGab,ProjectTextures::out,ProjectTextures::wood,ProjectTextures::curtainTexture);
		leftSideWall.justReverse();
		leftSideWall.initialize();
		leftSideWall.translate(-(wallThikness/2.0)-(width/2.0),0,0);
		//
		ground=Wall(Dimention(wallThikness,length+wallThikness*2,width+wallThikness*2),ProjectTextures::groundTex,ProjectTextures::groundTex);
		ground.setTextureCount(10,1);
		ground.translate(0,(-height/2)-(+wallThikness/2.3),0);
		ground.rotate(0,0,-90);
		//		
		engins=Wall(Dimention(enginsThikness,length+wallThikness*2+(hasConnecter?cLength:0),enginsWidth),ProjectTextures::enginsTex,ProjectTextures::enginsTex);
		engins.translate(0,-height/2.0-wallThikness-(enginsThikness/2.0)-0.001,hasConnecter?-cLength/2.0:0);
		engins.rotate(0,0,90);
		engins.setCustomTexture(ProjectTextures::enginsTex);
		engins.setTextureCount(1,3);
		//
		carpet=Wall(Dimention(wallThikness/7.5,length,Door::width),ProjectTextures::carpetTex,ProjectTextures::carpetTex);
		carpet.isChair=true;
		carpet.setTextureCount(2,5);
		carpet.translate(0,-height/2.0+wallThikness/7,0);
		carpet.rotate(0,0,-90);
		//
		



}
//---------------------------------------------------
void TrainCar::interactLight() {
  if (inRange())hasLight = !hasLight;
}
bool TrainCar::inRange() {
  double cx = UltimateCamera::walkX, cz = UltimateCamera::walkZ;
  return   cx <= tx + scaledWidth / 2.0
    &&  cx >= tx - scaledWidth / 2.0
    && cz <= tz + scaledLength / 2.0
    && cz >= tz - scaledLength / 2.0;
}
void TrainCar:: draw(){

	if(!visible)return;
	glPushMatrix();
	glTranslated(tx,ty,tz);
	glScaled(scale,scale,scale);
	if(CarListId<0){
		CarListId=glGenLists(1);
		glNewList(CarListId,GL_COMPILE);
		leftSideWall.draw();
		engins.draw();
		ground.draw();
		carpet.draw();
		glEndList();
	}
	glCallList(CarListId);

	//already has a list
	WallWithDoor(true);//front
	WallWithDoor(false);//back
	drawWheels();
	/*if(hasMainDoor)mainDoor.draw();*/
	drawRoof();
	//
	//wont have list for now 
	drawConnecter();
	//

	//special case of list 
	if(hasMainDoor){
		if(hasDoorId<0){
			hasDoorId=glGenLists(1);
			glNewList(hasDoorId,GL_COMPILE);
			lRightSideWall.draw();
			rRightSideWall.draw();
			aboveDoor.draw();
			mainDoor.draw();
			glEndList();
		}
		glCallList(hasDoorId);
	}else{
		if(noDoorId<0){
			noDoorId=glGenLists(1);
			glNewList(noDoorId,GL_COMPILE);
			lRightSideWall.draw();
			glEndList();
		}
		glCallList(noDoorId);
	}
	glPopMatrix();
	//
}
void TrainCar:: drawLast(){
	glPushMatrix();
	glTranslated(tx,ty,tz);
	glScaled(scale,scale,scale);
	leftSideWall.drawCurtains();
	lRightSideWall.drawCurtains();
	if(hasMainDoor){
		rRightSideWall.drawCurtains();
		if(lastWithDoorId<0){
			lastWithDoorId=glGenLists(1);
			glNewList(lastWithDoorId,GL_COMPILE);
			lRightSideWall.drawWindows();
			rRightSideWall.drawWindows();
			leftSideWall.drawWindows();
			glEnable(GL_BLEND);
			glColor4d(0,0,0,0.5);
			lConnecterGlass.draw();
			rConnecterGlass.draw();
			glDisable(GL_BLEND);
			glEndList();
		}
		glCallList(lastWithDoorId);
	}else{
		if(lastNoDoorId<0){
			lastNoDoorId=glGenLists(1);
			glNewList(lastNoDoorId,GL_COMPILE);
			lRightSideWall.drawWindows();
			leftSideWall.drawWindows();
			glEnable(GL_BLEND);
			glColor4d(0,0,0,0.5);
			lConnecterGlass.draw();
			rConnecterGlass.draw();
			glDisable(GL_BLEND);
			glEndList();
		}
		glCallList(lastNoDoorId);
	}	
	glPopMatrix();
}
void TrainCar:: initializeLists(){
	//wheels 
	wheelsListId=glGenLists(1);
	glNewList(wheelsListId,GL_COMPILE);
	WheelsBuild((enginsThikness)*0.8,0.05,0.05,enginsWidth+0.04,0.01);
	glEndList();
}
double TrainCar::getGoodLength(){
	return scaledLength+2*scaledWallThikness+(hasConnecter?cLength*scale:0);
}
void TrainCar::translate(double x,double y,double z){
	tx+=x;
	ty+=y;
	tz+=z;
}
void TrainCar::openFrontDoor(){
	if(canInteract(0,tz+scaledLength/2.0+scaledWallThikness/2.0,4) && !frontDoorLocked)
	{
		PlaySound(TEXT("Sounds/Door-open.wav"), NULL, SND_ASYNC);
		frontDoor.open();
		PlaySound(TEXT("sounds/Train-middle.wav"), NULL, SND_ASYNC | SND_LOOP);

	}
}
void TrainCar:: closeFrontDoor(){
	if(canInteract(0,tz+scaledLength/2.0+scaledWallThikness/2.0,4))
	{
		PlaySound(TEXT("Sounds/Door-close.wav"), NULL, SND_ASYNC);
		frontDoor.close();
			PlaySound(TEXT("sounds/Train-middle.wav"), NULL, SND_ASYNC | SND_LOOP);

	}

}
void TrainCar:: openBackDoor(){
	if(canInteract(0,tz-scaledLength/2.0-scaledWallThikness/2.0,4))
	{
		PlaySound(TEXT("Sounds/Door-open.wav"), NULL, SND_ASYNC);

		backDoor.open();
		PlaySound(TEXT("sounds/Train-middle.wav"), NULL, SND_ASYNC | SND_LOOP);

	}
}
void TrainCar:: closeBackDoor(){
	if(canInteract(0,tz-scaledLength/2.0-scaledWallThikness/2.0,4))
	{
		PlaySound(TEXT("Sounds/Door-close.wav"), NULL, SND_ASYNC);
		backDoor.close();
				PlaySound(TEXT("sounds/Train-middle.wav"), NULL, SND_ASYNC | SND_LOOP);

	}
}
void TrainCar:: closeDoors(){
	closeFrontDoor();
	closeBackDoor();
	mainDoor.close();
}
void TrainCar:: openDoors(){
	openFrontDoor();
	openBackDoor();
	mainDoor.open();
}
void TrainCar:: closeWindows(){
	leftSideWall.closeWindows();
	rRightSideWall.closeWindows();
	lRightSideWall.closeWindows();
}
void TrainCar:: openWindows(){
	leftSideWall.openWindows();
	rRightSideWall.openWindows();
	lRightSideWall.openWindows();
}
void TrainCar:: interactDoors(){
	if(frontDoor.status==0){
		openFrontDoor();
	}
	if(frontDoor.status==2){
		closeFrontDoor();
	}
	if(backDoor.status==0){
		openBackDoor();
	}
	if(backDoor.status==2){
		closeBackDoor();
	}
}
void TrainCar::interactWindows(){
	double cx=UltimateCamera::walkX ,cz=UltimateCamera::walkZ;
	if( inRange()){
			if(leftSideWall.windows[0].curtainState==0){
				openWindows();
			}
			if(leftSideWall.windows[0].curtainState==2){
				closeWindows();
			}
	}
}
//private 
void TrainCar::WallWithDoor(bool front=true){
double alength=width+(wallThikness*2);
double subWallWidth=(width-(Door::width)+wallThikness*2)/2.0;
int inside=ProjectTextures::out,outside=ProjectTextures::wood;
glPushMatrix();
if(front)glTranslated(0,0,(length/2.0)+(wallThikness/2.0));
else {
	glTranslated(0,0,-(length/2.0)-(wallThikness/2.0));
	inside=ProjectTextures::out;
	outside=ProjectTextures::wood;
}
glRotatef(90,0,1,0);

//door
glPushMatrix();
glTranslated(0,-((height/2.0)-(Door::height/2.0)),0);
if(front)frontDoor.draw();
else backDoor.draw();
glPopMatrix();
glPushMatrix();
if(front)glRotatef(180,0,1,0);
	if(wallWithDoorId<0){
		wallWithDoorId=glGenLists(1);
		glNewList(wallWithDoorId,GL_COMPILE);
		// up door subWall
		double subWallHeight=height-Door::height;
		glPushMatrix();
		glTranslated(0,(height/2.0)-(subWallHeight/2.0) ,0);
		Wall(Dimention(wallThikness,Door::width,subWallHeight),outside,inside).draw();
		if(front)
		glPopMatrix();
		//left subWall
		glPushMatrix();    
		glTranslated(0,0,-((alength/2.0) - (subWallWidth/2.0)));
		Wall(Dimention(wallThikness,subWallWidth,height),outside,inside).draw();
		glPopMatrix();
		//right subWall
		glPushMatrix();    
		glTranslated(0,0,((alength/2.0) - (subWallWidth/2.0)));
		Wall(Dimention(wallThikness,subWallWidth,height),outside,inside).draw();
		glPopMatrix();
		glEndList();
	}else 
		glCallList(wallWithDoorId);
glPopMatrix();

glPopMatrix();
	
}
void TrainCar::  drawRoofSide(bool left){
	if(hasLight)glDisable(GL_LIGHT1);
	double r=0.1;
	glColor3d(0.45, 0.46, 0.45);
	//draw first layer
	glBegin(GL_QUAD_STRIP);
	double ll=length/2.0+wallThikness;
	double clarity=0.3;
	for(double angle=0;angle<=1.58;angle+=clarity){
		glVertex3d((left?1:-1)*r*cos(angle),r*sin(angle),ll);
		glVertex3d((left?1:-1)*r*cos(angle),r*sin(angle),-ll);
	}
	glVertex3d((left?1:-1)*r*cos(1.58),r*sin(1.58),ll);
	glVertex3d((left?1:-1)*r*cos(1.58),r*sin(1.58),-ll);
	glEnd();
	//drawSecondLayer
	r+=wallThikness;
	glBegin(GL_QUAD_STRIP);
	for(double angle=0;angle<=1.58;angle+=clarity){
		glVertex3d((left?1:-1)*r*cos(angle),r*sin(angle),ll);
		glVertex3d((left?1:-1)*r*cos(angle),r*sin(angle),-ll);
	}
	glVertex3d((left?1:-1)*r*cos(1.58),r*sin(1.58),ll);
	glVertex3d((left?1:-1)*r*cos(1.58),r*sin(1.58),-ll);
	glEnd();
	//draw first cap
	glBegin(GL_TRIANGLE_FAN);
	glVertex3d(0,0,ll);
	for(double angle=0;angle<=1.58;angle+=clarity){
		glVertex3d((left?1:-1)*r*cos(angle),r*sin(angle),ll);
	}
	glVertex3d((left?1:-1)*r*cos(1.58),r*sin(1.58),ll);
	glEnd();
	//draw second cap
	glBegin(GL_TRIANGLE_FAN);
	glVertex3d(0,0,-ll);
	for(double angle=0;angle<=1.58;angle+=clarity){
		glVertex3d((left?1:-1)*r*cos(angle),r*sin(angle),-ll);
	}
	glVertex3d((left?1:-1)*r*cos(1.58),r*sin(1.58),-ll);
	glEnd();
	if(hasLight)glEnable(GL_LIGHT1);

}
void TrainCar::  drawRoof(){
	if(roofListId>=0){
		glCallList(roofListId);
		return;
	}
	roofListId=glGenLists(1);
	glNewList(roofListId,GL_COMPILE);
	double roofThikness=wallThikness/2.0;
	glPushMatrix();
	glTranslated(0,height/2,0);
	//right side
	glPushMatrix();
	glTranslated(width/2.0 -roofR,0,0);
	drawRoofSide(true);
	glPopMatrix();
	//left side
	glPushMatrix();
	glTranslated(-width/2.0 +roofR,0,0);
	drawRoofSide(false);
	glPopMatrix();
	//wall
	glPushMatrix();
	glTranslated(0,roofR+wallThikness/2.0,0);
	glRotated(90,0,0,1);
	Wall(Dimention(wallThikness,length+2*wallThikness,width - 2*roofR),ProjectTextures::out,ProjectTextures::out).draw();
	glPopMatrix();
	//fron wall
	glPushMatrix();
	glTranslated(0,roofR/2.0,+length/2.0+wallThikness/2.0);
	glRotated(-90,0,1,0);
	Wall(Dimention(wallThikness,width - 2*roofR,roofR),ProjectTextures::out,ProjectTextures::out).draw();
	glPopMatrix();
	//back wall
	glPushMatrix();
	glTranslated(0,roofR/2.0,-length/2.0-wallThikness/2.0);
	glRotated(90,0,1,0);
	Wall(Dimention(wallThikness,width - 2*roofR,roofR),ProjectTextures::out,ProjectTextures::out).draw();
	glPopMatrix();

	glPopMatrix();
	glEndList();
}
void TrainCar::  drawConnecter(){
		
	//floor 
	Wall connecter(Dimention(wallThikness,cLength,width+2*wallThikness),ProjectTextures::wood,ProjectTextures::connecterGroundTex);
	connecter.translate(0,-height/2.0 - wallThikness/2.0,-length/2.0 - wallThikness - cLength/2.0);
	connecter.rotate(0,0,90);
	connecter.setTextureCount(2,2);
	connecter.draw();
	//
	double handrailHeight=height*0.34;
	double handrailThikness=0.02;
	double barHeight=height*0.02;
	//left handrail
	Wall dHandrail(Dimention(handrailThikness,cLength,barHeight),ProjectTextures::wood,ProjectTextures::wood);
	dHandrail.translate((-width-wallThikness)/2.0,-height/2.0 +barHeight/2.0,-length/2.0 - wallThikness - cLength/2.0);
	dHandrail.draw();

	Wall uHandrail(Dimention(handrailThikness,cLength,barHeight),ProjectTextures::wood,ProjectTextures::wood);
	uHandrail.translate((-width-wallThikness)/2.0,-height/2.0 +barHeight/2.0 + handrailHeight,-length/2.0 - wallThikness - cLength/2.0);
	uHandrail.draw();

	lConnecterGlass=Wall(Dimention(handrailThikness,cLength,handrailHeight-barHeight),234,234);
	lConnecterGlass.translate((-width-wallThikness)/2.0,-height/2.0 +barHeight + (handrailHeight-barHeight)/2.0,-length/2.0 - wallThikness - cLength/2.0);
	lConnecterGlass.isWindow=true;

	dHandrail=Wall(Dimention(handrailThikness,cLength,barHeight),ProjectTextures::wood,ProjectTextures::wood);
	dHandrail.translate((width+wallThikness)/2.0,-height/2.0 +barHeight/2.0,-length/2.0 - wallThikness - cLength/2.0);
	dHandrail.draw();

	uHandrail=Wall(Dimention(handrailThikness,cLength,barHeight),ProjectTextures::wood,ProjectTextures::wood);
	uHandrail.translate((width+wallThikness)/2.0,-height/2.0 +barHeight/2.0 + handrailHeight,-length/2.0 - wallThikness - cLength/2.0);
	uHandrail.draw();

	rConnecterGlass=Wall(Dimention(handrailThikness,cLength,handrailHeight-barHeight),234,234);
	rConnecterGlass.translate((width+wallThikness)/2.0,-height/2.0 +barHeight + (handrailHeight-barHeight)/2.0,-length/2.0 - wallThikness - cLength/2.0);
	rConnecterGlass.isWindow=true;
		 
}
void TrainCar::  drawWheels(){
	wheelsAngle+=10;
	double distance=1.0;
	for(double i=length/2.0-distance/2.0;i>-length/2.0-cLength+distance*0.7;i-=distance){
		drawWheel(i);
	}
}
void TrainCar::  drawWheel(double z){
	glPushMatrix();
		glTranslated(0.075,engins.ty-0.05,z);
		glRotated(wheelsAngle,1,0,0);
		glRotated(90,0,1,0);
		glTranslated(0,0,(width)/2.0+0.05/2.0);
		glCallList(wheelsListId);
	glPopMatrix();
}
void TrainCar::  WheelsBuild(double WheelRadius,double WheelThikness,double WheelDepth,double CylinderLength,double CylinderRadius){
		glPushMatrix();
			WheelBuild(WheelRadius,WheelThikness,WheelDepth);
			glTranslated(0,0,-WheelDepth/2);
			glTranslated(0,0,-CylinderLength);
			WheelBuild(WheelRadius,WheelThikness,WheelDepth);
		glPopMatrix();
	}
void TrainCar::  WheelBuild(double radius,double thikness,double depth)
	{
		glColor3d(0,0,0);
		glBegin(GL_QUAD_STRIP);
		for(double a=0;a<=7;a+=0.5)
		{
			glVertex3d(radius*cos(a),radius*sin(a),0);
			glVertex3d(radius*cos(a),radius*sin(a),-depth);
		}
		glEnd();
		glBegin(GL_QUAD_STRIP);
		for(double a=0;a<=7;a+=0.5)
		{
			glVertex3d((radius-thikness)*cos(a),(radius-thikness)*sin(a),0);
			glVertex3d((radius-thikness)*cos(a),(radius-thikness)*sin(a),-depth);

		}
		glEnd();
		glBegin(GL_QUAD_STRIP);
		for(double a=0;a<=7;a+=0.5)
		{
			glVertex3d((radius-thikness)*cos(a),(radius-thikness)*sin(a),0);
			glVertex3d((radius)*cos(a),(radius)*sin(a),0);

		}
		glEnd();
		glBegin(GL_QUAD_STRIP);
		for(double a=0;a<=7;a+=0.5)
		{
			glVertex3d((radius-thikness)*cos(a),(radius-thikness)*sin(a),-depth);
			glVertex3d((radius)*cos(a),(radius)*sin(a),-depth);

		}
		glEnd();
		glColor3d(0.5,0.5,0.5);
		glBegin(GL_TRIANGLE_FAN);
		glVertex3d(0,0,0);
		for(double a=0;a<=6.8;a+=0.4)
		{
			glVertex3d((radius-thikness)*cos(a),(radius-thikness)*sin(a),-depth/2);
		}
		glEnd();
		glColor3d(1,1,1);

	}
void TrainCar::  CylinderBuild(double length,double radius)
	{
		glColor3d(0.2,0.2,0.2);
		glBegin(GL_QUAD_STRIP);
		for(double a=0;a<=6.4;a+=0.2)
		{
			glVertex3d(radius*cos(a),radius*sin(a),0);
			glVertex3d(radius*cos(a),radius*sin(a),-length);

		}
		glEnd();
		glColor3d(1,1,1);

	}
//protectd
void TrainCar::  drawDecore(){
}
void TrainCar::  initializeDecore(){
}
bool TrainCar::canCameraGoTo(double x,double y,double z){
	//here will be the code to manage collisions with the car (walls,doors)
	bool collision=false;
	double halfWidth=scaledWidth/2.0
		, halfLength=scaledLength/2.0
		, halfDoorThikness=Door::thikness*scale/2.0
		, halfDoorWidth=Door::width*scale/2.0
		, mainDoorWidth=MainDoor::width*scale;
		;
	double box=0.5;
	//front wall
	if(!collision){
		//front wall with door if closed
		collision|=(z>tz+halfLength-box && z<tz+halfLength+scaledWallThikness+box)&&
			( (x<tx-halfDoorWidth +halfDoorThikness*2 && x>tx-halfWidth )
			|| (x>tx+halfDoorWidth && x<tx+halfWidth )
			||(frontDoor.status==0 && x>tx-halfDoorWidth && x<tx+halfDoorWidth)
			);
		//front door when open
		if(!collision && frontDoor.status==2){
			collision|=(x>tx-halfDoorWidth -halfDoorThikness-box && x<tx-halfDoorWidth+halfDoorThikness +0.15) 
			&& (z>tz+halfLength && z<tz+halfLength + Door::width*scale +0.3);
		}
	}
	//back wall
	if(!collision){
		//back wall with door if closed
		collision|=(z<tz-halfLength+box && z>tz-halfLength-scaledWallThikness-box)&&
			( (x<tx-halfDoorWidth +halfDoorThikness*2 && x>tx-halfWidth )
			|| (x>tx+halfDoorWidth && x<tx+halfWidth )
			||(backDoor.status==0 && x>tx-halfDoorWidth && x<tx+halfDoorWidth)
			);
		//back door when open
		if(!collision && backDoor.status==2){
			collision|=(x>tx-halfDoorWidth -halfDoorThikness-box && x<tx-halfDoorWidth+halfDoorThikness +0.15) 
			&& (z<tz-halfLength && z>tz-halfLength - Door::width*scale -0.3);
		}
	}
	//left wall
	if(!collision){
		collision|=(x<tx-halfWidth+horizontalBox && x>tx-halfWidth-scaledWallThikness-box )
			&& (z>tz-halfLength-scaledWallThikness && z<tz+halfLength+scaledWallThikness);
	}
	//right wall
	if(!collision){
		collision|=(x>tx+halfWidth-horizontalBox && x<tx+halfWidth+scaledWallThikness+box )
			&& (
				(z>tz-halfLength-scaledWallThikness && z<tz-mainDoorWidth/2.0+0.1) ||
				(z<tz+halfLength+scaledWallThikness && z>tz+mainDoorWidth/2.0-0.1)||
				(hasMainDoor && mainDoor.state==0 && z<tz+mainDoorWidth/2.0 && z>tz-mainDoorWidth/2.0) ||
				(!hasMainDoor && z<tz+mainDoorWidth/2.0 && z>tz-mainDoorWidth/2.0)
			);
	}
	// left connecter wall
	if(hasConnecter && !collision){
		collision|=
			z<tz-halfLength-scaledWallThikness 
			&& z>tz-halfLength-scaledWallThikness-cLength*scale
			&& x<tx-halfWidth+0.2 
			&& x>tx-halfWidth-0.5 
			&& y<ty+2.5 ;
	}
	// right connecter wall
	if(hasConnecter && !collision){
		collision|=
			z<tz-halfLength-scaledWallThikness 
			&& z>tz-halfLength-scaledWallThikness-cLength*scale
			&& x>tx+halfWidth-0.2 
			&& x<tx+halfWidth+0.5 
			&& y<ty+2.5
			;
	}
	
	return !collision;
	

}
bool TrainCar::canInteract(double x , double z ,double r){
	bool result=true;
	double cx=UltimateCamera::walkX , cz=UltimateCamera::walkZ;
	double d=sqrt(pow(x - cx, 2) + pow(z - cz, 2));
	if(d>r)return false;
	/*if(cz<z){
		result=cz<UltimateCamera::povZ();
	}else 
	{
		result=cz>UltimateCamera::povZ();
	}*/
	return result;
}

TrainCar::~TrainCar(void)
{
}
