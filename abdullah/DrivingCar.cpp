#include "DrivingCar.h"


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

class mainTrain{
public:
	void static base(double length , double width , double thinkness ){
		Board boardIn (length , width , thinkness, false);
		boardIn.SetTexture(ProjectTextures::enginsTex);
		boardIn.build();
	}

	void static wall(double length , double width , double thinkness ){
		Board boardIn (length , width , thinkness, false);
		boardIn.SetTexture(ProjectTextures::wood);
		boardIn.build();
	}

	void static wall2(double length , double width , double thinkness ){
		Board boardIn (length , width , thinkness, false);
		boardIn.SetTexture(ProjectTextures::out2);
		boardIn.build();
	}

	void static control(double length , double width , double thinkness ){
		Board boardIn (length , width , thinkness, false);
		boardIn.SetTexture(ProjectTextures::out2);
		boardIn.build();
	}

	void static panel(double length , double width , double thinkness ){
		Board boardIn (length , width , thinkness, false);
		boardIn.SetTexture(ProjectTextures::control);
		boardIn.build();
	}

	void static foundation(double length , double width , double thinkness ){
		Board boardIn (length , width , thinkness, false);
		boardIn.SetTexture(ProjectTextures::out2);
		boardIn.build();
	}

	void static periodontal(double length , double width , double thinkness ){
		Board boardIn (length , width , thinkness, false);
		boardIn.SetTexture(ProjectTextures::out1);
		boardIn.build();
	}

	void static decore(double length , double width , double thinkness ){
		Board boardIn (length , width , thinkness, false);
		boardIn.SetTexture(ProjectTextures::out1);
		boardIn.build();
	}

	static void Cylinder(double length,double radiusFront,double radiusBack,bool front,bool back)
		{
			glPushMatrix();
				glTranslated(0,0,-length/2);  // to move the center to the middle of cylinder (for rotation ....elc)
				glColor3d(0,0,0); 
				if(front)                     // front circle
				{
					glBegin(GL_TRIANGLE_FAN);
					glColor3d(0,0,0);
					glVertex3d(0,0,length/2);
					for(double a=0;a<=6.8;a+=0.2)
					{
						glColor3d(0,0,0);
						glVertex3d(radiusFront*cos(a),radiusFront*sin(a),length/2);
					}
					glEnd();
				}
				if(back)                     // back circle
				{
					glBegin(GL_TRIANGLE_FAN);
					glColor3d(0,0,0);
					glVertex3d(0,0,-length/2);
					for(double a=0;a<=6.8;a+=0.2)
					{
						glColor3d(0,0,0);
						glVertex3d(radiusBack*cos(a),radiusBack*sin(a),-length/2);
					}
					glEnd();
				}
				glBegin(GL_QUAD_STRIP);
				glColor3d(0,0,0);
					for(double a=0;a<=6.8;a+=0.2)
					{
						glColor3d(0,0,0);
						glVertex3d(radiusFront*cos(a),radiusFront*sin(a),length/2);
						glVertex3d(radiusBack*cos(a),radiusBack*sin(a),-length/2);
					}
					glEnd();
			glPopMatrix();

		}

};
void foundations(){
	
	glPushMatrix();
	glTranslated(-0.799 ,0 ,2.6);
	//firs front door left
	mainTrain::foundation(1 , 0.1 , 0.1);

	glPushMatrix();
	glTranslated(0 , 0 , -2.5);
	//second back left
	mainTrain::foundation(1 , 0.1 , 0.1);
	glPopMatrix();


	glPopMatrix();

	glPushMatrix();
	glTranslated(1.6 , 0 , 0 );
	glPushMatrix();
	glTranslated(-0.799 ,0 ,2.6);
	//firs front door right
	mainTrain::foundation(1 , 0.1 , 0.1);

	glPushMatrix();
	glTranslated(0 , 0 , -2.5);
	//second back right
	mainTrain::foundation(1 , 0.1 , 0.1);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
}

void base(){
	//base
	glPushMatrix();
	glTranslated(0 ,-0.7 ,2.9);
	mainTrain::base(0.2 , 1.579 , 5.6);
	glPopMatrix();

	//ground
	glPushMatrix();
	glTranslated(0 ,-0.55 ,2.8);
	mainTrain::wall2(0.1 , 1.7 , 3);
	glPopMatrix();

	//floar
	glPushMatrix();
	glTranslated(0 ,0.6 ,2.6);
	mainTrain::wall2(0.2 , 2 , 2.7);
	glPopMatrix();
}

void frontWall (){
	glPushMatrix();
	glTranslated(0 ,0.3 ,2.6);
	mainTrain::wall(0.4 , 0.3 , 0.1);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.45 ,0,2.6);
	mainTrain::wall(1 , 0.6 , 0.1);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-0.45 ,0,2.6);
	mainTrain::wall(1 , 0.6 , 0.1);
	glPopMatrix();
}

