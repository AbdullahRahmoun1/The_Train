#pragma once
#include "Environment.h"
	int back, front, left, right, top, bottom;
	int wall, flooor, rooof, left_floor, out_tunnel, ground, grass, grass2, bridge, sea;
	int house_front, house_side, house_roof;
	int house_front2, house_side2, house_roof2;
	int house_front3, house_side3, house_roof3;
	int house_front5, house_side5, house_roof5;
	int building;
	int building2;
	int building3;
	int building4;
	int house_front6;
	int house_front7;
	int house_front8;
	int skybox_texture;
	Model_3DS tree;
	GLTexture leafTex, logTex;
	
double Environment::tz=0;
Environment::Environment(void)
{
}
void Environment::initialize(){
	wall = LoadTexture("Textures/realwall3.bmp",255);
	rooof = LoadTexture("Textures/roof22.bmp",255);
	flooor = LoadTexture("Textures/flooor_wide.bmp",255); // flooor1
	left_floor = LoadTexture("Textures/left_floor2.bmp",255);
	out_tunnel = LoadTexture("Textures/realoutwall.bmp",255);
	ground = LoadTexture("Textures/street_floor.bmp",255);
	grass = LoadTexture("Textures/bottomb2.bmp",255);
	grass2 = LoadTexture("Textures/grass5.bmp",255);
	sea = LoadTexture("Textures/sea4.bmp",255);
	bridge = LoadTexture("Textures/bridge2.bmp",255); // root6

	house_front = LoadTexture("Textures/house_front.bmp",255);
	house_side = LoadTexture("Textures/house_side.bmp",255);
	house_roof = LoadTexture("Textures/house_roof.bmp",255);


	house_front2 = LoadTexture("Textures/house_front10.bmp",255);
	house_side2 = LoadTexture("Textures/house_side10.bmp",255);
	house_roof2 = LoadTexture("Textures/house_roof10.bmp",255);


	house_front3 = LoadTexture("Textures/house_front4.bmp",255);
	house_side3 = LoadTexture("Textures/house_side3.bmp",255);
	house_roof3 = LoadTexture("Textures/house_roof.bmp",255);

	house_front5 = LoadTexture("Textures/house_front5.bmp",255);
	house_side5 = LoadTexture("Textures/house_side5.bmp",255);
	house_roof5 = LoadTexture("Textures/house_roof5.bmp",255);

	house_front6 = LoadTexture("Textures/house_front6.bmp",255);
	house_front7 = LoadTexture("Textures/house_front7.bmp",255);
	house_front8 = LoadTexture("Textures/house_front8.bmp",255);

	building = LoadTexture("Textures/buildingatnight.bmp",255);
	building2 = LoadTexture("Textures/building2.bmp",255);
	building3 = LoadTexture("Textures/building3.bmp",255);
	building4 = LoadTexture("Textures/building4.bmp",255);



	back = LoadTexture("Textures/back3.bmp",255);
	front = LoadTexture("Textures/front3.bmp",255);
	left = LoadTexture("Textures/left3.bmp",255);
	right = LoadTexture("Textures/right3.bmp",255);
	top = LoadTexture("Textures/top3.bmp",255);
	bottom = LoadTexture("Textures/bottom3.bmp",255);

	skybox_texture = LoadTexture("Textures/skybox3.bmp",255);
	tree.Load("data//M_TREE5.3DS");
	leafTex.LoadBMP("data//leaf.bmp");
	logTex.LoadBMP("data//log.bmp");
	tree.Materials[0].tex = logTex;
	tree.Materials[1].tex = leafTex;


}
void Environment::translate(double z){
	tz+=z;
}
void Environment::draw(){
	glPushMatrix();
	skybox2();
	glPopMatrix();

	if(tz > 8000)
	{
		tz= -1000;
	}

	//Keyboard();
	glPushMatrix();
	glTranslated(0,0,tz);
	DrawTunnel(+1500);
	DrawGrass();
	DrawTunnel(-1500);
	DrawSea();
	DrawTunnel(-4500);
	DrawFloor(-5750);
	DrawTunnel(-7500);
	glPopMatrix();

}
void Environment:: DrawRailRoad(int z)
{
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, flooor);
	
	glBegin(GL_QUADS); //Floor center 
	glTexCoord2d(0, 0);
	glVertex3d(3, 0, 0);
	glTexCoord2d(0, 20);
	glVertex3d(3, 0, z);
	glTexCoord2d(1, 20);
	glVertex3d(12, 0, z);
	glTexCoord2d(1, 0);
	glVertex3d(12, 0, 0);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, left_floor);

	glBegin(GL_QUADS); //Floor left 
	glTexCoord2d(0, 0);
	glVertex3d(0, 0.00, 0);
	glTexCoord2d(0, 50);
	glVertex3d(0, 0.00, z);
	glTexCoord2d(0.25, 50);
	glVertex3d(3, 0.00, z);
	glTexCoord2d(0.25, 0);
	glVertex3d(3, 0.00, 0);
	glEnd();


	glBegin(GL_QUADS); //Floor right 
	glTexCoord2d(0, 0);
	glVertex3d(12, 0, 0);
	glTexCoord2d(0, 50);
	glVertex3d(12, 0, z);
	glTexCoord2d(0.25, 50);
	glVertex3d(15, 0, z);
	glTexCoord2d(0.25, 0);
	glVertex3d(15, 0, 0);
	glEnd();
	glPopMatrix();
}
void Environment:: DrawHouse(int x, int y, int z, int house_front, int house_side, int house_roof)
{
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, house_front);


	glBegin(GL_QUADS); // BACK


	glTexCoord2d(0, 0);
	glVertex3d(0, 0, z);
	glTexCoord2d(1, 0);
	glVertex3d(x, 0, z);
	glTexCoord2d(1, 1);
	glVertex3d(x, y, z);
	glTexCoord2d(0, 1);
	glVertex3d(0, y, z);

	glEnd();

	glBindTexture(GL_TEXTURE_2D, house_side);

	glBegin(GL_QUADS); // LEFT

	glTexCoord2d(0, 0);
	glVertex3d(0, 0, 0);
	glTexCoord2d(0, 1);
	glVertex3d(0, y, 0);
	glTexCoord2d(1, 1);
	glVertex3d(0, y, z);
	glTexCoord2d(1, 0);
	glVertex3d(0, 0, z);

	glEnd();


	glBegin(GL_QUADS); // FRONT
	glTexCoord2d(0, 0);
	glVertex3d(0, 0, 0);
	glTexCoord2d(1, 0);
	glVertex3d(x, 0, 0);
	glTexCoord2d(1, 1);
	glVertex3d(x, y, 0);
	glTexCoord2d(0, 1);
	glVertex3d(0, y, 0);

	glEnd();

	glBegin(GL_QUADS); // RIGHT


	glTexCoord2d(0, 0);
	glVertex3d(x, 0, 0);
	glTexCoord2d(0, 1);
	glVertex3d(x, y, 0);
	glTexCoord2d(1, 1);
	glVertex3d(x, y, z);
	glTexCoord2d(1, 0);
	glVertex3d(x, 0, z);

	glEnd();

	glBindTexture(GL_TEXTURE_2D, house_roof);


	glBegin(GL_QUADS); // ROOF
	glTexCoord2d(0, 0);
	glVertex3d(0, y, 0);
	glTexCoord2d(1, 0);
	glVertex3d(x, y, 0);
	glTexCoord2d(1, 1);
	glVertex3d(x, y, z);
	glTexCoord2d(0, 1);
	glVertex3d(0, y, z);

	glEnd();

	//glBegin(GL_QUADS); // FLOOR
	//glTexCoord2d(0, 0);
	//glVertex3d(0, 0, 0);
	//glTexCoord2d(1, 0);
	//glVertex3d(x, 0, 0);
	//glTexCoord2d(1, 1);
	//glVertex3d(x, 0, z);
	//glTexCoord2d(0, 1);
	//glVertex3d(0, 0, z);
	glPopMatrix();

}

