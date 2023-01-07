#pragma once
#include "BedRoomCar.h"
#include "TrainCar.h"
#include "ProjectTextures.h"
#include <windows.h>		// Header File For Windows
#include <gl\gl.h>			// Header File For The OpenGL32 Library
#include <gl\glu.h>			// Header File For The GLu32 Library
#include <glaux.h>		// Header File For The Glaux Library
#include <texture.h>


class BedRoomCar : public TrainCar
{
public:
	static double leftdoorangle , rightdoorangle  , leftdrawer , rightdrawer ;
	static bool openleftdoor , openrightdoor , openleftdrawer , openrightdrawer ;
	static bool keys[];
	static int bedRoomId;
	void draw();
	BedRoomCar(void);
	BedRoomCar(int nothing);
	void interactCloast();

	
	~BedRoomCar(void);


private:
	void BedRoom();
	class Board;
	class DrawObject;
	
class Board
{
		public:
			double width,length,thikness;
			double tx,ty,tz,anglex,angley,anglez,r,g,b;
			int texture;
			bool special;
			bool face[6];
			Board(){}
			Board(double width,double length,double thikness,bool special)
			{
				this->length = length;
				this->width = width;
				this->thikness = thikness;
				this->special = special;
				tx = 0;
				ty = 0;
				tz = 0;
				r  = 1;
				g  = 1;
				b  = 1;
				anglex = 0;
				angley = 0;
				anglez = 0;
				face[6] = (true,true,true,true,true,true);
			}
			void SetTexture(int texture)
			{
				this->texture = texture;
				glBindTexture(GL_TEXTURE_2D,texture);
			}
			void SetColor(double r,double g,double b)
			{
				this->r = r;
				this->g = g;
				this->b = b;
			}
			void Translate(double x,double y,double z)
			{
				tx = x;
				ty = y;
				tz = z;
			}
			void Rotate(double anglex,double angley,double anglez)
			{
				this->anglex = anglex;
				this->angley = angley;
				this->anglez = anglez;
			}
			void build()
			{
				glPushMatrix();
					glTranslated(tx,ty,tz);
					glRotated(anglex,1,0,0);
					glRotated(angley,0,1,0);
					glRotated(anglez,0,0,1);
					/*
						if you want each face to have a different texuture , you have to do Binding for each texture before every face 
					*/
					if(face[0])
					DrawQuad(length/2,width/2,0,true,false,false);                      // front
					if(face[1])
					DrawQuad(length/2,width/2,-thikness,true,false,false);               // back

					if(face[2])
					DrawQuad(-length/2,width/2,-thikness,false,true,false);              // left
					if(face[3])
					DrawQuad(length/2,width/2,-thikness,false,true,false);               // right

					if(face[4])
					DrawQuad(length/2,-width/2,-thikness,false,false,true);              // down
					if(face[5])
					DrawQuad(length/2,width/2,-thikness,false,false,true);               // up
				glPopMatrix();

			}
		private:
			void DrawQuad(double x,double y,double z,bool front_back,bool left_right,bool up_down)
			{
				double x1,x2,x3,x4,y1,y2,y3,y4,z1,z2,z3,z4;     
				/*
					if statements make the code smaller,
					each two faces have similar features
				*/
				if(front_back)
				{
					x1 = x4 = -x;
					x2 = x3 =  x;

					y1 = y2 = y;
					y3 = y4 = -y;

					z1 = z2 = z3 = z4 = z;
				}
				else if(left_right)
				{
					x1 = x2 = x3 = x4 = x;
						
					y1 = y2 =  y;
					y3 = y4 = -y;

					z1 = z4 = 0;
					z2 = z3 = z;
				}
				else
				{
					x1 = x2 = -x;
					x4 = x3 =  x;

					y1 = y2 = y3 = y4 = y;

					z1 = z4 = 0;
					z2 = z3 = z;
				}
				if(special)               // for the object which doesn't have a texture (only color)
					glColor3f(r,g,b);
				else
					glColor3f(1,1,1);     // to reset the base color of an object 

				glBegin(GL_QUADS);
					glTexCoord2f(0,0);
					glVertex3f(x1,y1,z1);

					glTexCoord2f(1,0);
					glVertex3f(x2,y2,z2);

					glTexCoord2f(1,1);
					glVertex3f(x3,y3,z3);

					glTexCoord2f(0,1);
					glVertex3f(x4,y4,z4);
				glEnd();
			}
		
};
class DrawObject
{
	public:

