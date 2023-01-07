#include "Step.h"


Step::~Step()
{
}
	
		Step::Step()
		{
			this->dead = -1;
		}
	
		Step::Step(bool firstPlayer, double x, double y, double newx, double newy, int pawnNumber)
		{
			this->firstPlayer = firstPlayer;
			this->x = x;
			this->y = y;
			this->pawnNumber = pawnNumber;
			this->newx = newx;
			this->newy = newy;
			this->dead = -1;
		}