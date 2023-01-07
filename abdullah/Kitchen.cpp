#include "PassengersCar.h"
#include "Chair.h"

PassengersCar::PassengersCar(void)
	:TrainCar(true,true)//(hasMaindoor,hasConnecter)
{
}
void PassengersCar::drawDecore(){
	//draw your decore here
	float myZ;
		float myY=-height/2.0 + Chair::height/2.2;
		
		for(int i=0;i<leftSideWall.n;i++){
			float winZ=leftSideWall.windows[i].tz;
			myZ=winZ+Window::width/2.0+0.1;
			Chair::draw(-width/2.0+Chair::width/2.0+0.03  ,  myY ,myZ,ProjectTextures::seatTex,ProjectTextures::seatBackTex);
			Chair::draw(-width/2.0+Chair::width/2+Chair::width+0.07  ,  myY ,myZ,ProjectTextures::seatTex,ProjectTextures::seatBackTex);
			
		}
		for(int i=0;i<lRightSideWall.n;i++){
			float winZ=lRightSideWall.windows[i].tz;
			myZ=winZ+Window::width/2.0+0.1+lRightSideWall.tz;
			Chair::draw(width/2.0-Chair::width/2.0-0.03  ,  myY ,myZ,ProjectTextures::seatTex,ProjectTextures::seatBackTex);
			Chair::draw(width/2.0-Chair::width/2-Chair::width-0.07  ,  myY ,myZ,ProjectTextures::seatTex,ProjectTextures::seatBackTex);
			
		}
		if(hasMainDoor)
		for(int i=0;i<rRightSideWall.n;i++){
			float winZ=rRightSideWall.windows[i].tz + rRightSideWall.tz;
			myZ=winZ+Window::width/2.0+0.1;
			Chair::draw(width/2.0-Chair::width/2.0-0.03  ,  myY ,myZ,ProjectTextures::seatTex,ProjectTextures::seatBackTex);
			Chair::draw(width/2.0-Chair::width/2-Chair::width-0.07  ,  myY ,myZ,ProjectTextures::seatTex,ProjectTextures::seatBackTex);
		}

		for (Wall i : decoreWalls) {
			i.draw();
		}
}

void PassengersCar::initializeDecore(){
	//initialize objects in needed
	float myZ;
		float myY=-height/2.0 + Chair::height/2.2;
		float barWidth=Chair::width*2 + 0.07;
		for(int i=0;i<leftSideWall.n;i++){
			float winZ=leftSideWall.windows[i].tz;
			myZ=winZ+Window::width/2.0+0.1;
			Wall bar=Wall(Dimention(barWidth,Chair::width,0.02),ProjectTextures::wood,ProjectTextures::wood);
			bar.setCustomTexture(ProjectTextures::wood);
			bar.translate(-width/2.0+barWidth/2.0,myY-Chair::thikness-0.01,myZ-Chair::width/2.0-0.022);
			decoreWalls.push_back(bar);
		}
		for(int i=0;i<lRightSideWall.n;i++){
			float winZ=lRightSideWall.windows[i].tz;
			myZ=winZ+Window::width/2.0+0.1+lRightSideWall.tz;
			Wall bar=Wall(Dimention(barWidth,Chair::width,0.02),ProjectTextures::wood,ProjectTextures::wood);
			bar.setCustomTexture(ProjectTextures::wood);
			bar.translate(width/2.0-barWidth/2.0,myY-Chair::thikness-0.01,myZ-Chair::width/2.0-0.022);
			decoreWalls.push_back(bar);
		}
		if(hasMainDoor)
		for(int i=0;i<rRightSideWall.n;i++){
			float winZ=rRightSideWall.windows[i].tz + rRightSideWall.tz;
			myZ=winZ+Window::width/2.0+0.1;
			Wall bar=Wall(Dimention(barWidth,Chair::width,0.02),ProjectTextures::wood,ProjectTextures::wood);
			bar.setCustomTexture(ProjectTextures::wood);
			bar.translate(width/2.0-barWidth/2.0,myY-Chair::thikness-0.01,myZ-Chair::width/2.0-0.022);
			decoreWalls.push_back(bar);
		}
}

bool PassengersCar::canCameraGoTo(float x,float y,float z){
	bool result=true;
	if(!TrainCar::canCameraGoTo(x,y,z))return false;
	//now write code to check collisions with your decore my brother 
	// if no collisions found return true
	return result;
}

PassengersCar::~PassengersCar(void)
{

}