		static void BedBuild(int b1tex,int mattresstex,int pillowtex)
		{
			double baselength = 8 , basewidth = 3.5 , basethikness = 0.4;
			//________________________________________________board___________________________________________________________________________

			Board board1(baselength,basewidth,basethikness,false);
			board1.Rotate(90,0,0);
			board1.SetTexture(ProjectTextures::bedRoomB1tex);
			board1.build();
			//......................................................................
			board1.width = 2*basethikness;
			board1.length = baselength;
			board1.thikness = basethikness/2;
			board1.Rotate(0,90,0);
			board1.Translate(-basewidth/2,2*basethikness/2,0);
			board1.build();
			//......................................................................
			board1.Translate(basewidth/2 +basethikness/2,2*basethikness/2,0);
			board1.build();
			//......................................................................
			board1.length = basewidth;
			board1.width = 1.5*board1.width;
			board1.thikness = -basethikness/2;
			board1.Rotate(0,0,0);
			board1.Translate(0,2*basethikness/2,-baselength/2);
			board1.build();
			//......................................................................
			board1.length = basewidth;
			board1.width = 1.3*board1.width;
			board1.thikness = basethikness/2;
			board1.Translate(0,4*basethikness/2,baselength/2);
			board1.build();
			//________________________________________________stick___________________________________________________________________________

	
			Board stick1(2*basethikness,basethikness/2,basethikness/2,false);
			stick1.Translate(basewidth/2 + basethikness/4,-basethikness,baselength/2);
			stick1.SetTexture(ProjectTextures::bedRoomB1tex);
			stick1.build();
			//......................................................................
			stick1.ty = 2*basethikness;
			double t = stick1.width;
			stick1.width = 2.5*stick1.width;
			stick1.build();
			//......................................................................
			stick1.width = t;
			stick1.Translate(-basewidth/2 - basethikness/4,-basethikness,baselength/2);
			stick1.build();
			//......................................................................
			stick1.ty = 2*basethikness;
			stick1.width = 2.5*stick1.width;
			stick1.build();
			//......................................................................
			stick1.width = t;
			stick1.Translate(basewidth/2 + basethikness/4,-basethikness,-baselength/2 + basethikness/2);
			stick1.build();
			//......................................................................
			stick1.Translate(-basewidth/2 -basethikness/4,-basethikness,-baselength/2 + basethikness/2);
			stick1.build();

			//________________________________________________mattress________________________________________________________________________

			Board mattress(baselength-1.8*basethikness,basewidth-0.5*basethikness,0.6*board1.width,true);
			mattress.Rotate(90,0,0);
			mattress.SetTexture(mattresstex);
			mattress.SetColor(1,1,1);
			mattress.Translate(0,0.01,0);
			mattress.build();

			//_________________________________________________pillow_________________________________________________________________________

			Board pillow1(0.1*mattress.width,0.4*mattress.length,0.15*mattress.thikness,false);
			pillow1.Rotate(90,0,0);
			pillow1.SetTexture(pillowtex);
			pillow1.SetColor(1,1,1);
			pillow1.Translate(-mattress.length/4,mattress.thikness,0.4*mattress.width);
			pillow1.build();

			//......................................................................

			pillow1.tx = mattress.length/4;
			pillow1.build();
		}

