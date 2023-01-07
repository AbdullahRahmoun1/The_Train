#pragma once
#include "Point.h"
#include <glaux.h>
#include <windows.h>		// Header File For Windows
#include <gl\GL.h>			// Header File For The OpenGL32 Library
#include <gl\GLU.h>			// Header File For The GLu32 Library 
#include <gl\gl.h>			// Header File For The OpenGL32 Library
#include <gl\glu.h>			// Header File For The GLu32 Library
#include <texture.h>

class Chess
{
public:
	double size;
	static int chesstex;
		Point point[4];
	
		Chess(double size);
		void builder();
	Chess();
	~Chess();
};

