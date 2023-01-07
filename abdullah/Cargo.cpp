#include "Cargo.h"
#include <windows.h>		// Header File For Windows
#include <gl\gl.h>			// Header File For The OpenGL32 Library
#include <gl\glu.h>			// Header File For The GLu32 Library
#include <glaux.h>		// Header File For The Glaux Library
#include <math.h>
#include <texture.h>

class Board
{
public:
	double width, length, thikness;
	double tx, ty, tz, anglex, angley, anglez, r, g, b;
	int texture;
	bool special;
	bool face[6];
	Board() {}
	Board(double width, double length, double thikness, bool special)
	{
		this->length = length;
		this->width = width;
		this->thikness = thikness;
		this->special = special;
		tx = 0;
		ty = 0;
		tz = 0;
		r = 1;
		g = 1;
		b = 1;
		anglex = 0;
		angley = 0;
		anglez = 0;
		face[6] = (true, true, true, true, true, true);
	}
	void SetTexture(int texture)
	{
		this->texture = texture;
		glBindTexture(GL_TEXTURE_2D, texture);
	}
	void SetColor(double r, double g, double b)
	{
		this->r = r;
		this->g = g;
		this->b = b;
	}
	void Translate(double x, double y, double z)
	{
		tx = x;
		ty = y;
		tz = z;
	}
	void Rotate(double anglex, double angley, double anglez)
	{
		this->anglex = anglex;
		this->angley = angley;
		this->anglez = anglez;
	}
	void build()
	{
		glPushMatrix();
		glTranslated(tx, ty, tz);
		glRotated(anglex, 1, 0, 0);
		glRotated(angley, 0, 1, 0);
		glRotated(anglez, 0, 0, 1);
		/*
		if you want each face to have a different texuture , you have to do Binding for each texture before every face
		*/
		if (face[0])
			DrawQuad(length / 2, width / 2, 0, true, false, false);                      // front
		if (face[1])
			DrawQuad(length / 2, width / 2, -thikness, true, false, false);               // back

		if (face[2])
			DrawQuad(-length / 2, width / 2, -thikness, false, true, false);              // left
		if (face[3])
			DrawQuad(length / 2, width / 2, -thikness, false, true, false);               // right

		if (face[4])
			DrawQuad(length / 2, -width / 2, -thikness, false, false, true);              // down
		if (face[5])
			DrawQuad(length / 2, width / 2, -thikness, false, false, true);               // up
		glPopMatrix();

	}
private:
	void DrawQuad(double x, double y, double z, bool front_back, bool left_right, bool up_down)
	{
		double x1, x2, x3, x4, y1, y2, y3, y4, z1, z2, z3, z4;
		/*
		if statements make the code smaller,
		each two faces have similar features
		*/
		if (front_back)
		{
			x1 = x4 = -x;
			x2 = x3 = x;

			y1 = y2 = y;
			y3 = y4 = -y;

			z1 = z2 = z3 = z4 = z;
		}
		else if (left_right)
		{
			x1 = x2 = x3 = x4 = x;

			y1 = y2 = y;
			y3 = y4 = -y;

			z1 = z4 = 0;
			z2 = z3 = z;
		}
		else
		{
			x1 = x2 = -x;
			x4 = x3 = x;

			y1 = y2 = y3 = y4 = y;

			z1 = z4 = 0;
			z2 = z3 = z;
		}
		if (special)               // for the object which doesn't have a texture (only color)
			glColor3f(r, g, b);
		else
			glColor3f(1, 1, 1);     // to reset the base color of an object 

		glBegin(GL_QUADS);
		glTexCoord2f(0, 0);
		glVertex3f(x1, y1, z1);

		glTexCoord2f(1, 0);
		glVertex3f(x2, y2, z2);

		glTexCoord2f(1, 1);
		glVertex3f(x3, y3, z3);

		glTexCoord2f(0, 1);
		glVertex3f(x4, y4, z4);
		glEnd();
	}

};

Cargo::Cargo()
{
}


Cargo::~Cargo()
{
}



void Cargo::drawBox(double length, double width, double thickness, int tex) {
	//double length = 2, width = 2, thickness = 2;
	Board b(length,width,thickness,false);
	b.SetTexture(tex);
	b.build();
	
}

void Cargo::drawWoods(double length, double width, double thickness, int tex) {
	Board b(length, width, thickness, false);
	b.SetTexture(tex);

	//-----------11111111111111111111111111---------------
	b.Translate(0, 0, 0);
	b.Rotate(-90, 0, -90);
	b.build();

	//----------222222222222222222222---------------
	b.Translate(1, 0, 0);
	b.build();

	//----------333333333333333333333333---------------
	b.Translate(0.5, 0.33, 0);
	b.Rotate(-90, 0, -80);
	b.build();

	//----------444444444444444444444444---------------
	b.Translate(0.7, 0.75, 0);
	b.Rotate(-87, -10, -95);
	b.build();


	//----------5555555555555555555555555---------------
	b.Translate(-0.6, 0.5, 0);
	b.Rotate(-85, -10, -93);
	b.build();
}

