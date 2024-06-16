#include "Player.h"
#include "Engine.h"

APlayer::APlayer()
{
	ColorR = 255;
	ColorG = 0;
	ColorB = 255;

	X = 1;
	Y = 1;
	Team = Teamname::REDTEAM;
	HP = 2;
	Layer = 0;
	Damage = 0;
	IsCollision = true;
	MySurface = SDL_LoadBMP("Data/Player.bmp");
	SDL_SetColorKey(MySurface, 1, SDL_MapRGB(MySurface->format, ColorR, ColorG, ColorB));
	MyTexture = SDL_CreateTextureFromSurface(MYENGINE->GetMyRenderer(), MySurface);

	PlayerRect = { 0, };

	PlayerRectX = 0;
	PlayerRectY = 0;
	PlayerSpriteSizew = 0;
	PlayerSpriteSizeh = 0;

	PlayerDeltaTime = 0;
}

APlayer::APlayer(int NewX, int NewY, Teamname NewTeam, int NewHP)
{
	ColorR = 255;
	ColorG = 0;
	ColorB = 255;

	X = NewX;
	Y = NewY;
	Team = NewTeam;
	HP = NewHP;
	Layer = 0;
	Damage = 0;
	IsCollision = true;
	MySurface = SDL_LoadBMP("Data/Player.bmp");
	SDL_SetColorKey(MySurface, 1, SDL_MapRGB(MySurface->format, ColorR, ColorG, ColorB));
	MyTexture = SDL_CreateTextureFromSurface(MYENGINE->GetMyRenderer(), MySurface);

	PlayerRect = { 0, };

	PlayerRectX = 0;
	PlayerRectY = 0;
	PlayerSpriteSizew = 0;
	PlayerSpriteSizeh = 0;

	PlayerDeltaTime = 0;
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
			PlayerRectY = 2;
			if (Predict(X, Y - 1))
			{
				Y--;
			}
			break;
		case SDLK_s:
			PlayerRectY = 3;
			if (Predict(X, Y + 1))
			{
				Y++;
			}
			break;
		case SDLK_a:
			PlayerRectY = 0;
			if (Predict(X - 1, Y))
			{
				X--;
			}
			break;
		case SDLK_d:
			PlayerRectY = 1;
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

void APlayer::Render()
{

	PlayerSpriteSizew = MySurface->w / 5;
	PlayerSpriteSizeh = MySurface->h / 5;

	PlayerRect.x = PlayerRectX * PlayerSpriteSizew;
	PlayerRect.y = PlayerRectY * PlayerSpriteSizeh;
	PlayerRect.w = PlayerSpriteSizew;
	PlayerRect.h = PlayerSpriteSizeh;

	MyRect.x = X * SpriteSize;
	MyRect.y = Y * SpriteSize;
	MyRect.w = SpriteSize;
	MyRect.h = SpriteSize;

	PlayerDeltaTime += MYENGINE->GetDeltaTime();
	MyTexture = SDL_CreateTextureFromSurface(MYENGINE->GetMyRenderer(), MySurface);

	if (MyTexture)
	{
		SDL_RenderCopy(MYENGINE->GetMyRenderer(), MyTexture, &PlayerRect, &MyRect);
	}
	else
	{
		SDL_Log("Texture does not exist.");
	}

	if(PlayerDeltaTime >= 200)
	{
		PlayerRectX++;

		if (PlayerRectX >= 4)
		{
			PlayerRectX = 0;
		}

		PlayerDeltaTime = 0;

	}

}
