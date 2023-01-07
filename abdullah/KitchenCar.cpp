#include "KitchenCar.h"

int KitchenCar::dishListId=0;
int KitchenCar::kitchenId=-1000;
KitchenCar::KitchenCar(void) : TrainCar(false , true , 2)
{
	closeWindows();
}
KitchenCar::KitchenCar(int t ) {
}
void KitchenCar::initializeList(){
		dishListId=glGenLists(1);
		glNewList(dishListId,GL_COMPILE);
		Kitchen:: Cylinder(0.02 , 0.1 , 0.05, true , false);
		glEndList();
		

	}
void  KitchenCar::DrawKitchen(){
	/////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////
	//Closets1
	glPushMatrix();
	glTranslated(0 , 0 , -2);


	glPushMatrix();
	glTranslated(-0.6 , -0.1 , 0);
	Kitchen:: refregrator(1 , 0.3 , 0.03 );
	glPopMatrix();

	glPushMatrix();
	glTranslated(-0.68 , -0.1 , 0.49);
	glRotated(90 , 0 , 1 , 0);
	Kitchen:: refregrator(1 , 0.97 , 0.03 );
	glPopMatrix();


	glPushMatrix();
	glTranslated(-0.6 , -0.1 , 1);
	Kitchen:: refregrator(1 , 0.3 , 0.03 );
	glPopMatrix();

	glPushMatrix();
	glTranslated(-0.6 , 0.4 , 0.48);
	glRotated(90 , 1 , 0 , 0);
	Kitchen:: refregrator(1.1 , 0.3 , 0.03 );
	glPopMatrix();

	glPushMatrix();
	glTranslated(-0.6 , 0.1 , 0.484);
	glRotated(90 , 1 , 0 , 0);
	Kitchen:: refregrator(0.965 , 0.3 , 0.03 );
	glPopMatrix();

	glPushMatrix();
	glTranslated(-0.6 , -0.2 , 0.484);
	glRotated(90 , 1 , 0 , 0);
	Kitchen:: refregrator(0.965 , 0.3 , 0.03 );
	glPopMatrix();

	////////////////////////////////////////////////////////////

	
	//Dishes5
	glPushMatrix();
	glTranslated(-0.59 , 0.15 , 0.3);
	glBindTexture(GL_TEXTURE_2D , ProjectTextures::cloast);
	glBindTexture(GL_TEXTURE_2D , ProjectTextures::table1);
	glColor3f(1,1,1);
	glRotated(-90 , 1 ,0 , 0);
	glCallList(dishListId);
	
	glTranslated(0 , 0 , 0.025);
	glCallList(dishListId);

	glTranslated(0 , 0 , 0.025);
	glCallList(dishListId);

	glTranslated(0 , 0 , 0.025);
	glCallList(dishListId);

	glTranslated(0 , 0 , 0.025);
	glCallList(dishListId);

	glTranslated(0 , 0 , 0.025);
	glCallList(dishListId);

	glTranslated(0 , 0 , 0.025);
	glCallList(dishListId);

	glTranslated(0 , 0 , 0.025);
	glCallList(dishListId);
	glTranslated(0 , 0 , 0.025);
	
	glPopMatrix();
	//////////////////////////////////////////////////////

	//Dishes6
	glPushMatrix();
	glTranslated(-0.59 , -0.14 , 0.7);
	glBindTexture(GL_TEXTURE_2D , ProjectTextures::cloast);
	glBindTexture(GL_TEXTURE_2D , ProjectTextures::table1);
	glColor3f(1,1,1);
	glRotated(-90 , 1 ,0 , 0);
	glCallList(dishListId);
	
	glTranslated(0 , 0 , 0.025);
	glCallList(dishListId);

	glTranslated(0 , 0 , 0.025);
	glCallList(dishListId);

	glTranslated(0 , 0 , 0.025);
	glCallList(dishListId);

	glTranslated(0 , 0 , 0.025);
	glCallList(dishListId);

	glTranslated(0 , 0 , 0.025);
	glCallList(dishListId);

	glTranslated(0 , 0 , 0.025);
	glCallList(dishListId);

	glTranslated(0 , 0 , 0.025);
	glCallList(dishListId);
	glTranslated(0 , 0 , 0.025);
	
	glPopMatrix();
	/////////////////////////////////////////////////////

	//cup5
	glPushMatrix();
	glTranslated(-0.6 , -0.09 , 0.2);

	glPushMatrix();
	glTranslated(0 , 0 , 0.);
	glBindTexture(GL_TEXTURE_2D , ProjectTextures::cloast);
	glBindTexture(GL_TEXTURE_2D , ProjectTextures::table1);
	glColor3f(0,1,0);
	glRotated(-90 , 1 ,0 , 0);
	Kitchen:: Cylinder(0.075 , 0.03 , 0.03, false , true);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.055 , -0.06 , 0.);
	glRotated(90 , 0 , 1 , 0);
	glBindTexture(GL_TEXTURE_2D , ProjectTextures::cloast);
	glBindTexture(GL_TEXTURE_2D , ProjectTextures::table1);
	glColor3f(0,1,0);
	Kitchen:: Cylinder(0.045 , 0.005 , 0.005, false , true);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.055 , -0.06 , 0.);
	glRotated(90 , 1 , 0 , 0);
	glBindTexture(GL_TEXTURE_2D , ProjectTextures::cloast);
	glBindTexture(GL_TEXTURE_2D ,ProjectTextures:: table1);
	glColor3f(0,1,0);
	Kitchen:: Cylinder(0.045 , 0.005 , 0.005, false , true);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.055 , -0.015 , 0.);
	glRotated(90 , 0 , 1 , 0);
	glBindTexture(GL_TEXTURE_2D , ProjectTextures::cloast);
	glBindTexture(GL_TEXTURE_2D , ProjectTextures::table1);
	glColor3f(0,1,0);
	Kitchen:: Cylinder(0.045 , 0.005 , 0.005, false , true);
	glPopMatrix();

	glPopMatrix();
	////////////////////////////////////////////////////////////
	//cup6
	glPushMatrix();
	glTranslated(-0.6 , -0.09 , 0.5);

	glPushMatrix();
	glTranslated(0 , 0 , 0.);
	glBindTexture(GL_TEXTURE_2D , ProjectTextures::cloast);
	glBindTexture(GL_TEXTURE_2D , ProjectTextures::table1);
	glColor3f(0,1,0);
	glRotated(-90 , 1 ,0 , 0);
	Kitchen:: Cylinder(0.075 , 0.03 , 0.03, false , true);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.055 , -0.06 , 0.);
	glRotated(90 , 0 , 1 , 0);
	glBindTexture(GL_TEXTURE_2D , ProjectTextures::cloast);
	glBindTexture(GL_TEXTURE_2D , ProjectTextures::table1);
	glColor3f(0,1,0);
	Kitchen:: Cylinder(0.045 , 0.005 , 0.005, false , true);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.055 , -0.06 , 0.);
	glRotated(90 , 1 , 0 , 0);
	glBindTexture(GL_TEXTURE_2D , ProjectTextures::cloast);
	glBindTexture(GL_TEXTURE_2D ,ProjectTextures:: table1);
	glColor3f(0,1,0);
	Kitchen:: Cylinder(0.045 , 0.005 , 0.005, false , true);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.055 , -0.015 , 0.);
	glRotated(90 , 0 , 1 , 0);
	glBindTexture(GL_TEXTURE_2D , ProjectTextures::cloast);
	glBindTexture(GL_TEXTURE_2D , ProjectTextures::table1);
	glColor3f(0,1,0);
	Kitchen:: Cylinder(0.045 , 0.005 , 0.005, false , true);
	glPopMatrix();

	glPopMatrix();
	////////////////////////////////////////////////////////////

	//cup7
	glPushMatrix();
	glTranslated(-0.6 , 0.2 , 0.5);

	glPushMatrix();
	glTranslated(0 , 0 , 0.);
	glBindTexture(GL_TEXTURE_2D , ProjectTextures::cloast);
	glBindTexture(GL_TEXTURE_2D , ProjectTextures::table1);
	glColor3f(0,1,0);
	glRotated(-90 , 1 ,0 , 0);
	Kitchen:: Cylinder(0.075 , 0.03 , 0.03, false , true);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.055 , -0.06 , 0.);
	glRotated(90 , 0 , 1 , 0);
	glBindTexture(GL_TEXTURE_2D ,ProjectTextures:: cloast);
	glBindTexture(GL_TEXTURE_2D , ProjectTextures::table1);
	glColor3f(0,1,0);
	Kitchen:: Cylinder(0.045 , 0.005 , 0.005, false , true);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.055 , -0.06 , 0.);
	glRotated(90 , 1 , 0 , 0);
	glBindTexture(GL_TEXTURE_2D , ProjectTextures::cloast);
	glBindTexture(GL_TEXTURE_2D , ProjectTextures::table1);
	glColor3f(0,1,0);
	Kitchen:: Cylinder(0.045 , 0.005 , 0.005, false , true);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.055 , -0.015 , 0.);
	glRotated(90 , 0 , 1 , 0);
	glBindTexture(GL_TEXTURE_2D ,ProjectTextures:: cloast);
	glBindTexture(GL_TEXTURE_2D , ProjectTextures::table1);
	glColor3f(0,1,0);
	Kitchen:: Cylinder(0.045 , 0.005 , 0.005, false , true);
	glPopMatrix();
	glPopMatrix();

	glPopMatrix();
	////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////

	/////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////
	//Closets2
	glPushMatrix();
	glTranslated(0 , 0 , -0.4);

	glPushMatrix();
	glTranslated(-0.6 , -0.1 , 0);
	Kitchen:: refregrator(1 , 0.3 , 0.03 );
	glPopMatrix();

	glPushMatrix();
	glTranslated(-0.68 , -0.1 , 0.49);
	glRotated(90 , 0 , 1 , 0);
	Kitchen:: refregrator(1 , 0.97 , 0.03 );
	glPopMatrix();


	glPushMatrix();
	glTranslated(-0.6 , -0.1 , 1);
	Kitchen:: refregrator(1 , 0.3 , 0.03 );
	glPopMatrix();

	glPushMatrix();
	glTranslated(-0.6 , 0.4 , 0.48);
	glRotated(90 , 1 , 0 , 0);
	Kitchen:: refregrator(1.1 , 0.3 , 0.03 );
	glPopMatrix();

	glPushMatrix();
	glTranslated(-0.6 , 0.1 , 0.484);
	glRotated(90 , 1 , 0 , 0);
	Kitchen:: refregrator(0.965 , 0.3 , 0.03 );
	glPopMatrix();

	glPushMatrix();
	glTranslated(-0.6 , -0.2 , 0.484);
	glRotated(90 , 1 , 0 , 0);
	Kitchen:: refregrator(0.965 , 0.3 , 0.03 );
	glPopMatrix();

	////////////////////////////////////////////////////////////

	
	//Dishes5
	glPushMatrix();
	glTranslated(-0.59 , 0.15 , 0.3);
	glBindTexture(GL_TEXTURE_2D ,ProjectTextures:: cloast);
	glBindTexture(GL_TEXTURE_2D , ProjectTextures::table1);
	glColor3f(1,1,1);
	glRotated(-90 , 1 ,0 , 0);
	glCallList(dishListId);
	
	glTranslated(0 , 0 , 0.025);
	glCallList(dishListId);

	glTranslated(0 , 0 , 0.025);
	glCallList(dishListId);

	glTranslated(0 , 0 , 0.025);
	glCallList(dishListId);

	glTranslated(0 , 0 , 0.025);
	glCallList(dishListId);

	glTranslated(0 , 0 , 0.025);
	glCallList(dishListId);

	glTranslated(0 , 0 , 0.025);
	glCallList(dishListId);

	glTranslated(0 , 0 , 0.025);
	glCallList(dishListId);
	glTranslated(0 , 0 , 0.025);
	
	glPopMatrix();
	//////////////////////////////////////////////////////

	//Dishes6
	glPushMatrix();
	glTranslated(-0.59 , -0.14 , 0.7);
	glBindTexture(GL_TEXTURE_2D ,ProjectTextures:: cloast);
	glBindTexture(GL_TEXTURE_2D , ProjectTextures::table1);
	glColor3f(1,1,1);
	glRotated(-90 , 1 ,0 , 0);
	glCallList(dishListId);
	
	glTranslated(0 , 0 , 0.025);
	glCallList(dishListId);

	glTranslated(0 , 0 , 0.025);
	glCallList(dishListId);

	glTranslated(0 , 0 , 0.025);
	glCallList(dishListId);

	glTranslated(0 , 0 , 0.025);
	glCallList(dishListId);

	glTranslated(0 , 0 , 0.025);
	glCallList(dishListId);

	glTranslated(0 , 0 , 0.025);
	glCallList(dishListId);

	glTranslated(0 , 0 , 0.025);
	glCallList(dishListId);
	glTranslated(0 , 0 , 0.025);
	
	glPopMatrix();
	/////////////////////////////////////////////////////

	//cup5
	glPushMatrix();
	glTranslated(-0.6 , -0.09 , 0.2);

	glPushMatrix();
	glTranslated(0 , 0 , 0.);
	glBindTexture(GL_TEXTURE_2D , ProjectTextures::cloast);
	glBindTexture(GL_TEXTURE_2D , ProjectTextures::table1);
	glColor3f(0,1,0);
	glRotated(-90 , 1 ,0 , 0);
	Kitchen:: Cylinder(0.075 , 0.03 , 0.03, false , true);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.055 , -0.06 , 0.);
	glRotated(90 , 0 , 1 , 0);
	glBindTexture(GL_TEXTURE_2D , ProjectTextures::cloast);
	glBindTexture(GL_TEXTURE_2D ,ProjectTextures:: table1);
	glColor3f(0,1,0);
	Kitchen:: Cylinder(0.045 , 0.005 , 0.005, false , true);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.055 , -0.06 , 0.);
	glRotated(90 , 1 , 0 , 0);
	glBindTexture(GL_TEXTURE_2D , ProjectTextures::cloast);
	glBindTexture(GL_TEXTURE_2D ,ProjectTextures:: table1);
	glColor3f(0,1,0);
	Kitchen:: Cylinder(0.045 , 0.005 , 0.005, false , true);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.055 , -0.015 , 0.);
	glRotated(90 , 0 , 1 , 0);
	glBindTexture(GL_TEXTURE_2D ,ProjectTextures:: cloast);
	glBindTexture(GL_TEXTURE_2D , ProjectTextures::table1);
	glColor3f(0,1,0);
	Kitchen:: Cylinder(0.045 , 0.005 , 0.005, false , true);
	glPopMatrix();

	glPopMatrix();
	////////////////////////////////////////////////////////////
	//cup6
	glPushMatrix();
	glTranslated(-0.6 , -0.09 , 0.5);

	glPushMatrix();
	glTranslated(0 , 0 , 0.);
	glBindTexture(GL_TEXTURE_2D , ProjectTextures::cloast);
	glBindTexture(GL_TEXTURE_2D , ProjectTextures::table1);
	glColor3f(0,1,0);
	glRotated(-90 , 1 ,0 , 0);
	Kitchen:: Cylinder(0.075 , 0.03 , 0.03, false , true);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.055 , -0.06 , 0.);
	glRotated(90 , 0 , 1 , 0);
	glBindTexture(GL_TEXTURE_2D , ProjectTextures::cloast);
	glBindTexture(GL_TEXTURE_2D , ProjectTextures::table1);
	glColor3f(0,1,0);
	Kitchen:: Cylinder(0.045 , 0.005 , 0.005, false , true);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.055 , -0.06 , 0.);
	glRotated(90 , 1 , 0 , 0);
	glBindTexture(GL_TEXTURE_2D ,ProjectTextures:: cloast);
	glBindTexture(GL_TEXTURE_2D , ProjectTextures::table1);
	glColor3f(0,1,0);
	Kitchen:: Cylinder(0.045 , 0.005 , 0.005, false , true);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.055 , -0.015 , 0.);
	glRotated(90 , 0 , 1 , 0);
	glBindTexture(GL_TEXTURE_2D , ProjectTextures::cloast);
	glBindTexture(GL_TEXTURE_2D ,ProjectTextures:: table1);
	glColor3f(0,1,0);
	Kitchen:: Cylinder(0.045 , 0.005 , 0.005, false , true);
	glPopMatrix();

	glPopMatrix();
	////////////////////////////////////////////////////////////

	//cup7
	glPushMatrix();
	glTranslated(-0.6 , 0.2 , 0.5);

	glPushMatrix();
	glTranslated(0 , 0 , 0.);
	glBindTexture(GL_TEXTURE_2D , ProjectTextures::cloast);
	glBindTexture(GL_TEXTURE_2D , ProjectTextures::table1);
	glColor3f(0,1,0);
	glRotated(-90 , 1 ,0 , 0);
	Kitchen:: Cylinder(0.075 , 0.03 , 0.03, false , true);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.055 , -0.06 , 0.);
	glRotated(90 , 0 , 1 , 0);
	glBindTexture(GL_TEXTURE_2D , ProjectTextures::cloast);
	glBindTexture(GL_TEXTURE_2D , ProjectTextures::table1);
	glColor3f(0,1,0);
	Kitchen:: Cylinder(0.045 , 0.005 , 0.005, false , true);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.055 , -0.06 , 0.);
	glRotated(90 , 1 , 0 , 0);
	glBindTexture(GL_TEXTURE_2D , ProjectTextures::cloast);
	glBindTexture(GL_TEXTURE_2D , ProjectTextures::table1);
	glColor3f(0,1,0);
	Kitchen:: Cylinder(0.045 , 0.005 , 0.005, false , true);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.055 , -0.015 , 0.);
	glRotated(90 , 0 , 1 , 0);
	glBindTexture(GL_TEXTURE_2D , ProjectTextures::cloast);
	glBindTexture(GL_TEXTURE_2D , ProjectTextures::table1);
	glColor3f(0,1,0);
	Kitchen:: Cylinder(0.045 , 0.005 , 0.005, false , true);
	glPopMatrix();
	glPopMatrix();

	glPopMatrix();
	////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////

	/////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////
	//Closets3
	glPushMatrix();
	glTranslated(0 , 0 , 1);

	glPushMatrix();
	glTranslated(-0.6 , -0.1 , 0);
	Kitchen:: refregrator(1 , 0.3 , 0.03 );
	glPopMatrix();

	glPushMatrix();
	glTranslated(-0.68 , -0.1 , 0.49);
	glRotated(90 , 0 , 1 , 0);
	Kitchen:: refregrator(1 , 0.97 , 0.03 );
	glPopMatrix();


	glPushMatrix();
	glTranslated(-0.6 , -0.1 , 1);
	Kitchen:: refregrator(1 , 0.3 , 0.03 );
	glPopMatrix();

	glPushMatrix();
	glTranslated(-0.6 , 0.4 , 0.48);
	glRotated(90 , 1 , 0 , 0);
	Kitchen:: refregrator(1.1 , 0.3 , 0.03 );
	glPopMatrix();

	glPushMatrix();
	glTranslated(-0.6 , 0.1 , 0.484);
	glRotated(90 , 1 , 0 , 0);
	Kitchen:: refregrator(0.965 , 0.3 , 0.03 );
	glPopMatrix();

	glPushMatrix();
	glTranslated(-0.6 , -0.2 , 0.484);
	glRotated(90 , 1 , 0 , 0);
	Kitchen:: refregrator(0.965 , 0.3 , 0.03 );
	glPopMatrix();

	////////////////////////////////////////////////////////////

	
	//Dishes5
	glPushMatrix();
	glTranslated(-0.59 , 0.15 , 0.3);
	glBindTexture(GL_TEXTURE_2D ,ProjectTextures:: cloast);
	glBindTexture(GL_TEXTURE_2D , ProjectTextures::table1);
	glColor3f(1,1,1);
	glRotated(-90 , 1 ,0 , 0);
	glCallList(dishListId);
	
	glTranslated(0 , 0 , 0.025);
	glCallList(dishListId);

	glTranslated(0 , 0 , 0.025);
	glCallList(dishListId);

	glTranslated(0 , 0 , 0.025);
	glCallList(dishListId);

	glTranslated(0 , 0 , 0.025);
	glCallList(dishListId);

	glTranslated(0 , 0 , 0.025);
	glCallList(dishListId);

	glTranslated(0 , 0 , 0.025);
	glCallList(dishListId);

	glTranslated(0 , 0 , 0.025);
	glCallList(dishListId);
	glTranslated(0 , 0 , 0.025);
	
	glPopMatrix();
	//////////////////////////////////////////////////////

	//Dishes6
	glPushMatrix();
	glTranslated(-0.59 , -0.14 , 0.7);
	glBindTexture(GL_TEXTURE_2D , ProjectTextures::cloast);
	glBindTexture(GL_TEXTURE_2D , ProjectTextures::table1);
	glColor3f(1,1,1);
	glRotated(-90 , 1 ,0 , 0);
	glCallList(dishListId);
	
	glTranslated(0 , 0 , 0.025);
	glCallList(dishListId);

	glTranslated(0 , 0 , 0.025);
	glCallList(dishListId);

	glTranslated(0 , 0 , 0.025);
	glCallList(dishListId);

	glTranslated(0 , 0 , 0.025);
	glCallList(dishListId);

	glTranslated(0 , 0 , 0.025);
	glCallList(dishListId);

	glTranslated(0 , 0 , 0.025);
	glCallList(dishListId);

	glTranslated(0 , 0 , 0.025);
	glCallList(dishListId);
	glTranslated(0 , 0 , 0.025);
	
	glPopMatrix();
	/////////////////////////////////////////////////////

	//cup5
	glPushMatrix();
	glTranslated(-0.6 , -0.09 , 0.2);

	glPushMatrix();
	glTranslated(0 , 0 , 0.);
	glBindTexture(GL_TEXTURE_2D , ProjectTextures::cloast);
	glBindTexture(GL_TEXTURE_2D ,ProjectTextures:: table1);
	glColor3f(0,1,0);
	glRotated(-90 , 1 ,0 , 0);
	Kitchen:: Cylinder(0.075 , 0.03 , 0.03, false , true);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.055 , -0.06 , 0.);
	glRotated(90 , 0 , 1 , 0);
	glBindTexture(GL_TEXTURE_2D , ProjectTextures::cloast);
	glBindTexture(GL_TEXTURE_2D , ProjectTextures::table1);
	glColor3f(0,1,0);
	Kitchen:: Cylinder(0.045 , 0.005 , 0.005, false , true);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.055 , -0.06 , 0.);
	glRotated(90 , 1 , 0 , 0);
	glBindTexture(GL_TEXTURE_2D , ProjectTextures::cloast);
	glBindTexture(GL_TEXTURE_2D , ProjectTextures::table1);
	glColor3f(0,1,0);
	Kitchen:: Cylinder(0.045 , 0.005 , 0.005, false , true);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.055 , -0.015 , 0.);
	glRotated(90 , 0 , 1 , 0);
	glBindTexture(GL_TEXTURE_2D , ProjectTextures::cloast);
	glBindTexture(GL_TEXTURE_2D , ProjectTextures::table1);
	glColor3f(0,1,0);
	Kitchen:: Cylinder(0.045 , 0.005 , 0.005, false , true);
	glPopMatrix();

	glPopMatrix();
	////////////////////////////////////////////////////////////
	//cup6
	glPushMatrix();
	glTranslated(-0.6 , -0.09 , 0.5);

	glPushMatrix();
	glTranslated(0 , 0 , 0.);
	glBindTexture(GL_TEXTURE_2D ,ProjectTextures:: cloast);
	glBindTexture(GL_TEXTURE_2D , ProjectTextures::table1);
	glColor3f(0,1,0);
	glRotated(-90 , 1 ,0 , 0);
	Kitchen:: Cylinder(0.075 , 0.03 , 0.03, false , true);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.055 , -0.06 , 0.);
	glRotated(90 , 0 , 1 , 0);
	glBindTexture(GL_TEXTURE_2D ,ProjectTextures:: cloast);
	glBindTexture(GL_TEXTURE_2D , ProjectTextures::table1);
	glColor3f(0,1,0);
	Kitchen:: Cylinder(0.045 , 0.005 , 0.005, false , true);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.055 , -0.06 , 0.);
	glRotated(90 , 1 , 0 , 0);
	glBindTexture(GL_TEXTURE_2D ,ProjectTextures:: cloast);
	glBindTexture(GL_TEXTURE_2D ,ProjectTextures:: table1);
	glColor3f(0,1,0);
	Kitchen:: Cylinder(0.045 , 0.005 , 0.005, false , true);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.055 , -0.015 , 0.);
	glRotated(90 , 0 , 1 , 0);
	glBindTexture(GL_TEXTURE_2D ,ProjectTextures:: cloast);
	glBindTexture(GL_TEXTURE_2D , ProjectTextures::table1);
	glColor3f(0,1,0);
	Kitchen:: Cylinder(0.045 , 0.005 , 0.005, false , true);
	glPopMatrix();

	glPopMatrix();
	////////////////////////////////////////////////////////////

	//cup7
	glPushMatrix();
	glTranslated(-0.6 , 0.2 , 0.5);

	glPushMatrix();
	glTranslated(0 , 0 , 0.);
	glBindTexture(GL_TEXTURE_2D , ProjectTextures::cloast);
	glBindTexture(GL_TEXTURE_2D , ProjectTextures::table1);
	glColor3f(0,1,0);
	glRotated(-90 , 1 ,0 , 0);
	Kitchen:: Cylinder(0.075 , 0.03 , 0.03, false , true);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.055 , -0.06 , 0.);
	glRotated(90 , 0 , 1 , 0);
	glBindTexture(GL_TEXTURE_2D , ProjectTextures::cloast);
	glBindTexture(GL_TEXTURE_2D , ProjectTextures::table1);
	glColor3f(0,1,0);
	Kitchen:: Cylinder(0.045 , 0.005 , 0.005, false , true);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.055 , -0.06 , 0.);
	glRotated(90 , 1 , 0 , 0);
	glBindTexture(GL_TEXTURE_2D ,ProjectTextures:: cloast);
	glBindTexture(GL_TEXTURE_2D , ProjectTextures::table1);
	glColor3f(0,1,0);
	Kitchen:: Cylinder(0.045 , 0.005 , 0.005, false , true);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.055 , -0.015 , 0.);
	glRotated(90 , 0 , 1 , 0);
	glBindTexture(GL_TEXTURE_2D , ProjectTextures::cloast);
	glBindTexture(GL_TEXTURE_2D ,ProjectTextures:: table1);
	glColor3f(0,1,0);
	Kitchen:: Cylinder(0.045 , 0.005 , 0.005, false , true);
	glPopMatrix();
	glPopMatrix();

	glPopMatrix();


	////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////
		
	//table1
	//side
	glPushMatrix();
	glTranslated(0 , 0 , -0.5);
	glPushMatrix();
	glTranslated(0.57 , -0.41 , -1.5);
	Kitchen:: table(0.4 , 0.4 , 0.03 );
	glPopMatrix();
	//side
	glPushMatrix();
	glTranslated(0.57 , -0.41 , 0);
	Kitchen:: table(0.4 , 0.4 , 0.03 );
	glPopMatrix();
	//up
	glPushMatrix();
	glTranslated(0.57 , -0.23 , -0.77);
	glRotated(90 , 1 , 0 , 0);
	Kitchen:: tableT(1.54 , 0.4 , 0.03 );
	glPopMatrix();
	//front
	glPushMatrix();
	glTranslated(0.41 , -0.41 , -0.75);
	glRotated(90 , 0 , 1 , 0);
	Kitchen:: tableF(0.4 , 1 , 0.03 );
	glPopMatrix();
	//////////////////////////////////
	////////////////////////////////////////////////////////////
		//Dishes3
	glPushMatrix();
	glTranslated(0.45 , -0.175 , -1.18);
	glBindTexture(GL_TEXTURE_2D ,ProjectTextures:: cloast);
	glBindTexture(GL_TEXTURE_2D ,ProjectTextures:: table1);
	glColor3f(1,1,1);
	glRotated(-90 , 1 ,0 , 0);
	glCallList(dishListId);
	
	glTranslated(0 , 0 , 0.025);
	glCallList(dishListId);

	glTranslated(0 , 0 , 0.025);
	glCallList(dishListId);

	glTranslated(0 , 0 , 0.025);
	glCallList(dishListId);

	glTranslated(0 , 0 , 0.025);
	glCallList(dishListId);

	
	glPopMatrix();
	////////////////////////////////////


	//Dishes4
	glPushMatrix();
	glTranslated(0.55 , -0.175 , -0.9);
	glBindTexture(GL_TEXTURE_2D , ProjectTextures::cloast);
	glBindTexture(GL_TEXTURE_2D , ProjectTextures::table1);
	glColor3f(1,1,1);
	glRotated(-90 , 1 ,0 , 0);
	glCallList(dishListId);
	
	glTranslated(0 , 0 , 0.025);
	glCallList(dishListId);

	glTranslated(0 , 0 , 0.025);
	glCallList(dishListId);

	glTranslated(0 , 0 , 0.025);
	glCallList(dishListId);

	glTranslated(0 , 0 , 0.025);
	glCallList(dishListId);

	glTranslated(0 , 0 , 0.025);
	glCallList(dishListId);

	glTranslated(0 , 0 , 0.025);
	glCallList(dishListId);

	glTranslated(0 , 0 , 0.025);
	glCallList(dishListId);
	glTranslated(0 , 0 , 0.025);
	
	glPopMatrix();
	/////////////////////////////////////////////////////////////////////////////////
	//ÿ‰Ã—…
	glPushMatrix();
	glTranslated(0.6 , -0.1 , -0.5);
	glPushMatrix();
	glTranslated(0 , 0 , 0.);
	glBindTexture(GL_TEXTURE_2D , ProjectTextures::cloast);
	glBindTexture(GL_TEXTURE_2D , ProjectTextures::table1);
	glColor3f(1,0,0);
	glRotated(-90 , 1 ,0 , 0);
	Kitchen:: CylinderT(0.1 , 0.1 , 0.1, false , true);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0 , -0.03 , 0.1);
	glRotated(90 , 0 , 1 , 0);
	glBindTexture(GL_TEXTURE_2D ,ProjectTextures:: cloast);
	glBindTexture(GL_TEXTURE_2D , ProjectTextures::table1);
	glColor3f(0,1,0);
	Kitchen:: Cylinder(0.045 , 0.005 , 0.005, false , true);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0 , -0.03 , -0.1);
	glRotated(90 , 0 , 1 , 0);
	glBindTexture(GL_TEXTURE_2D ,ProjectTextures:: cloast);
	glBindTexture(GL_TEXTURE_2D ,ProjectTextures:: table1);
	glColor3f(0,1,0);
	Kitchen:: Cylinder(0.045 , 0.005 , 0.005, false , true);
	glPopMatrix();

	glPopMatrix();

	//////////////////////////////////
	//cup1
	glPushMatrix();
	glTranslated(0.5 , -0.13 , -0.1);

	glPushMatrix();
	glTranslated(0 , 0 , 0.);
	glBindTexture(GL_TEXTURE_2D ,ProjectTextures:: cloast);
	glBindTexture(GL_TEXTURE_2D ,ProjectTextures:: table1);
	glColor3f(0,1,0);
	glRotated(-90 , 1 ,0 , 0);
	Kitchen:: Cylinder(0.075 , 0.03 , 0.03, false , true);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.055 , -0.06 , 0.);
	glRotated(90 , 0 , 1 , 0);
	glBindTexture(GL_TEXTURE_2D , ProjectTextures::cloast);
	glBindTexture(GL_TEXTURE_2D , ProjectTextures::table1);
	glColor3f(0,1,0);
	Kitchen:: Cylinder(0.045 , 0.005 , 0.005, false , true);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.055 , -0.06 , 0.);
	glRotated(90 , 1 , 0 , 0);
	glBindTexture(GL_TEXTURE_2D , ProjectTextures::cloast);
	glBindTexture(GL_TEXTURE_2D , ProjectTextures::table1);
	glColor3f(0,1,0);
	Kitchen:: Cylinder(0.045 , 0.005 , 0.005, false , true);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.055 , -0.015 , 0.);
	glRotated(90 , 0 , 1 , 0);
	glBindTexture(GL_TEXTURE_2D ,ProjectTextures:: cloast);
	glBindTexture(GL_TEXTURE_2D , ProjectTextures::table1);
	glColor3f(0,1,0);
	Kitchen:: Cylinder(0.045 , 0.005 , 0.005, false , true);
	glPopMatrix();

	glPopMatrix();
	////////////////////////////////////////////////////////////
	
	//cup2
	glPushMatrix();
	glTranslated(0.63 , -0.13 , -0.1);

	glPushMatrix();
	glTranslated(0 , 0 , 0.);
	glBindTexture(GL_TEXTURE_2D ,ProjectTextures:: cloast);
	glBindTexture(GL_TEXTURE_2D , ProjectTextures::table1);
	glColor3f(0,1,0);
	glRotated(-90 , 1 ,0 , 0);
	Kitchen:: Cylinder(0.075 , 0.03 , 0.03, false , true);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.055 , -0.06 , 0.);
	glRotated(90 , 0 , 1 , 0);
	glBindTexture(GL_TEXTURE_2D , ProjectTextures::cloast);
	glBindTexture(GL_TEXTURE_2D , ProjectTextures::table1);
	glColor3f(0,1,0);
	Kitchen:: Cylinder(0.045 , 0.005 , 0.005, false , true);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.055 , -0.06 , 0.);
	glRotated(90 , 1 , 0 , 0);
	glBindTexture(GL_TEXTURE_2D ,ProjectTextures:: cloast);
	glBindTexture(GL_TEXTURE_2D ,ProjectTextures:: table1);
	glColor3f(0,1,0);
	Kitchen:: Cylinder(0.045 , 0.005 , 0.005, false , true);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.055 , -0.015 , 0.);
	glRotated(90 , 0 , 1 , 0);
	glBindTexture(GL_TEXTURE_2D ,ProjectTextures:: cloast);
	glBindTexture(GL_TEXTURE_2D ,ProjectTextures:: table1);
	glColor3f(0,1,0);
	Kitchen:: Cylinder(0.045 , 0.005 , 0.005, false , true);
	glPopMatrix();

	glPopMatrix();
	////////////////////////////////////////////////////////////
	//cup3
	glPushMatrix();
	glTranslated(0.63 , -0.13 , -0.25);

	glPushMatrix();
	glTranslated(0 , 0 , 0.);
	glBindTexture(GL_TEXTURE_2D ,ProjectTextures:: cloast);
	glBindTexture(GL_TEXTURE_2D ,ProjectTextures:: table1);
	glColor3f(0,1,0);
	glRotated(-90 , 1 ,0 , 0);
	Kitchen:: Cylinder(0.075 , 0.03 , 0.03, false , true);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.055 , -0.06 , 0.);
	glRotated(90 , 0 , 1 , 0);
	glBindTexture(GL_TEXTURE_2D , ProjectTextures::cloast);
	glBindTexture(GL_TEXTURE_2D ,ProjectTextures:: table1);
	glColor3f(0,1,0);
	Kitchen:: Cylinder(0.045 , 0.005 , 0.005, false , true);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.055 , -0.06 , 0.);
	glRotated(90 , 1 , 0 , 0);
	glBindTexture(GL_TEXTURE_2D ,ProjectTextures:: cloast);
	glBindTexture(GL_TEXTURE_2D ,ProjectTextures:: table1);
	glColor3f(0,1,0);
	Kitchen:: Cylinder(0.045 , 0.005 , 0.005, false , true);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.055 , -0.015 , 0.);
	glRotated(90 , 0 , 1 , 0);
	glBindTexture(GL_TEXTURE_2D , ProjectTextures::cloast);
	glBindTexture(GL_TEXTURE_2D , ProjectTextures::table1);
	glColor3f(0,1,0);
	Kitchen:: Cylinder(0.045 , 0.005 , 0.005, false , true);
	glPopMatrix();

	glPopMatrix();
	////////////////////////////////////////////////////////////
	//cup4
	glPushMatrix();
	glTranslated(0.50 , -0.13 , -0.25);

	glPushMatrix();
	glTranslated(0 , 0 , 0.);
	glBindTexture(GL_TEXTURE_2D , ProjectTextures::cloast);
	glBindTexture(GL_TEXTURE_2D , ProjectTextures::table1);
	glColor3f(0,1,0);
	glRotated(-90 , 1 ,0 , 0);
	Kitchen:: Cylinder(0.075 , 0.03 , 0.03, false , true);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.055 , -0.06 , 0.);
	glRotated(90 , 0 , 1 , 0);
	glBindTexture(GL_TEXTURE_2D , ProjectTextures::cloast);
	glBindTexture(GL_TEXTURE_2D , ProjectTextures::table1);
	glColor3f(0,1,0);
	Kitchen:: Cylinder(0.045 , 0.005 , 0.005, false , true);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.055 , -0.06 , 0.);
	glRotated(90 , 1 , 0 , 0);
	glBindTexture(GL_TEXTURE_2D ,ProjectTextures:: cloast);
	glBindTexture(GL_TEXTURE_2D , ProjectTextures::table1);
	glColor3f(0,1,0);
	Kitchen:: Cylinder(0.045 , 0.005 , 0.005, false , true);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.055 , -0.015 , 0.);
	glRotated(90 , 0 , 1 , 0);
	glBindTexture(GL_TEXTURE_2D , ProjectTextures::cloast);
	glBindTexture(GL_TEXTURE_2D ,ProjectTextures:: table1);
	glColor3f(0,1,0);
	Kitchen:: Cylinder(0.045 , 0.005 , 0.005, false , true);
	glPopMatrix();

	glPopMatrix();
	////////////////////////////////////////

	//table up
	glPushMatrix();
	glTranslated(0 , 0.8 , -0.19);
	glScalef(1 , 0.9 , 0.7);

	//side
	glPushMatrix();
	glTranslated(0.57 , -0.41 , -1.5);
	Kitchen:: table(0.4 , 0.4 , 0.03 );
	glPopMatrix();
	//side
	glPushMatrix();
	glTranslated(0.57 , -0.41 , 0);
	Kitchen:: table(0.4 , 0.4 , 0.03 );
	glPopMatrix();
	//up
	glPushMatrix();
	glTranslated(0.57 , -0.23 , -0.77);
	glRotated(90 , 1 , 0 , 0);
	Kitchen:: tableT(1.54 , 0.4 , 0.03 );
	glPopMatrix();

	//down
	glPushMatrix();
	glTranslated(0.57 , -0.62 , -0.77);
	glRotated(90 , 1 , 0 , 0);
	Kitchen:: tableT(1.54 , 0.4 , 0.03 );
	glPopMatrix();

	//front
	glPushMatrix();
	glTranslated(0.41 , -0.41 , -0.75);
	glRotated(90 , 0 , 1 , 0);
	Kitchen:: tableF(0.4 , 1 , 0.03 );
	glPopMatrix();

	glPopMatrix();

	//////////////////////////////////////////////
	//Dishes1
	
	glPushMatrix();
	glTranslated(0.5 , 0.29 , -0.35);
	glBindTexture(GL_TEXTURE_2D ,ProjectTextures:: cloast);
	glBindTexture(GL_TEXTURE_2D , ProjectTextures::table1);
	glColor3f(1,1,1);
	glRotated(-90 , 1 ,0 , 0);
	glCallList(dishListId);
	
	glTranslated(0 , 0 , 0.025);
	glCallList(dishListId);

	glTranslated(0 , 0 , 0.025);
	glCallList(dishListId);

	glTranslated(0 , 0 , 0.025);
	glCallList(dishListId);

	glTranslated(0 , 0 , 0.025);
	glCallList(dishListId);

	glTranslated(0 , 0 , 0.025);
	glCallList(dishListId);

	glTranslated(0 , 0 , 0.025);
	glCallList(dishListId);

	glTranslated(0 , 0 , 0.025);
	glCallList(dishListId);
	glTranslated(0 , 0 , 0.025);
	glCallList(dishListId);
	glTranslated(0 , 0 , 0.025);
	glCallList(dishListId);
	glTranslated(0 , 0 , 0.025);
	glCallList(dishListId);
	glTranslated(0 , 0 , 0.025);
	glCallList(dishListId);
	glPopMatrix();


	//Dishes2
	glPushMatrix();
	glTranslated(0.5 , 0.29 , -1.1);
	glBindTexture(GL_TEXTURE_2D ,ProjectTextures:: cloast);
	glBindTexture(GL_TEXTURE_2D , ProjectTextures::table1);
	glColor3f(1,1,1);
	glRotated(-90 , 1 ,0 , 0);
	glCallList(dishListId);
	
	glTranslated(0 , 0 , 0.025);
	glCallList(dishListId);

	glTranslated(0 , 0 , 0.025);
	glCallList(dishListId);

	glTranslated(0 , 0 , 0.025);
	glCallList(dishListId);

	glTranslated(0 , 0 , 0.025);
	glCallList(dishListId);

	glTranslated(0 , 0 , 0.025);
	glCallList(dishListId);

	glTranslated(0 , 0 , 0.025);
	glCallList(dishListId);

	glTranslated(0 , 0 , 0.025);
	glCallList(dishListId);
	glTranslated(0 , 0 , 0.025);
	glCallList(dishListId);
	glTranslated(0 , 0 , 0.025);
	glCallList(dishListId);
	glTranslated(0 , 0 , 0.025);
	glCallList(dishListId);
	glTranslated(0 , 0 , 0.025);
	glCallList(dishListId);
	glPopMatrix();

	glPopMatrix();
	////////////////////////////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////
	glPushMatrix();
	glTranslated(0 , 0 , 2);

	//table2
	//side
	glPushMatrix();
	glTranslated(0.57 , -0.41 , -1.5);
	Kitchen:: table(0.4 , 0.4 , 0.03 );
	glPopMatrix();
	//side
	glPushMatrix();
	glTranslated(0.57 , -0.41 , 0);
	Kitchen:: table(0.4 , 0.4 , 0.03 );
	glPopMatrix();
	//up
	glPushMatrix();
	glTranslated(0.57 , -0.23 , -0.77);
	glRotated(90 , 1 , 0 , 0);
	Kitchen:: tableT(1.54 , 0.4 , 0.03 );
	glPopMatrix();
	//front
	glPushMatrix();
	glTranslated(0.41 , -0.41 , -0.75);
	glRotated(90 , 0 , 1 , 0);
	Kitchen:: tableF(0.4 , 1 , 0.03 );
	glPopMatrix();
	//////////////////////////////////
	////////////////////////////////////////////////////////////
		//Dishes3
	glPushMatrix();
	glTranslated(0.45 , -0.175 , -1.18);
	glBindTexture(GL_TEXTURE_2D , ProjectTextures::cloast);
	glBindTexture(GL_TEXTURE_2D , ProjectTextures::table1);
	glColor3f(1,1,1);
	glRotated(-90 , 1 ,0 , 0);
	glCallList(dishListId);
	
	glTranslated(0 , 0 , 0.025);
	glCallList(dishListId);

	glTranslated(0 , 0 , 0.025);
	glCallList(dishListId);

	glTranslated(0 , 0 , 0.025);
	glCallList(dishListId);

	glTranslated(0 , 0 , 0.025);
	glCallList(dishListId);

	
	glPopMatrix();
	////////////////////////////////////


	//Dishes4
	glPushMatrix();
	glTranslated(0.55 , -0.175 , -0.9);
	glBindTexture(GL_TEXTURE_2D , ProjectTextures::cloast);
	glBindTexture(GL_TEXTURE_2D , ProjectTextures::table1);
	glColor3f(1,1,1);
	glRotated(-90 , 1 ,0 , 0);
	glCallList(dishListId);
	
	glTranslated(0 , 0 , 0.025);
	glCallList(dishListId);

	glTranslated(0 , 0 , 0.025);
	glCallList(dishListId);

	glTranslated(0 , 0 , 0.025);
	glCallList(dishListId);

	glTranslated(0 , 0 , 0.025);
	glCallList(dishListId);

	glTranslated(0 , 0 , 0.025);
	glCallList(dishListId);

	glTranslated(0 , 0 , 0.025);
	glCallList(dishListId);

	glTranslated(0 , 0 , 0.025);
	glCallList(dishListId);
	glTranslated(0 , 0 , 0.025);
	
	glPopMatrix();
	/////////////////////////////////////////////////////////////////////////////////
	//ÿ‰Ã—…
	glPushMatrix();
	glTranslated(0.6 , -0.1 , -0.5);
	glPushMatrix();
	glTranslated(0 , 0 , 0.);
	glBindTexture(GL_TEXTURE_2D ,ProjectTextures:: cloast);
	glBindTexture(GL_TEXTURE_2D , ProjectTextures::table1);
	glColor3f(1,0,0);
	glRotated(-90 , 1 ,0 , 0);
	Kitchen:: CylinderT(0.1 , 0.1 , 0.1, false , true);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0 , -0.03 , 0.1);
	glRotated(90 , 0 , 1 , 0);
	glBindTexture(GL_TEXTURE_2D ,ProjectTextures:: cloast);
	glBindTexture(GL_TEXTURE_2D ,ProjectTextures:: table1);
	glColor3f(0,1,0);
	Kitchen:: Cylinder(0.045 , 0.005 , 0.005, false , true);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0 , -0.03 , -0.1);
	glRotated(90 , 0 , 1 , 0);
	glBindTexture(GL_TEXTURE_2D , ProjectTextures::cloast);
	glBindTexture(GL_TEXTURE_2D ,ProjectTextures:: table1);
	glColor3f(0,1,0);
	Kitchen:: Cylinder(0.045 , 0.005 , 0.005, false , true);
	glPopMatrix();

	glPopMatrix();

	//////////////////////////////////
	//cup1
	glPushMatrix();
	glTranslated(0.5 , -0.13 , -0.1);

	glPushMatrix();
	glTranslated(0 , 0 , 0.);
	glBindTexture(GL_TEXTURE_2D , ProjectTextures::cloast);
	glBindTexture(GL_TEXTURE_2D ,ProjectTextures:: table1);
	glColor3f(0,1,0);
	glRotated(-90 , 1 ,0 , 0);
	Kitchen:: Cylinder(0.075 , 0.03 , 0.03, false , true);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.055 , -0.06 , 0.);
	glRotated(90 , 0 , 1 , 0);
	glBindTexture(GL_TEXTURE_2D , ProjectTextures::cloast);
	glBindTexture(GL_TEXTURE_2D , ProjectTextures::table1);
	glColor3f(0,1,0);
	Kitchen:: Cylinder(0.045 , 0.005 , 0.005, false , true);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.055 , -0.06 , 0.);
	glRotated(90 , 1 , 0 , 0);
	glBindTexture(GL_TEXTURE_2D , ProjectTextures::cloast);
	glBindTexture(GL_TEXTURE_2D ,ProjectTextures:: table1);
	glColor3f(0,1,0);
	Kitchen:: Cylinder(0.045 , 0.005 , 0.005, false , true);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.055 , -0.015 , 0.);
	glRotated(90 , 0 , 1 , 0);
	glBindTexture(GL_TEXTURE_2D ,ProjectTextures:: cloast);
	glBindTexture(GL_TEXTURE_2D , ProjectTextures::table1);
	glColor3f(0,1,0);
	Kitchen:: Cylinder(0.045 , 0.005 , 0.005, false , true);
	glPopMatrix();

	glPopMatrix();
	////////////////////////////////////////////////////////////
	
	//cup2
	glPushMatrix();
	glTranslated(0.63 , -0.13 , -0.1);

	glPushMatrix();
	glTranslated(0 , 0 , 0.);
	glBindTexture(GL_TEXTURE_2D , ProjectTextures::cloast);
	glBindTexture(GL_TEXTURE_2D , ProjectTextures::table1);
	glColor3f(0,1,0);
	glRotated(-90 , 1 ,0 , 0);
	Kitchen:: Cylinder(0.075 , 0.03 , 0.03, false , true);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.055 , -0.06 , 0.);
	glRotated(90 , 0 , 1 , 0);
	glBindTexture(GL_TEXTURE_2D , ProjectTextures::cloast);
	glBindTexture(GL_TEXTURE_2D , ProjectTextures::table1);
	glColor3f(0,1,0);
	Kitchen:: Cylinder(0.045 , 0.005 , 0.005, false , true);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.055 , -0.06 , 0.);
	glRotated(90 , 1 , 0 , 0);
	glBindTexture(GL_TEXTURE_2D , ProjectTextures::cloast);
	glBindTexture(GL_TEXTURE_2D , ProjectTextures::table1);
	glColor3f(0,1,0);
	Kitchen:: Cylinder(0.045 , 0.005 , 0.005, false , true);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.055 , -0.015 , 0.);
	glRotated(90 , 0 , 1 , 0);
	glBindTexture(GL_TEXTURE_2D ,ProjectTextures:: cloast);
	glBindTexture(GL_TEXTURE_2D , ProjectTextures::table1);
	glColor3f(0,1,0);
	Kitchen:: Cylinder(0.045 , 0.005 , 0.005, false , true);
	glPopMatrix();

	glPopMatrix();
	////////////////////////////////////////////////////////////
	//cup3
	glPushMatrix();
	glTranslated(0.63 , -0.13 , -0.25);

	glPushMatrix();
	glTranslated(0 , 0 , 0.);
	glBindTexture(GL_TEXTURE_2D , ProjectTextures::cloast);
	glBindTexture(GL_TEXTURE_2D ,ProjectTextures:: table1);
	glColor3f(0,1,0);
	glRotated(-90 , 1 ,0 , 0);
	Kitchen:: Cylinder(0.075 , 0.03 , 0.03, false , true);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.055 , -0.06 , 0.);
	glRotated(90 , 0 , 1 , 0);
	glBindTexture(GL_TEXTURE_2D , ProjectTextures::cloast);
	glBindTexture(GL_TEXTURE_2D , ProjectTextures::table1);
	glColor3f(0,1,0);
	Kitchen:: Cylinder(0.045 , 0.005 , 0.005, false , true);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.055 , -0.06 , 0.);
	glRotated(90 , 1 , 0 , 0);
	glBindTexture(GL_TEXTURE_2D , ProjectTextures::cloast);
	glBindTexture(GL_TEXTURE_2D , ProjectTextures::table1);
	glColor3f(0,1,0);
	Kitchen:: Cylinder(0.045 , 0.005 , 0.005, false , true);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.055 , -0.015 , 0.);
	glRotated(90 , 0 , 1 , 0);
	glBindTexture(GL_TEXTURE_2D , ProjectTextures::cloast);
	glBindTexture(GL_TEXTURE_2D , ProjectTextures::table1);
	glColor3f(0,1,0);
	Kitchen:: Cylinder(0.045 , 0.005 , 0.005, false , true);
	glPopMatrix();

	glPopMatrix();
	////////////////////////////////////////////////////////////
	//cup4
	glPushMatrix();
	glTranslated(0.50 , -0.13 , -0.25);

	glPushMatrix();
	glTranslated(0 , 0 , 0.);
	glBindTexture(GL_TEXTURE_2D , ProjectTextures::cloast);
	glBindTexture(GL_TEXTURE_2D , ProjectTextures::table1);
	glColor3f(0,1,0);
	glRotated(-90 , 1 ,0 , 0);
	Kitchen:: Cylinder(0.075 , 0.03 , 0.03, false , true);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.055 , -0.06 , 0.);
	glRotated(90 , 0 , 1 , 0);
	glBindTexture(GL_TEXTURE_2D ,ProjectTextures:: cloast);
	glBindTexture(GL_TEXTURE_2D , ProjectTextures::table1);
	glColor3f(0,1,0);
	Kitchen:: Cylinder(0.045 , 0.005 , 0.005, false , true);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.055 , -0.06 , 0.);
	glRotated(90 , 1 , 0 , 0);
	glBindTexture(GL_TEXTURE_2D , ProjectTextures::cloast);
	glBindTexture(GL_TEXTURE_2D , ProjectTextures::table1);
	glColor3f(0,1,0);
	Kitchen:: Cylinder(0.045 , 0.005 , 0.005, false , true);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.055 , -0.015 , 0.);
	glRotated(90 , 0 , 1 , 0);
	glBindTexture(GL_TEXTURE_2D , ProjectTextures::cloast);
	glBindTexture(GL_TEXTURE_2D ,ProjectTextures:: table1);
	glColor3f(0,1,0);
	Kitchen:: Cylinder(0.045 , 0.005 , 0.005, false , true);
	glPopMatrix();
	glPopMatrix();
	////////////////////////////////////////

	//table up
	glPushMatrix();
	glTranslated(0 , 0.8 , -0.19);
	glScalef(1 , 0.9 , 0.7);

	//side
	glPushMatrix();
	glTranslated(0.57 , -0.41 , -1.5);
	Kitchen:: table(0.4 , 0.4 , 0.03 );
	glPopMatrix();
	//side
	glPushMatrix();
	glTranslated(0.57 , -0.41 , 0);
	Kitchen:: table(0.4 , 0.4 , 0.03 );
	glPopMatrix();
	//up
	glPushMatrix();
	glTranslated(0.57 , -0.23 , -0.77);
	glRotated(90 , 1 , 0 , 0);
	Kitchen:: tableT(1.54 , 0.4 , 0.03 );
	glPopMatrix();

	//down
	glPushMatrix();
	glTranslated(0.57 , -0.62 , -0.77);
	glRotated(90 , 1 , 0 , 0);
	Kitchen:: tableT(1.54 , 0.4 , 0.03 );
	glPopMatrix();

	//front
	glPushMatrix();
	glTranslated(0.41 , -0.41 , -0.75);
	glRotated(90 , 0 , 1 , 0);
	Kitchen:: tableF(0.4 , 1 , 0.03 );
	glPopMatrix();

	glPopMatrix();

	//////////////////////////////////////////////
	//Dishes1
	
	glPushMatrix();
	glTranslated(0.5 , 0.29 , -0.35);
	glBindTexture(GL_TEXTURE_2D , ProjectTextures::cloast);
	glBindTexture(GL_TEXTURE_2D , ProjectTextures::table1);
	glColor3f(1,1,1);
	glRotated(-90 , 1 ,0 , 0);
	glCallList(dishListId);
	
	glTranslated(0 , 0 , 0.025);
	glCallList(dishListId);

	glTranslated(0 , 0 , 0.025);
	glCallList(dishListId);

	glTranslated(0 , 0 , 0.025);
	glCallList(dishListId);

	glTranslated(0 , 0 , 0.025);
	glCallList(dishListId);

	glTranslated(0 , 0 , 0.025);
	glCallList(dishListId);

	glTranslated(0 , 0 , 0.025);
	glCallList(dishListId);

	glTranslated(0 , 0 , 0.025);
	glCallList(dishListId);
	glTranslated(0 , 0 , 0.025);
	glCallList(dishListId);
	glTranslated(0 , 0 , 0.025);
	glCallList(dishListId);
	glTranslated(0 , 0 , 0.025);
	glCallList(dishListId);
	glTranslated(0 , 0 , 0.025);
	glCallList(dishListId);
	glPopMatrix();


	//Dishes2
	glPushMatrix();
	glTranslated(0.5 , 0.29 , -1.1);
	glBindTexture(GL_TEXTURE_2D , ProjectTextures::cloast);
	glBindTexture(GL_TEXTURE_2D ,ProjectTextures:: table1);
	glColor3f(1,1,1);
	glRotated(-90 , 1 ,0 , 0);
	glCallList(dishListId);
	
	glTranslated(0 , 0 , 0.025);
	glCallList(dishListId);

	glTranslated(0 , 0 , 0.025);
	glCallList(dishListId);

	glTranslated(0 , 0 , 0.025);
	glCallList(dishListId);

	glTranslated(0 , 0 , 0.025);
	glCallList(dishListId);

	glTranslated(0 , 0 , 0.025);
	glCallList(dishListId);

	glTranslated(0 , 0 , 0.025);
	glCallList(dishListId);

	glTranslated(0 , 0 , 0.025);
	glCallList(dishListId);
	glTranslated(0 , 0 , 0.025);
	glCallList(dishListId);
	glTranslated(0 , 0 , 0.025);
	glCallList(dishListId);
	glTranslated(0 , 0 , 0.025);
	glCallList(dishListId);
	glTranslated(0 , 0 , 0.025);
	glCallList(dishListId);
	glPopMatrix();

	glPopMatrix();
	////////////////////////////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////////////////////////////

	//////////////////////////////////////


	

	glPopMatrix();
}
void KitchenCar::draw(){
	if(hasLight)glEnable(GL_LIGHT1);

	TrainCar::draw();
	if(glIsEnabled( GL_LIGHT2))
		glDisable(GL_LIGHT2);
	glPushMatrix();
	//glPointSize(50);
	glTranslated(tx,ty,tz);//this will move the point to the center
	glScaled(scale,scale,scale);//this will translate it like the train car scale=4
	if(kitchenId<0){
		kitchenId=glGenLists(1);
		glNewList(kitchenId,GL_COMPILE);
		DrawKitchen();
		glEndList();
	}
	glCallList(kitchenId);
	glPopMatrix();
	if(hasLight)glDisable(GL_LIGHT1);
	glEnable(GL_LIGHT2);
}

KitchenCar::~KitchenCar(void)
{
}