void Environment:: DrawCube(int x, int y, int z, int tex)
{
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, tex);


	glBegin(GL_QUADS); // BACK


	glTexCoord2d(0, 0);
	glVertex3d(0, 0, z);
	glTexCoord2d(1, 0);
	glVertex3d(x, 0, z);
	glTexCoord2d(1, 1);
	glVertex3d(x, y, z);
	glTexCoord2d(0, 1);
	glVertex3d(0, y, z);

	glEnd();

	glBegin(GL_QUADS); // LEFT

	glTexCoord2d(0, 0);
	glVertex3d(0, 0, 0);
	glTexCoord2d(0, 1);
	glVertex3d(0, y, 0);
	glTexCoord2d(150, 1);
	glVertex3d(0, y, z);
	glTexCoord2d(150, 0);
	glVertex3d(0, 0, z);

	glEnd();


	glBegin(GL_QUADS); // FRONT
	glTexCoord2d(0, 0);
	glVertex3d(0, 0, 0);
	glTexCoord2d(1, 0);
	glVertex3d(x, 0, 0);
	glTexCoord2d(1, 1);
	glVertex3d(x, y, 0);
	glTexCoord2d(0, 1);
	glVertex3d(0, y, 0);

	glEnd();

	glBegin(GL_QUADS); // RIGHT


	glTexCoord2d(0, 0);
	glVertex3d(x, 0, 0);
	glTexCoord2d(0, 1);
	glVertex3d(x, y, 0);
	glTexCoord2d(150, 1);
	glVertex3d(x, y, z);
	glTexCoord2d(150, 0);
	glVertex3d(x, 0, z);

	glEnd();

	glBegin(GL_QUADS); // ROOF
	glTexCoord2d(0, 0);
	glVertex3d(0, y, 0);
	glTexCoord2d(1, 0);
	glVertex3d(x, y, 0);
	glTexCoord2d(1, 150);
	glVertex3d(x, y, z);
	glTexCoord2d(0, 150);
	glVertex3d(0, y, z);

	glEnd();

	//glBegin(GL_QUADS); // FLOOR
	//glTexCoord2d(0, 0);
	//glVertex3d(0, 0, 0);
	//glTexCoord2d(1, 0);
	//glVertex3d(x, 0, 0);
	//glTexCoord2d(1, 1);
	//glVertex3d(x, 0, z);
	//glTexCoord2d(0, 1);
	//glVertex3d(0, 0, z);
	glPopMatrix();

}


