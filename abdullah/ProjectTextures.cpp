#include "ProjectTextures.h"
#include <windows.h>		// Header File For Windows
#include <gl\gl.h>			// Header File For The OpenGL32 Library
#include <gl\glu.h>			// Header File For The GLu32 Library
#include <glaux.h>		// Header File For The Glaux Library
#include <texture.h>
//abdullah
int ProjectTextures::out=0;
int ProjectTextures::wood=0;
int ProjectTextures::door=0;
int ProjectTextures::rdoor=0;
int ProjectTextures::groundTex=0;
int ProjectTextures::connecterGroundTex=0;
int ProjectTextures::carpetTex=0;
int ProjectTextures::seatTex=0;
int ProjectTextures::seatBackTex=0;
int ProjectTextures::enginsTex=0;
int ProjectTextures::mainDoorLeft=0;
int ProjectTextures::mainDoorRight=0;
int ProjectTextures::curtainTexture=0;
//example
int ProjectTextures::somethingMetal=0;//do this for all of your textures 
int ProjectTextures::somethingSomething=0;
//adnan
int ProjectTextures::bedRoomB1tex=0;
int ProjectTextures::bedRoomMattresstex=0;
int ProjectTextures::bedRoomPillowtex=0;
int ProjectTextures::bedRoomTable=0;
int ProjectTextures::bedRoomChair=0;
int ProjectTextures::bedRoomTest=0;
int ProjectTextures::bedRoomKeytex=0;
int ProjectTextures::bedRoomBlack=0;
int ProjectTextures::bedRoomRobic=0;
int ProjectTextures::bedRoomChess=0;
int ProjectTextures::bedRoomScreen[2]={0,0};
//mousa
int ProjectTextures::woodsTex =0;
int ProjectTextures::boxTex1 =0;
int ProjectTextures::boxTex2 = 0;
int ProjectTextures::ladderTex = 0;
int ProjectTextures::stepTex = 0;
int ProjectTextures::frameTex = 0;
int ProjectTextures::nightTex = 0;
int ProjectTextures::monaTex = 0;
//alaa
int ProjectTextures::cloast=0;//....
int ProjectTextures::table1=0;
int ProjectTextures::control=0;
int ProjectTextures::out1=0;
int ProjectTextures::out2=0;
// omran

//....
ProjectTextures::ProjectTextures(void)
{
}

void ProjectTextures::initialize(){
		out=LoadTexture("Textures/out_test.bmp",255);
		wood=LoadTexture("Textures/out_test.bmp",255);
		door=LoadTexture("Textures/4door2.bmp",255);
		rdoor=LoadTexture("Textures/door2.bmp",255);
		groundTex=LoadTexture("Textures/wall.bmp",255);
		connecterGroundTex=LoadTexture("Textures/connecterGround.bmp",255);
		//carpetTex=LoadTexture("wall.bmp",255);
		seatTex=LoadTexture("Textures/seat2.bmp",255);
		seatBackTex=LoadTexture("Textures/seat2.bmp",255);
		enginsTex=LoadTexture("Textures/engins2.bmp",255);
		mainDoorLeft=LoadTexture("Textures/mainDoorLeft.bmp",255);
		mainDoorRight=LoadTexture("Textures/mainDoorRight.bmp",255);
		curtainTexture=LoadTexture("Textures/wall.bmp",255);	
		bedRoomB1tex = LoadTexture("Textures/bed7.bmp",255);
		bedRoomMattresstex = LoadTexture("Textures/beds.bmp",255);
		bedRoomPillowtex = LoadTexture("Textures/pillow.bmp",255);
		bedRoomTable = LoadTexture("Textures/bed2.bmp",255);
		bedRoomChair = LoadTexture("Textures/bed2.bmp",255);
		bedRoomBlack = LoadTexture("Textures/black.bmp",255);
		bedRoomKeytex = LoadTexture("Textures/keyboard2.bmp",255);
		bedRoomScreen[0] = LoadTexture("Textures/screen1.bmp",255);
		bedRoomScreen[1] = LoadTexture("Textures/screen2.bmp",255);
		bedRoomRobic = LoadTexture("Textures/robic1.bmp",255);
		bedRoomChess = LoadTexture("Textures/chess3.bmp",255);
		bedRoomTest = LoadTexture("Textures/ch.bmp",255);
		//AbDulla Musa's
		woodsTex = LoadTexture("cargo/woods.bmp", 255);
		boxTex1 = LoadTexture("cargo/crate1.bmp", 255);
		boxTex2 = LoadTexture("cargo/crate2.bmp", 255);
		ladderTex = LoadTexture("cargo/ladder.bmp", 255);
		stepTex = LoadTexture("cargo/steps.bmp", 255);
		frameTex = LoadTexture("cargo/frame.bmp", 255);
		nightTex = LoadTexture("cargo/night.bmp", 255);
		monaTex = LoadTexture("cargo/mona.bmp", 255);
		//alaa 
		cloast = LoadTexture("Textures/cloast.bmp",255);
		table1 = LoadTexture("Textures/table2.bmp",255);
		control = LoadTexture("Textures/control1.bmp",255);
		out1=LoadTexture("Textures/out_test.bmp",255);
		out2=LoadTexture("Textures/out.bmp",255);
}
ProjectTextures::~ProjectTextures(void)
{
}
