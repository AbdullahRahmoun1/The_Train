#pragma once
#include <windows.h>		// Header File For Windows
#include <gl\gl.h>			// Header File For The OpenGL32 Library
#include <gl\glu.h>			// Header File For The GLu32 Library
#include <glaux.h>		// Header File For The Glaux Library
#include <iostream>
#include <math.h>
#include <string>
#include <iostream>
#include <vector>
#include "Point2.h"
#include "Dimention.h"
#include "Wall.h"
#include "Door.h"
#include "Window.h"
#include "SideWall.h"
#include "MainDoor.h"
#include "Chair.h"
#include "ProjectTextures.h"
#include "TrainCar.h"
#include "PassengersCar.h"
#include "UltimateCamera.h"
#include "BedRoomCar.h"
#include "CargoCar.h"
#include "KitchenCar.h"
#include "Train.h"
#include "Environment.h"
#include "Player.h"
#include "DrivingCar.h"
#include "Point.h"
#include "Chess.h"
#include "Pawn.h"
#include "Step.h"
#include <stack>
std::stack <Step> steps;


HDC			hDC = NULL;		// Private GDI Device Context
HGLRC		hRC = NULL;		// Permanent Rendering Cntext
HWND		hWnd = NULL;		// Holds Our Window Handle
HINSTANCE	hInstance;		// Holds The Instance Of The Application

bool	keys[256];			// Array Used For The Keyboard Routine
bool	active = TRUE;		// Window Active Flag Set To TRUE By Default
bool	fullscreen = FALSE;	// Fullscreen Flag Set To Fullscreen Mode By Default

LRESULT	CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);	// Declaration For WndProc

GLvoid ReSizeGLScene(GLsizei width, GLsizei height)		// Resize And Initialize The GL Window
{
	if (height == 0)										// Prevent A Divide By Zero By
	{
		height = 1;										// Making Height Equal One
	}

	glViewport(0, 0, width, height);						// Reset The Current Viewport

	glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
	glLoadIdentity();									// Reset The Projection Matrix

														// Calculate The Aspect Ratio Of The Window
	gluPerspective(45.0f, (GLfloat)width / (GLfloat)height, 0.1f, 200000.0f);

	glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
	glLoadIdentity();									// Reset The Modelview Matrix
}



double mouseX, mouseY;
void keyBoard();

//------------------------------------------------------------------------------------------
GLfloat LightPos[] = { 50, 100 ,0}; 
GLfloat LightPos2[] = { 0, 10 ,0}; 

GLfloat LightAmb[] = { 0.5, 0.5, 0.5, 1.0f };
GLfloat LightDiff[] = { 0.8, 0.8, 0.8, 1.0f };
GLfloat LightSpec[] = { 0.5, 0.5, 0.5,1.0f }; 
 
 
GLfloat MatAmb[] = { 1.0f,1.0f,1.0f,1.0f }; 
GLfloat MatDif[] = { 0.6f,0.6f,0.6f,1.0f }; 
GLfloat MatSpec[] = { 0.2f,0.2f,0.2f,1.0f }; 
GLfloat MatShn[] = { 128.0f };

float m=0;
float ll = 0;
// start of chess game......................................................................................................................

int   test,winner1,winner2,back2;
bool firstplayer , secondplayer , endgame , firstwin , secondwin ,canStepBack ;
bool hasPawn[8][8];
int raw,column;
int stepBackCounter;

void initializer();



int InitGL(GLvoid)										// All Setup For OpenGL Goes Here
{
	glShadeModel(GL_SMOOTH);							// Enable Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.5f);				// Black Background
	glClearDepth(1.0f);									// Depth Buffer Setup
	glEnable(GL_DEPTH_TEST);							// Enables Depth Testing
	glDepthFunc(GL_LEQUAL);								// The Type Of Depth Testing To Do
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really Nice Perspective Calculations
	ShowCursor(FALSE);


		 glEnable(GL_LIGHTING); 
	 //glEnable(GL_NORMALIZE); 
	 glLightfv(GL_LIGHT1, GL_POSITION, LightPos); 
	 glLightfv(GL_LIGHT1, GL_AMBIENT, LightAmb); 
	 glLightfv(GL_LIGHT1, GL_DIFFUSE, LightDiff); 
	 glLightfv(GL_LIGHT1, GL_SPECULAR, LightSpec); 
 
	 glMaterialfv(GL_FRONT, GL_AMBIENT, MatAmb); 
	 glMaterialfv(GL_FRONT, GL_DIFFUSE, MatDif); 
	 glMaterialfv(GL_FRONT, GL_SPECULAR, MatSpec); 
	 glMaterialfv(GL_FRONT, GL_SHININESS, MatShn); 
  
	glLightfv(GL_LIGHT2, GL_POSITION, LightPos2); 
	glLightfv(GL_LIGHT2, GL_AMBIENT, LightAmb); 
	glLightfv(GL_LIGHT2, GL_DIFFUSE, LightDiff); 
	glLightfv(GL_LIGHT2, GL_SPECULAR, LightSpec); 
	glEnable(GL_LIGHT2);

	glEnable(GL_COLOR_MATERIAL);

	glEnable(GL_TEXTURE_2D);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
	ProjectTextures::initialize();
	Train::initialize();
	Environment::initialize();

	winner1 = LoadTexture("winner1.bmp",255);
	winner2 = LoadTexture("winner2.bmp",255);
	back2 = LoadTexture("back222.bmp",255);
	test = LoadTexture("test.bmp",255);
	initializer();
	
	PlaySound(TEXT("sounds/Train-Beginning.wav"), NULL, SND_ASYNC | SND_LOOP);
	return TRUE;										// Initialization Went OK
}




