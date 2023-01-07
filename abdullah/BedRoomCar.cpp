#include "BedRoomCar.h"
#include "TrainCar.h"
#include "ProjectTextures.h"
#include <windows.h>		// Header File For Windows
#include <gl\gl.h>			// Header File For The OpenGL32 Library
#include <gl\glu.h>			// Header File For The GLu32 Library
#include <glaux.h>		// Header File For The Glaux Library
#include <texture.h>

double BedRoomCar::leftdoorangle=0;
double BedRoomCar::rightdoorangle=0;
double BedRoomCar::leftdrawer=0;
double BedRoomCar::rightdrawer=0;
bool BedRoomCar::openleftdoor=false;
bool BedRoomCar::openrightdoor=false;
bool BedRoomCar::openleftdrawer=false;
bool BedRoomCar::openrightdrawer=false;
int BedRoomCar::bedRoomId=-3458349;
BedRoomCar::BedRoomCar(void) : TrainCar(false ,true,2.05)
{
	closeWindows();
}
BedRoomCar::BedRoomCar(int t) {
}
void BedRoomCar::draw(){
	if(hasLight)glEnable(GL_LIGHT1);
	TrainCar::draw();
	if(glIsEnabled( GL_LIGHT2))
		glDisable(GL_LIGHT2);
	glPushMatrix();
	glTranslated(tx,ty+0.35,tz);
	glScaled(scale/9,scale/9,scale/9);
	if(bedRoomId<0)
	{
		bedRoomId=glGenLists(1);
		glNewList(bedRoomId,GL_COMPILE);
		BedRoom();
		glEndList();
	}
	glCallList(bedRoomId);
	glPopMatrix();
	if(hasLight)glDisable(GL_LIGHT1);
	glEnable(GL_LIGHT2);
}
void BedRoomCar::interactCloast(){
	if( canInteract(tx,tz,6)){
		if(openleftdoor){
			openleftdoor=false;
			openrightdoor=false;
			PlaySound(TEXT("Sounds/Door-close.wav"), NULL, SND_ASYNC);
		}else {
			openleftdoor=true;
			openrightdoor=true;
			PlaySound(TEXT("Sounds/Door-open.wav"), NULL, SND_ASYNC);
		}
	}
}