		static void TableBuild()
		{
			double baselength = 5 , basewidth = 3 , basethikness = 0.5;




			Board board1(basewidth,baselength,basethikness,false);
			board1.Rotate(90,0,0);
			board1.SetTexture(ProjectTextures::bedRoomTable);
			board1.face[5] = false;
			board1.build();
			glPushMatrix();


			/*if(keys[VK_F3])
				openleftdrawer= true;
			if(keys[VK_F4])
				openleftdrawer = false;
*/
			if(BedRoomCar::openleftdrawer && leftdrawer<=basewidth/3.5)
				leftdrawer+=0.1;
			if(!openleftdrawer && leftdrawer>=0.01*basewidth)
				leftdrawer-=0.1;
			glTranslated(0,0,leftdrawer);

			Board board2(0.99*basewidth,0.49*baselength,0.95*basethikness,false);
			board2.Rotate(90,0,0);
			board2.Translate(-0.248*baselength,0.04*basethikness,0);
			board2.SetTexture(ProjectTextures::bedRoomTable);
			board2.face[1] = false;
			board2.build();


			glLineWidth(5);
			glTranslated(-0.248*baselength,0.5*basethikness,basewidth/2);
			glColor3f(0,0,0);
			glBegin(GL_LINE_STRIP);
			glVertex3d(-0.05*baselength,0,0);
			glVertex3d(-0.05*baselength,0,0.05);
			glVertex3d(0.05*baselength,0,0.05);
			glVertex3d(0.05*baselength,0,0);
			glEnd();
			glPopMatrix();

			glPushMatrix();

			/*if(keys[VK_F5])
				openrightdrawer= true;
			if(keys[VK_F6])
				openrightdrawer = false;*/

			if(openrightdrawer && rightdrawer<=basewidth/3.5)
				rightdrawer+=0.1;
			if(!openrightdrawer && rightdrawer>=0.01*basewidth)
				rightdrawer-=0.1;
			glTranslated(0,0,rightdrawer);

			board2.Translate(0.248*baselength,0.04*basethikness,0);
			board2.build();

			
			glTranslated(-0.248*baselength,0.5*basethikness,basewidth/2);

			glTranslated(0.496*baselength,0,0);
			glColor3d(0,0,0);
			glBegin(GL_LINE_STRIP);
			glVertex3d(-0.05*baselength,0,0);
			glVertex3d(-0.05*baselength,0,0.05);
			glVertex3d(0.05*baselength,0,0.05);
			glVertex3d(0.05*baselength,0,0);
			glEnd();
			glColor3f(1,1,1);
			glPopMatrix();
			//................................................................
			Board stick1(0.5*basewidth,basethikness/2,basethikness/2,false);
			stick1.Translate(baselength/2-basethikness/4,-1.001*0.5*basewidth/2,basewidth/2);
			stick1.SetTexture(ProjectTextures::bedRoomTable);
			stick1.build();

			stick1.Translate(-baselength/2+basethikness/4,-1.001*0.5*basewidth/2,basewidth/2);
			stick1.build();

			stick1.Translate(-baselength/2+basethikness/4,-1.001*0.5*basewidth/2,-basewidth/2+basethikness/2);
			stick1.build();

			stick1.Translate(+baselength/2-basethikness/4,-1.001*0.5*basewidth/2,-basewidth/2+basethikness/2);
			stick1.build();


		}

		static void ChairBuild()
		{
			double baselength = 1 , basewidth = 1 , basethikness = 0.2;

			Board board1(basewidth,baselength,0.5*basethikness,false);
			board1.Rotate(90,0,0);
			board1.SetTexture(ProjectTextures::bedRoomChair);
			board1.build();


			glPushMatrix();
			glTranslated(0,0.52*basethikness,0);
			board1.SetTexture(ProjectTextures::bedRoomMattresstex);
			board1.build();
			glPopMatrix();

			Board stick1(basewidth,basethikness/2,basethikness/2,false);
			stick1.Translate(baselength/2-basethikness/4,-1.001*basewidth/2,basewidth/2);
			stick1.SetTexture(ProjectTextures::bedRoomTable);
			stick1.build();

			

			stick1.Translate(-baselength/2+basethikness/4,-1.001*basewidth/2,basewidth/2);
			stick1.build();

			stick1.Translate(-baselength/2+basethikness/4,-1.001*basewidth/2,-basewidth/2+basethikness/2);
			stick1.build();

			stick1.Translate(+baselength/2-basethikness/4,-1.001*basewidth/2,-basewidth/2+basethikness/2);
			stick1.build();

			stick1.Translate(-baselength/2+basethikness/4,basewidth-3*basethikness/4,basewidth/2);
			stick1.width*=1.5;
			stick1.build();

			stick1.tx = baselength/2-basethikness/4 ;
			stick1.build();

			Board stick2(basethikness/2,baselength,basethikness/2,false);
			stick2.Translate(0,stick1.width/5,basewidth/2);
			stick2.SetTexture(ProjectTextures::bedRoomTable);
			stick2.build();

			stick2.ty += stick1.width/5; 
			stick2.build();

			stick2.ty += stick1.width/5; 
			stick2.build();

			stick2.ty += stick1.width/5; 
			stick2.build();

			stick2.ty += stick1.width/5; 
			stick2.build();


			
		}

