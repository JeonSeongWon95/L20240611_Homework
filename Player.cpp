#include "Player.h"
#include "Engine.h"

APlayer::APlayer()
{
	X = 1;
	Y = 1;
	Team = Teamname::REDTEAM;
	HP = 100;
	Shape = 'P';
	Layer = 0;
}

APlayer::APlayer(int NewX, int NewY, Teamname NewTeam, int NewHP, char NewShape)
{
	X = NewX;
	Y = NewY;
	Team = NewTeam;
	HP = NewHP;
	Shape = NewShape;
	Layer = 0;
}

APlayer::~APlayer()
{

}

void APlayer::Tick()
{
	switch (MYENGINE->GetKey())
	{
	case 'W':
	case 'w':
		--Y;
		break;
	case 'S':
	case 's':
		++Y;
		break;
	case 'D':
	case 'd':
		++X;
		break;
	case 'A':
	case 'a':
		--X;
		break;
	}
}
