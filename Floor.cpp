#include "Floor.h"

AFloor::AFloor()
{
	X = 0;
	Y = 0;
	Team = Teamname::NONE;
	HP = 0;
	Shape = ' ';
	Layer = 4;
}

AFloor::AFloor(int NewX, int NewY)
{
	X = NewX;
	Y = NewY;
	Team = Teamname::NONE;
	HP = 0;
	Shape = ' ';
	Layer = 4;
}

AFloor::~AFloor()
{
}
