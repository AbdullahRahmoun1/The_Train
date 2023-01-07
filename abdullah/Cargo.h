#pragma once
class Cargo
{
public:
	Cargo();
	~Cargo();

	static void drawBox(double,double, double,int);
	static void drawWoods(double, double, double, int);
	static void drawLadder(double, double, double, int, int);
	static void drawArtpiece(double, double, double, int, int);
	static void drawCargo(int[]);
};

