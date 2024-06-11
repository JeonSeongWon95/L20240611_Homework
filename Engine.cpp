#include "Engine.h"

UEngine::~UEngine()
{
	delete AddressEngine;
}

UEngine* UEngine::GetInstance()
{
	if (AddressEngine)
	{
		AddressEngine = new UEngine();
	}
	return AddressEngine;
}

UEngine::UEngine()
{
	AddressEngine = nullptr;
}
