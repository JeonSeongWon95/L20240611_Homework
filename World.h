#pragma once
#include "Engine.h"
#include <fstream>
#include <iostream>
#include <vector>
#include "Actor.h"


class UWorld : public UEngine
{
public:
	UWorld();

	virtual ~UWorld();

	void SpwanActor(AActor* NewActor);


protected:
	std::ifstream Map;
	std::vector<AActor*> Actors;
};

