#pragma once
#include "World.h"
#include "SDL.h"

#define MYENGINE UEngine::GetInstance()

class UEngine
{
protected:
	UEngine();

public:
	virtual ~UEngine();
	static UEngine* GetInstance() 
	{
		if (!AddressEngine)
		{
			AddressEngine = new UEngine();

			return AddressEngine;
		}

		return AddressEngine;
	};

	inline bool GetIsRunning() const { return IsRunning; }

	void Render();
	void Tick();
	void Input();
	void SetSumTime(float NewSum);
	inline UWorld* GetWorld() { return World; }
	inline float GetSumTime() { return SumTime; }
	inline SDL_Event* GetEvent() { return MyEvent; }
	inline bool GetIsRunning() { return IsRunning; }
	inline SDL_Renderer* GetMyRenderer() { return MyRenderer; }

	void Run();
	void LoadLevel(std::string Filename);

protected:
	UWorld* World;
	bool IsRunning;
	static UEngine* AddressEngine;
	SDL_Window* MyWindow;
	SDL_Event* MyEvent;
	SDL_Renderer* MyRenderer;
	float DeltaTime;
	float LastTime;
	float SumTime;
};
