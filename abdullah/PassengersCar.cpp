#include "PassengersCar.h"
#include "Chair.h"



int PassengersCar::passengersId=-1000;
PassengersCar::PassengersCar(void)
	:TrainCar(true,true,(scaledWidth/2.0-Door::width*scale/2.0)+0.3)//(hasMaindoor,hasConnecter)
{
	initializeDecore();
}
PassengersCar::PassengersCar(int t){
}
void PassengersCar::draw(){
	//draw the train car
	if(hasLight)glEnable(GL_LIGHT1);
	TrainCar::draw(); // already scaled and translated up
	if(glIsEnabled( GL_LIGHT2))
		glDisable(GL_LIGHT2);
	
	//draw the decore
	glPushMatrix();   // you have to do the scaling and translating
	glTranslated(tx,ty,tz);
	glScaled(scale,scale,scale);
	if(passengersId<0){
		passengersId=glGenLists(1);
		glNewList(passengersId,GL_COMPILE);
		double myZ;
		double myY=-height/2.0 + Chair::height/2.2;
		
		for(int i=0;i<leftSideWall.n;i++){
			double winZ=leftSideWall.windows[i].tz;
			myZ=winZ+Window::width/2.0+0.1;
			Chair::draw(-width/2.0+Chair::width/2.0+0.03  ,  myY ,myZ,ProjectTextures::seatTex,ProjectTextures::seatBackTex);
			Chair::draw(-width/2.0+Chair::width/2+Chair::width+0.07  ,  myY ,myZ,ProjectTextures::seatTex,ProjectTextures::seatBackTex);
			
		}
		for(int i=0;i<lRightSideWall.n;i++){
			double winZ=lRightSideWall.windows[i].tz;
			myZ=winZ+Window::width/2.0+0.1+lRightSideWall.tz;
			Chair::draw(width/2.0-Chair::width/2.0-0.03  ,  myY ,myZ,ProjectTextures::seatTex,ProjectTextures::seatBackTex);
			Chair::draw(width/2.0-Chair::width/2-Chair::width-0.07  ,  myY ,myZ,ProjectTextures::seatTex,ProjectTextures::seatBackTex);
			
		}
		if(hasMainDoor)
		for(int i=0;i<rRightSideWall.n;i++){
			double winZ=rRightSideWall.windows[i].tz + rRightSideWall.tz;
			myZ=winZ+Window::width/2.0+0.1;
			Chair::draw(width/2.0-Chair::width/2.0-0.03  ,  myY ,myZ,ProjectTextures::seatTex,ProjectTextures::seatBackTex);
			Chair::draw(width/2.0-Chair::width/2-Chair::width-0.07  ,  myY ,myZ,ProjectTextures::seatTex,ProjectTextures::seatBackTex);
		}

		for (Wall i : decoreWalls) {
			i.draw();
		}
		glEndList();
	}
	glCallList(passengersId);
	
		glPopMatrix();
		if(hasLight)glDisable(GL_LIGHT1);
			glEnable( GL_LIGHT2);

}

void PassengersCar::initializeDecore(){
	//initialize objects in needed
	double myZ;
		double myY=-height/2.0 + Chair::height/2.2;
		double barWidth=Chair::width*2 + 0.07;
		for(int i=0;i<leftSideWall.n;i++){
			double winZ=leftSideWall.windows[i].tz;
			myZ=winZ+Window::width/2.0+0.1;
			Wall bar=Wall(Dimention(barWidth,Chair::width,0.02),ProjectTextures::wood,ProjectTextures::wood);
			bar.setCustomTexture(ProjectTextures::wood);
			bar.translate(-width/2.0+barWidth/2.0,myY-Chair::thikness-0.01,myZ-Chair::width/2.0-0.022);
			bar.isChair=true;
			decoreWalls.push_back(bar);
		}
		for(int i=0;i<lRightSideWall.n;i++){
			double winZ=lRightSideWall.windows[i].tz;
			myZ=winZ+Window::width/2.0+0.1+lRightSideWall.tz;
			Wall bar=Wall(Dimention(barWidth,Chair::width,0.02),ProjectTextures::wood,ProjectTextures::wood);
			bar.setCustomTexture(ProjectTextures::wood);
			bar.translate(width/2.0-barWidth/2.0,myY-Chair::thikness-0.01,myZ-Chair::width/2.0-0.022);
			bar.isChair=true;
			decoreWalls.push_back(bar);
		}
		if(hasMainDoor)
		for(int i=0;i<rRightSideWall.n;i++){
			double winZ=rRightSideWall.windows[i].tz + rRightSideWall.tz;
			myZ=winZ+Window::width/2.0+0.1;
			Wall bar=Wall(Dimention(barWidth,Chair::width,0.02),ProjectTextures::wood,ProjectTextures::wood);
			bar.setCustomTexture(ProjectTextures::wood);
			bar.translate(width/2.0-barWidth/2.0,myY-Chair::thikness-0.01,myZ-Chair::width/2.0-0.022);
			bar.isChair=true;
			decoreWalls.push_back(bar);
		}
}


PassengersCar::~PassengersCar(void)
{

}
