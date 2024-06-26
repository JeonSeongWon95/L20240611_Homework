#include "Goal.h"
#include "Engine.h"

AGoal::AGoal()
{
	X = 8;
	Y = 8;
	Team = Teamname::NONE;
	HP = 0;
	Layer = 2;
	MySurface = SDL_LoadBMP("Data/Goal.bmp");
	SDL_SetColorKey(MySurface, 1, SDL_MapRGB(MySurface->format, ColorR, ColorG, ColorB));
	MyTexture = SDL_CreateTextureFromSurface(MYENGINE->GetMyRenderer(), MySurface);
}

AGoal::AGoal(int NewX, int NewY)
{
	X = NewX;
	Y = NewY;
	Team = Teamname::NONE;
	HP = 0;
	MySurface = SDL_LoadBMP("Data/Goal.bmp");
	SDL_SetColorKey(MySurface, 1, SDL_MapRGB(MySurface->format, ColorR, ColorG, ColorB));
	MyTexture = SDL_CreateTextureFromSurface(MYENGINE->GetMyRenderer(), MySurface);
}

AGoal::~AGoal()
{
}
