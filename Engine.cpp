#include "Engine.h"

static UEngine* AddressEngine;

UEngine::~UEngine()
{

}

UEngine* UEngine::GetInstance()
{

	AddressEngine = new UEngine();
	return AddressEngine;
}

void UEngine::Render()
{
	World.SettingMap();
	World.RederWorld();
}

UEngine::UEngine()
{
	IsRunning = true;
	AddressEngine = nullptr;
}