void frontWallDecor(){
	glPushMatrix();
	glTranslated(0 ,0.3 ,2.61);
	mainTrain::decore(0.4 , 0.3 , 0.01);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.5 ,0,2.61);
	mainTrain::decore(1 , 0.7 , 0.01);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-0.5 ,0,2.601);
	mainTrain::decore(1 , 0.7 , 0.01);
	glPopMatrix();
}

void rightWallDecor(){
	glPushMatrix();
	glTranslated(-0.85 ,0 ,2.5);
	mainTrain::decore(1 , 0.01 , 0.5);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-0.85 ,0 ,1.55);
	mainTrain::decore(1 , 0.01 , 0.43);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-0.85 ,0 ,0.65);
	mainTrain::decore(1 , 0.01 , 0.6);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-0.85 ,-0.33 ,1.120);
	mainTrain::decore(0.35 , 0.01 , 0.469);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-0.85 ,0.33 ,1.120);
	mainTrain::decore(0.35 , 0.01 , 0.469);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0 , 0 , 0.9);

	glPushMatrix();
	glTranslated(-0.85 ,-0.33 ,1.120);
	mainTrain::decore(0.35 , 0.01 , 0.469);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-0.85 ,0.33 ,1.120);
	mainTrain::decore(0.35 , 0.005 , 0.469);
	glPopMatrix();
	
	glPopMatrix();
}

void leftWallDecor(){
	glPushMatrix();
	glTranslated(0.85 ,0 ,2.5);
	mainTrain::decore(1 , 0.01 , 0.5);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.85 ,0 ,1.55);
	mainTrain::decore(1 , 0.01 , 0.43);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.85 ,0 ,0.65);
	mainTrain::decore(1 , 0.01 , 0.6);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.85 ,-0.33 ,1.120);
	mainTrain::decore(0.35 , 0.01 , 0.469);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.85 ,0.33 ,1.120);
	mainTrain::decore(0.35 , 0.01 , 0.469);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0 , 0 , 0.9);

	glPushMatrix();
	glTranslated(0.85 ,-0.33 ,1.120);
	mainTrain::decore(0.35 , 0.01 , 0.469);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.85 ,0.33 ,1.120);
	mainTrain::decore(0.35 , 0.005 , 0.469);
	glPopMatrix();
	
	glPopMatrix();
}

void backWallDecor(){
	glPushMatrix();
	glTranslated(0 , 0 , -0.1  );
	mainTrain::decore(1 , 0.8  , 0.01);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.615 , -0.375 , -0.1  );
	mainTrain::decore(0.25 , 0.43 , 0.01);
	glPopMatrix();


	glPushMatrix();
	glTranslated(0.615 , 0.375 , -0.1 );
	mainTrain::decore(0.25 , 0.43 , 0.01);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-0.615 , -0.375 , -0.1  );
	mainTrain::decore(0.25 , 0.43 , 0.01);
	glPopMatrix();


	glPushMatrix();
	glTranslated(-0.615 , 0.375 , -0.1  );
	mainTrain::decore(0.25 , 0.43 , 0.01);
	glPopMatrix();
}

void decoration(){
	frontWallDecor();
	rightWallDecor();
	leftWallDecor();
	backWallDecor();
}

void rightWall(){
	glPushMatrix();
	glTranslated(-0.799 ,0 ,2.5);
	mainTrain::wall(1 , 0.1 , 0.5);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-0.799 ,0 ,1.55);
	mainTrain::wall(1 , 0.1 , 0.43);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-0.799 ,0 ,0.65);
	mainTrain::wall(1 , 0.1 , 0.6);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-0.799 ,-0.33 ,1.120);
	mainTrain::wall(0.35 , 0.1 , 0.469);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-0.799 ,0.33 ,1.120);
	mainTrain::wall(0.35 , 0.1 , 0.469);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0 , 0 , 0.9);

	glPushMatrix();
	glTranslated(-0.799 ,-0.33 ,1.120);
	mainTrain::wall(0.35 , 0.1 , 0.469);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-0.799 ,0.33 ,1.120);
	mainTrain::wall(0.35 , 0.1 , 0.469);
	glPopMatrix();
	
	glPopMatrix();
}

void leftWall(){
	glPushMatrix();
	glTranslated(1.6 , 0 , 0);

	glPushMatrix();
	glTranslated(-0.799 ,0 ,2.5);
	mainTrain::wall(1 , 0.1 , 0.5);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-0.799 ,0 ,1.55);
	mainTrain::wall(1 , 0.1 , 0.43);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-0.799 ,0 ,0.65);
	mainTrain::wall(1 , 0.1 , 0.6);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-0.799 ,-0.33 ,1.120);
	mainTrain::wall(0.35 , 0.1 , 0.469);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-0.799 ,0.33 ,1.120);
	mainTrain::wall(0.35 , 0.1 , 0.469);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0 , 0 , 0.9);

	glPushMatrix();
	glTranslated(-0.799 ,-0.33 ,1.120);
	mainTrain::wall(0.35 , 0.1 , 0.469);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-0.799 ,0.33 ,1.120);
	mainTrain::wall(0.35 , 0.1 , 0.469);
	glPopMatrix();
	
	glPopMatrix();

	glPopMatrix();
}

