#include "Wall.h"

AWall::AWall()
{
	X = 0;
	Y = 0;
	Team = Teamname::NONE;
	HP = 0;
	Shape = '*';
	Layer = 3;
	IsCollision = true;
}

AWall::AWall(int NewX, int NewY)
{
	X = NewX;
	Y = NewY;
	Team = Teamname::NONE;
	HP = 0;
	Shape = '*';
	Layer = 3;
	IsCollision = true;
}

AWall::~AWall()
{
}
