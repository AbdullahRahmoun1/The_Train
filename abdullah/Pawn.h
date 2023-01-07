#pragma once
#include <glaux.h>
#include <math.h>
class Pawn
{
public:
	double x, y, length, radius;
	bool firstplayer, isLive;
	Pawn();
	Pawn(double length, double radius, bool firstplayer, bool isLive, double x, double y);
	void builder();
	void dead();
	void revive();
	~Pawn();
};

