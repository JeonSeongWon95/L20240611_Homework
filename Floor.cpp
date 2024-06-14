#include "Floor.h"
#include "Engine.h"

AFloor::AFloor()
{
	X = 0;
	Y = 0;
	Team = Teamname::NONE;
	HP = 0;
	Layer = 4;
	MySurface = SDL_LoadBMP("Data/Floor.bmp");
	MyTexture = SDL_CreateTextureFromSurface(MYENGINE->GetMyRenderer(), MySurface);
}

AFloor::AFloor(int NewX, int NewY)
{
	X = NewX;
	Y = NewY;
	Team = Teamname::NONE;
	HP = 0;
	Layer = 4;
	MySurface = SDL_LoadBMP("Data/Floor.bmp");
	MyTexture = SDL_CreateTextureFromSurface(MYENGINE->GetMyRenderer(), MySurface);
}

AFloor::~AFloor()
{
}