void Environment:: DrawBuildings(int x)
{

	glPushMatrix();
	glTranslatef(x, 0, 0);
	
	for (int i = 0; i < 18; i++)
	{
		glTranslatef(0, 0, -50);
		DrawHouse(25, 25, 25, building2, building2, house_roof);

		glTranslatef(0, 0, -50);
		DrawHouse(25, 25, 25, house_front6, house_front6, house_roof);
	}


	//Another side 

	glTranslatef(x * 2 , 0, +1750);

	for (int i = 0; i < 3; i++)
	{
		glTranslatef(0, 0, -150);
		DrawHouse(60, 100, 60, house_front3, house_front3, house_roof);

		glTranslatef(0, 0, -150);
		DrawHouse(60, 100, 60, house_front5, house_front5, house_roof);

		glTranslatef(0, 0, -150);
		DrawHouse(60, 100, 60, building3, building3, house_roof);

		glTranslatef(0, 0, -150);
		DrawHouse(60, 100, 60, building4, building4, house_roof);
	}

	glPopMatrix();
}

void Environment:: DrawHouses(int x)
{

	glPushMatrix();
	glTranslatef(x, 0, 0);

	for (int i = 0; i < 16; i++)
	{
		glTranslatef(0, 0, -50);
		DrawHouse(20, 20, 20, house_front, house_side, house_roof);

		glTranslatef(0, 0, -50);
		DrawHouse(20, 20, 20, house_front2, house_side2, house_roof2);
	}
	
	////Another side 

	glTranslatef(x * 2, 0, 1600);
	for (int i = 0; i < 16; i++)
	{
		glTranslatef(0, 0, -50);
		DrawHouse(20, 20, 20, house_front, house_side, house_roof);
		glTranslatef(0, 0, -50);
		DrawHouse(20, 20, 20, house_front2, house_side2, house_roof2);
	}

	glPopMatrix();
}


