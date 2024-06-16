#include "Actor.h"
#include "Engine.h"
#include <iostream>

AActor::AActor()
{
	HP = 0;
	Team = Teamname::NONE;
	X = 0;
	Y = 0;
	Layer = 0;
	Damage = 0;
	IsCollision = false;
	MySurface = nullptr;
	MyTexture = nullptr;
	MyRect = { 0, };
	SpriteSize = 60;
	ColorR = 255;
	ColorG = 255;
	ColorB = 255;
}

AActor::~AActor()
{
}

void AActor::Tick()
{
}

void AActor::Render()
{
	MyRect.x = X * SpriteSize;
	MyRect.y = Y * SpriteSize;
	MyRect.w = SpriteSize;
	MyRect.h = SpriteSize;

	if (MyTexture)
	{
		SDL_RenderCopy(MYENGINE->GetMyRenderer(), MyTexture, nullptr, &MyRect);
	}
	else
	{
		SDL_Log("Texture does not exist.");
	}

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

bool AActor::Predict(int NewX, int NewY)
{
	for (AActor* Actor : UEngine::GetInstance()->GetWorld()->GetActors())
	{
		if (this == Actor)
		{
			continue;
		}
		if (!Actor->GetIsCollision())
		{
			continue;
		}
		if (Actor->GetX() == NewX && Actor->GetY() == NewY)
		{
			return false;
		}

	}

	return true;
}
