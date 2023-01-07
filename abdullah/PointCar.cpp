#include "PointCar.h"
#include <windows.h>		// Header File For Windows
#include <gl\gl.h>			// Header File For The OpenGL32 Library
#include <gl\glu.h>			// Header File For The GLu32 Library
#include <glaux.h>		// Header File For The Glaux Library
#include <texture.h>

PointCar::PointCar(void)
{
}
void PointCar::drawDecore(){
	glBegin(GL_POINTS);
}

PointCar::~PointCar(void)
{
}
