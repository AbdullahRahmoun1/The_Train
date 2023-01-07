#include <glaux.h>
#include <windows.h>		// Header File For Windows
#include <math.h>
#include "UltimateCamera.h"
#include "Point2.h"
#include "Train.h"

UltimateCamera::UltimateCamera()
{
}


UltimateCamera::~UltimateCamera()
{
}

double UltimateCamera::walkX = 0; 
double UltimateCamera::walkZ = 0;
double UltimateCamera::breath = 0;
double UltimateCamera::turn = 0;
double UltimateCamera::updown = 0;
double UltimateCamera::height = 3.5;
bool UltimateCamera::moving=false;
bool UltimateCamera::firstPerson=true;
double UltimateCamera::screenX;
double UltimateCamera::screenY;
double UltimateCamera::mouseX = screenX;
double UltimateCamera::mouseY = screenY;

void UltimateCamera::cameraSitting(bool keys[], HWND hWnd) {


	//Before calling this function in DrawGLScene please copy this line to global
	//double walkX = 0, walkZ = 10, breath = 0, turn = 0, updown = 0, height = 1.1;
	//Human up and down walking simulation
	double r = 0.2*fabs(cos(breath));
	//variables for walking and looking front-back-right-left
	double tx = sin(turn);
	double tz = cos(turn);
	//variables for looking up and down
	double round = sin(updown);
	double fixX, fixZ;
	if (updown > 0) {
		fixZ = round*tz;
		fixX = round*tx;
	}
	else {
		fixZ = -round*tz;
		fixX = -round*tx;
	}
	//walking IFs
	moving=false;
	if (keys['W'] ) {
		if (Train::canCameraGoTo(walkX, height, walkZ - 0.1*tz)){
			walkZ -= 0.1*tz;
			moving=true;
		}
		if(Train::canCameraGoTo(walkX + 0.1*tx, height, walkZ)){
			moving=true;	
			walkX += 0.1*tx;
		}
	}
	if (keys['S']) {
		if(Train::canCameraGoTo(walkX, height, walkZ + 0.1*tz)){
			moving=true;
			walkZ += 0.1*tz;
		}
		if(Train::canCameraGoTo(walkX - 0.1*tx, height, walkZ)){
			walkX -= 0.1*tx;
			moving=true;
		}
	}
	if (keys['D']) {
		if (Train::canCameraGoTo(walkX, height, walkZ + 0.1*tx))
			walkZ += 0.1*tx;
		if (Train::canCameraGoTo(walkX + 0.1*tz, height, walkZ))
			walkX += 0.1*tz;
	}
	if (keys['A']) {
		if (Train::canCameraGoTo(walkX, height, walkZ - 0.1*tx))
			walkZ -= 0.1*tx;
		if (Train::canCameraGoTo(walkX - 0.1*tz, height, walkZ))
			walkX -= 0.1*tz;
	}
	
	RECT rect;
	if (GetWindowRect(hWnd, &rect))
	{
		screenX = rect.right - rect.left;
		screenY = rect.bottom - rect.top;
	}

	SetCursorPos(screenX / 2.0, screenY / 2.0 + 23);

	//looking UP to DOWN, Right to Left IFs
	if (keys[VK_RIGHT] || (mouseX > screenX / 2.0 + 3))
		turn += 0.12;
	if (keys[VK_LEFT] || (mouseX < screenX / 2.0 - 3))
		turn -= 0.12;
	if ((keys[VK_UP] || (mouseY < screenY / 2.0 - 3)) && round <= 0.99)
		updown += 0.07;
	if ((keys[VK_DOWN] || (mouseY > screenY / 2.0 + 3)) && round >= -0.99)
		updown -= 0.07;
	//go UP and Down IFs
	

	//Human up and down simulation IFs
	if (keys['A'] || keys['D'] || keys['W'] || keys['S'])
		breath += 0.1;
		
	//debugging look angle (not important)
	//gluLookAt(0,3.1,8, 0, 3.1, 0, 0, 1, 0);

	gluLookAt(
		walkX, height + r, walkZ,
		walkX + tx - fixX, height + round + r, walkZ - tz + fixZ,
		0, 1, 0);

	//glEnable(GL_POINT_SMOOTH);
	//glPointSize(50);
	//glBegin(GL_POINTS);
	//glColor3f(0, 1, 1);
	//glVertex3f(walkX + tx + -fixX, height + round + r, walkZ - tz + fixZ);
	//glColor3f(1, 0, 0);
	//glVertex3f(walkX , height + r, walkZ);
	//glEnd();


}
