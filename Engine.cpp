#include "Engine.h"
#include <string>

UEngine* UEngine::AddressEngine = nullptr;

UEngine::~UEngine()
{
}

void UEngine::Render()
{
	World.RederWorld();
}

void UEngine::Tick()
{
	World.TickWorld();
}

void UEngine::Input()
{
	World.Input();
}

char UEngine::GetKey()
{
	return World.GetKey();
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
	World.SettingMap(Filename);
}

UEngine::UEngine()
{
	IsRunning = true;
	AddressEngine = nullptr;
}