Pawn firstpawn[3],secondpawn[3];
void initializer()
{
	
	stepBackCounter = 3;

	firstplayer = true;
	secondplayer = false;

	endgame = false;
	
	canStepBack = false;

	firstwin = secondwin = false;


	for(int i=0;i<8;i++)
		for(int j=0;j<8;j++)
			hasPawn[i][j]=false;

	while(!steps.empty())
	{
		steps.pop();
	}

	int x1 = rand() % 8,x2,x3,x=0,xx=0,xxx=0;
	x2 = x1;
	while(x2==x1)
	{
		x2 = rand() % 8;
	}
	x3 = x2;
	while(x3==x2 || x3==x1)
	{
		x3 = rand() % 8;
	}
	
	if(x1>x2)
	{
		if(x1>x3)
		{
			xxx = x1;
			if(x3>x2)
			{
				xx = x3;
				x = x2;
			}
			else
			{
				xx = x2;
				x = x3;
			}
		}
		else
		{
			xxx = x3;
			xx = x1;
			x = x2;
		}
	}
	else
	{
		if(x2>x3)
		{
			xxx = x2;
			if(x1>x3)
			{
				xx = x1;
				x = x3;
			}
			else
			{
				xx = x3;
				x = x1;
			}
		}
		else
		{
			xxx = x3;
			xx = x2;
			x = x1;
		}
	}


	// first player 
		
	firstpawn[0] = Pawn(0.45,0.2,true,true,x,0);
	firstpawn[1] = Pawn(0.45,0.2,true,true,xx,0);
	firstpawn[2] = Pawn(0.45,0.2,true,true,xxx,0);


	x1 = rand() % 8;
	x2 = x1;
	while(x2==x1)
	{
		x2 = rand() % 8;
	}
	x3 = x2;
	while(x3==x2 || x3==x1)
	{
		x3 = rand() % 8;
	}
	
	if(x1>x2)
	{
		if(x1>x3)
		{
			xxx = x1;
			if(x3>x2)
			{
				xx = x3;
				x = x2;
			}
			else
			{
				xx = x2;
				x = x3;
			}
		}
		else
		{
			xxx = x3;
			xx = x1;
			x = x2;
		}
	}
	else
	{
		if(x2>x3)
		{
			xxx = x2;
			if(x1>x3)
			{
				xx = x1;
				x = x3;
			}
			else
			{
				xx = x3;
				x = x1;
			}
		}
		else
		{
			xxx = x3;
			xx = x2;
			x = x1;
		}
	}

	// second player

	secondpawn[0] = Pawn(0.45,0.2,false,true,x,7);
	secondpawn[1] = Pawn(0.45,0.2,false,true,xx,7);
	secondpawn[2] = Pawn(0.45,0.2,false,true,xxx,7);
}
void move()
{
	if(firstplayer)
	{
	
		if(keys[VK_F1] && firstpawn[0].isLive)
		{
			raw = firstpawn[0].y;
			column = firstpawn[0].x;
			if(raw<7 && column<7)
			{
				if(hasPawn[raw+1][column+1])
				{
					if(keys['E'] && !((column+1)==firstpawn[1].x && (raw+1)==firstpawn[1].y) && !((column+1)==firstpawn[2].x  && (raw+1)==firstpawn[2].y))
					{
						Step s;
						if(canStepBack)
						{
							s = Step(true,firstpawn[0].x,firstpawn[0].y,firstpawn[0].x+1,firstpawn[0].y+1,1);
						}
						firstpawn[0].x++;
						firstpawn[0].y++;
						hasPawn[raw][column] = false;
						firstplayer=false;
						secondplayer = true;
						if((column+1)==secondpawn[0].x && (raw+1)==secondpawn[0].y)
						{
							secondpawn[0].isLive = false;
							if(canStepBack)
								s.dead = 0;
						}
						else if((column+1)==secondpawn[1].x && (raw+1)==secondpawn[1].y)
						{
							secondpawn[1].isLive = false;
							if(canStepBack)
								s.dead = 1;
						}						
						else 
						{
							secondpawn[2].isLive = false;
							if(canStepBack)
								s.dead = 2;
						}
						steps.push(s);
						return;
					}
				}
				if(hasPawn[raw+1][column-1])
				{
					if(keys['Q'] && !((column-1)==firstpawn[1].x && (raw+1)==firstpawn[1].y) && !((column-1)==firstpawn[2].x  && (raw+1)==firstpawn[2].y))
					{
						Step s;
						if(canStepBack)
						{
							s = Step(true,firstpawn[0].x,firstpawn[0].y,firstpawn[0].x-1,firstpawn[0].y+1,1);
						}
						firstpawn[0].x--;
						firstpawn[0].y++;
						hasPawn[raw][column] = false;
						firstplayer=false;
						secondplayer = true;
						if((column-1)==secondpawn[0].x && (raw+1)==secondpawn[0].y)
						{
							secondpawn[0].isLive = false;
							if(canStepBack)
								s.dead = 0;
						}
						else if((column-1)==secondpawn[1].x && (raw+1)==secondpawn[1].y)
						{
							secondpawn[1].isLive = false;
							if(canStepBack)
								s.dead = 1;
						}
						else 
						{
							secondpawn[2].isLive = false;
							if(canStepBack)
								s.dead = 2;
						}
						steps.push(s);

						return;
					}
				}

			}
			//......................

			if(keys[VK_UP] && raw<7 && !hasPawn[raw+1][column])
			{
				if(canStepBack)
				{
					Step s = Step(true,firstpawn[0].x,firstpawn[0].y,firstpawn[0].x,firstpawn[0].y+1,1);
					steps.push(s);
				}
				firstpawn[0].y++;
				hasPawn[raw][column] = false;
				firstplayer=false;
				secondplayer = true;
				return;
			}
			if(keys[VK_RIGHT] && column<7 && !hasPawn[raw][column+1])
			{
				if(canStepBack)
				{
					Step s = Step(true,firstpawn[0].x,firstpawn[0].y,firstpawn[0].x+1,firstpawn[0].y,1);
					steps.push(s);
				}
				firstpawn[0].x++;
				hasPawn[raw][column] = false;
				firstplayer=false;
				secondplayer = true;
				return;
			}
			if(keys[VK_LEFT] && column>0 && !hasPawn[raw][column-1])
			{
				if(canStepBack)
				{
					Step s = Step(true,firstpawn[0].x,firstpawn[0].y,firstpawn[0].x-1,firstpawn[0].y,1);
					steps.push(s);
				}
				firstpawn[0].x--;
				hasPawn[raw][column] = false;
				firstplayer=false;
				secondplayer = true;
				return;
			}
		}
		if(keys[VK_F2] && firstpawn[1].isLive)
		{
			raw = (int) firstpawn[1].y;
			column = (int) firstpawn[1].x;
			if(raw<7 && column<7)
			{
				if(hasPawn[raw+1][column+1])
				{
					if(keys['E'] && !((column+1)==(int)firstpawn[0].x && (raw+1)==(int)firstpawn[0].y) && !((column+1)==(int)firstpawn[2].x  && (raw+1)==(int)firstpawn[2].y))
					{
						Step s;
						if(canStepBack)
						{
							s = Step(true,firstpawn[1].x,firstpawn[1].y,firstpawn[1].x+1,firstpawn[1].y+1,2);
						}
						firstpawn[1].x++;
						firstpawn[1].y++;
						hasPawn[raw][column] = false;
						firstplayer=false;
						secondplayer = true;
						if((column+1)==(int)secondpawn[0].x && (raw+1)==(int)secondpawn[0].y)
						{
							secondpawn[0].isLive = false;
							if(canStepBack)
								s.dead = 0;
						}
						else if((column+1)==(int)secondpawn[1].x && (raw+1)==(int)secondpawn[1].y)
						{
							secondpawn[1].isLive = false;
							if(canStepBack)
								s.dead = 1;
						}
						else 
						{
							secondpawn[2].isLive = false;
							if(canStepBack)
								s.dead = 2;
						}
						steps.push(s);

						return;
					}
				}
				if(hasPawn[raw+1][column-1])
				{
					if(keys['Q'] && !((column-1)==(int)firstpawn[0].x && (raw+1)==(int)firstpawn[0].y) && !((column-1)==(int)firstpawn[2].x  && (raw+1)==(int)firstpawn[2].y))
					{
						Step s;
						if(canStepBack)
						{
							s = Step(true,firstpawn[1].x,firstpawn[1].y,firstpawn[1].x-1,firstpawn[1].y+1,2);
						}
						firstpawn[1].x--;
						firstpawn[1].y++;
						hasPawn[raw][column] = false;
						firstplayer=false;
						secondplayer = true;
						if((column-1)==(int)secondpawn[0].x && (raw+1)==(int)secondpawn[0].y)
						{
							secondpawn[0].isLive = false;
							if(canStepBack)
								s.dead = 0;
						}
						else if((column-1)==(int)secondpawn[1].x && (raw+1)==(int)secondpawn[1].y)
						{
							secondpawn[1].isLive = false;
							if(canStepBack)
								s.dead = 1;
						}
						else 
						{
							secondpawn[2].isLive = false;
							if(canStepBack)
								s.dead = 2;
						}
						steps.push(s);

						return;
					}
				}
			}

			if(keys[VK_UP] && raw<7 && !hasPawn[raw+1][column])
			{
				if(canStepBack)
				{
					Step s = Step(true,firstpawn[1].x,firstpawn[1].y,firstpawn[1].x,firstpawn[1].y+1,2);
					steps.push(s);
				}
				firstpawn[1].y++;
				hasPawn[raw][column] = false;
				firstplayer=false;
				secondplayer = true;
				return;
			}
			if(keys[VK_RIGHT] && column<7 && !hasPawn[raw][column+1])
			{
				if(canStepBack)
				{
					Step s = Step(true,firstpawn[1].x,firstpawn[1].y,firstpawn[1].x+1,firstpawn[1].y,2);
					steps.push(s);
				}
				firstpawn[1].x++;
				hasPawn[raw][column] = false;
				firstplayer=false;
				secondplayer = true;
				return;
			}
			if(keys[VK_LEFT] && column>0 && !hasPawn[raw][column-1])
			{
				if(canStepBack)
				{
					Step s = Step(true,firstpawn[1].x,firstpawn[1].y,firstpawn[1].x-1,firstpawn[1].y,2);
					steps.push(s);
				}
				firstpawn[1].x--;
				hasPawn[raw][column] = false;
				firstplayer=false;
				secondplayer = true;
				return;
			}
		}
	
		if(keys[VK_F3] && firstpawn[2].isLive)
		{
			raw = (int) firstpawn[2].y;
			column = (int) firstpawn[2].x;
			if(raw<7 && column<7)
			{
				if(hasPawn[raw+1][column+1])
				{
					if(keys['E'] && !((column+1)==(int)firstpawn[0].x && (raw+1)==(int)firstpawn[0].y) && !((column+1)==(int)firstpawn[1].x && (raw+1)==(int)firstpawn[1].y))
					{
						Step s;
						if(canStepBack)
						{
							s = Step(true,firstpawn[2].x,firstpawn[2].y,firstpawn[2].x+1,firstpawn[2].y+1,3);
						}
						firstpawn[2].x++;
						firstpawn[2].y++;
						hasPawn[raw][column] = false;
						firstplayer=false;
						secondplayer = true;
						if((column+1)==(int)secondpawn[0].x && (raw+1)==(int)secondpawn[0].y)
						{
							secondpawn[0].isLive = false;
							if(canStepBack)
								s.dead = 0;
						}
						else if((column+1)==(int)secondpawn[1].x && (raw+1)==(int)secondpawn[1].y)
						{
							secondpawn[1].isLive = false;
							if(canStepBack)
								s.dead = 1;
						}
						else 
						{
							secondpawn[2].isLive = false;
							if(canStepBack)
								s.dead = 2;
						}
						steps.push(s);

						return;
					}
				}
				if(hasPawn[raw+1][column-1])
				{
					if(keys['Q'] && !((column-1)==(int)firstpawn[0].x && (raw+1)==(int)firstpawn[0].y) && !((column-1)==(int)firstpawn[1].x && (raw+1)==(int)firstpawn[1].y))
					{
						Step s;
						if(canStepBack)
						{
							s = Step(true,firstpawn[2].x,firstpawn[2].y,firstpawn[2].x-1,firstpawn[2].y+1,3);
						}
						firstpawn[2].x--;
						firstpawn[2].y++;
						hasPawn[raw][column] = false;
						firstplayer=false;
						secondplayer = true;
						if((column-1)==(int)secondpawn[0].x && (raw+1)==(int)secondpawn[0].y)
						{
							secondpawn[0].isLive = false;
							if(canStepBack)
								s.dead = 0;
						}
						else if((column-1)==(int)secondpawn[1].x && (raw+1)==(int)secondpawn[1].y)
						{
							secondpawn[1].isLive = false;
							if(canStepBack)
								s.dead = 1;
						}
						else 
						{
							secondpawn[2].isLive = false;
							if(canStepBack)
								s.dead = 2;
						}
						steps.push(s);

						return;
					}
				}
			}

			if(keys[VK_UP] && raw<7 && !hasPawn[raw+1][column])
			{
				if(canStepBack)
				{
					Step s = Step(true,firstpawn[2].x,firstpawn[2].y,firstpawn[2].x,firstpawn[2].y+1,3);
					steps.push(s);
				}
				firstpawn[2].y++;
				hasPawn[raw][column] = false;
				firstplayer=false;
				secondplayer = true;
				return;
			}
			if(keys[VK_RIGHT] && column<7 && !hasPawn[raw][column+1])
			{
				if(canStepBack)
				{
					Step s = Step(true,firstpawn[2].x,firstpawn[2].y,firstpawn[2].x+1,firstpawn[2].y,3);
					steps.push(s);
				}
				firstpawn[2].x++;
				hasPawn[raw][column] = false;
				firstplayer=false;
				secondplayer = true;
				return;
			}
			if(keys[VK_LEFT] && column>0 && !hasPawn[raw][column-1])
			{
				if(canStepBack)
				{
					Step s = Step(true,firstpawn[2].x,firstpawn[2].y,firstpawn[2].x-1,firstpawn[2].y,3);
					steps.push(s);
				}
				firstpawn[2].x--;
				hasPawn[raw][column] = false;
				firstplayer=false;
				secondplayer = true;
				return;
			}
		}
	}
	else
	{
		if(keys['1'] && secondpawn[0].isLive)
		{
			raw  = (int) secondpawn[0].y;
			column  = (int) secondpawn[0].x;
			if(raw>0 && column<7)
			{
				if(hasPawn[raw-1][column+1])
				{
					if(keys['E'] && !((column+1)==(int)secondpawn[1].x && (raw-1)==(int)secondpawn[1].y) && !((column+1)==(int)secondpawn[2].x && (raw-1)==(int)secondpawn[2].y))
					{
						Step s;
						if(canStepBack)
						{
							s = Step(false,secondpawn[0].x,secondpawn[0].y,secondpawn[0].x+1,secondpawn[0].y-1,1);
						}
						secondpawn[0].x++;
						secondpawn[0].y--;
						hasPawn[raw][column] = false;
						firstplayer=true;
						secondplayer = false;
						if((column+1)==(int)firstpawn[0].x && (raw-1)==(int)firstpawn[0].y)
						{
							firstpawn[0].isLive = false;
							if(canStepBack)
								s.dead = 0;
						}
						else if((column+1)==(int)firstpawn[1].x && (raw-1)==(int)firstpawn[1].y)
						{
							firstpawn[1].isLive = false;
							if(canStepBack)
								s.dead = 1;
						}
						else 
						{
							firstpawn[2].isLive = false;
							if(canStepBack)
								s.dead = 2;
						}
						steps.push(s);

						return;
					}
				}
				if(hasPawn[raw-1][column-1])
				{
					if(keys['Q'] && !((column-1)==(int)secondpawn[1].x && (raw-1)==(int)secondpawn[1].y) && !((column-1)==(int)secondpawn[2].x && (raw-1)==(int)secondpawn[2].y))
					{
						Step s;
						if(canStepBack)
						{
							s = Step(false,secondpawn[0].x,secondpawn[0].y,secondpawn[0].x-1,secondpawn[0].y-1,1);
						}
						secondpawn[0].x--;
						secondpawn[0].y--;
						hasPawn[raw][column] = false;
						firstplayer=true;
						secondplayer = false;
						if((column-1)==(int)firstpawn[0].x && (raw-1)==(int)firstpawn[0].y)
						{
							firstpawn[0].isLive = false;
							if(canStepBack)
								s.dead = 0;
						}
						else if((column-1)==(int)firstpawn[1].x && (raw-1)==(int)firstpawn[1].y)
						{
							firstpawn[1].isLive = false;
							if(canStepBack)
								s.dead = 1;
						}
						else 
						{
							firstpawn[2].isLive = false;
							if(canStepBack)
								s.dead = 2;
						}
						steps.push(s);

						return;
					}
				}
			}

			if(keys[VK_DOWN] && raw>0 && !hasPawn[raw-1][column])
			{
				if(canStepBack)
				{
					Step s = Step(false,secondpawn[0].x,secondpawn[0].y,secondpawn[0].x,secondpawn[0].y-1,1);
					steps.push(s);
				}
				secondpawn[0].y--;
				hasPawn[raw][column] = false;
				firstplayer=true;
				secondplayer = false;
				return;
			}
			if(keys[VK_RIGHT] && column<7 && !hasPawn[raw][column+1])
			{
				if(canStepBack)
				{
					Step s = Step(false,secondpawn[0].x,secondpawn[0].y,secondpawn[0].x+1,secondpawn[0].y,1);
					steps.push(s);
				}
				secondpawn[0].x++;
				hasPawn[raw][column] = false;
				firstplayer=true;
				secondplayer = false;
				return;
			}
			if(keys[VK_LEFT] && column>0 && !hasPawn[raw][column-1])
			{
				if(canStepBack)
				{
					Step s = Step(false,secondpawn[0].x,secondpawn[0].y,secondpawn[0].x-1,secondpawn[0].y,1);
					steps.push(s);
				}
				secondpawn[0].x--;
				hasPawn[raw][column] = false;
				firstplayer=true;
				secondplayer = false;
				return;
			}
		}

		if(keys['2'] && secondpawn[1].isLive)
		{
			raw  = (int) secondpawn[1].y;
			column  = (int) secondpawn[1].x;
			if(raw>0 && column<7)
			{
				if(hasPawn[raw-1][column+1])
				{
					if(keys['E'] && !((column+1)==(int)secondpawn[0].x && (raw-1)==(int)secondpawn[0].y) && !((column+1)==(int)secondpawn[2].x && (raw-1)==(int)secondpawn[2].y))
					{
						Step s;
						if(canStepBack)
						{
							s = Step(false,secondpawn[1].x,secondpawn[1].y,secondpawn[1].x+1,secondpawn[1].y-1,2);
						}
						secondpawn[1].x++;
						secondpawn[1].y--;
						hasPawn[raw][column] = false;
						firstplayer=true;
						secondplayer = false;
						if((column+1)==(int)firstpawn[0].x && (raw-1)==(int)firstpawn[0].y)
						{
							firstpawn[0].isLive = false;
							if(canStepBack)
								s.dead = 0;
						}
						else if((column+1)==(int)firstpawn[1].x && (raw-1)==(int)firstpawn[1].y)
						{
							firstpawn[1].isLive = false;
							if(canStepBack)
								s.dead = 1;
						}
						else 
						{
							firstpawn[2].isLive = false;
							if(canStepBack)
								s.dead = 2;
						}
						steps.push(s);

						return;
					}
				}
				if(hasPawn[raw-1][column-1])
				{
					if(keys['Q'] && !((column-1)==(int)secondpawn[0].x && (raw-1)==(int)secondpawn[0].y) && !((column-1)==(int)secondpawn[2].x && (raw-1)==(int)secondpawn[2].y))
					{
						Step s;
						if(canStepBack)
						{
							s = Step(false,secondpawn[1].x,secondpawn[1].y,secondpawn[1].x-1,secondpawn[1].y-1,2);
						}
						secondpawn[1].x--;
						secondpawn[1].y--;
						hasPawn[raw][column] = false;
						firstplayer=true;
						secondplayer = false;
						if((column-1)==(int)firstpawn[0].x && (raw-1)==(int)firstpawn[0].y)
						{
							firstpawn[0].isLive = false;
							if(canStepBack)
								s.dead = 0;
						}
						else if((column-1)==(int)firstpawn[1].x && (raw-1)==(int)firstpawn[1].y)
						{
							firstpawn[1].isLive = false;
							if(canStepBack)
								s.dead = 1;
						}
						else 
						{
							firstpawn[2].isLive = false;
							if(canStepBack)
								s.dead = 2;
						}
						steps.push(s);

						return;
					}
				}
			}

			if(keys[VK_DOWN] && raw>0 && !hasPawn[raw-1][column])
			{
				if(canStepBack)
				{
					Step s = Step(false,secondpawn[1].x,secondpawn[1].y,secondpawn[1].x,secondpawn[1].y-1,2);
					steps.push(s);
				}
				secondpawn[1].y--;
				hasPawn[raw][column] = false;
				firstplayer=true;
				secondplayer = false;
				return;
			}
			if(keys[VK_RIGHT] && column<7 && !hasPawn[raw][column+1])
			{
				if(canStepBack)
				{
					Step s = Step(false,secondpawn[1].x,secondpawn[1].y,secondpawn[1].x+1,secondpawn[1].y,2);
					steps.push(s);
				}
				secondpawn[1].x++;
				hasPawn[raw][column] = false;
				firstplayer=true;
				secondplayer = false;
				return;
			}
			if(keys[VK_LEFT] && column>0 && !hasPawn[raw][column-1])
			{
				if(canStepBack)
				{
					Step s = Step(false,secondpawn[1].x,secondpawn[1].y,secondpawn[1].x-1,secondpawn[1].y,2);
					steps.push(s);
				}
				secondpawn[1].x--;
				hasPawn[raw][column] = false;
				firstplayer=true;
				secondplayer = false;
				return;
			}
		}

		if(keys['3'] && secondpawn[2].isLive)
		{
			raw  = (int) secondpawn[2].y;
			column  = (int) secondpawn[2].x;
			if(raw>0 && column<7)
			{
				if(hasPawn[raw-1][column+1])
				{
					if(keys['E'] && !((column+1)==(int)secondpawn[0].x && (raw-1)==(int)secondpawn[0].y) && !((column+1)==(int)secondpawn[1].x && (raw-1)==(int)secondpawn[1].y))
					{
						Step s;
						if(canStepBack)
						{
							s = Step(false,secondpawn[2].x,secondpawn[2].y,secondpawn[2].x+1,secondpawn[2].y-1,3);
						}
						secondpawn[2].x++;
						secondpawn[2].y--;
						hasPawn[raw][column] = false;
						firstplayer=true;
						secondplayer = false;
						if((column+1)==(int)firstpawn[0].x && (raw-1)==(int)firstpawn[0].y)
						{
							firstpawn[0].isLive = false;
							if(canStepBack)
								s.dead = 0;
						}
						else if((column+1)==(int)firstpawn[1].x && (raw-1)==(int)firstpawn[1].y)
						{
							firstpawn[1].isLive = false;
							if(canStepBack)
								s.dead = 1;
						}
						else 
						{
							firstpawn[2].isLive = false;
							if(canStepBack)
								s.dead = 2;
						}
						steps.push(s);

						return;
					}
				}
				if(hasPawn[raw-1][column-1])
				{
					if(keys['Q'] && !((column-1)==(int)secondpawn[0].x && (raw-1)==(int)secondpawn[0].y) && !((column-1)==(int)secondpawn[1].x && (raw-1)==(int)secondpawn[1].y))
					{
						Step s;
						if(canStepBack)
						{
							s = Step(false,secondpawn[2].x,secondpawn[2].y,secondpawn[2].x-1,secondpawn[2].y-1,3);
						}
						secondpawn[2].x--;
						secondpawn[2].y--;
						hasPawn[raw][column] = false;
						firstplayer=true;
						secondplayer = false;
						if((column-1)==(int)firstpawn[0].x && (raw-1)==(int)firstpawn[0].y)
						{
							firstpawn[0].isLive = false;
							if(canStepBack)
								s.dead = 0;
						}
						else if((column-1)==(int)firstpawn[1].x && (raw-1)==(int)firstpawn[1].y)
						{
							firstpawn[1].isLive = false;
							if(canStepBack)
								s.dead = 1;
						}
						else 
						{
							firstpawn[2].isLive = false;
							if(canStepBack)
								s.dead = 2;
						}
						steps.push(s);

						return;
					}
				}
			}

			if(keys[VK_DOWN] && raw>0 && !hasPawn[raw-1][column])
			{
				if(canStepBack)
				{
					Step s = Step(false,secondpawn[2].x,secondpawn[2].y,secondpawn[2].x,secondpawn[2].y-1,3);
					steps.push(s);
				}
				secondpawn[2].y--;
				hasPawn[raw][column] = false;
				firstplayer=true;
				secondplayer = false;
				return;
			}
			if(keys[VK_RIGHT] && column<7 && !hasPawn[raw][column+1])
			{
				if(canStepBack)
				{
					Step s = Step(false,secondpawn[2].x,secondpawn[2].y,secondpawn[2].x+1,secondpawn[2].y,3);
					steps.push(s);
				}
				secondpawn[2].x++;
				hasPawn[raw][column] = false;
				firstplayer=true;
				secondplayer = false;
				return;
			}
			if(keys[VK_LEFT] && column>0 && !hasPawn[raw][column-1])
			{
				if(canStepBack)
				{
					Step s = Step(false,secondpawn[2].x,secondpawn[2].y,secondpawn[2].x-1,secondpawn[2].y,3);
					steps.push(s);
				}
				secondpawn[2].x--;
				hasPawn[raw][column] = false;
				firstplayer=true;
				secondplayer = false;
			}
		}
	} 
	
}
void DrawPawns()
{
	glBindTexture(GL_TEXTURE_2D,test);

	if(firstpawn[0].isLive)
	{
		firstpawn[0].builder();
		hasPawn[(int)firstpawn[0].y][(int)firstpawn[0].x] = true;
	}
	if(firstpawn[1].isLive)
	{
		firstpawn[1].builder();
		hasPawn[(int)firstpawn[1].y][(int)firstpawn[1].x] = true;

	}
	if(firstpawn[2].isLive)
	{
		firstpawn[2].builder();
		hasPawn[(int)firstpawn[2].y][(int)firstpawn[2].x] = true;

	}
	if(secondpawn[0].isLive)
	{
		secondpawn[0].builder();
		hasPawn[(int)secondpawn[0].y][(int)secondpawn[0].x] = true;

	}
	if(secondpawn[1].isLive)
	{
		

		secondpawn[1].builder();
		hasPawn[(int)secondpawn[1].y][(int)secondpawn[1].x] = true;
		 
	}
	if(secondpawn[2].isLive)
	{
		secondpawn[2].builder();
		hasPawn[(int)secondpawn[2].y][(int)secondpawn[2].x] = true;
	}
	
}

