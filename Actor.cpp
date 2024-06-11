#include "Actor.h"

AActor::AActor()
{
	HP = 0;
	Shape = ' ';
	Team = Teamname::NONE;
	X = 0;
	Y = 0;
}

AActor::~AActor()
{
}

void AActor::SetHP(int NewHP)
{
	HP = NewHP;
}

void AActor::SetTeam(Teamname NewTeam)
{
	Team = NewTeam;
}

void AActor::SetX(int NewX)
{
	X = NewX;
}

void AActor::SetY(int NewY)
{
	Y = NewY;
}

void AActor::SetShape(char NewShape)
{
	Shape = NewShape;
}
