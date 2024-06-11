#include "Goal.h"

AGoal::AGoal()
{
	X = 8;
	Y = 8;
	Team = Teamname::NONE;
	HP = 0;
	Shape = 'G';
	Layer = 2;
}

AGoal::AGoal(int NewX, int NewY)
{
	X = NewX;
	Y = NewY;
	Team = Teamname::NONE;
	HP = 0;
	Shape = 'G';
}

AGoal::~AGoal()
{
}