		static void KeyBoardBuild(int texture,double width,double length,double thikness)
		{
			Board keyboard(width,length,thikness,false);
			keyboard.SetTexture(ProjectTextures::bedRoomBlack);
			keyboard.face[0] = false;
			keyboard.Rotate(-90,0,0);
			keyboard.build();

			keyboard.SetTexture(texture);
			keyboard.face[0] = true;
			keyboard.face[1] = false;
			keyboard.face[2] = false;
			keyboard.face[3] = false;
			keyboard.face[4] = false;
			keyboard.face[5] = false;
			keyboard.Rotate(90,0,0);
			keyboard.build();
		}

		static void ComputerScreenBuild(int screentex)
		{
			KeyBoardBuild(screentex,1.2,1.8,0.1);
		}

		static void RobicCubeBuild(double width)
		{
			Board robicCube(width,width,width,false);
			robicCube.SetTexture(ProjectTextures::bedRoomRobic);
			robicCube.build();
			
		}

		static void ClosetBuild()
		{
			double width = 5,length = 3,thikness = 1.5;
			Board closet(width,length,thikness,false);
			closet.SetTexture(ProjectTextures::bedRoomTable);
			closet.face[0] = false;
			closet.build();

			glPushMatrix();
		/*	if(keys[VK_F7])
				openleftdoor = true;
			if(keys[VK_F8])
				openleftdoor = false;
				*/

			glTranslated(-length/2,0,0);
			if(openleftdoor && leftdoorangle>=-90)
				leftdoorangle-=0.8;
			if(!openleftdoor && leftdoorangle<=0)
				leftdoorangle+=0.8;

			glRotated(leftdoorangle,0,1,0);

			closet.Translate(length/4,0,0);
			closet.length =length/2;
			closet.face[0] = true;
			closet.face[1] = false;
			closet.face[2] = false;
			closet.face[3] = false;
			closet.face[4] = false;
			closet.face[5] = false;
			closet.build();


			glLineWidth(5);
			glColor3f(0,0,0);
			glBegin(GL_LINE_STRIP);
			glVertex3d(3*length/8,width/20,0);
			glVertex3d(3*length/8,width/20,0.05);
			glVertex3d(3*length/8,-width/20,0.05);
			glVertex3d(3*length/8,-width/20,0);
			glEnd();

			glPopMatrix();

			glPushMatrix();
		/*	if(keys[VK_F2])
				openrightdoor = true;
			if(keys[VK_F1])
				openrightdoor = false;
				*/

			glTranslated(length/2,0,0);
			if(openrightdoor && rightdoorangle<=90)
				rightdoorangle+=0.8;
			if(!openrightdoor && rightdoorangle>=0)
				rightdoorangle-=0.8;

			glRotated(rightdoorangle,0,1,0);

			glBegin(GL_LINE_STRIP);
			glVertex3d(-3*length/8,width/20,0);
			glVertex3d(-3*length/8,width/20,0.05);
			glVertex3d(-3*length/8,-width/20,0.05);
			glVertex3d(-3*length/8,-width/20,0);
			glEnd();

			
			closet.Translate(-length/4,0,0);
			closet.build();

			glPopMatrix();
			
			glColor3f(1,1,1);


			closet.length = length;
			closet.face[0] = false;
			closet.face[5] = true;
			closet.Translate(0,-width/3,0);
			closet.build();

			glPushMatrix();
			glTranslated(length/4,width/6+0.13,-thikness/2);
			RobicCubeBuild(0.25);
			glTranslated(-length/2,0,0);
			RobicCubeBuild(0.25);
			glTranslated(length/4,0,0);
			KeyBoardBuild(ProjectTextures::bedRoomChess,thikness/2,thikness/2,0.12);
			glTranslated(-length/4,-width/3,0);
			RobicCubeBuild(0.25);
			glTranslated(length/2,0,0);
			RobicCubeBuild(0.25);
			glTranslated(-length/4,0,0);
			KeyBoardBuild(ProjectTextures::bedRoomChess,thikness/2,thikness/2,0.12);

			glPopMatrix();

			closet.Translate(0,-2*width/3,0);
			closet.SetTexture(ProjectTextures::bedRoomTable);
			closet.build();
		}

