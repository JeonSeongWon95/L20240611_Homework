#pragma once
#include "World.h"


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
	char GetKey();
	void Run();
	void LoadLevel(std::string Filename);

protected:
	UWorld World;
	bool IsRunning;
	static UEngine* AddressEngine;
};

#define MYENGINE UEngine::GetInstance()
