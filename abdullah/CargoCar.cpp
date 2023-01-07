#include "CargoCar.h"
#include "Cargo.h"
//#include "TrainCar.h"

int CargoCar::cargoId=-1000;
CargoCar::CargoCar(void) : TrainCar(true, true, 2.2)
{
}
CargoCar::CargoCar(int t ) {
}

void CargoCar::draw() {
	if(hasLight)glEnable(GL_LIGHT1);
	TrainCar::draw();
	
	if(glIsEnabled( GL_LIGHT2))
		glDisable(GL_LIGHT2);
	int tex[10];
	tex[0] = ProjectTextures::boxTex1;
	tex[1] = ProjectTextures::boxTex2;
	tex[2] = ProjectTextures::woodsTex;
	tex[3] = ProjectTextures::ladderTex;
	tex[4] = ProjectTextures::stepTex;
	tex[5] = ProjectTextures::frameTex;
	tex[6] = ProjectTextures::nightTex;
	tex[7] = ProjectTextures::monaTex;
	glPushMatrix();
	glTranslated(tx, ty +0.35, tz);
	glScaled(scale / 9.0, scale / 9.0, scale / 9.0);
	if(cargoId<0){
		cargoId=glGenLists(1);
		glNewList(cargoId,GL_COMPILE);
		Cargo::drawCargo(tex);
		glEndList();
	}
	glCallList(cargoId);
	glPopMatrix();
	if(hasLight)glDisable(GL_LIGHT1);
	glEnable(GL_LIGHT2);
}



CargoCar::~CargoCar()
{
}
