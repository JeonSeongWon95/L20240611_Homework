#include "Monster.h"
#include <iostream>

AMonster::AMonster()
{
	X = 5;
	Y = 5;
	Team = Teamname::ENEMY;
	HP = 50;
	Shape = 'M';
	Layer = 1;
}

AMonster::AMonster(int NewX, int NewY, Teamname NewTeam, int NewHP, char NewShape)
{
	X = NewX;
	Y = NewY;
	Team = NewTeam;
	HP = NewHP;
	Shape = NewShape;
	Layer = 1;
}

AMonster::~AMonster()
{
}

void AMonster::Tick()
{
	/*srand(time(nullptr));

	int RandomMove = rand() % 4;

	switch (RandomMove)
	{
	case 0:
		X++;
		break;
	case 1:
		X--;
		break;
	case 2:
		Y++;
		break;
	default:
		Y--;
		break;
	}
	*/
}
