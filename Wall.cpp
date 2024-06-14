#include "Wall.h"
#include "Engine.h"

AWall::AWall()
{
	X = 0;
	Y = 0;
	Team = Teamname::NONE;
	HP = 0;
	Layer = 3;
	IsCollision = true;
	MySurface = SDL_LoadBMP("Data/Wall.bmp");
	MyTexture = SDL_CreateTextureFromSurface(MYENGINE->GetMyRenderer(), MySurface);
}

AWall::AWall(int NewX, int NewY)
{
	X = NewX;
	Y = NewY;
	Team = Teamname::NONE;
	HP = 0;
	Layer = 3;
	IsCollision = true;
	MySurface = SDL_LoadBMP("Data/Wall.bmp");
	MyTexture = SDL_CreateTextureFromSurface(MYENGINE->GetMyRenderer(), MySurface);
}

AWall::~AWall()
{
}
