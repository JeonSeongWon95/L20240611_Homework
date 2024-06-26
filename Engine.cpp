#include "Engine.h"
#include "SDL.h"
#include "SDL_mixer.h"
#include <string>
#include <conio.h>

UEngine* UEngine::AddressEngine = nullptr;


UEngine::UEngine()
{
	World = new UWorld;
	IsRunning = true;
	AddressEngine = nullptr;
	MyEvent = new SDL_Event;
	LastTime = 0;
	DeltaTime = 0;
	SumTime = 0;

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		std::cout << "Init Fail" << endl;
	}
	else
	{
		std::cout << "Init Success" << endl;
	}

	MyWindow = SDL_CreateWindow("My Game", 300, 300, 640, 640, SDL_WINDOW_OPENGL);
	MyRenderer = SDL_CreateRenderer(MyWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_TARGETTEXTURE);

	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);

	Sound = Mix_LoadWAV("Data/bgm.mp3");

	Mix_PlayChannel(-1, Sound, -1);

}

UEngine::~UEngine()
{
	Mix_FreeChunk(Sound);
}

void UEngine::Render()
{
	SDL_GetRenderDrawColor(MyRenderer, 0, 0, 0, 0);
	SDL_RenderClear(MyRenderer);

	for (auto Actor : World->GetActors())
	{
		Actor->Render();
	}

	SDL_RenderPresent(MyRenderer);

}

void UEngine::Tick()
{
	DeltaTime = SDL_GetTicks64() - LastTime;
	LastTime = SDL_GetTicks64();
	SumTime += DeltaTime;
	
	World->TickWorld();
}

void UEngine::Input()
{
	SDL_PollEvent(MyEvent);
}

void UEngine::SetSumTime(float NewSum)
{
	SumTime = NewSum;
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
