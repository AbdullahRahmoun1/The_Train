#include "Pawn.h"

Pawn::Pawn() {}
Pawn::Pawn(double length, double radius, bool firstplayer, bool isLive, double x, double y)
{
	this->length = length;
	this->radius = radius;
	this->firstplayer = firstplayer;
	this->x = x;
	this->y = y;
	this->isLive = isLive;
}

void Pawn::builder()
{
	glPushMatrix();
	if (firstplayer)
		glColor3d(0.7, 0.7, 0.7);
	else
		glColor3d(0.25, 0.25, 0.25);

	glTranslated(x, y, length);
	auxSolidSphere(0.8*radius);
	glTranslated(0, 0, -length / 2);

	glBegin(GL_TRIANGLE_FAN);
	glVertex3d(0, 0, -length / 2);
	for (float a = 0; a <= 6.4; a += 0.2)
	{
		glVertex3d(radius*cos(a), radius*sin(a), -length / 2);
	}
	glEnd();
	glBegin(GL_QUAD_STRIP);
	for (float a = 0; a <= 6.4; a += 0.2)
	{
		glVertex3d(0.2*radius*cos(a), 0.2*radius*sin(a), length / 2);
		glVertex3d(radius*cos(a), radius*sin(a), -length / 2);
	}
	glEnd();
	glColor3d(1, 1, 1);
	glPopMatrix();

}
void Pawn::dead()
{
	isLive = false;
}
void Pawn::revive()
{
	isLive = true;
}


Pawn::~Pawn()
{
}
