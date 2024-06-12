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
	IsCollision = true;
}

APlayer::APlayer(int NewX, int NewY, Teamname NewTeam, int NewHP, char NewShape)
{
	X = NewX;
	Y = NewY;
	Team = NewTeam;
	HP = NewHP;
	Shape = NewShape;
	Layer = 0;
	IsCollision = true;
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
		if (Predict(X, Y - 1))
		{
			Y--;
		}
		break;
	case 'S':
	case 's':
		if (Predict(X, Y + 1))
		{
			Y++;
		}
		break;
	case 'D':
	case 'd':
		if (Predict(X + 1, Y))
		{
			X++;
		}
		break;
	case 'A':
	case 'a':
		if (Predict(X - 1, Y))
		{
			X--;
		}
		break;
	}
}
