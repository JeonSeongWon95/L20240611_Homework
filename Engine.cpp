#include "Engine.h"

UEngine* UEngine::AddressEngine = nullptr;

UEngine::~UEngine()
{

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
