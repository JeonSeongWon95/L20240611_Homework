#pragma once
#include "World.h"


class UEngine
{
public:
	virtual ~UEngine();
	static UEngine* GetInstance();

	inline bool GetIsRunning() { return IsRunning; }

	void Render();
	void Tick();
	void Input();

protected:
	UEngine();
	UWorld World;
	bool IsRunning;
};