void endGame()
{
	glColor3d(1,1,1);
	if(firstwin)
		glBindTexture(GL_TEXTURE_2D,winner1);
	else
		glBindTexture(GL_TEXTURE_2D,winner2);

	glBegin(GL_QUADS);
		glTexCoord2d(0,1);
		glVertex2d(-6,4);
		glTexCoord2d(1,1);
		glVertex2d(6,4);
		glTexCoord2d(1,0);
		glVertex2d(6,-4);
		glTexCoord2d(0,0);
		glVertex2d(-6,-4);
	glEnd();
}

void checkIfEnd()
{
	if((!firstpawn[0].isLive && !firstpawn[1].isLive && !firstpawn[2].isLive) || secondpawn[0].y==0 || secondpawn[1].y==0 || secondpawn[2].y==0)
	{
		secondwin = true;
		endgame = true;
		return;
	}
	if((!secondpawn[0].isLive && !secondpawn[1].isLive && !secondpawn[2].isLive) || firstpawn[0].y==7 || firstpawn[1].y==7 || firstpawn[2].y==7)
	{
		firstwin = true;
		endgame = true;
	}
}

void playAgain()
{
	if(keys[VK_SPACE])
		initializer();
		
}

void player()
{
	glPushMatrix();
		if(firstplayer)
		{
			glTranslated(9,0.5,0);
			glColor3d(1,0,0);
			glBegin(GL_TRIANGLE_FAN);
			glVertex2d(0,0);
			for(double a=0;a<=6.3;a+=0.1)
				glVertex2d(0.5*cos(a),0.5*sin(a));
			glEnd();
			glColor3d(1,1,1);
		}
		else
		{
			glTranslated(9,6.5,0);
			glColor3d(0,1,0);
			glBegin(GL_TRIANGLE_FAN);
			glVertex2d(0,0);
			for(double a=0;a<=6.3;a+=0.1)
				glVertex2d(0.5*cos(a),0.5*sin(a));
			glEnd();
			glColor3d(1,1,1);

		}
	glPopMatrix();
}

