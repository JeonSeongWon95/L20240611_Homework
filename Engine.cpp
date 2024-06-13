#include "Engine.h"
#include "SDL.h"
#include <string>
#include <conio.h>

UEngine* UEngine::AddressEngine = nullptr;

UEngine::UEngine()
{
	World = new UWorld;
	IsRunning = true;
	AddressEngine = nullptr;
	Key = 0;

	MyRect.x = 100;
	MyRect.y = 100;
	MyRect.w = 300;
	MyRect.h = 200;

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		std::cout << "Init Fail" << endl;
	}
	else
	{
		std::cout << "Init Success" << endl;
	}
	
	MyWindow = SDL_CreateWindow("My Game", 500, 500, 640, 480, SDL_WINDOW_OPENGL);
	MyRenderer = SDL_CreateRenderer(MyWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_TARGETTEXTURE);
}

UEngine::~UEngine()
{
}

void UEngine::Render()
{
	//World->RederWorld();
	SDL_RenderDrawRect(MyRenderer, &MyRect);
	SDL_SetRenderDrawColor(MyRenderer, 100, 200, 100, 0);
	SDL_RenderPresent(MyRenderer);
}

void UEngine::Tick()
{

	switch (MyEvent.type)
	{
	case SDL_KEYDOWN:
		switch (MyEvent.key.keysym.sym)
		{
		case SDLK_ESCAPE:
			IsRunning = false;
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
}

void UEngine::Input()
{
	SDL_PollEvent(&MyEvent);
}

void UEngine::Run()
{
	while (IsRunning)
	{
		Input();
		Tick();
		Render();
	}
}

void UEngine::LoadLevel(std::string Filename)
{
	World->SettingMap(Filename);
}