BedRoomCar::~BedRoomCar(void)
{
}
void BedRoomCar::BedRoom()
{


	glPushMatrix();

		glPushMatrix();
		glTranslated(4.6,-2.8,0);
		glRotated(-90,0,1,0);
		DrawObject::ClosetBuild();
		glRotated(180,0,1,0);
		glTranslated(0,0,-9.4);
		DrawObject::ClosetBuild();

		glPopMatrix();
		glTranslated(4.6,-4.55,18); 
		DrawObject::BedBuild(ProjectTextures::bedRoomB1tex,ProjectTextures::bedRoomMattresstex,ProjectTextures::bedRoomPillowtex);

		glTranslated(-9.2,0,0);
		DrawObject::BedBuild(ProjectTextures::bedRoomB1tex,ProjectTextures::bedRoomMattresstex,ProjectTextures::bedRoomPillowtex);

		glTranslated(9.2,0,-36);
		glRotated(180,0,1,0);
		DrawObject::BedBuild(ProjectTextures::bedRoomB1tex,ProjectTextures::bedRoomMattresstex,ProjectTextures::bedRoomPillowtex);
		glTranslated(9.2,0,0);
		DrawObject::BedBuild(ProjectTextures::bedRoomB1tex,ProjectTextures::bedRoomMattresstex,ProjectTextures::bedRoomPillowtex);
	glPopMatrix();

	glPushMatrix();

		glTranslated(5.2,-3.85,-11);
		glPushMatrix();
			glTranslated(0,1.1,0);
			glRotated(90,1,0,0);
			glRotated(90,0,0,1);
			DrawObject::ComputerScreenBuild(ProjectTextures::bedRoomScreen[0]);
		glPopMatrix();

		glRotated(-90,0,1,0);
		DrawObject::TableBuild();

		glPushMatrix();
			glTranslated(0,0.62,1);
			DrawObject::KeyBoardBuild(ProjectTextures::bedRoomKeytex,0.5,1.8,0.1);

			glTranslated(1.5,0,0);
			DrawObject::RobicCubeBuild(0.25);
		glPopMatrix();


		glPushMatrix();
			glTranslated(0,-0.5,1.8);
			DrawObject::ChairBuild();
		glPopMatrix();

		glTranslated(19.5,0,0);
		glPushMatrix();
		glTranslated(2,0,0);
		DrawObject::TableBuild();
		glPopMatrix();


		glPushMatrix();

			glTranslated(-13.5,0,0);
			glRotated(90,0,1,0);
			glPushMatrix();
				glTranslated(0,1.1,0);
				glRotated(90,1,0,0);
				glRotated(90,0,0,1);
				DrawObject::ComputerScreenBuild(ProjectTextures::bedRoomScreen[0]);
			glPopMatrix();

			glRotated(-90,0,1,0);
			DrawObject::TableBuild();

			glPushMatrix();
				glTranslated(0,0.62,1);
				DrawObject::KeyBoardBuild(ProjectTextures::bedRoomKeytex,0.5,1.8,0.1);

				glTranslated(1.5,0,0);
				DrawObject::RobicCubeBuild(0.25);
			glPopMatrix();


			glPushMatrix();
				glTranslated(0,-0.5,1.8);
				DrawObject::ChairBuild();
			glPopMatrix();
		glPopMatrix();

		//......................

		glPushMatrix();

			glTranslated(-3.5,0,0);
			glRotated(90,0,1,0);
			glPushMatrix();
				glTranslated(0,1.1,0);
				glRotated(90,1,0,0);
				glRotated(90,0,0,1);
				DrawObject::ComputerScreenBuild(ProjectTextures::bedRoomScreen[0]);
			glPopMatrix();

			glRotated(-90,0,1,0);
			DrawObject::TableBuild();

			glPushMatrix();
				glTranslated(0,0.62,1);
				DrawObject::KeyBoardBuild(ProjectTextures::bedRoomKeytex,0.5,1.8,0.1);

				glTranslated(1.5,0,0);
				DrawObject::RobicCubeBuild(0.25);
			glPopMatrix();


			glPushMatrix();
				glTranslated(0,-0.5,1.8);
				DrawObject::ChairBuild();
			glPopMatrix();
		glPopMatrix();

		//......................


		glPushMatrix();
			glTranslated(2,0,0);

			glRotated(90,0,1,0);
			glTranslated(0,1.1,0);
			glRotated(90,1,0,0);
			glRotated(90,0,0,1);
			DrawObject::ComputerScreenBuild(ProjectTextures::bedRoomScreen[0]);
		glPopMatrix();

		glPushMatrix();
			glTranslated(2,0.62,1);
			DrawObject::KeyBoardBuild(ProjectTextures::bedRoomKeytex,0.5,1.8,0.1);

			glTranslated(1.5,0,0);
			DrawObject::RobicCubeBuild(0.25);
		glPopMatrix();

		glPushMatrix();
			glTranslated(2,-0.5,1.8);
			DrawObject::ChairBuild();
		glPopMatrix();

		//..................................

		glRotated(180,0,1,0);
		glTranslated(0,0,-10.5);


		glPushMatrix();
			glTranslated(3.5,0,0);

			DrawObject::TableBuild();

		glPushMatrix();
			glRotated(90,0,1,0);
			glTranslated(0,1.1,0);
			glRotated(90,1,0,0);
			glRotated(90,0,0,1);
			DrawObject::ComputerScreenBuild(ProjectTextures::bedRoomScreen[1]);
		glPopMatrix();

		glPushMatrix();
			glTranslated(0,0.62,1);
			DrawObject::KeyBoardBuild(ProjectTextures::bedRoomKeytex,0.5,1.8,0.1);

			glTranslated(1.5,0,0);
			DrawObject::RobicCubeBuild(0.25);
		glPopMatrix();

		glPushMatrix();
			glTranslated(0,-0.5,1.8);
			DrawObject::ChairBuild();
		glPopMatrix();
		glPopMatrix();


		//....
		glPushMatrix();
		glTranslated(-2,0,0);
		DrawObject::TableBuild();

		glPushMatrix();
			glRotated(90,0,1,0);
			glTranslated(0,1.1,0);
			glRotated(90,1,0,0);
			glRotated(90,0,0,1);
			DrawObject::ComputerScreenBuild(ProjectTextures::bedRoomScreen[1]);
		glPopMatrix();

		glPushMatrix();
			glTranslated(0,0.62,1);
			DrawObject::KeyBoardBuild(ProjectTextures::bedRoomKeytex,0.5,1.8,0.1);

			glTranslated(1.5,0,0);
			DrawObject::RobicCubeBuild(0.25);
		glPopMatrix();

		glPushMatrix();
			glTranslated(0,-0.5,1.8);
			DrawObject::ChairBuild();
		glPopMatrix();
		glPopMatrix();




		glTranslated(19.5,0,0);

		DrawObject::TableBuild();

		glPushMatrix();
			glRotated(90,0,1,0);
			glTranslated(0,1.1,0);
			glRotated(90,1,0,0);
			glRotated(90,0,0,1);
			DrawObject::ComputerScreenBuild(ProjectTextures::bedRoomScreen[1]);
		glPopMatrix();

		glPushMatrix();
			glTranslated(0,0.62,1);
			DrawObject::KeyBoardBuild(ProjectTextures::bedRoomKeytex,0.5,1.8,0.1);

			glTranslated(1.5,0,0);
			DrawObject::RobicCubeBuild(0.25);
		glPopMatrix();

		glPushMatrix();
			glTranslated(0,-0.5,1.8);
			DrawObject::ChairBuild();
		glPopMatrix();


		glTranslated(-6,0,0);
		DrawObject::TableBuild();

		glPushMatrix();
			glRotated(90,0,1,0);
			glTranslated(0,1.1,0);
			glRotated(90,1,0,0);
			glRotated(90,0,0,1);
			DrawObject::ComputerScreenBuild(ProjectTextures::bedRoomScreen[1]);
		glPopMatrix();

		glPushMatrix();
			glTranslated(0,0.62,1);
			DrawObject::KeyBoardBuild(ProjectTextures::bedRoomKeytex,0.5,1.8,0.1);

			glTranslated(1.5,0,0);
			DrawObject::RobicCubeBuild(0.25);
		glPopMatrix();

		glPushMatrix();
			glTranslated(0,-0.5,1.8);
			DrawObject::ChairBuild();
		glPopMatrix();

	glPopMatrix();
}