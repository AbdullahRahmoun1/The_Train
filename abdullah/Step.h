#pragma once
class Step
{
public:
		bool firstPlayer;
		double x, y, newx, newy;
		int pawnNumber, dead;
	
		Step();
	
		Step(bool firstPlayer, double x, double y, double newx, double newy, int pawnNumber);
	~Step();
};