void backTex()
{
	glPushMatrix();
		glTranslated(9,3.5,0);
		glBindTexture(GL_TEXTURE_2D,back2);
		glBegin(GL_QUADS);
			glTexCoord2d(0,1);
			glVertex2d(-0.5,0.5);
			glTexCoord2d(1,1);
			glVertex2d(0.5,0.5);
			glTexCoord2d(1,0);
			glVertex2d(0.5,-0.5);
			glTexCoord2d(0,0);
			glVertex2d(-0.5,-0.5);
		glEnd();
	glPopMatrix();
}

void backStep()
{
	canStepBack = stepBackCounter>0;
	if(keys[VK_BACK] && !steps.empty() && canStepBack)
	{
		keys[VK_BACK] = false;
		stepBackCounter--;
		Step s = steps.top();
		steps.pop();
		if(s.firstPlayer)
		{
			if(s.pawnNumber==1)
			{
				firstpawn[0].x = s.x;
				firstpawn[0].y = s.y;
			}
			else if(s.pawnNumber==2)
			{
				firstpawn[1].x = s.x;
				firstpawn[1].y = s.y;
				
			}
			else
			{
				firstpawn[2].x = s.x;
				firstpawn[2].y = s.y;
			}

			if(s.dead != -1)
				secondpawn[s.dead].isLive = true;

			firstplayer = true;
			secondplayer = false;
			hasPawn[(int)s.newy][(int)s.newx] = false;
		}
		else
		{
			if(s.pawnNumber==1)
			{
				secondpawn[0].x = s.x;
				secondpawn[0].y = s.y;
			}
			else if(s.pawnNumber==2)
			{
				secondpawn[1].x = s.x;
				secondpawn[1].y = s.y;
			}
			else
			{
				secondpawn[2].x = s.x;
				secondpawn[2].y = s.y;
			}

			if(s.dead != -1)
				firstpawn[s.dead].isLive = true;

			firstplayer = false;
			secondplayer = true;
			hasPawn[(int)s.newy][(int)s.newx] = false;

		}
	}
}


