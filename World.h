#pragma once
#include "Engine.h"
#include <fstream>

class UWorld : public UEngine
{
public:
	UWorld();
	virtual ~UWorld();


protected:
	std::fstream Map;
};