void Cargo::drawLadder(double l, double w, double t, int tex,int steptex) {

	Board leg(l, w, t, false);
	leg.SetTexture(tex);
	leg.build();

	leg.Translate(1.6, 0, 0);
	leg.build();

	//---------------------steps----------------

	Board step(0.2, 1.3, 0.2,false);
	step.SetTexture(steptex);
	step.Translate(0.8,-3.5,0);
	step.build();
	step.Translate(0.8, -2.5, 0);
	step.build();
	step.Translate(0.8, -1.5, 0);
	step.build();
	step.Translate(0.8, -0.5, 0);
	step.build();
	step.Translate(0.8, 0.5, 0);
	step.build();
	step.Translate(0.8, 1.5, 0);
	step.build();
	step.Translate(0.8, 2.5, 0);
	step.build();
	step.Translate(0.8, 3.5, 0);
	step.build();

	//---------------------downs----------------
	Board down(0.02, 0.3, 0.3, false);
	down.Translate(0, -4.5, 0);
	down.build();

	down.Translate(1.6, -4.5, 0);
	down.build();
}

void Cargo::drawArtpiece(double l, double w, double t, int tex, int pictex) {
	Board frame(l, w, t, false);
	frame.SetTexture(tex);
	
	frame.Translate(-w / 2 + 0.25, -w / 2 + 0.2, -0);
	frame.Rotate(0, 0, 270);
	frame.build();

	frame.Translate(+w / 2 - 0.25, -w / 2 + 0.2, -0);
	frame.Rotate(0, 0, 90);
	frame.build();

	frame.Translate(0, 0, 0);
	frame.Rotate(0, 0, 180);
	frame.build();

	frame.Translate(0, -w, 0);
	frame.Rotate(0, 0, 0);
	frame.build();

	//------------------the picture-=-------
	Board pic(w - w/5+0.5, w , 0, false);
	pic.SetTexture(pictex);
	pic.Rotate(0, 180, 180);
	pic.Translate(0, -w / 2, -t);
	pic.build();
}

void Cargo::drawCargo(int texa[]) {
	double baselength = 3.6, basewidth = 3.6, basethickness = 3.6;
	double percent = 0.7;

	//-----------first wall-----------------
	glPushMatrix();

	glPushMatrix();
	glTranslated(-4.5, -3.5, -18);
	drawBox(baselength, basewidth, basethickness, texa[0]);
	glPopMatrix();
	
	glPushMatrix();
	glTranslated(-5, -4.8, -10);
	glScaled(1.15, 1.15, 1.15);
	drawWoods(0.8, 12, 0.3, texa[2]);
	glPopMatrix();

	glTranslated(-4.6, -4, 1);
	glRotated(-10, 0, 1, 0);
	drawBox(baselength*percent, basewidth*percent, basethickness*percent, texa[1]);


	glTranslated(1.4, 0.7, 5);
	glRotated(20, 0, 1, 0);
	percent = 1.1;
	drawBox(baselength*percent, basewidth*percent, basethickness*percent, texa[1]);

	glScaled(1.1, 1.1, 1.1);
	glTranslated(-1.2, 0.68, 2.5);

	//fixx-------------------------fixx
	glRotated(10, 0, 1, 0);
	glRotated(-20, 0, 1, 0);
	//fixx-------------------------fixx


	glPushMatrix();
	glRotated(10, 0, 1, 0);
	glRotated(-60, 1, 0, 0);
	drawLadder(9, 0.3, 0.3, texa[3],texa[4]);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-1.4, 2.5, 8);
	glRotated(20, 0, 0, 1);
	glRotated(90, 0, 1, 0);
	drawArtpiece(0.5, 5, 0.15, texa[5], texa[6]);
	glPopMatrix();
	glPopMatrix();
	//------------second wall----------------

	glTranslated(4.8, -0.2, -20.6);

	glPushMatrix();
	glRotated(45, 0, 1, 0);
	glRotated(-15, 0, 0, 1);
	glRotated(-90, 0, 1, 0);
	drawArtpiece(0.5, 5, 0.15, texa[5], texa[7]);
	glPopMatrix();

	glTranslated(0.5, -0.7,5.4);

	glPushMatrix();
	glRotated(-15, 0, 0, 1);
	glRotated(-90, 0, 1, 0);
	drawLadder(9, 0.3, 0.3, texa[3], texa[4]);
	glPopMatrix();

	percent = 0.9;
	glTranslated(-0.2, -2.8, 6.5);
	drawBox(baselength*percent, basewidth*percent, basethickness*percent, texa[1]);

	percent = 0.8;

	glPushMatrix();
	glTranslated(0.1, 0, 3.6);
	drawBox(baselength*percent, basewidth*percent, basethickness*percent, texa[0]);
	glPopMatrix();

	percent = 0.7;
	glTranslated(0.2, 2.88, -0.4);
	glPushMatrix();
	glRotated(10, 0, 1, 0);
	drawBox(baselength*percent, basewidth*percent, basethickness*percent, texa[0]);
	glPopMatrix();

	glTranslated(0.1, -4, 24);
	glRotated(182, 0, 1, 0);
	glScaled(1.2, 1.2, 1.2);
	drawWoods(0.8, 12, 0.3, texa[2]);
}