void Environment:: DrawFloor(int tr)
{
	
	glPushMatrix();
	glTranslatef(0, 0, tr);

	glPushMatrix();
	

	double z = -2000;
	double x = 500;



	glPushMatrix();
	glTranslatef(-7.5, 0, 0);
	DrawRailRoad(z);
	glPopMatrix();
	

	glPushMatrix();

	for (int i = 0; i < 5; i = i++)
	{
		tree.scale = 0.5;
		tree.pos.x = -12;
		tree.pos.y = 0;
		tree.pos.z = -350 + -i * 300;
		tree.Draw();
	}
	glPopMatrix();

	glPushMatrix();
	for (int i = 0; i < 4; i = i++)
	{
		tree.scale = 0.5;
		tree.pos.x = 12;
		tree.pos.y = 0;
		tree.pos.z = -500 + -i * 300;
		tree.Draw();
	}
	glPopMatrix();


	glPushMatrix();
	glTranslatef(-x/2, 0, 0);

	glBindTexture(GL_TEXTURE_2D, ground);

	glBegin(GL_QUADS); // Every 4 points will be connected together

	glTexCoord2d(0, 0);
	glVertex3d(0, 0, 0);
	glTexCoord2d(0, 60);
	glVertex3d(0, 0, z);
	glTexCoord2d(10, 60);
	glVertex3d(x / 2 - 7.5, 0, z);
	glTexCoord2d(10, 0);
	glVertex3d(x / 2 - 7.5, 0, 0);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(x/2 + 7.5, 0, 0);
	glTexCoord2d(0, 20);
	glVertex3d(x/2 + 7.5, 0, z);
	glTexCoord2d(10, 20);
	glVertex3d(x, 0, z);
	glTexCoord2d(10, 0);
	glVertex3d(x, 0, 0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	DrawBuildings(30);
	DrawBuildings(-60);
	glPopMatrix();



	//Bash
	glPushMatrix();
	glTranslatef(-25, 0, 0);
	DrawCube(10, 2, -2000, grass2);

	glTranslatef(40, 0, 0);
	DrawCube(10, 2, -2000, grass2);


	glPopMatrix();

	glPopMatrix();
	glPopMatrix();
}

void Environment:: DrawGrass()
{

	glPushMatrix();
	glTranslatef(0, 0, 0);

	glPushMatrix();


	double z = -3000;
	double x = 750;

	glPushMatrix();
	glTranslatef(-7.5, 0, 0);
	DrawRailRoad(z);
	glPopMatrix();

	glPushMatrix();

	for (int i = 0; i < 5; i = i++)
	{
		tree.scale = 0.5;
		tree.pos.x = -12;
		tree.pos.y = 0;
		tree.pos.z = -100 + -i * 300;
		tree.Draw();
	}
	glPopMatrix();

	glPushMatrix();

	for (int i = 0; i < 4; i = i++)
	{
		tree.scale = 0.5;
		tree.pos.x = 12;
		tree.pos.y = 0;
		tree.pos.z = -250 + -i * 300;
		tree.Draw();
	}
	glPopMatrix();



	glPushMatrix();
	glTranslatef(-25, 0, 0);
	DrawCube(10, 2, -1500, grass2);
	glTranslatef(40, 0, 0);
	DrawCube(10, 2, -1500, grass2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-x / 2, 0, 0);

	glBindTexture(GL_TEXTURE_2D, grass);

	glBegin(GL_QUADS); // Every 4 points will be connected together

	glTexCoord2d(0, 0);
	glVertex3d(0, 0, 0);
	glTexCoord2d(0, 30);
	glVertex3d(0, 0, z);
	glTexCoord2d(10, 30);
	glVertex3d(x / 2 - 7.5, 0, z);
	glTexCoord2d(10, 0);
	glVertex3d(x / 2 - 7.5, 0, 0);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(x / 2 + 7.5, 0, 0);
	glTexCoord2d(0, 60);
	glVertex3d(x / 2 + 7.5, 0, z);
	glTexCoord2d(10, 60);
	glVertex3d(x, 0, z);
	glTexCoord2d(10, 0);
	glVertex3d(x, 0, 0);
	glEnd();
	glPopMatrix();

	DrawHouses(50);
	DrawHouses(-70);

	//Bash
	glPushMatrix();


	glPopMatrix();

	glPopMatrix();
	glPopMatrix();
}


void Environment:: skybox2()
{
	glPushMatrix();

	int x = 0;
	int y = 0;
	int z = 0;
	int height = 3000;
	int width = 3000;
	int length = 3000;
	int sbox = skybox_texture;
	// Center the Skybox around the given x,y,z position
	x = x - width / 2;
	y = y - height / 2;
	z = z - length / 2;
	// Draw Front side
	glBindTexture(GL_TEXTURE_2D, sbox);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812F);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812F);
	glBegin(GL_QUADS);
	glColor3d(1, 1, 1);
	glTexCoord2f(0.25f, 0.3333333); glVertex3f(x, y, z);
	glTexCoord2f(0.5f, 0.33333333); glVertex3f(x + width, y, z);
	glTexCoord2f(0.5f, 0.66666666); glVertex3f(x + width, y + height, z);
	glTexCoord2f(0.25f, 0.6666666); glVertex3f(x, y + height, z);


	glEnd();

	// Draw Back side
	glBindTexture(GL_TEXTURE_2D, sbox);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812F);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812F);
	glBegin(GL_QUADS);
	glTexCoord2f(0.75f, 0.3333333333333); glVertex3f(x + width, y, z + length);
	glTexCoord2f(1, 0.3333333333333); glVertex3f(x, y, z + length);
	glTexCoord2f(1, 0.666666666666); glVertex3f(x, y + height, z + length);
	glTexCoord2f(0.75, 0.666666666666); glVertex3f(x + width, y + height, z + length);
	glEnd();

	// Draw Left side
	glBindTexture(GL_TEXTURE_2D, sbox);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812F);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812F);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.3333333333333); glVertex3f(x, y, z + length);
	glTexCoord2f(0.0f, 0.666666666666); glVertex3f(x, y + height, z + length);
	glTexCoord2f(0.25f, 0.666666666666); glVertex3f(x, y + height, z);
	glTexCoord2f(0.25f, 0.3333333333333); glVertex3f(x, y, z);
	glEnd();

	// Draw Right side
	glBindTexture(GL_TEXTURE_2D, sbox);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812F);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812F);
	glBegin(GL_QUADS);
	glTexCoord2f(0.5f, 0.3333333333333); glVertex3f(x + width, y, z);
	glTexCoord2f(0.75f, 0.3333333333333); glVertex3f(x + width, y, z + length);
	glTexCoord2f(0.75f, 0.666666666666); glVertex3f(x + width, y + height, z + length);
	glTexCoord2f(0.5f, 0.666666666666); glVertex3f(x + width, y + height, z);
	glEnd();

	// Draw Up side
	glBindTexture(GL_TEXTURE_2D, sbox);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812F);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812F);
	glBegin(GL_QUADS);
	glTexCoord2f(0.25f, 0.666666666666); glVertex3f(x, y + height, z);
	glTexCoord2f(0.5f, 0.666666666666); glVertex3f(x + width, y + height, z);
	glTexCoord2f(0.5f, 1.0f); glVertex3f(x + width, y + height, z + length);
	glTexCoord2f(0.25f, 1.0f); glVertex3f(x, y + height, z + length);
	glEnd();

	// Draw Down side
	glBindTexture(GL_TEXTURE_2D, sbox);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812F);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812F);
	glBegin(GL_QUADS);
	glTexCoord2f(0.25f, 0.3333333333333); glVertex3f(x, y, z);
	glTexCoord2f(0.25f, 0.0f); glVertex3f(x, y, z + length);
	glTexCoord2f(0.5f, 0.0f); glVertex3f(x + width, y, z + length);
	glTexCoord2f(0.5f, 0.3333333333333); glVertex3f(x + width, y, z);
	glEnd();

	glColor3f(1, 1, 1);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glPopMatrix();
}

