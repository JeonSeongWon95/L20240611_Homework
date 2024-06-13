#include "Player.h"
#include "Engine.h"

APlayer::APlayer()
{
	X = 1;
	Y = 1;
	Team = Teamname::REDTEAM;
	HP = 100;
	Layer = 0;
	IsCollision = true;
	MySurface = SDL_LoadBMP("Player.bmp");
	MyTexture = SDL_CreateTextureFromSurface(MYENGINE->GetMyRenderer(), MySurface);
}

APlayer::APlayer(int NewX, int NewY, Teamname NewTeam, int NewHP)
{
	X = NewX;
	Y = NewY;
	Team = NewTeam;
	HP = NewHP;
	Layer = 0;
	IsCollision = true;
	MySurface = SDL_LoadBMP("Player.bmp");
	MyTexture = SDL_CreateTextureFromSurface(MYENGINE->GetMyRenderer(), MySurface);
}

APlayer::~APlayer()
{

}

void APlayer::Tick()
{
	switch (MYENGINE->GetEvent()->type)
	{
	case SDL_KEYDOWN:
		switch (MYENGINE->GetEvent()->key.keysym.sym)
		{
		case SDLK_w:
			if (Predict(X, Y - 1))
			{
				Y--;
			}
			break;
		case SDLK_s:
			if (Predict(X, Y + 1))
			{
				Y++;
			}
			break;
		case SDLK_a:
			if (Predict(X - 1, Y))
			{
				X--;
			}
			break;
		case SDLK_d:
			if (Predict(X + 1, Y))
			{
				X++;
			}
			break;
		case SDLK_ESCAPE:
			SDL_QUIT;
			break;
		default:
			break;
		}
	default:
		break;
	}
}
