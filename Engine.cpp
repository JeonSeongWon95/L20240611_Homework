#include "Engine.h"
#include <string>
#include <conio.h>

UEngine* UEngine::AddressEngine = nullptr;

UEngine::UEngine()
{
	World = new UWorld;
	IsRunning = true;
	AddressEngine = nullptr;
	Key = 0;
}

UEngine::~UEngine()
{
}

void UEngine::Render()
{
	World->RederWorld();
}

void UEngine::Tick()
{
	World->TickWorld();
}

void UEngine::Input()
{
	Key = _getch();
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