		static void WheelsBuild(double WheelRadius,double WheelThikness,double WheelDepth,double CylinderLength,double CylinderRadius)
		{
			glPushMatrix();
				WheelBuild(WheelRadius,WheelThikness,WheelDepth);
				glTranslated(0,0,-WheelDepth/2);
				CylinderBuild(CylinderLength,CylinderRadius);
				glTranslated(0,0,-CylinderLength);
				WheelBuild(WheelRadius,WheelThikness,WheelDepth);
			glPopMatrix();

		}


		static void Cylinder(double length,double radiusFront,double radiusBack,bool front,bool back)
		{
			glPushMatrix();
				glTranslated(0,0,-length/2);  // to move the center to the middle of cylinder (for rotation ....elc)
				glColor3d(0.6,0.6,0.6); 
				if(front)                     // front circle
				{
					glBegin(GL_TRIANGLE_FAN);
					glVertex3d(0,0,length/2);
					for(double a=0;a<=6.4;a+=0.2)
					{
						glVertex3d(radiusFront*cos(a),radiusFront*sin(a),length/2);
					}
					glEnd();
				}
				if(back)                     // back circle
				{
					glBegin(GL_TRIANGLE_FAN);
					glVertex3d(0,0,-length/2);
					for(double a=0;a<=6.4;a+=0.2)
					{
						glVertex3d(radiusBack*cos(a),radiusBack*sin(a),-length/2);
					}
					glEnd();
				}
				glBegin(GL_QUAD_STRIP);
					for(double a=0;a<=6.4;a+=0.2)
					{
						glVertex3d(radiusFront*cos(a),radiusFront*sin(a),length/2);
						glVertex3d(radiusBack*cos(a),radiusBack*sin(a),-length/2);
					}
					glEnd();
				glColor3d(1,1,1);
			glPopMatrix();

		}

	private:
		static void WheelBuild(double radius,double thikness,double depth)
		{
			glColor3d(0,0,0);
			glBegin(GL_QUAD_STRIP);
			for(double a=0;a<=6.4;a+=0.2)
			{
				glVertex3d(radius*cos(a),radius*sin(a),0);
				glVertex3d(radius*cos(a),radius*sin(a),-depth);

			}
			glEnd();
			glBegin(GL_QUAD_STRIP);
			for(double a=0;a<=6.4;a+=0.2)
			{
				glVertex3d((radius-thikness)*cos(a),(radius-thikness)*sin(a),0);
				glVertex3d((radius-thikness)*cos(a),(radius-thikness)*sin(a),-depth);

			}
			glEnd();
			glBegin(GL_QUAD_STRIP);
			for(double a=0;a<=6.4;a+=0.2)
			{
				glVertex3d((radius-thikness)*cos(a),(radius-thikness)*sin(a),0);
				glVertex3d((radius)*cos(a),(radius)*sin(a),0);

			}
			glEnd();
			glBegin(GL_QUAD_STRIP);
			for(double a=0;a<=6.4;a+=0.2)
			{
				glVertex3d((radius-thikness)*cos(a),(radius-thikness)*sin(a),-depth);
				glVertex3d((radius)*cos(a),(radius)*sin(a),-depth);

			}
			glEnd();
			glColor3d(0.5,0.5,0.5);
			glBegin(GL_TRIANGLE_FAN);
			glVertex3d(0,0,0);
			for(double a=0;a<=6.4;a+=0.2)
			{
				glVertex3d((radius-thikness)*cos(a),(radius-thikness)*sin(a),-depth/2);
			}
			glEnd();
			glColor3d(1,1,1);

		}

		static void CylinderBuild(double length,double radius)
		{
			glColor3d(0.2,0.2,0.2);
			glBegin(GL_QUAD_STRIP);
			for(double a=0;a<=6.4;a+=0.2)
			{
				glVertex3d(radius*cos(a),radius*sin(a),0);
				glVertex3d(radius*cos(a),radius*sin(a),-length);

			}
			glEnd();
			glColor3d(1,1,1);

		}

};

};


