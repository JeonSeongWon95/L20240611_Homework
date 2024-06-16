#include "Monster.h"
#include "Engine.h"
#include <iostream>

AMonster::AMonster()
{
	X = 5;
	Y = 5;
	Team = Teamname::ENEMY;
	HP = 1;
	Layer = 1;
	Damage = 1;
	MonsterTime = 0;
	MySurface = SDL_LoadBMP("Data/Monster.bmp");
	SDL_SetColorKey(MySurface, 1, SDL_MapRGB(MySurface->format, ColorR, ColorG, ColorB));
	MyTexture = SDL_CreateTextureFromSurface(MYENGINE->GetMyRenderer(), MySurface);
}

AMonster::AMonster(int NewX, int NewY, Teamname NewTeam, int NewHP)
{
	X = NewX;
	Y = NewY;
	Team = NewTeam;
	HP = NewHP;
	Layer = 1;
	Damage = 1;
	MonsterTime = 0;
	MySurface = SDL_LoadBMP("Data/Monster.bmp");
	SDL_SetColorKey(MySurface, 1, SDL_MapRGB(MySurface->format, ColorR, ColorG, ColorB));
	MyTexture = SDL_CreateTextureFromSurface(MYENGINE->GetMyRenderer(), MySurface);
}

AMonster::~AMonster()
{
}

void AMonster::Tick()
{
	srand(time(0));

	int RandomMove = rand() % 4;
	MonsterTime += MYENGINE->GetDeltaTime();

	if (MonsterTime >= 200)
	{

		switch (RandomMove)
		{
		case 0:
			if (Predict(X + 1, Y))
			{
				X++;
			}
			break;
		case 1:
			if (Predict(X - 1, Y))
			{
				X--;
			}
			break;
		case 2:
			if (Predict(X, Y + 1))
			{
				Y++;
			}
			break;
		default:
			if (Predict(X, Y - 1))
			{
				Y--;
			}
			break;
		}

		MonsterTime = 0.0f;

	}
	
}
