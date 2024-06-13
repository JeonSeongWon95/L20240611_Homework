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
	IsCollision = false;
	MySurface = nullptr;
	MyTexture = nullptr;
}

AActor::~AActor()
{
}

void AActor::Tick()
{
}

void AActor::Render()
{
	//SDL_RenderDrawRect(MyRenderer, &MyRect);
	//SDL_SetRenderDrawColor(MyRenderer, 100, 200, 100, 0);
	//SDL_RenderPresent(MyRenderer);

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
