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
	MySurface = SDL_LoadBMP("Data/Player.bmp");
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
	MySurface = SDL_LoadBMP("Data/Player.bmp");
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

//void APlayer::Render()
//{
//	SDL_Rect MyRect2;
//	MyRect2.x = X * SpriteSize;
//	MyRect2.y = Y * SpriteSize;
//	MyRect2.w = SpriteSize;
//	MyRect2.h = SpriteSize;
//
//	SDL_Rect SrcRect;
//	int SpriteX = SpriteSize / 5;
//	int SpriteY = SpriteSize / 5;
//
//	SrcRect.x = X * SpriteX;
//	SrcRect.y = Y * SpriteY;
//	SrcRect.w = SpriteX;
//	SrcRect.h = SpriteY;
//
//	MyTexture = SDL_CreateTextureFromSurface(MYENGINE->GetMyRenderer(), MySurface);
//
//	if (MYENGINE->GetSumTime() >= 200)
//	{
//		MYENGINE->SetSumTime(0);
//
//	}
//	if (MyTexture)
//	{
//		SDL_RenderCopy(MYENGINE->GetMyRenderer(), MyTexture, &SrcRect, &MyRect2);
//	}
//	else
//	{
//		SDL_Log("Texture does not exist.");
//	}
//
//}