void Environment:: skybox()
{
	glBindTexture(GL_TEXTURE_2D, front);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-500, -500, -500);
	glTexCoord2d(1, 0);
	glVertex3d(500, -500, -500);
	glTexCoord2d(1, 1);
	glVertex3d(500, 500, -500);
	glTexCoord2d(0, 1);
	glVertex3d(-500, 500, -500);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, back);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-500, -500, 500);
	glTexCoord2d(1, 0);
	glVertex3d(500, -500, 500);
	glTexCoord2d(1, 1);
	glVertex3d(500, 500, 500);
	glTexCoord2d(0, 1);
	glVertex3d(-500, 500, 500);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, left);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-500, -500, 500);
	glTexCoord2d(1, 0);
	glVertex3d(-500, -500, -500);
	glTexCoord2d(1, 1);
	glVertex3d(-500, 500, -500);
	glTexCoord2d(0, 1);
	glVertex3d(-500, 500, 500);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, right);
	glBegin(GL_QUADS);
	glTexCoord2d(1, 0);
	glVertex3d(500, -500, 500);
	glTexCoord2d(0, 0);
	glVertex3d(500, -500, -500);
	glTexCoord2d(0, 1);
	glVertex3d(500, 500, -500);
	glTexCoord2d(1, 1);
	glVertex3d(500, 500, 500);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, top);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-500, 500, -500);
	glTexCoord2d(1, 0);
	glVertex3d(500, 500, -500);
	glTexCoord2d(1, 1);
	glVertex3d(500, 500, 500);
	glTexCoord2d(0, 1);
	glVertex3d(-500, 500, 500);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, bottom);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-500, -500, -500);
	glTexCoord2d(50, 0);
	glVertex3d(500, -500, -500);
	glTexCoord2d(50, 50);
	glVertex3d(500, -500, 500);
	glTexCoord2d(0, 50);
	glVertex3d(-500, -500, 500);
	glEnd();
}