void drawChess()
{
	glPushMatrix();
	glTranslatef(0, 0, -15);
	if(!endgame)
	{
		glPushMatrix();
			Chess c = Chess(8);
			c.builder();
			glTranslated(-3.5,-3.5,0);
			backTex();
			player();
			DrawPawns();
			move();
			backStep();
		glPopMatrix();
	}
	else
	    endGame();

	checkIfEnd();
	playAgain();
	glPopMatrix();
}



// end of chess game......................................................................................................................


bool playChess;     // for switching between chess and env

void DrawGLScene(GLvoid)									// Here's Where We Do All The Drawing
{
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	
	glLoadIdentity();	
	
	//---------- utils ----------------

	if(keys['N'])
	{
		playChess = !playChess;
	}

	if(playChess)
	{
		glEnable(GL_LIGHT1);     // for lightining the chess
		drawChess();
		glDisable(GL_LIGHT1);

	}
	else
	{
		UltimateCamera::mouseX = mouseX; 
	UltimateCamera::mouseY = mouseY;
	Train::interact(keys);
	if(keys[VK_TAB])UltimateCamera::firstPerson=true;
	if(keys[VK_SHIFT])UltimateCamera::firstPerson=false;
	if(UltimateCamera::firstPerson)
		UltimateCamera::cameraSitting(keys,hWnd);
	else keyBoard();
	Player::drawAndManage();
	//--------_____SCENE_____-----------
	if(true){
		glPushMatrix();
		glEnable(GL_LIGHT2);

		Environment::draw();
		if(keys['X'])
		{
			ll += 0.1;
		}
		if(keys['V'])
		{
			ll -= 0.1;
		}
		Environment::translate(ll);
		glPopMatrix();


		Train::draw();
	}
	}

	//SwapBuffers(hDC);
}
//handle keyboard and walking and camera!
float hAngle=3.14/2,walking=0;
Point2 eye=Point2(0,1.0,0),target=Point2(0,0.5,-10);
void keyBoard(){
	float plus=0.5,p=0.05;
	float y=eye.y,ty=target.y;
	if(keys['W']){
			eye.z-=plus/2.0 * 3;
			target.z-=plus/2.0 * 3;
			walking+=0.1;
			//y=eye.y+(abs(sin(walking))/12);
			//ty=target.y+(abs(sin(walking))/12);
	}
	if(keys['S']){
			eye.z+=plus/2.0*3;
			target.z+=plus/2.0*3;
			walking+=0.1;
	}
	if(keys['A']){
		eye.x-=plus*2;
		target.x-=plus*2;
	}
	if(keys['D']){
			eye.x+=plus*2;
			target.x+=plus*2;
	}
	if(keys['F']){
		eye.y+=plus;
		target.y+=plus;
	}
	if(keys['C']){
		eye.y-=plus;
		target.y-=plus;
	}
	if(keys['M']){
		Environment::translate(7.0);
	}

	if(keys[VK_UP]&& abs( target.y-eye.y+p)<4)
		target.y+=p;
	if(keys[VK_DOWN]&& abs( target.y-eye.y)<4)
		target.y-=p;
	if(keys[VK_RIGHT] ){
		hAngle-=p/2;
		target.x=eye.x+cos(hAngle);
		target.z=(eye.z-sin(hAngle));
		}
	if(keys[VK_LEFT] ){
		hAngle+=p/2;
		target.x=eye.x+cos(hAngle);
		target.z=(eye.z-sin(hAngle));
		}
	
	if(keys['F']){

	}
	if(keys['P']){
		Train::cCar1.closeDoors();
	}
	if(keys['K']){
		Train::cCar1.closeWindows();
	}
	if(keys['L']){
		Train::bCar1.openBackDoor();
	}
	
	
	
	gluLookAt(eye.x,y,eye.z,target.x,ty,target.z,0,1,0);	

}







