#pragma once
#include <windows.h>		// Header File For Windows
#include <gl\gl.h>			// Header File For The OpenGL32 Library
#include <gl\glu.h>			// Header File For The GLu32 Library
#include <glaux.h>		// Header File For The Glaux Library
#include <texture.h>
#include "Model_3DS.h"		// Header File For The Glaux Library
#include "GLTexture.h"		// Header File For The Glaux Library
	

class Environment
{
public:
	Environment(void);
	~Environment(void);
	static double tz;
	static void draw();
	static void initialize();
	static void translate(double z);

private:
	static void DrawRailRoad(int z);
	static void DrawHouse(int x, int y, int z, int house_front, int house_side, int house_roof);
	static void DrawCube(int x, int y, int z, int tex);
	static void DrawBuildings(int x);
	static void DrawHouses(int x);
	static void DrawFloor(int tr);
	static void DrawGrass();
	static void skybox2();
	static void skybox();
	static void drawBridgeWall(int x, int height);	
	static void drawBridgeUp(int x, int y);
	static void DrawSea();
	static void DrawTunnel(int tr);



};