void Environment:: drawBridgeWall(int x, int height)
{
	int z = -1500;
	glPushMatrix();
	glBegin(GL_QUADS); // left bridge wall 
	glTexCoord2d(0, 0);
	glVertex3d(x, height, 0);
	glTexCoord2d(0, 0.5);
	glVertex3d(x, height + 0.25, 0);
	glTexCoord2d(100, 0.5);
	glVertex3d(x, height + 0.25, z);
	glTexCoord2d(100, 0);
	glVertex3d(x, height, z);
	glEnd();
	glPopMatrix();
}

void Environment:: drawBridgeUp(int x, int y)
{
	int z = -500;
	glBindTexture(GL_TEXTURE_2D, bridge);
	glPushMatrix();

	glBegin(GL_QUADS); // up 
	glTexCoord2d(0, 0);
	glVertex3d(-0.25 + x, y, 0);
	glTexCoord2d(0, 100);
	glVertex3d(-0.25 + x, y, z);
	glTexCoord2d(1, 100);
	glVertex3d( x, y, z);
	glTexCoord2d(1, 0);
	glVertex3d(x, y, 0);
	glEnd();

	glPopMatrix();

}


void Environment:: DrawSea()
{
	double tr = -3000;
	double z = -2000;
	
	glPushMatrix();

	glPushMatrix();
	glTranslated(-7.5, 0, tr);
	DrawRailRoad(-1500);
	glPopMatrix();

	glPushMatrix();

	glBindTexture(GL_TEXTURE_2D, sea);
	glTranslated(-1250, -20, tr);

	glBegin(GL_QUADS); // Every 4 points will be connected 
	glTexCoord2d(0, 0);
	glVertex3d(0, 0, 0);
	glTexCoord2d(0, 75);
	glVertex3d(0, 0, z);
	glTexCoord2d(125, 75);
	glVertex3d(2500, 0, z);
	glTexCoord2d(125, 0);
	glVertex3d(2500, 0, 0);

	glEnd();
	glPopMatrix();


	glPushMatrix();

	glBindTexture(GL_TEXTURE_2D, bridge);
	glTranslated(-7.5, 0, tr);

	drawBridgeWall(0, 0);
	drawBridgeWall(0, 1.5);
	drawBridgeWall(0, 3);
	drawBridgeWall(0, 4.5);

	//drawBridgeWall(-0.25, 0);
	//drawBridgeWall(-0.25, 1.5);
	//drawBridgeWall(-0.25, 3);
	//drawBridgeWall(-0.25, 4.5);

	//drawBridgeUp(0, 0.25);
	//drawBridgeUp(0, 1.75);
	//drawBridgeUp(0, 3.25);
	//drawBridgeUp(0, 4.75);

	//drawBridgeUp(0, 0);
	//drawBridgeUp(0, 1.5);
	//drawBridgeUp(0, 3);
	//drawBridgeUp(0, 4.5);

	glPushMatrix();
	glTranslated(15, 0, 0);

	drawBridgeWall(0, 0);
	drawBridgeWall(0, 1.5);
	drawBridgeWall(0, 3);
	drawBridgeWall(0, 4.5);

	glPopMatrix();

	glPopMatrix();

	glPopMatrix();
}

