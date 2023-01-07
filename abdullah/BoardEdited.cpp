#include <windows.h>		// Header File For Windows
#include <gl\gl.h>			// Header File For The OpenGL32 Library
#include <gl\glu.h>			// Header File For The GLu32 Library
#include <glaux.h>		// Header File For The Glaux Library
#include <math.h>
class Board
{
		public:
			float width,length,thikness;
			float tx,ty,tz,anglex,angley,anglez,r,g,b;
			int texture;
			bool special;
			bool face[6];
			Board(){}
			Board(float width,float length,float thikness,bool special)
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
			void SetColor(float r,float g,float b)
			{
				this->r = r;
				this->g = g;
				this->b = b;
			}
			void Translate(float x,float y,float z)
			{
				tx = x;
				ty = y;
				tz = z;
			}
			void Rotate(float anglex,float angley,float anglez)
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
			void DrawQuad(float x,float y,float z,bool front_back,bool left_right,bool up_down)
			{
				float x1,x2,x3,x4,y1,y2,y3,y4,z1,z2,z3,z4;     
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