void backWall(){
	glPushMatrix();
	mainTrain::wall(1 , 0.8  , 0.1);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.615 , -0.375 , 0 );
	mainTrain::wall(0.25 , 0.43 , 0.1);
	glPopMatrix();


	glPushMatrix();
	glTranslated(0.615 , 0.375 , 0 );
	mainTrain::wall(0.25 , 0.43 , 0.1);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-0.615 , -0.375 , 0 );
	mainTrain::wall(0.25 , 0.43 , 0.1);
	glPopMatrix();


	glPushMatrix();
	glTranslated(-0.615 , 0.375 , 0 );
	mainTrain::wall(0.25 , 0.43 , 0.1);
	glPopMatrix();

}

void panel(){
	glPushMatrix();
	glTranslated(0 , -0.14, 0.22);
	glRotated( 30, 1 , 0 ,0);
	glPushMatrix();
	glRotated( 90, 0 , 1 ,0);
	mainTrain::panel(0.01 , 0.1  , 0.12);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.13 , -0.14, 0.22);
	glRotated( 30, 1 , 0 ,0);
	glPushMatrix();
	glRotated( 90, 0 , 1 ,0);
	mainTrain::panel(0.01 , 0.1  , 0.12);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-0.13 , -0.14, 0.22);
	glRotated( 30, 1 , 0 ,0);
	glPushMatrix();
	glRotated( 90, 0 , 1 ,0);
	mainTrain::panel(0.01 , 0.1  , 0.12);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-0.32 , -0.1, 0.25);
	glRotated( -30, 1 , 0 ,0);
	glPushMatrix();
	mainTrain::Cylinder(0.5 , 0.005  , 0.005 , true , true);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-0.3 , -0.1, 0.25);
	glRotated( 90, 0 , 1 ,0);
	glPushMatrix();
	mainTrain::Cylinder(0.05 , 0.005  , 0.005 , true , true);
	glPopMatrix();
	glPopMatrix();

	
};

void controlPanel(){
	glPushMatrix();
	glTranslated(0 , -0.3, 0.01);
	mainTrain::control(0.4 , 0.8  , 0.01);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0 , -0.35, 0.28);
	mainTrain::control(0.36 , 0.8  , 0.01);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0 , -0.1, 0.15);
	mainTrain::control(0.01 , 0.8  , 0.15);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0 , -0.175, 0.27);
	glRotated( 30, 1 , 0 ,0);
	mainTrain::control(0.01 , 0.8  , 0.15);
	glPopMatrix();

	panel();
}



void something(){
		glPushMatrix();
		glTranslated(0 ,-0.17 ,-0.1);
		mainTrain::wall2(0.6 , 0.8 , 0.2);
		glPopMatrix();

	glPushMatrix();
	glTranslated(-0.799 ,0 ,2.5);
	glPushMatrix();
	glTranslated(0 , 0 , -2.5);
	mainTrain::foundation(1 , 0.1 , 0.1);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.799 ,0 ,2.5);
	glPushMatrix();
	glTranslated(0 , 0 , -2.5);
	mainTrain::foundation(1 , 0.1 , 0.1);
	glPopMatrix();
	glPopMatrix();
}

void walls(){
	frontWall();
	rightWall();
	leftWall();
	backWall();
}

void frontOfMainTrain(){
	glPushMatrix();
	glTranslated(0 , -0.3 , -0.2);
	mainTrain::Cylinder( 2.5 , 0.4 , 0.4 , true , true);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.55 , -0.55 , -0.2);
	mainTrain::periodontal( 0.15 , 0.4 , 2.5);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-0.55 , -0.55 , -0.2);
	mainTrain::periodontal( 0.15 , 0.4 , 2.5);
	glPopMatrix();

}


void drawOldTrain(){
	base();
	foundations();
	walls();
	frontOfMainTrain();
	something();
	decoration();
	controlPanel();
}

DrivingCar::DrivingCar(int t){};
DrivingCar::DrivingCar(void) : TrainCar(true, true, 0.5)
{
	openDoors();
}
DrivingCar::~DrivingCar(void)
{
}
void DrivingCar::draw(){
	wheelsAngle+=0;
	glPushMatrix();
	glTranslated(tx,ty,tz);
	glScaled(scale,scale,scale);	
	drawOldTrain();
	drawWheels();
	glPopMatrix();
}