void Environment:: DrawTunnel(int tr)
{
	glPushMatrix();
	double z = -1500;
	double x = 25;
	double y = 10;
	//double tr = -500;
	double thick = 2.5;

	glBindTexture(GL_TEXTURE_2D, rooof);	

	glPushMatrix();

	glTranslatef(0, 0, tr);

	glTranslatef(-7.5, 0, 0);
	DrawRailRoad(z);
	//glTranslatef(-6.25, 0, 0);
	//DrawRailRoad(z);
	//glTranslatef(-6.25, 0, 0);
	//DrawRailRoad(z);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-x / 2, 0, tr);


	glPushMatrix();
	glTranslatef(-thick, 0, -1);
	DrawCube(1, -20, 1, bridge);
	glTranslatef(4, 0, 0);
	DrawCube(1, -20, 1, bridge);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(x + thick, 0, -1);
	DrawCube(-1, -20, 1, bridge);
	glTranslatef(-4, 0, 0);
	DrawCube(-1, -20, 1, bridge);
	glPopMatrix();

	glBindTexture(GL_TEXTURE_2D, left_floor);

	glBegin(GL_QUADS); //Floor left 
	glTexCoord2d(0, 0);
	glVertex3d(0, 0, 0);
	glTexCoord2d(0, 25);
	glVertex3d(0, 0, z);
	glTexCoord2d(0.5, 25);
	glVertex3d(x / 2 - 7.5, 0, z);
	glTexCoord2d(0.5, 0);
	glVertex3d(x / 2 - 7.5, 0, 0);	
	glEnd();


	glBegin(GL_QUADS); //Floor right 
	glTexCoord2d(0, 0);
	glVertex3d(x / 2 + 7.5, 0, 0);
	glTexCoord2d(0, 25);
	glVertex3d(x / 2 + 7.5, 0, z);
	glTexCoord2d(0.5, 25);
	glVertex3d(x, 0, z);
	glTexCoord2d(0.5, 0);
	glVertex3d(x, 0, 0);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, rooof);
	glBegin(GL_QUADS); // Roof
	glTexCoord2d(0, 0);
	glVertex3d(0, y, 0);
	glTexCoord2d(y, 0);
	glVertex3d(0, y, z);
	glTexCoord2d(y, 1);
	glVertex3d(x, y, z);
	glTexCoord2d(0, 1);
	glVertex3d(x, y, 0);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, wall);

	glBegin(GL_QUADS); // Left wall 
	glTexCoord2d(0, 0);
	glVertex3d(0, 0, 0);
	glTexCoord2d(0, 1);
	glVertex3d(0, y, 0);
	glTexCoord2d(10, 1);
	glVertex3d(0, y, z);
	glTexCoord2d(10, 0);
	glVertex3d(0, 0, z);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, wall);

	glBegin(GL_QUADS); // Right wall

	glTexCoord2d(0, 0);
	glVertex3d(x, 0, 0);
	glTexCoord2d(0, 1);
	glVertex3d(x, y, 0);
	glTexCoord2d(8, 1);
	glVertex3d(x, y, z);
	glTexCoord2d(8, 0);
	glVertex3d(x, 0, z);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, out_tunnel);

	glBegin(GL_QUADS); // Roof above
	glTexCoord2d(0, 0);
	glVertex3d(-thick, y+4, 0);
	glTexCoord2d(y * 2, 0);
	glVertex3d(-thick, y+4, z);
	glTexCoord2d(y * 2, 1);
	glVertex3d(x+ thick, y+4, z);
	glTexCoord2d(0, 1);
	glVertex3d(x+ thick, y+4, 0);
	glEnd();

	glBegin(GL_QUADS); // Left left wall 
	glTexCoord2d(0, 0);
	glVertex3d(-thick, 0, 0);
	glTexCoord2d(0, 1);
	glVertex3d(-thick, y+4, 0);
	glTexCoord2d(40, 1);
	glVertex3d(-thick, y+4, z);
	glTexCoord2d(40, 0);
	glVertex3d(-thick, 0, z);
	glEnd();

	glBegin(GL_QUADS); // Right right wall

	glTexCoord2d(0, 0);
	glVertex3d(x+ thick, 0, 0);
	glTexCoord2d(0, 1);
	glVertex3d(x+ thick, y+4, 0);
	glTexCoord2d(40, 1);
	glVertex3d(x+ thick, y+4, z);
	glTexCoord2d(40, 0);
	glVertex3d(x+thick, 0, z);
	glEnd();

	glBegin(GL_QUADS); // Left front

	glTexCoord2d(0, 0);
	glVertex3d(-thick, 0, z);
	glTexCoord2d(0, 1);
	glVertex3d(-thick, y+4, z);
	glTexCoord2d(1, 1);
	glVertex3d(0, y+4, z);
	glTexCoord2d(1, 0);
	glVertex3d(0, 0, z);
	glEnd();

	glBegin(GL_QUADS); // Right front

	glTexCoord2d(0, 0);
	glVertex3d(x, 0, z);
	glTexCoord2d(0, 1);
	glVertex3d(x, y+4, z);
	glTexCoord2d(1, 1);
	glVertex3d(x+thick, y+4, z);
	glTexCoord2d(1, 0);
	glVertex3d(x+thick, 0, z);
	glEnd();

	glBegin(GL_QUADS); // up front left

	glTexCoord2d(0, 0);
	glVertex3d(-thick, 0, z);
	glTexCoord2d(0, 1);
	glVertex3d(-thick, y + 4, z);
	glTexCoord2d(1, 1);
	glVertex3d(x / 2 - 7.5, y + 4, z);
	glTexCoord2d(1, 0);
	glVertex3d(x / 2 - 7.5, 0, z);
	glEnd();

	glBegin(GL_QUADS); // up front right

	glTexCoord2d(0, 0);
	glVertex3d(x / 2 + 7.5 , 0, z);
	glTexCoord2d(0, 1);
	glVertex3d(x / 2 + 7.5 , y + 4, z);
	glTexCoord2d(1, 1);
	glVertex3d(x + thick, y + 4, z);
	glTexCoord2d(1, 0);
	glVertex3d(x + thick, 0, z);
	glEnd();

	glBegin(GL_QUADS); // up front

	glTexCoord2d(0, 0);
	glVertex3d(-thick, y, z);
	glTexCoord2d(0, 1);
	glVertex3d(-thick, y + 4, z);
	glTexCoord2d(1, 1);
	glVertex3d(x + thick, y + 4, z);
	glTexCoord2d(1, 0);
	glVertex3d(x + thick, y, z);
	glEnd();


	glBegin(GL_QUADS); // Left back

	glTexCoord2d(0, 0);
	glVertex3d(-thick, 0, 0);
	glTexCoord2d(0, 1);
	glVertex3d(-thick, y+4, 0);
	glTexCoord2d(1, 1);
	glVertex3d(0, y+4, 0);
	glTexCoord2d(1, 0);
	glVertex3d(0, 0, 0);
	glEnd();

	glBegin(GL_QUADS); // Right back

	glTexCoord2d(0, 0);
	glVertex3d(x, 0, 0);
	glTexCoord2d(0, 1);
	glVertex3d(x, y+4, 0);
	glTexCoord2d(1, 1);
	glVertex3d(x+thick, y+4, 0);
	glTexCoord2d(1, 0);
	glVertex3d(x+thick, 0, 0);
	glEnd();

	glBegin(GL_QUADS); // up back

	glTexCoord2d(0, 0);
	glVertex3d(-thick, y, 0);
	glTexCoord2d(0, 1);
	glVertex3d(-thick, y+4, 0);
	glTexCoord2d(1, 1);
	glVertex3d(x+thick, y+4, 0);
	glTexCoord2d(1, 0);
	glVertex3d(x+thick, y, 0);
	glEnd();

	glPopMatrix();
	glPopMatrix();
	
}


Environment::~Environment(void)
{
}