GLvoid KillGLWindow(GLvoid)								// Properly Kill The Window
{
	if (fullscreen)										// Are We In Fullscreen Mode?
	{
		ChangeDisplaySettings(NULL, 0);					// If So Switch Back To The Desktop
		ShowCursor(TRUE);								// Show Mouse Pointer
	}

	if (hRC)											// Do We Have A Rendering Context?
	{
		if (!wglMakeCurrent(NULL, NULL))					// Are We Able To Release The DC And RC Contexts?
		{
			MessageBox(NULL, "Release Of DC And RC Failed.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		}

		if (!wglDeleteContext(hRC))						// Are We Able To Delete The RC?
		{
			MessageBox(NULL, "Release Rendering Context Failed.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		}
		hRC = NULL;										// Set RC To NULL
	}

	if (hDC && !ReleaseDC(hWnd, hDC))					// Are We Able To Release The DC
	{
		MessageBox(NULL, "Release Device Context Failed.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		hDC = NULL;										// Set DC To NULL
	}

	if (hWnd && !DestroyWindow(hWnd))					// Are We Able To Destroy The Window?
	{
		MessageBox(NULL, "Could Not Release hWnd.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		hWnd = NULL;										// Set hWnd To NULL
	}

	if (!UnregisterClass("OpenGL", hInstance))			// Are We Able To Unregister Class
	{
		MessageBox(NULL, "Could Not Unregister Class.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		hInstance = NULL;									// Set hInstance To NULL
	}
}

/*	This Code Creates Our OpenGL Window.  Parameters Are:					*
*	title			- Title To Appear At The Top Of The Window				*
*	width			- Width Of The GL Window Or Fullscreen Mode				*
*	height			- Height Of The GL Window Or Fullscreen Mode			*
*	bits			- Number Of Bits To Use For Color (8/16/24/32)			*
*	fullscreenflag	- Use Fullscreen Mode (TRUE) Or Windowed Mode (FALSE)	*/

BOOL CreateGLWindow(char* title, int width, int height, int bits, bool fullscreenflag)
{
	GLuint		PixelFormat;			// Holds The Results After Searching For A Match
	WNDCLASS	wc;						// Windows Class Structure
	DWORD		dwExStyle;				// Window Extended Style
	DWORD		dwStyle;				// Window Style
	RECT		WindowRect;				// Grabs Rectangle Upper Left / Lower Right Values
	WindowRect.left = (long)0;			// Set Left Value To 0
	WindowRect.right = (long)width;		// Set Right Value To Requested Width
	WindowRect.top = (long)0;				// Set Top Value To 0
	WindowRect.bottom = (long)height;		// Set Bottom Value To Requested Height

	fullscreen = fullscreenflag;			// Set The Global Fullscreen Flag

	hInstance = GetModuleHandle(NULL);				// Grab An Instance For Our Window
	wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;	// Redraw On Size, And Own DC For Window.
	wc.lpfnWndProc = (WNDPROC)WndProc;					// WndProc Handles Messages
	wc.cbClsExtra = 0;									// No Extra Window Data
	wc.cbWndExtra = 0;									// No Extra Window Data
	wc.hInstance = hInstance;							// Set The Instance
	wc.hIcon = LoadIcon(NULL, IDI_WINLOGO);			// Load The Default Icon
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);			// Load The Arrow Pointer
	wc.hbrBackground = NULL;									// No Background Required For GL
	wc.lpszMenuName = NULL;									// We Don't Want A Menu
	wc.lpszClassName = "OpenGL";								// Set The Class Name

	if (!RegisterClass(&wc))									// Attempt To Register The Window Class
	{
		MessageBox(NULL, "Failed To Register The Window Class.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;											// Return FALSE
	}

	if (fullscreen)												// Attempt Fullscreen Mode?
	{
		DEVMODE dmScreenSettings;								// Device Mode
		memset(&dmScreenSettings, 0, sizeof(dmScreenSettings));	// Makes Sure Memory's Cleared
		dmScreenSettings.dmSize = sizeof(dmScreenSettings);		// Size Of The Devmode Structure
		dmScreenSettings.dmPelsWidth = width;				// Selected Screen Width
		dmScreenSettings.dmPelsHeight = height;				// Selected Screen Height
		dmScreenSettings.dmBitsPerPel = bits;					// Selected Bits Per Pixel
		dmScreenSettings.dmFields = DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT;

		// Try To Set Selected Mode And Get Results.  NOTE: CDS_FULLSCREEN Gets Rid Of Start Bar.
		if (ChangeDisplaySettings(&dmScreenSettings, CDS_FULLSCREEN) != DISP_CHANGE_SUCCESSFUL)
		{
			// If The Mode Fails, Offer Two Options.  Quit Or Use Windowed Mode.
			if (MessageBox(NULL, "The Requested Fullscreen Mode Is Not Supported By\nYour Video Card. Use Windowed Mode Instead?", "GL template", MB_YESNO | MB_ICONEXCLAMATION) == IDYES)
			{
				fullscreen = FALSE;		// Windowed Mode Selected.  Fullscreen = FALSE
			}
			else
			{
				// Pop Up A Message Box Letting User Know The Program Is Closing.
				MessageBox(NULL, "Program Will Now Close.", "ERROR", MB_OK | MB_ICONSTOP);
				return FALSE;									// Return FALSE
			}
		}
	}

	if (fullscreen)												// Are We Still In Fullscreen Mode?
	{
		dwExStyle = WS_EX_APPWINDOW;								// Window Extended Style
		dwStyle = WS_POPUP;										// Windows Style
		ShowCursor(FALSE);										// Hide Mouse Pointer
	}
	else
	{
		dwExStyle = WS_EX_APPWINDOW | WS_EX_WINDOWEDGE;			// Window Extended Style
		dwStyle = WS_OVERLAPPEDWINDOW;							// Windows Style
	}

	AdjustWindowRectEx(&WindowRect, dwStyle, FALSE, dwExStyle);		// Adjust Window To True Requested Size

																	// Create The Window
	if (!(hWnd = CreateWindowEx(dwExStyle,							// Extended Style For The Window
		"OpenGL",							// Class Name
		title,								// Window Title
		dwStyle |							// Defined Window Style
		WS_CLIPSIBLINGS |					// Required Window Style
		WS_CLIPCHILDREN,					// Required Window Style
		0, 0,								// Window Position
		WindowRect.right - WindowRect.left,	// Calculate Window Width
		WindowRect.bottom - WindowRect.top,	// Calculate Window Height
		NULL,								// No Parent Window
		NULL,								// No Menu
		hInstance,							// Instance
		NULL)))								// Dont Pass Anything To WM_CREATE
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Window Creation Error.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	static	PIXELFORMATDESCRIPTOR pfd =				// pfd Tells Windows How We Want Things To Be
	{
		sizeof(PIXELFORMATDESCRIPTOR),				// Size Of This Pixel Format Descriptor
		1,											// Version Number
		PFD_DRAW_TO_WINDOW |						// Format Must Support Window
		PFD_SUPPORT_OPENGL |						// Format Must Support OpenGL
		PFD_DOUBLEBUFFER,							// Must Support Double Buffering
		PFD_TYPE_RGBA,								// Request An RGBA Format
		bits,										// Select Our Color Depth
		0, 0, 0, 0, 0, 0,							// Color Bits Ignored
		0,											// No Alpha Buffer
		0,											// Shift Bit Ignored
		0,											// No Accumulation Buffer
		0, 0, 0, 0,									// Accumulation Bits Ignored
		16,											// 16Bit Z-Buffer (Depth Buffer)  
		0,											// No Stencil Buffer
		0,											// No Auxiliary Buffer
		PFD_MAIN_PLANE,								// Main Drawing Layer
		0,											// Reserved
		0, 0, 0										// Layer Masks Ignored
	};

	if (!(hDC = GetDC(hWnd)))							// Did We Get A Device Context?
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Can't Create A GL Device Context.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if (!(PixelFormat = ChoosePixelFormat(hDC, &pfd)))	// Did Windows Find A Matching Pixel Format?
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Can't Find A Suitable PixelFormat.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if (!SetPixelFormat(hDC, PixelFormat, &pfd))		// Are We Able To Set The Pixel Format?
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Can't Set The PixelFormat.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if (!(hRC = wglCreateContext(hDC)))				// Are We Able To Get A Rendering Context?
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Can't Create A GL Rendering Context.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if (!wglMakeCurrent(hDC, hRC))					// Try To Activate The Rendering Context
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Can't Activate The GL Rendering Context.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	ShowWindow(hWnd, SW_SHOW);						// Show The Window
	SetForegroundWindow(hWnd);						// Slightly Higher Priority
	SetFocus(hWnd);									// Sets Keyboard Focus To The Window
	ReSizeGLScene(width, height);	
	ShowWindow(hWnd, SW_MAXIMIZE);
	// Set Up Our Perspective GL Screen

	if (!InitGL())									// Initialize Our Newly Created GL Window
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Initialization Failed.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	return TRUE;									// Success
}

LRESULT CALLBACK WndProc(HWND	hWnd,			// Handle For This Window
	UINT	uMsg,			// Message For This Window
	WPARAM	wParam,			// Additional Message Information
	LPARAM	lParam)			// Additional Message Information
{
	switch (uMsg)									// Check For Windows Messages
	{
	case WM_ACTIVATE:							// Watch For Window Activate Message
	{
		if (!HIWORD(wParam))					// Check Minimization State
		{
			active = TRUE;						// Program Is Active
		}
		else
		{
			active = FALSE;						// Program Is No Longer Active
		}

		return 0;								// Return To The Message Loop
	}

	case WM_SYSCOMMAND:							// Intercept System Commands
	{
		switch (wParam)							// Check System Calls
		{
		case SC_SCREENSAVE:					// Screensaver Trying To Start?
		case SC_MONITORPOWER:				// Monitor Trying To Enter Powersave?
			return 0;							// Prevent From Happening
		}
		break;									// Exit
	}

	case WM_CLOSE:								// Did We Receive A Close Message?
	{
		PostQuitMessage(0);						// Send A Quit Message
		return 0;								// Jump Back
	}

	case WM_KEYDOWN:							// Is A Key Being Held Down?
	{
		keys[wParam] = TRUE;					// If So, Mark It As TRUE
		return 0;								// Jump Back
	}

	case WM_KEYUP:								// Has A Key Been Released?
	{
		keys[wParam] = FALSE;					// If So, Mark It As FALSE
		return 0;								// Jump Back
	}

	case WM_SIZE:								// Resize The OpenGL Window
	{
		ReSizeGLScene(LOWORD(lParam), HIWORD(lParam));  // LoWord=Width, HiWord=Height
		return 0;								// Jump Back
	}
	case WM_MOUSEMOVE: 
	{ 
	  mouseX = (int)LOWORD(lParam); 
	  mouseY = (int)HIWORD(lParam); 
	  break; 
	 }
	}

	// Pass All Unhandled Messages To DefWindowProc
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE	hInstance,			// Instance
	HINSTANCE	hPrevInstance,		// Previous Instance
	LPSTR		lpCmdLine,			// Command Line Parameters
	int			nCmdShow)			// Window Show State
{
	MSG		msg;									// Windows Message Structure
	BOOL	done = FALSE;								// Bool Variable To Exit Loop

														// Ask The User Which Screen Mode They Prefer
														//if (MessageBox(NULL,"Would You Like To Run In Fullscreen Mode?", "Start FullScreen?",MB_YESNO|MB_ICONQUESTION)==IDNO)
	{
		fullscreen = FALSE;							// Windowed Mode
	}

	// Create Our OpenGL Window
	if (!CreateGLWindow("OpenGL template", 640, 480, 16, fullscreen))
	{
		return 0;									// Quit If Window Was Not Created
	}

	while (!done)									// Loop That Runs While done=FALSE
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))	// Is There A Message Waiting?
		{
			if (msg.message == WM_QUIT)				// Have We Received A Quit Message?
			{
				done = TRUE;							// If So done=TRUE
			}
			else									// If Not, Deal With Window Messages
			{
				TranslateMessage(&msg);				// Translate The Message
				DispatchMessage(&msg);				// Dispatch The Message
			}
		}
		else										// If There Are No Messages
		{
			// Draw The Scene.  Watch For ESC Key And Quit Messages From DrawGLScene()
			if (active)								// Program Active?
			{
				if (keys[VK_ESCAPE])				// Was ESC Pressed?
				{
					done = TRUE;						// ESC Signalled A Quit
				}
				else								// Not Time To Quit, Update Screen
				{
					DrawGLScene();					// Draw The Scene
					SwapBuffers(hDC);				// Swap Buffers (Double Buffering)
				}
			}

			if (keys[VK_F7])						// Is F1 Being Pressed?
			{
				keys[VK_F7] = FALSE;					// If So Make Key FALSE
				KillGLWindow();						// Kill Our Current Window
				fullscreen = !fullscreen;				// Toggle Fullscreen / Windowed Mode
														// Recreate Our OpenGL Window
				if (!CreateGLWindow("OpenGL template", 1920, 1080, 15.6, fullscreen))
				{
					return 0;						// Quit If Window Was Not Created
				}
			}
		}
	}

	// Shutdown
	KillGLWindow();									// Kill The Window
	return (msg.wParam);							// Exit The Program
}





