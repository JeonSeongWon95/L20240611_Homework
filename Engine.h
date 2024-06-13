#pragma once
#include "World.h"
#include "SDL.h"


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
	inline char GetKey() { return Key; }
	inline UWorld* GetWorld() { return World; }
	void Run();
	void LoadLevel(std::string Filename);

protected:
	UWorld* World;
	char Key;
	bool IsRunning;
	static UEngine* AddressEngine;
	SDL_Window* MyWindow;
	SDL_Event MyEvent;
	SDL_Renderer* MyRenderer;
	SDL_Rect MyRect;
};

#define MYENGINE UEngine::GetInstance()
